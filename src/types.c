// Copyright 2023 Open Source Robotics Foundation, Inc.
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

#include "rosidl_dynamic_typesupport/types.h"


rosidl_dynamic_typesupport_serialization_support_t
rosidl_dynamic_typesupport_get_zero_initialized_serialization_support(void)
{
  return (rosidl_dynamic_typesupport_serialization_support_t) {0, 0, 0};  // NOLINT
}


rosidl_dynamic_typesupport_dynamic_type_builder_t
rosidl_dynamic_typesupport_get_zero_initialized_dynamic_type_builder(void)
{
  return (rosidl_dynamic_typesupport_dynamic_type_builder_t) {0, 0};  // NOLINT
}


rosidl_dynamic_typesupport_dynamic_type_t
rosidl_dynamic_typesupport_get_zero_initialized_dynamic_type(void)
{
  return (rosidl_dynamic_typesupport_dynamic_type_t) {0, 0};  // NOLINT
}


rosidl_dynamic_typesupport_dynamic_data_t
rosidl_dynamic_typesupport_get_zero_initialized_dynamic_data(void)
{
  return (rosidl_dynamic_typesupport_dynamic_data_t) {0, 0};  // NOLINT
}


rosidl_dynamic_typesupport_serialization_support_impl_t
rosidl_dynamic_typesupport_get_zero_initialized_serialization_support_impl(void)
{
  return (rosidl_dynamic_typesupport_serialization_support_impl_t) {0, 0};  // NOLINT
}


rosidl_dynamic_typesupport_dynamic_type_builder_impl_t
rosidl_dynamic_typesupport_get_zero_initialized_dynamic_type_builder_impl(void)
{
  return (rosidl_dynamic_typesupport_dynamic_type_builder_impl_t) {0};  // NOLINT
}


rosidl_dynamic_typesupport_dynamic_type_impl_t
rosidl_dynamic_typesupport_get_zero_initialized_dynamic_type_impl(void)
{
  return (rosidl_dynamic_typesupport_dynamic_type_impl_t) {0};  // NOLINT
}


rosidl_dynamic_typesupport_dynamic_data_impl_t
rosidl_dynamic_typesupport_get_zero_initialized_dynamic_data_impl(void)
{
  return (rosidl_dynamic_typesupport_dynamic_data_impl_t) {0};  // NOLINT
}
