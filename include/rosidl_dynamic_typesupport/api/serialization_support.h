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

/// Polymorphic serialization support interface
/// Downstream middlewares should populate this interface as appropriate

#ifndef ROSIDL_DYNAMIC_TYPESUPPORT__API__SERIALIZATION_SUPPORT_H_
#define ROSIDL_DYNAMIC_TYPESUPPORT__API__SERIALIZATION_SUPPORT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <rosidl_dynamic_typesupport/types.h>

#include <rosidl_dynamic_typesupport/api/serialization_support_interface.h>
#include <rosidl_dynamic_typesupport/api/dynamic_data.h>
#include <rosidl_dynamic_typesupport/api/dynamic_type.h>
#include <rosidl_dynamic_typesupport/visibility_control.h>

#include <rcutils/types/rcutils_ret.h>


// CORE ============================================================================================
ROSIDL_DYNAMIC_TYPESUPPORT_PUBLIC
const char *
rosidl_dynamic_typesupport_serialization_support_get_library_identifier(
  const rosidl_dynamic_typesupport_serialization_support_t * serialization_support);

ROSIDL_DYNAMIC_TYPESUPPORT_PUBLIC
rcutils_ret_t
rosidl_dynamic_typesupport_serialization_support_create(
  rosidl_dynamic_typesupport_serialization_support_impl_t * impl,
  rosidl_dynamic_typesupport_serialization_support_interface_t * methods,
  rosidl_dynamic_typesupport_serialization_support_t ** serialization_support);  // OUT

ROSIDL_DYNAMIC_TYPESUPPORT_PUBLIC
rcutils_ret_t
rosidl_dynamic_typesupport_serialization_support_destroy(
  rosidl_dynamic_typesupport_serialization_support_t * serialization_support);


#ifdef __cplusplus
}
#endif

#endif  // ROSIDL_DYNAMIC_TYPESUPPORT__API__SERIALIZATION_SUPPORT_H_
