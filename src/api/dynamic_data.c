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
#include <uchar.h>
#include <rcutils/allocator.h>
#include <rcutils/types/uint8_array.h>
#include <rosidl_dynamic_typesupport/api/dynamic_data.h>
#include <rosidl_dynamic_typesupport/types.h>


// =================================================================================================
// DYNAMIC DATA
// =================================================================================================

// DYNAMIC DATA UTILS ==============================================================================
void
rosidl_dynamic_typesupport_dynamic_data_clear_all_values(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  (dynamic_data->serialization_support->interface->dynamic_data_clear_all_values)(
    dynamic_data->serialization_support->impl, dynamic_data->impl);
}


void
rosidl_dynamic_typesupport_dynamic_data_clear_nonkey_values(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  (dynamic_data->serialization_support->interface->dynamic_data_clear_nonkey_values)(
    dynamic_data->serialization_support->impl, dynamic_data->impl);
}


void
rosidl_dynamic_typesupport_dynamic_data_clear_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_clear_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, id);
}


bool
rosidl_dynamic_typesupport_dynamic_data_equals(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  const rosidl_dynamic_typesupport_dynamic_data_t * other)
{
  assert(
    dynamic_data->serialization_support->library_identifier ==
    other->serialization_support->library_identifier);
  return (dynamic_data->serialization_support->interface->dynamic_data_equals)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, other->impl);
}


size_t
rosidl_dynamic_typesupport_dynamic_data_get_item_count(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  return (dynamic_data->serialization_support->interface->dynamic_data_get_item_count)(
    dynamic_data->serialization_support->impl, dynamic_data->impl);
}


rosidl_dynamic_typesupport_member_id_t
rosidl_dynamic_typesupport_dynamic_data_get_member_id_by_name(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, const char * name,
  size_t name_length)
{
  return (dynamic_data->serialization_support->interface->dynamic_data_get_member_id_by_name)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, name, name_length);
}


rosidl_dynamic_typesupport_member_id_t
rosidl_dynamic_typesupport_dynamic_data_get_member_id_at_index(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, size_t index)
{
  return (dynamic_data->serialization_support->interface->dynamic_data_get_member_id_at_index)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, index);
}


rosidl_dynamic_typesupport_member_id_t
rosidl_dynamic_typesupport_dynamic_data_get_array_index(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, size_t index)
{
  return (dynamic_data->serialization_support->interface->dynamic_data_get_array_index)(
    dynamic_data
    ->serialization_support->impl, dynamic_data->impl, index);
}


rosidl_dynamic_typesupport_dynamic_data_t *
rosidl_dynamic_typesupport_dynamic_data_loan_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosidl_dynamic_typesupport_dynamic_data_t * out =
    allocator.zero_allocate(1, sizeof(rosidl_dynamic_typesupport_dynamic_data_t), &allocator.state);
  out->serialization_support = dynamic_data->serialization_support;
  out->impl = (dynamic_data->serialization_support->interface->dynamic_data_loan_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, id);
  return out;
}


void
rosidl_dynamic_typesupport_dynamic_data_return_loaned_value(
  rosidl_dynamic_typesupport_dynamic_data_t * outer_dynamic_data,
  rosidl_dynamic_typesupport_dynamic_data_t * inner_dynamic_data)
{
  assert(
    outer_dynamic_data->serialization_support->library_identifier ==
    inner_dynamic_data->serialization_support->library_identifier);
  (outer_dynamic_data->serialization_support->interface->dynamic_data_return_loaned_value)(
    outer_dynamic_data->serialization_support->impl,
    outer_dynamic_data->impl,
    inner_dynamic_data->impl);
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  allocator.deallocate(inner_dynamic_data, &allocator.state);
}


void
rosidl_dynamic_typesupport_dynamic_data_print(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  (dynamic_data->serialization_support->interface->dynamic_data_print)(
    dynamic_data->serialization_support->impl, dynamic_data->impl);
}


