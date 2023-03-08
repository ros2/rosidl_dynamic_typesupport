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
#include <wchar.h>
#include <rosidl_dynamic_typesupport/api/dynamic_data.h>
#include <rosidl_dynamic_typesupport/types.h>


// =================================================================================================
// DYNAMIC DATA
// =================================================================================================

// DYNAMIC DATA UTILS ==============================================================================
void
rosidl_dynamic_typesupport_dynamic_data_clear_all_values(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  (dynamic_data->serialization_support->interface->dynamic_data_clear_all_values)(dynamic_data->serialization_support->impl, dynamic_data->impl);
}


void
rosidl_dynamic_typesupport_dynamic_data_clear_nonkey_values(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  (dynamic_data->serialization_support->interface->dynamic_data_clear_nonkey_values)(dynamic_data->serialization_support->impl, dynamic_data->impl);
}


void
rosidl_dynamic_typesupport_dynamic_data_clear_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_clear_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, id);
}


bool
rosidl_dynamic_typesupport_dynamic_data_equals(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, const rosidl_dynamic_typesupport_dynamic_data_t * other)
{
  assert(dynamic_data->serialization_support->library_identifier == other->serialization_support->library_identifier);
  return (dynamic_data->serialization_support->interface->dynamic_data_equals)(dynamic_data->serialization_support->impl, dynamic_data->impl, other->impl);
}


size_t
rosidl_dynamic_typesupport_dynamic_data_get_item_count(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  return (dynamic_data->serialization_support->interface->dynamic_data_get_item_count)(dynamic_data->serialization_support->impl, dynamic_data->impl);
}


rosidl_dynamic_typesupport_member_id_t
rosidl_dynamic_typesupport_dynamic_data_get_member_id_by_name_by_name(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, const char * name, size_t name_length)
{
  return (dynamic_data->serialization_support->interface->dynamic_data_get_member_id_by_name)(dynamic_data->serialization_support->impl, dynamic_data->impl, name, name_length);
}


rosidl_dynamic_typesupport_member_id_t
rosidl_dynamic_typesupport_dynamic_data_get_member_id_at_index(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, size_t index)
{
  return (dynamic_data->serialization_support->interface->dynamic_data_get_member_id_at_index)(dynamic_data->serialization_support->impl, dynamic_data->impl, index);
}


rosidl_dynamic_typesupport_member_id_t
rosidl_dynamic_typesupport_dynamic_data_get_array_index(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, size_t index)
{
  return (dynamic_data->serialization_support->interface->dynamic_data_get_array_index)(dynamic_data->serialization_support->impl, dynamic_data->impl, index);
}


rosidl_dynamic_typesupport_dynamic_data_t *
rosidl_dynamic_typesupport_dynamic_data_loan_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, rosidl_dynamic_typesupport_member_id_t id)
{
  rosidl_dynamic_typesupport_dynamic_data_t * out = calloc(1, sizeof(rosidl_dynamic_typesupport_dynamic_data_t));
  out->serialization_support = dynamic_data->serialization_support;
  out->impl = (dynamic_data->serialization_support->interface->dynamic_data_loan_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, id);
  return out;
}


void
rosidl_dynamic_typesupport_dynamic_data_return_loaned_value(rosidl_dynamic_typesupport_dynamic_data_t * outer_dynamic_data, rosidl_dynamic_typesupport_dynamic_data_t * inner_dynamic_data)
{
  assert(outer_dynamic_data->serialization_support->library_identifier == inner_dynamic_data->serialization_support->library_identifier);
  (outer_dynamic_data->serialization_support->interface->dynamic_data_return_loaned_value)(outer_dynamic_data->serialization_support->impl, outer_dynamic_data->impl, inner_dynamic_data->impl);
  free(inner_dynamic_data);
}


void
rosidl_dynamic_typesupport_dynamic_data_print(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  (dynamic_data->serialization_support->interface->dynamic_data_print)(dynamic_data->serialization_support->impl, dynamic_data->impl);
}


// DYNAMIC DATA CONSTRUCTION =======================================================================
rosidl_dynamic_typesupport_dynamic_data_t *
rosidl_dynamic_typesupport_dynamic_data_init_from_dynamic_type_builder(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder)
{
  rosidl_dynamic_typesupport_dynamic_data_t * out = calloc(1, sizeof(rosidl_dynamic_typesupport_dynamic_data_t));
  out->serialization_support = dynamic_type_builder->serialization_support;
  out->impl = (out->serialization_support->interface->dynamic_data_init_from_dynamic_type_builder)(out->serialization_support->impl, dynamic_type_builder->impl);
  return out;
}


rosidl_dynamic_typesupport_dynamic_data_t *
rosidl_dynamic_typesupport_dynamic_data_init_from_dynamic_type(rosidl_dynamic_typesupport_dynamic_type_t * dynamic_type)
{
  rosidl_dynamic_typesupport_dynamic_data_t * out = calloc(1, sizeof(rosidl_dynamic_typesupport_dynamic_data_t));
  out->serialization_support = dynamic_type->serialization_support;
  out->impl = (out->serialization_support->interface->dynamic_data_init_from_dynamic_type)(out->serialization_support->impl, dynamic_type->impl);
  return out;
}


