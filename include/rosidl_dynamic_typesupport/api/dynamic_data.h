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

#ifndef ROSIDL_DYNAMIC_TYPESUPPORT__API__DYNAMIC_DATA_H_
#define ROSIDL_DYNAMIC_TYPESUPPORT__API__DYNAMIC_DATA_H_

#include <wchar.h>
#include <rosidl_dynamic_typesupport/api/serialization_support_interface.h>


#ifdef __cplusplus
extern "C" {
#endif

// ===============================================================================================
// DYNAMIC DATA
// ===============================================================================================

// DYNAMIC DATA UTILS ==============================================================================
void
rosidl_dynamic_typesupport_dynamic_data_clear_all_values(rosidl_dynamic_typesupport_dynamic_data_t * data);

void
rosidl_dynamic_typesupport_dynamic_data_clear_nonkey_values(rosidl_dynamic_typesupport_dynamic_data_t * data);

void
rosidl_dynamic_typesupport_dynamic_data_clear_value(rosidl_dynamic_typesupport_dynamic_data_t * data, rosidl_dynamic_typesupport_member_id_t id);

bool
rosidl_dynamic_typesupport_dynamic_data_equals(const rosidl_dynamic_typesupport_dynamic_data_t * data, const rosidl_dynamic_typesupport_dynamic_data_t * other);

size_t
rosidl_dynamic_typesupport_dynamic_data_get_item_count(const rosidl_dynamic_typesupport_dynamic_data_t * data);

rosidl_dynamic_typesupport_member_id_t
rosidl_dynamic_typesupport_dynamic_data_get_member_id_by_name_by_name(const rosidl_dynamic_typesupport_dynamic_data_t * data, const char * name, size_t name_length);

rosidl_dynamic_typesupport_member_id_t
rosidl_dynamic_typesupport_dynamic_data_get_member_id_at_index(const rosidl_dynamic_typesupport_dynamic_data_t * data, size_t index);

// You must use this for arrays
rosidl_dynamic_typesupport_member_id_t
rosidl_dynamic_typesupport_dynamic_data_get_array_index(rosidl_dynamic_typesupport_dynamic_data_t * data, size_t index);

rosidl_dynamic_typesupport_dynamic_data_t *
rosidl_dynamic_typesupport_dynamic_data_loan_value(rosidl_dynamic_typesupport_dynamic_data_t * data, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_return_loaned_value(rosidl_dynamic_typesupport_dynamic_data_t * data, rosidl_dynamic_typesupport_dynamic_data_t * inner_dynamic_data);

void
rosidl_dynamic_typesupport_dynamic_data_print(rosidl_dynamic_typesupport_dynamic_data_t * data);

// DYNAMIC DATA CONSTRUCTION =======================================================================
rosidl_dynamic_typesupport_dynamic_data_t *
rosidl_dynamic_typesupport_dynamic_data_init_from_dynamic_type_builder(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder);

rosidl_dynamic_typesupport_dynamic_data_t *
rosidl_dynamic_typesupport_dynamic_data_init_from_dynamic_type(rosidl_dynamic_typesupport_dynamic_type_t * dynamic_type);

rosidl_dynamic_typesupport_dynamic_data_t *
rosidl_dynamic_typesupport_dynamic_data_clone(const rosidl_dynamic_typesupport_dynamic_data_t * data);

void
rosidl_dynamic_typesupport_dynamic_data_fini(rosidl_dynamic_typesupport_dynamic_data_t * data);

// DYNAMIC DATA PRIMITIVE MEMBER GETTERS ===========================================================
void
rosidl_dynamic_typesupport_dynamic_data_get_bool_value(const rosidl_dynamic_typesupport_dynamic_data_t * data, bool * value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_get_byte_value(const rosidl_dynamic_typesupport_dynamic_data_t * data, uint8_t * value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_get_char_value(const rosidl_dynamic_typesupport_dynamic_data_t * data, char * value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_get_wchar_value(const rosidl_dynamic_typesupport_dynamic_data_t * data, wchar_t * value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_get_float32_value(const rosidl_dynamic_typesupport_dynamic_data_t * data, float * value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_get_float64_value(const rosidl_dynamic_typesupport_dynamic_data_t * data, double * value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_get_float128_value(const rosidl_dynamic_typesupport_dynamic_data_t * data, long double * value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_get_int8_value(const rosidl_dynamic_typesupport_dynamic_data_t * data, int8_t * value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_get_uint8_value(const rosidl_dynamic_typesupport_dynamic_data_t * data, uint8_t * value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_get_int16_value(const rosidl_dynamic_typesupport_dynamic_data_t * data, int16_t * value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_get_uint16_value(const rosidl_dynamic_typesupport_dynamic_data_t * data, uint16_t * value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_get_int32_value(const rosidl_dynamic_typesupport_dynamic_data_t * data, int32_t * value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_get_uint32_value(const rosidl_dynamic_typesupport_dynamic_data_t * data, uint32_t * value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_get_int64_value(const rosidl_dynamic_typesupport_dynamic_data_t * data, int64_t * value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_get_uint64_value(const rosidl_dynamic_typesupport_dynamic_data_t * data, uint64_t * value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_get_string_value(
  const rosidl_dynamic_typesupport_dynamic_data_t * data, const char ** value, size_t * value_length, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_get_wstring_value(
  const rosidl_dynamic_typesupport_dynamic_data_t * data, const wchar_t ** value, size_t * value_length, rosidl_dynamic_typesupport_member_id_t id);

// DYNAMIC DATA PRIMITIVE MEMBER SETTERS ===========================================================
void
rosidl_dynamic_typesupport_dynamic_data_set_bool_value(rosidl_dynamic_typesupport_dynamic_data_t * data, bool value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_set_byte_value(rosidl_dynamic_typesupport_dynamic_data_t * data, uint8_t value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_set_char_value(rosidl_dynamic_typesupport_dynamic_data_t * data, char value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_set_wchar_value(rosidl_dynamic_typesupport_dynamic_data_t * data, wchar_t value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_set_float32_value(rosidl_dynamic_typesupport_dynamic_data_t * data, float value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_set_float64_value(rosidl_dynamic_typesupport_dynamic_data_t * data, double value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_set_float128_value(rosidl_dynamic_typesupport_dynamic_data_t * data, long double value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_set_int8_value(rosidl_dynamic_typesupport_dynamic_data_t * data, int8_t value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_set_uint8_value(rosidl_dynamic_typesupport_dynamic_data_t * data, uint8_t value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_set_int16_value(rosidl_dynamic_typesupport_dynamic_data_t * data, int16_t value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_set_uint16_value(rosidl_dynamic_typesupport_dynamic_data_t * data, uint16_t value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_set_int32_value(rosidl_dynamic_typesupport_dynamic_data_t * data, int32_t value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_set_uint32_value(rosidl_dynamic_typesupport_dynamic_data_t * data, uint32_t value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_set_int64_value(rosidl_dynamic_typesupport_dynamic_data_t * data, int64_t value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_set_uint64_value(rosidl_dynamic_typesupport_dynamic_data_t * data, uint64_t value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_set_string_value(
  rosidl_dynamic_typesupport_dynamic_data_t * data, const char * value, size_t value_length, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_set_wstring_value(
  rosidl_dynamic_typesupport_dynamic_data_t * data, const wchar_t * value, size_t value_length, rosidl_dynamic_typesupport_member_id_t id);

// DYNAMIC DATA SEQUENCES ==========================================================================
void
rosidl_dynamic_typesupport_dynamic_data_clear_sequence_data(rosidl_dynamic_typesupport_dynamic_data_t * data);

void
rosidl_dynamic_typesupport_dynamic_data_remove_sequence_data(rosidl_dynamic_typesupport_dynamic_data_t * data, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_sequence_data(rosidl_dynamic_typesupport_dynamic_data_t * data, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_bool_value(rosidl_dynamic_typesupport_dynamic_data_t * data, bool value, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_byte_value(rosidl_dynamic_typesupport_dynamic_data_t * data, uint8_t value, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_char_value(rosidl_dynamic_typesupport_dynamic_data_t * data, char value, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_wchar_value(rosidl_dynamic_typesupport_dynamic_data_t * data, wchar_t value, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_float32_value(rosidl_dynamic_typesupport_dynamic_data_t * data, float value, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_float64_value(rosidl_dynamic_typesupport_dynamic_data_t * data, double value, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_float128_value(rosidl_dynamic_typesupport_dynamic_data_t * data, long double value, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_int8_value(rosidl_dynamic_typesupport_dynamic_data_t * data, int8_t value, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_uint8_value(rosidl_dynamic_typesupport_dynamic_data_t * data, uint8_t value, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_int16_value(rosidl_dynamic_typesupport_dynamic_data_t * data, int16_t value, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_uint16_value(rosidl_dynamic_typesupport_dynamic_data_t * data, uint16_t value, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_int32_value(rosidl_dynamic_typesupport_dynamic_data_t * data, int32_t value, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_uint32_value(rosidl_dynamic_typesupport_dynamic_data_t * data, uint32_t value, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_int64_value(rosidl_dynamic_typesupport_dynamic_data_t * data, int64_t value, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_uint64_value(rosidl_dynamic_typesupport_dynamic_data_t * data, uint64_t value, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_string_value(rosidl_dynamic_typesupport_dynamic_data_t * data, const char * value, size_t value_length, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_wstring_value(
  rosidl_dynamic_typesupport_dynamic_data_t * data, const wchar_t * value, size_t value_length, rosidl_dynamic_typesupport_member_id_t * out_id);

// DYNAMIC DATA NESTED =============================================================================
// The user is expected to allocate the '** value' outparam outside
// This function will then reassign the '** value''s 'serialization_support' member to match the
// input's
void
rosidl_dynamic_typesupport_dynamic_data_get_complex_value(const rosidl_dynamic_typesupport_dynamic_data_t * data, rosidl_dynamic_typesupport_dynamic_data_t ** value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_set_complex_value(rosidl_dynamic_typesupport_dynamic_data_t * data, rosidl_dynamic_typesupport_dynamic_data_t * value, rosidl_dynamic_typesupport_member_id_t id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_const_complex_value(
  rosidl_dynamic_typesupport_dynamic_data_t * data, const rosidl_dynamic_typesupport_dynamic_data_t * value, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_complex_value(rosidl_dynamic_typesupport_dynamic_data_t * data, rosidl_dynamic_typesupport_dynamic_data_t * value, rosidl_dynamic_typesupport_member_id_t * out_id);

void
rosidl_dynamic_typesupport_dynamic_data_insert_complex_value_ptr(
  rosidl_dynamic_typesupport_dynamic_data_t * data, rosidl_dynamic_typesupport_dynamic_data_t * value, rosidl_dynamic_typesupport_member_id_t * out_id);

#ifdef __cplusplus
}
#endif

#endif  // ROSIDL_DYNAMIC_TYPESUPPORT__API__DYNAMIC_DATA_H_