const char *
rosidl_dynamic_typesupport_dynamic_data_get_name(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, size_t * name_length)
{
  return (dynamic_data->serialization_support->interface->dynamic_data_get_name)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, name_length);
}


// DYNAMIC DATA CONSTRUCTION =======================================================================
rosidl_dynamic_typesupport_dynamic_data_t *
rosidl_dynamic_typesupport_dynamic_data_init_from_dynamic_type_builder(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosidl_dynamic_typesupport_dynamic_data_t * out =
    allocator.zero_allocate(1, sizeof(rosidl_dynamic_typesupport_dynamic_data_t), &allocator.state);
  out->serialization_support = dynamic_type_builder->serialization_support;
  out->impl = (out->serialization_support->interface->dynamic_data_init_from_dynamic_type_builder)(
    out->serialization_support->impl, dynamic_type_builder->impl);
  return out;
}


rosidl_dynamic_typesupport_dynamic_data_t *
rosidl_dynamic_typesupport_dynamic_data_init_from_dynamic_type(
  rosidl_dynamic_typesupport_dynamic_type_t * dynamic_type)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosidl_dynamic_typesupport_dynamic_data_t * out =
    allocator.zero_allocate(1, sizeof(rosidl_dynamic_typesupport_dynamic_data_t), &allocator.state);
  out->serialization_support = dynamic_type->serialization_support;
  out->impl = (out->serialization_support->interface->dynamic_data_init_from_dynamic_type)(
    out->serialization_support->impl, dynamic_type->impl);
  return out;
}


rosidl_dynamic_typesupport_dynamic_data_t *
rosidl_dynamic_typesupport_dynamic_data_clone(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosidl_dynamic_typesupport_dynamic_data_t * out =
    allocator.zero_allocate(1, sizeof(rosidl_dynamic_typesupport_dynamic_data_t), &allocator.state);
  out->serialization_support = dynamic_data->serialization_support;
  out->impl = (dynamic_data->serialization_support->interface->dynamic_data_clone)(
    dynamic_data->serialization_support->impl, dynamic_data->impl);
  return out;
}


void
rosidl_dynamic_typesupport_dynamic_data_fini(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  if (!dynamic_data) {
    return;
  }
  (dynamic_data->serialization_support->interface->dynamic_data_fini)(
    dynamic_data->serialization_support->impl, dynamic_data->impl);
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  allocator.deallocate(dynamic_data->impl, &allocator.state);
}


// DYNAMIC DATA SERIALIZATION ======================================================================
bool
rosidl_dynamic_typesupport_dynamic_data_serialize(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, rcutils_uint8_array_t * buffer)
{
  return (dynamic_data->serialization_support->interface->dynamic_data_serialize)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, buffer);
}


bool
rosidl_dynamic_typesupport_dynamic_data_deserialize(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, rcutils_uint8_array_t * buffer)
{
  return (dynamic_data->serialization_support->interface->dynamic_data_deserialize)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, buffer);
}


// DYNAMIC DATA PRIMITIVE MEMBER GETTERS ===========================================================
#define ROSIDL_DYNAMIC_DATA_GET_VALUE_FN(FunctionT, ValueT) \
  void \
  rosidl_dynamic_typesupport_dynamic_data_get_ ## FunctionT ## _value( \
    const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, \
    rosidl_dynamic_typesupport_member_id_t id, \
    ValueT * value) \
  { \
    (dynamic_data->serialization_support->interface->dynamic_data_get_ ## FunctionT ## _value)( \
      dynamic_data->serialization_support->impl, dynamic_data->impl, id, value); \
  }