rosidl_dynamic_typesupport_dynamic_data_t *
rosidl_dynamic_typesupport_dynamic_data_clone(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  rosidl_dynamic_typesupport_dynamic_data_t * out = calloc(1, sizeof(rosidl_dynamic_typesupport_dynamic_data_t));
  out->serialization_support = dynamic_data->serialization_support;
  out->impl = (dynamic_data->serialization_support->interface->dynamic_data_clone)(dynamic_data->serialization_support->impl, dynamic_data->impl);
  return out;
}


void
rosidl_dynamic_typesupport_dynamic_data_fini(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  (dynamic_data->serialization_support->interface->dynamic_data_fini)(dynamic_data->serialization_support->impl, dynamic_data->impl);
  free(dynamic_data->impl);
}


// DYNAMIC DATA PRIMITIVE MEMBER GETTERS ===========================================================
void
rosidl_dynamic_typesupport_dynamic_data_get_bool_value(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, bool * value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_bool_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_byte_value(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, uint8_t * value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_byte_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_char_value(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, char * value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_char_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_wchar_value(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, wchar_t * value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_wchar_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_float32_value(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, float * value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_float32_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_float64_value(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, double * value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_float64_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_float128_value(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, long double * value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_float128_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_int8_value(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, int8_t * value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_int8_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_uint8_value(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, uint8_t * value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_uint8_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_int16_value(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, int16_t * value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_int16_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_uint16_value(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, uint16_t * value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_uint16_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_int32_value(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, int32_t * value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_int32_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_uint32_value(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, uint32_t * value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_uint32_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_int64_value(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, int64_t * value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_int64_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_uint64_value(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, uint64_t * value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_uint64_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_string_value(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, const char ** value, size_t * value_length, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_string_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, value_length, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_wstring_value(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, const wchar_t ** value, size_t * value_length, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_wstring_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, value_length, id);
}


// DYNAMIC DATA PRIMITIVE MEMBER SETTERS ===========================================================
void
rosidl_dynamic_typesupport_dynamic_data_set_bool_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, bool value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_bool_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_byte_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, uint8_t value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_byte_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_char_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, char value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_char_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_wchar_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, wchar_t value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_wchar_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_float32_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, float value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_float32_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_float64_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, double value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_float64_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_float128_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, long double value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_float128_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_int8_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, int8_t value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_int8_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_uint8_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, uint8_t value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_uint8_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_int16_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, int16_t value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_int16_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_uint16_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, uint16_t value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_uint16_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_int32_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, int32_t value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_int32_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_uint32_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, uint32_t value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_uint32_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_int64_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, int64_t value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_int64_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_uint64_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, uint64_t value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_uint64_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_string_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, const char * value, size_t value_length, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_string_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, value_length, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_wstring_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, const wchar_t * value, size_t value_length, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_wstring_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, value_length, id);
}


// DYNAMIC DATA SEQUENCES ==========================================================================
void
rosidl_dynamic_typesupport_dynamic_data_clear_sequence_data(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  (dynamic_data->serialization_support->interface->dynamic_data_clear_sequence_data)(dynamic_data->serialization_support->impl, dynamic_data->impl);
}


void
rosidl_dynamic_typesupport_dynamic_data_remove_sequence_data(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_remove_sequence_data)(dynamic_data->serialization_support->impl, dynamic_data->impl, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_sequence_data(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_sequence_data)(dynamic_data->serialization_support->impl, dynamic_data->impl, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_bool_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, bool value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_bool_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_byte_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, uint8_t value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_byte_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_char_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, char value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_char_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_wchar_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, wchar_t value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_wchar_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_float32_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, float value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_float32_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_float64_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, double value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_float64_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_float128_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, long double value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_float128_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_int8_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, int8_t value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_int8_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_uint8_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, uint8_t value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_uint8_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_int16_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, int16_t value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_int16_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_uint16_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, uint16_t value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_uint16_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_int32_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, int32_t value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_int32_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_uint32_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, uint32_t value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_uint32_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_int64_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, int64_t value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_int64_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_uint64_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, uint64_t value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_uint64_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_string_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, const char * value, size_t value_length, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_string_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, value_length, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_wstring_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, const wchar_t * value, size_t value_length, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_wstring_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value, value_length, out_id);
}


// DYNAMIC DATA NESTED =============================================================================
void
rosidl_dynamic_typesupport_dynamic_data_get_complex_value(const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, rosidl_dynamic_typesupport_dynamic_data_t ** value, rosidl_dynamic_typesupport_member_id_t id)
{
  (*value)->serialization_support = dynamic_data->serialization_support;
  (dynamic_data->serialization_support->interface->dynamic_data_get_complex_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, &(*value)->impl, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_complex_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, rosidl_dynamic_typesupport_dynamic_data_t * value, rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_complex_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value->impl, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_const_complex_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, const rosidl_dynamic_typesupport_dynamic_data_t * value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_const_complex_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value->impl, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_complex_value(rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, rosidl_dynamic_typesupport_dynamic_data_t * value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_complex_value)(dynamic_data->serialization_support->impl, dynamic_data->impl, value->impl, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_complex_value_ptr(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, rosidl_dynamic_typesupport_dynamic_data_t * value, rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_complex_value_ptr)(dynamic_data->serialization_support->impl, dynamic_data->impl, value->impl, out_id);
}
