// Copyright 2022 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <rcutils/allocator.h>
#include <rcutils/error_handling.h>
#include <rcutils/logging_macros.h>
#include <rcutils/types/rcutils_ret.h>
#include <rosidl_runtime_c/message_type_support_struct.h>
#include <rosidl_runtime_c/type_description/type_description__struct.h>
#include <rosidl_runtime_c/type_description/type_description__functions.h>
#include <rosidl_runtime_c/type_description/type_source__functions.h>

#include "rosidl_dynamic_typesupport/dynamic_message_type_support_struct.h"
#include "rosidl_dynamic_typesupport/identifier.h"


rcutils_ret_t
rosidl_dynamic_message_type_support_handle_create(
  rosidl_dynamic_typesupport_serialization_support_t * serialization_support,
  const rosidl_type_hash_t * type_hash,
  const rosidl_runtime_c__type_description__TypeDescription * type_description,
  const rosidl_runtime_c__type_description__TypeSource__Sequence * type_description_sources,
  rosidl_message_type_support_t ** ts)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(serialization_support, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(type_hash, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(type_description, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(ts, RCUTILS_RET_INVALID_ARGUMENT);

  // NOTE(methylDragon): Not supported for now
  // RCUTILS_CHECK_ARGUMENT_FOR_NULL(type_description_sources, RCUTILS_RET_INVALID_ARGUMENT);

  rcutils_ret_t ret = RCUTILS_RET_ERROR;
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  *ts = allocator.zero_allocate(1, sizeof(rosidl_message_type_support_t), allocator.state);
  if (!*ts) {
    RCUTILS_SET_ERROR_MSG("Could not allocate rosidl_message_type_support_t struct");
    return RCUTILS_RET_BAD_ALLOC;
  }

  (*ts)->data = allocator.zero_allocate(
    1, sizeof(rosidl_dynamic_message_type_support_impl_t), allocator.state);
  if (!ts) {
    RCUTILS_SET_ERROR_MSG("Could not allocate rosidl_dynamic_message_type_support_impl_t struct");
    ret = RCUTILS_RET_BAD_ALLOC;
    goto fail;
  }

  rosidl_dynamic_message_type_support_impl_t * ts_impl =
    (rosidl_dynamic_message_type_support_impl_t *) (*ts)->data;

  // Copy init type hash (never null (checked above))
  ts_impl->type_hash = allocator.zero_allocate(1, sizeof(rosidl_type_hash_t), allocator.state);
  if (!ts_impl->type_hash) {
    RCUTILS_SET_ERROR_MSG("Could not create type hash to assign into");
    ret = RCUTILS_RET_BAD_ALLOC;
    goto fail;
  }

  ts_impl->type_hash->version = type_hash->version;
  memcpy(ts_impl->type_hash->value, type_hash->value, sizeof(type_hash->value));

  // Copy init type description (never null (checked above))
  ts_impl->type_description = rosidl_runtime_c__type_description__TypeDescription__create();
  if (ts_impl->type_description == NULL) {
    RCUTILS_SET_ERROR_MSG("Could not create type description to assign into");
    ret = RCUTILS_RET_BAD_ALLOC;
    goto fail;
  }

  if (!rosidl_runtime_c__type_description__TypeDescription__copy(
      type_description, ts_impl->type_description))
  {
    RCUTILS_SET_ERROR_MSG("Could not copy type description");
    ret = RCUTILS_RET_ERROR;
    goto fail;
  }

  // Copy init type description sources (might be null)
  if (type_description_sources != NULL) {
    ts_impl->type_description_sources =
      rosidl_runtime_c__type_description__TypeSource__Sequence__create(
      type_description_sources->size);
    if (ts_impl->type_description_sources == NULL) {
      RCUTILS_SET_ERROR_MSG("Could not create type description sources sequence to assign into");
      ret = RCUTILS_RET_BAD_ALLOC;
      goto fail;
    }

    if (!rosidl_runtime_c__type_description__TypeSource__Sequence__copy(
        type_description_sources, ts_impl->type_description_sources))
    {
      RCUTILS_SET_ERROR_MSG("Could not copy type description sources");
      ret = RCUTILS_RET_ERROR;
      goto fail;
    }
  }

  ts_impl->serialization_support = serialization_support;

  (*ts)->typesupport_identifier = rosidl_dynamic_typesupport_c__identifier;
  (*ts)->func = get_message_typesupport_handle_function;
  (*ts)->get_type_hash_func =
    rosidl_get_dynamic_message_type_support_type_hash_function;
  (*ts)->get_type_description_func =
    rosidl_get_dynamic_message_type_support_type_description_function;
  (*ts)->get_type_description_sources_func =
    rosidl_get_dynamic_message_type_support_type_description_sources_function;

  ret = rosidl_dynamic_typesupport_dynamic_type_create_from_description(
    ts_impl->serialization_support, type_description, &ts_impl->dynamic_message_type);
  if (ret != RCUTILS_RET_OK || !ts_impl->dynamic_message_type) {
    RCUTILS_SET_ERROR_MSG(
      "Could not construct dynamic type for rosidl_dynamic_message_type_support_impl_t struct");
    goto fail;
  }

  ret = rosidl_dynamic_typesupport_dynamic_data_create_from_dynamic_type(
    ts_impl->dynamic_message_type, &ts_impl->dynamic_message);
  if (ret != RCUTILS_RET_OK || !ts_impl->dynamic_message) {
    rcutils_error_string_t error_string = rcutils_get_error_string();
    rcutils_reset_error();
    RCUTILS_SET_ERROR_MSG_WITH_FORMAT_STRING(
      "Could not construct dynamic data for rosidl_dynamic_message_type_support_impl_t struct:\n%s",
      error_string.str);
    goto fail;
  }

  return RCUTILS_RET_OK;

fail:
  if (rosidl_dynamic_message_type_support_handle_destroy(*ts) != RCUTILS_RET_OK) {
    RCUTILS_SAFE_FWRITE_TO_STDERR(
      "While handling another error, could not destroy dynamic message typesupport");
  }
  return ret;
}


rcutils_ret_t
rosidl_dynamic_message_type_support_handle_destroy(rosidl_message_type_support_t * ts)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(ts, RCUTILS_RET_INVALID_ARGUMENT);

  // NOTE(methylDragon): Ignores const...
  if (ts->typesupport_identifier != rosidl_dynamic_typesupport_c__identifier) {
    RCUTILS_SET_ERROR_MSG("type support not from this implementation");
    return RCUTILS_RET_INVALID_ARGUMENT;
  }

  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (ts->data) {
    rosidl_dynamic_message_type_support_impl_t * ts_impl =
      (rosidl_dynamic_message_type_support_impl_t *)ts->data;
    if (ts_impl->type_description) {
      rosidl_runtime_c__type_description__TypeDescription__fini(ts_impl->type_description);
    }
    if (ts_impl->type_description_sources) {
      rosidl_runtime_c__type_description__TypeSource__Sequence__fini(
        ts_impl->type_description_sources);
    }
    if (ts_impl->dynamic_message_type) {
      rosidl_dynamic_typesupport_dynamic_type_destroy(ts_impl->dynamic_message_type);
    }
    if (ts_impl->dynamic_message) {
      rosidl_dynamic_typesupport_dynamic_data_destroy(ts_impl->dynamic_message);
    }
    allocator.deallocate(ts_impl->type_hash, allocator.state);
  }
  allocator.deallocate((void *)ts->data, allocator.state);
  allocator.deallocate(ts, allocator.state);
  return RCUTILS_RET_OK;
}


// GETTERS =========================================================================================
const rosidl_type_hash_t *
rosidl_get_dynamic_message_type_support_type_hash_function(
  const rosidl_message_type_support_t * type_support)
{
  const rosidl_message_type_support_t * ts = get_message_typesupport_handle(
    type_support, rosidl_dynamic_typesupport_c__identifier);
  if (ts == NULL) {
    return NULL;
  }
  rosidl_dynamic_message_type_support_impl_t * ts_impl =
    (rosidl_dynamic_message_type_support_impl_t *) ts->data;
  return ts_impl->type_hash;
}


const rosidl_runtime_c__type_description__TypeDescription *
rosidl_get_dynamic_message_type_support_type_description_function(
  const rosidl_message_type_support_t * type_support)
{
  const rosidl_message_type_support_t * ts = get_message_typesupport_handle(
    type_support, rosidl_dynamic_typesupport_c__identifier);
  if (ts == NULL) {
    return NULL;
  }
  rosidl_dynamic_message_type_support_impl_t * ts_impl =
    (rosidl_dynamic_message_type_support_impl_t *) ts->data;
  return ts_impl->type_description;
}


const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosidl_get_dynamic_message_type_support_type_description_sources_function(
  const rosidl_message_type_support_t * type_support)
{
  const rosidl_message_type_support_t * ts = get_message_typesupport_handle(
    type_support, rosidl_dynamic_typesupport_c__identifier);
  if (ts == NULL) {
    return NULL;
  }
  rosidl_dynamic_message_type_support_impl_t * ts_impl =
    (rosidl_dynamic_message_type_support_impl_t *) ts->data;
  return ts_impl->type_description_sources;
}
