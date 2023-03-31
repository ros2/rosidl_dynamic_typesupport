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

#include <assert.h>
#include <stdlib.h>

#include <rosidl_dynamic_typesupport/api/serialization_support.h>
#include <rosidl_dynamic_typesupport/api/serialization_support_interface.h>
#include <rosidl_dynamic_typesupport/types.h>

#include <rcutils/allocator.h>
#include <rcutils/error_handling.h>
#include <rcutils/types/rcutils_ret.h>

// CORE ============================================================================================
const char *
rosidl_dynamic_typesupport_serialization_support_get_library_identifier(
  const rosidl_dynamic_typesupport_serialization_support_t * serialization_support)
{
  // RCUTILS_CHECK_ARGUMENT_FOR_NULL(serialization_support, RCUTILS_RET_INVALID_ARGUMENT);
  return serialization_support->library_identifier;
}


rosidl_dynamic_typesupport_serialization_support_t *
rosidl_dynamic_typesupport_serialization_support_init(
  rosidl_dynamic_typesupport_serialization_support_impl_t * impl,
  rosidl_dynamic_typesupport_serialization_support_interface_t * interface)
{
  // RCUTILS_CHECK_ARGUMENT_FOR_NULL(impl, RCUTILS_RET_INVALID_ARGUMENT);
  // RCUTILS_CHECK_ARGUMENT_FOR_NULL(interface, RCUTILS_RET_INVALID_ARGUMENT);

  if (impl->library_identifier != interface->library_identifier) {
    // RCUTILS_SET_ERROR_MSG(
    //   "Library identifiers for serialization support impl and interface do not match");
    // return RCUTILS_RET_INVALID_ARGUMENT;
  }

  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosidl_dynamic_typesupport_serialization_support_t * ts =
    (rosidl_dynamic_typesupport_serialization_support_t *) allocator.zero_allocate(
      1, sizeof(rosidl_dynamic_typesupport_serialization_support_t), &allocator.state);
  ts->library_identifier = interface->library_identifier;
  ts->impl = impl;
  ts->interface = interface;
  return ts;
}


rcutils_ret_t
rosidl_dynamic_typesupport_serialization_support_fini(
  rosidl_dynamic_typesupport_serialization_support_t * serialization_support)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(serialization_support, RCUTILS_RET_INVALID_ARGUMENT);

  rcutils_ret_t ret = (serialization_support->interface->serialization_support_impl_handle_fini)(
    serialization_support->impl);
  if (ret != RCUTILS_RET_OK) {
    return ret;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  allocator.deallocate(serialization_support->interface, &allocator.state);
  allocator.deallocate(serialization_support->impl, &allocator.state);
  return RCUTILS_RET_OK;
}


rcutils_ret_t
rosidl_dynamic_typesupport_serialization_support_destroy(
  rosidl_dynamic_typesupport_serialization_support_t * serialization_support)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(serialization_support, RCUTILS_RET_INVALID_ARGUMENT);

  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rcutils_ret_t ret = rosidl_dynamic_typesupport_serialization_support_fini(serialization_support);
  if (ret != RCUTILS_RET_OK) {
    return ret;
  }
  allocator.deallocate(serialization_support, &allocator.state);
  return RCUTILS_RET_OK;
}
