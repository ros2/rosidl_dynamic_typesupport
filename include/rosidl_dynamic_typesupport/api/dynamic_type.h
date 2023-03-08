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

#ifndef ROSIDL_DYNAMIC_TYPESUPPORT__API__DYNAMIC_TYPE_H_
#define ROSIDL_DYNAMIC_TYPESUPPORT__API__DYNAMIC_TYPE_H_

#include <rosidl_dynamic_typesupport/api/serialization_support_interface.h>


#ifdef __cplusplus
extern "C" {
#endif


// =================================================================================================
// DYNAMIC TYPE
// =================================================================================================

// DYNAMIC TYPE UTILS ==============================================================================
bool
rosidl_dynamic_typesupport_dynamic_type_equals(rosidl_dynamic_typesupport_dynamic_type_t * dynamic_type, rosidl_dynamic_typesupport_dynamic_type_t * other);

size_t
rosidl_dynamic_typesupport_dynamic_type_get_member_count(const rosidl_dynamic_typesupport_dynamic_type_t * dynamic_type);


// DYNAMIC TYPE CONSTRUCTION =======================================================================
rosidl_dynamic_typesupport_dynamic_type_builder_t *
rosidl_dynamic_typesupport_dynamic_type_builder_init(rosidl_dynamic_typesupport_serialization_support_t * serialization_support, const char * name, size_t name_length);

rosidl_dynamic_typesupport_dynamic_type_builder_t *
rosidl_dynamic_typesupport_dynamic_type_builder_clone(const rosidl_dynamic_typesupport_dynamic_type_builder_t * other);

void
rosidl_dynamic_typesupport_dynamic_type_builder_fini(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder);

rosidl_dynamic_typesupport_dynamic_type_t *
rosidl_dynamic_typesupport_dynamic_type_init_from_dynamic_type_builder(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder);

rosidl_dynamic_typesupport_dynamic_type_t *
rosidl_dynamic_typesupport_dynamic_type_init_from_description(rosidl_dynamic_typesupport_serialization_support_t * serialization_support, type_description_t * description);

rosidl_dynamic_typesupport_dynamic_type_t *
rosidl_dynamic_typesupport_dynamic_type_clone(const rosidl_dynamic_typesupport_dynamic_type_t * other);

void
rosidl_dynamic_typesupport_dynamic_type_fini(rosidl_dynamic_typesupport_dynamic_type_t * dynamic_type);

void
rosidl_dynamic_typesupport_dynamic_type_set_name(rosidl_dynamic_typesupport_dynamic_type_t * dynamic_type, const char * name, size_t name_length);

char *
rosidl_dynamic_typesupport_dynamic_type_builder_get_name(const rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder);

void
rosidl_dynamic_typesupport_dynamic_type_builder_set_name(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, const char * name, size_t name_length);

// DYNAMIC TYPE PRIMITIVE MEMBERS ==================================================================
void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bool_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_byte_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_char_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_wchar_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float32_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float64_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float128_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int8_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint8_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int16_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint16_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int32_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint32_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int64_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint64_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_string_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_wstring_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_string_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t string_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_wstring_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t wstring_bound);


// DYNAMIC TYPE STATIC ARRAY MEMBERS ===============================================================
void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bool_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_byte_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_char_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_wchar_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float32_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float64_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float128_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int8_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint8_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int16_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint16_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int32_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint32_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int64_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint64_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_string_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_wstring_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_string_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length,
  size_t string_bound, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_wstring_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length,
  size_t wstring_bound, size_t array_length);


// DYNAMIC TYPE UNBOUNDED SEQUENCE MEMBERS =========================================================
void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bool_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_byte_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_char_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_wchar_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float32_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float64_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float128_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int8_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint8_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int16_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint16_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int32_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint32_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int64_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint64_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_string_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_wstring_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_string_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t string_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_wstring_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t wstring_bound);


// DYNAMIC TYPE BOUNDED SEQUENCE MEMBERS ===========================================================
void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bool_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_byte_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_char_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_wchar_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float32_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float64_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float128_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int8_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint8_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int16_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint16_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int32_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint32_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int64_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint64_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_string_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_wstring_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_string_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length,
  size_t string_bound, size_t sequence_bound);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_wstring_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length,
  size_t wstring_bound, size_t sequence_bound);


// DYNAMIC TYPE NESTED MEMBERS =====================================================================
void
rosidl_dynamic_typesupport_dynamic_type_builder_add_complex_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder,
  rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, rosidl_dynamic_typesupport_dynamic_type_t * nested_struct);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_complex_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length,
  rosidl_dynamic_typesupport_dynamic_type_t * nested_struct, size_t array_length);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_complex_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, rosidl_dynamic_typesupport_dynamic_type_t * nested_struct);

void
rosidl_dynamic_typesupport_dynamic_type_builder_add_complex_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length,
  rosidl_dynamic_typesupport_dynamic_type_t * nested_struct, size_t sequence_bound);


#ifdef __cplusplus
}
#endif

#endif  // ROSIDL_DYNAMIC_TYPESUPPORT__API__DYNAMIC_TYPE_H_