ROSIDL_DYNAMIC_DATA_GET_VALUE_FN(bool, bool)
ROSIDL_DYNAMIC_DATA_GET_VALUE_FN(byte, uint8_t)
ROSIDL_DYNAMIC_DATA_GET_VALUE_FN(char, char)
ROSIDL_DYNAMIC_DATA_GET_VALUE_FN(wchar, char16_t)
ROSIDL_DYNAMIC_DATA_GET_VALUE_FN(float32, float)
ROSIDL_DYNAMIC_DATA_GET_VALUE_FN(float64, double)
ROSIDL_DYNAMIC_DATA_GET_VALUE_FN(float128, long double)
ROSIDL_DYNAMIC_DATA_GET_VALUE_FN(int8, int8_t)
ROSIDL_DYNAMIC_DATA_GET_VALUE_FN(uint8, uint8_t)
ROSIDL_DYNAMIC_DATA_GET_VALUE_FN(int16, int16_t)
ROSIDL_DYNAMIC_DATA_GET_VALUE_FN(uint16, uint16_t)
ROSIDL_DYNAMIC_DATA_GET_VALUE_FN(int32, int32_t)
ROSIDL_DYNAMIC_DATA_GET_VALUE_FN(uint32, uint32_t)
ROSIDL_DYNAMIC_DATA_GET_VALUE_FN(int64, int64_t)
ROSIDL_DYNAMIC_DATA_GET_VALUE_FN(uint64, uint64_t)
#undef ROSIDL_DYNAMIC_DATA_GET_VALUE_FN


void
rosidl_dynamic_typesupport_dynamic_data_get_string_value(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  char ** value,
  size_t * value_length)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_string_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, id, value, value_length);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_wstring_value(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  char16_t ** value,
  size_t * value_length)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_wstring_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, id, value, value_length);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_bounded_string_value(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  char ** value,
  size_t * value_length,
  size_t string_bound)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_bounded_string_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl,
    id, value, value_length, string_bound);
}


void
rosidl_dynamic_typesupport_dynamic_data_get_bounded_wstring_value(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  char16_t ** value,
  size_t * value_length,
  size_t wstring_bound)
{
  (dynamic_data->serialization_support->interface->dynamic_data_get_bounded_wstring_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl,
    id, value, value_length, wstring_bound);
}


// DYNAMIC DATA PRIMITIVE MEMBER SETTERS ===========================================================
#define ROSIDL_DYNAMIC_DATA_SET_VALUE_FN(FunctionT, ValueT) \
  void \
  rosidl_dynamic_typesupport_dynamic_data_set_ ## FunctionT ## _value( \
    rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, \
    rosidl_dynamic_typesupport_member_id_t id, \
    ValueT value) \
  { \
    (dynamic_data->serialization_support->interface->dynamic_data_set_ ## FunctionT ## _value)( \
      dynamic_data->serialization_support->impl, dynamic_data->impl, id, value); \
  }


ROSIDL_DYNAMIC_DATA_SET_VALUE_FN(bool, bool)
ROSIDL_DYNAMIC_DATA_SET_VALUE_FN(byte, uint8_t)
ROSIDL_DYNAMIC_DATA_SET_VALUE_FN(char, char)
ROSIDL_DYNAMIC_DATA_SET_VALUE_FN(wchar, char16_t)
ROSIDL_DYNAMIC_DATA_SET_VALUE_FN(float32, float)
ROSIDL_DYNAMIC_DATA_SET_VALUE_FN(float64, double)
ROSIDL_DYNAMIC_DATA_SET_VALUE_FN(float128, long double)
ROSIDL_DYNAMIC_DATA_SET_VALUE_FN(int8, int8_t)
ROSIDL_DYNAMIC_DATA_SET_VALUE_FN(uint8, uint8_t)
ROSIDL_DYNAMIC_DATA_SET_VALUE_FN(int16, int16_t)
ROSIDL_DYNAMIC_DATA_SET_VALUE_FN(uint16, uint16_t)
ROSIDL_DYNAMIC_DATA_SET_VALUE_FN(int32, int32_t)
ROSIDL_DYNAMIC_DATA_SET_VALUE_FN(uint32, uint32_t)
ROSIDL_DYNAMIC_DATA_SET_VALUE_FN(int64, int64_t)
ROSIDL_DYNAMIC_DATA_SET_VALUE_FN(uint64, uint64_t)
#undef ROSIDL_DYNAMIC_DATA_SET_VALUE_FN


