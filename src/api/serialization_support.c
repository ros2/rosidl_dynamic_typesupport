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
#include <rosidl_dynamic_typesupport/macros.h>
#include <rosidl_dynamic_typesupport/types.h>

#include <rcutils/allocator.h>
#include <rcutils/error_handling.h>
#include <rcutils/types/rcutils_ret.h>

// CORE ============================================================================================
const char *
rosidl_dynamic_typesupport_serialization_support_get_library_identifier(
  const rosidl_dynamic_typesupport_serialization_support_t * serialization_support)
{
  return serialization_support->library_identifier;
}


rcutils_ret_t
rosidl_dynamic_typesupport_serialization_support_init(
  rosidl_dynamic_typesupport_serialization_support_impl_t * impl,
  rosidl_dynamic_typesupport_serialization_support_interface_t * interface,
  rosidl_dynamic_typesupport_serialization_support_t ** serialization_support)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(impl, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(interface, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(serialization_support, RCUTILS_RET_INVALID_ARGUMENT);

  if (impl->library_identifier != interface->library_identifier) {
    RCUTILS_SET_ERROR_MSG(
      "Library identifiers for serialization support impl and interface do not match");
    return RCUTILS_RET_INVALID_ARGUMENT;
  }

  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  *serialization_support =
    (rosidl_dynamic_typesupport_serialization_support_t *) allocator.zero_allocate(
    1, sizeof(rosidl_dynamic_typesupport_serialization_support_t), &allocator.state);
  if (!*serialization_support) {
    RCUTILS_SET_ERROR_MSG("Could not allocate serialization support");
    return RCUTILS_RET_BAD_ALLOC;
  }

  (*serialization_support)->library_identifier = interface->library_identifier;
  (*serialization_support)->impl = impl;
  (*serialization_support)->interface = interface;
  return RCUTILS_RET_OK;
}


rcutils_ret_t
rosidl_dynamic_typesupport_serialization_support_destroy(
  rosidl_dynamic_typesupport_serialization_support_t * serialization_support)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(serialization_support, RCUTILS_RET_INVALID_ARGUMENT);

  ROSIDL_DYNAMIC_TYPESUPPORT_CHECK_RET_FOR_NOT_OK(
    (serialization_support->interface->serialization_support_impl_destroy)(
      serialization_support->impl)
  );

  ROSIDL_DYNAMIC_TYPESUPPORT_CHECK_RET_FOR_NOT_OK(
    (serialization_support->interface->serialization_support_interface_destroy)(
      serialization_support->interface)
  );

  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  allocator.deallocate(serialization_support, &allocator.state);
  return RCUTILS_RET_OK;
}