void
rosidl_dynamic_typesupport_dynamic_data_set_string_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  const char * value,
  size_t value_length)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_string_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, id, value, value_length);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_wstring_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  const char16_t * value,
  size_t value_length)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_wstring_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, id, value, value_length);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_bounded_string_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  const char * value,
  size_t value_length,
  size_t string_bound)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_bounded_string_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl,
    id, value, value_length, string_bound);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_bounded_wstring_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  const char16_t * value,
  size_t value_length,
  size_t wstring_bound)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_bounded_wstring_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl,
    id, value, value_length, wstring_bound);
}


// DYNAMIC DATA SEQUENCES ==========================================================================
void
rosidl_dynamic_typesupport_dynamic_data_clear_sequence_data(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  (dynamic_data->serialization_support->interface->dynamic_data_clear_sequence_data)(
    dynamic_data->serialization_support->impl, dynamic_data->impl);
}


void
rosidl_dynamic_typesupport_dynamic_data_remove_sequence_data(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_remove_sequence_data)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_sequence_data(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_sequence_data)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, out_id);
}


#define ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN(FunctionT, ValueT) \
  void \
  rosidl_dynamic_typesupport_dynamic_data_insert_ ## FunctionT ## _value( \
    rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, \
    ValueT value, \
    rosidl_dynamic_typesupport_member_id_t * out_id) \
  { \
    (dynamic_data->serialization_support->interface->dynamic_data_insert_ ## FunctionT ## _value)( \
      dynamic_data->serialization_support->impl, dynamic_data->impl, value, out_id); \
  }


ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN(bool, bool)
ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN(byte, uint8_t)
ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN(char, char)
ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN(wchar, char16_t)
ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN(float32, float)
ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN(float64, double)
ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN(float128, long double)
ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN(int8, int8_t)
ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN(uint8, uint8_t)
ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN(int16, int16_t)
ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN(uint16, uint16_t)
ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN(int32, int32_t)
ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN(uint32, uint32_t)
ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN(int64, int64_t)
ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN(uint64, uint64_t)
#undef ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN


void
rosidl_dynamic_typesupport_dynamic_data_insert_string_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  const char * value,
  size_t value_length,
  rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_string_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, value, value_length, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_wstring_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  const char16_t * value,
  size_t value_length,
  rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_wstring_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, value, value_length, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_bounded_string_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  const char * value,
  size_t value_length,
  size_t string_bound,
  rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_bounded_string_value)(
    dynamic_data->serialization_support->impl,
    dynamic_data->impl,
    value,
    value_length,
    string_bound,
    out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_bounded_wstring_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  const char16_t * value,
  size_t value_length,
  size_t wstring_bound,
  rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_bounded_wstring_value)(
    dynamic_data->serialization_support->impl,
    dynamic_data->impl,
    value,
    value_length,
    wstring_bound,
    out_id);
}


// DYNAMIC DATA NESTED =============================================================================
void
rosidl_dynamic_typesupport_dynamic_data_get_complex_value(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  rosidl_dynamic_typesupport_dynamic_data_t ** value)
{
  (*value)->serialization_support = dynamic_data->serialization_support;
  (dynamic_data->serialization_support->interface->dynamic_data_get_complex_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, id, &(*value)->impl);
}


void
rosidl_dynamic_typesupport_dynamic_data_set_complex_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  rosidl_dynamic_typesupport_dynamic_data_t * value)
{
  (dynamic_data->serialization_support->interface->dynamic_data_set_complex_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, id, value->impl);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_complex_value_copy(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  const rosidl_dynamic_typesupport_dynamic_data_t * value,
  rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_complex_value_copy)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, value->impl, out_id);
}


void
rosidl_dynamic_typesupport_dynamic_data_insert_complex_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_dynamic_data_t * value,
  rosidl_dynamic_typesupport_member_id_t * out_id)
{
  (dynamic_data->serialization_support->interface->dynamic_data_insert_complex_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, value->impl, out_id);
}
