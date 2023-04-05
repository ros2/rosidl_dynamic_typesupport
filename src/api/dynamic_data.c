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

#include <rcutils/allocator.h>
#include <rcutils/error_handling.h>
#include <rcutils/types/rcutils_ret.h>
#include <rcutils/types/uint8_array.h>
#include <rosidl_dynamic_typesupport/api/dynamic_data.h>
#include <rosidl_dynamic_typesupport/macros.h>
#include <rosidl_dynamic_typesupport/types.h>
#include <rosidl_dynamic_typesupport/uchar.h>


// =================================================================================================
// DYNAMIC DATA
// =================================================================================================

// DYNAMIC DATA UTILS ==============================================================================
rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_clear_all_values(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_clear_all_values)(
    dynamic_data->serialization_support->impl, dynamic_data->impl);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_clear_nonkey_values(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_clear_nonkey_values)(
    dynamic_data->serialization_support->impl, dynamic_data->impl);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_clear_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_clear_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, id);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_equals(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  const rosidl_dynamic_typesupport_dynamic_data_t * other,
  bool * equals)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(other, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(equals, RCUTILS_RET_INVALID_ARGUMENT);
  if (dynamic_data->serialization_support->library_identifier !=
    other->serialization_support->library_identifier)
  {
    RCUTILS_SET_ERROR_MSG("Library identifiers for dynamic datas do not match");
    return RCUTILS_RET_INVALID_ARGUMENT;
  }
  return (dynamic_data->serialization_support->methods->dynamic_data_equals)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, other->impl, equals);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_get_item_count(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  size_t * item_count)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(item_count, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_get_item_count)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, item_count);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_get_member_id_by_name(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  const char * name, size_t name_length,
  rosidl_dynamic_typesupport_member_id_t * member_id)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(name, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(member_id, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_get_member_id_by_name)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, name, name_length, member_id);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_get_member_id_at_index(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  size_t index,
  rosidl_dynamic_typesupport_member_id_t * member_id)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(member_id, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_get_member_id_at_index)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, index, member_id);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_get_array_index(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  size_t index,
  rosidl_dynamic_typesupport_member_id_t * array_index)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(array_index, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_get_array_index)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, index, array_index);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_loan_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  rosidl_dynamic_typesupport_dynamic_data_t ** loaned_dynamic_data)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(loaned_dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);

  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosidl_dynamic_typesupport_dynamic_data_t * out = allocator.zero_allocate(
    1, sizeof(rosidl_dynamic_typesupport_dynamic_data_t), &allocator.state);
  if (!out) {
    RCUTILS_SET_ERROR_MSG("Could not allocate dynamic data");
    return RCUTILS_RET_BAD_ALLOC;
  }

  out->serialization_support = dynamic_data->serialization_support;
  ROSIDL_DYNAMIC_TYPESUPPORT_CHECK_RET_FOR_NOT_OK_WITH_CLEANUP(
    (dynamic_data->serialization_support->methods->dynamic_data_loan_value)(
      dynamic_data->serialization_support->impl, dynamic_data->impl, id, &out->impl),
    allocator.deallocate(out, allocator.state)  // Cleanup
  );
  *loaned_dynamic_data = out;
  return RCUTILS_RET_OK;
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_return_loaned_value(
  rosidl_dynamic_typesupport_dynamic_data_t * outer_dynamic_data,
  rosidl_dynamic_typesupport_dynamic_data_t * inner_dynamic_data)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(outer_dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(inner_dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  if (outer_dynamic_data->serialization_support->library_identifier !=
    inner_dynamic_data->serialization_support->library_identifier)
  {
    RCUTILS_SET_ERROR_MSG("Library identifiers for dynamic datas do not match");
    return RCUTILS_RET_INVALID_ARGUMENT;
  }
  ROSIDL_DYNAMIC_TYPESUPPORT_CHECK_RET_FOR_NOT_OK(
    (outer_dynamic_data->serialization_support->methods->dynamic_data_return_loaned_value)(
      outer_dynamic_data->serialization_support->impl,
      outer_dynamic_data->impl,
      inner_dynamic_data->impl)
  );
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  allocator.deallocate(inner_dynamic_data, &allocator.state);
  return RCUTILS_RET_OK;
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_print(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_print)(
    dynamic_data->serialization_support->impl, dynamic_data->impl);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_get_name(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  const char ** name,
  size_t * name_length)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(name, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(name_length, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_get_name)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, name, name_length);
}


// DYNAMIC DATA CONSTRUCTION =======================================================================
rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_init_from_dynamic_type_builder(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder,
  rosidl_dynamic_typesupport_dynamic_data_t ** dynamic_data)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_type_builder, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);

  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosidl_dynamic_typesupport_dynamic_data_t * out = allocator.zero_allocate(
    1, sizeof(rosidl_dynamic_typesupport_dynamic_data_t), &allocator.state);
  if (!out) {
    RCUTILS_SET_ERROR_MSG("Could not allocate dynamic data");
    return RCUTILS_RET_BAD_ALLOC;
  }

  out->serialization_support = dynamic_type_builder->serialization_support;
  ROSIDL_DYNAMIC_TYPESUPPORT_CHECK_RET_FOR_NOT_OK_WITH_CLEANUP(
    (out->serialization_support->methods->dynamic_data_init_from_dynamic_type_builder)(
      out->serialization_support->impl, dynamic_type_builder->impl, &out->impl),
    allocator.deallocate(out, allocator.state)  // Cleanup
  );
  *dynamic_data = out;
  return RCUTILS_RET_OK;
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_init_from_dynamic_type(
  rosidl_dynamic_typesupport_dynamic_type_t * dynamic_type,
  rosidl_dynamic_typesupport_dynamic_data_t ** dynamic_data)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_type, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);

  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosidl_dynamic_typesupport_dynamic_data_t * out = allocator.zero_allocate(
    1, sizeof(rosidl_dynamic_typesupport_dynamic_data_t), &allocator.state);
  if (!out) {
    RCUTILS_SET_ERROR_MSG("Could not allocate dynamic data");
    return RCUTILS_RET_BAD_ALLOC;
  }

  out->serialization_support = dynamic_type->serialization_support;
  ROSIDL_DYNAMIC_TYPESUPPORT_CHECK_RET_FOR_NOT_OK_WITH_CLEANUP(
    (out->serialization_support->methods->dynamic_data_init_from_dynamic_type)(
      out->serialization_support->impl, dynamic_type->impl, &out->impl),
    allocator.deallocate(out, allocator.state)  // Cleanup
  );
  *dynamic_data = out;
  return RCUTILS_RET_OK;
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_clone(
  const rosidl_dynamic_typesupport_dynamic_data_t * other_dynamic_data,
  rosidl_dynamic_typesupport_dynamic_data_t ** dynamic_data)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(other_dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);

  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosidl_dynamic_typesupport_dynamic_data_t * out = allocator.zero_allocate(
    1, sizeof(rosidl_dynamic_typesupport_dynamic_data_t), &allocator.state);
  if (!out) {
    RCUTILS_SET_ERROR_MSG("Could not allocate dynamic data");
    return RCUTILS_RET_BAD_ALLOC;
  }

  out->serialization_support = other_dynamic_data->serialization_support;
  ROSIDL_DYNAMIC_TYPESUPPORT_CHECK_RET_FOR_NOT_OK_WITH_CLEANUP(
    (other_dynamic_data->serialization_support->methods->dynamic_data_clone)(
      other_dynamic_data->serialization_support->impl, other_dynamic_data->impl, &out->impl),
    allocator.deallocate(out, allocator.state)  // Cleanup
  );
  *dynamic_data = out;
  return RCUTILS_RET_OK;
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_destroy(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  ROSIDL_DYNAMIC_TYPESUPPORT_CHECK_RET_FOR_NOT_OK(
    (dynamic_data->serialization_support->methods->dynamic_data_destroy)(
      dynamic_data->serialization_support->impl, dynamic_data->impl)
  );
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  allocator.deallocate(dynamic_data, &allocator.state);
  return RCUTILS_RET_OK;
}


// DYNAMIC DATA SERIALIZATION ======================================================================
rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_serialize(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rcutils_uint8_array_t * buffer,
  bool * success)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(buffer, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(success, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_serialize)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, buffer, success);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_deserialize(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rcutils_uint8_array_t * buffer,
  bool * success)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(buffer, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(success, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_deserialize)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, buffer, success);
}


// DYNAMIC DATA PRIMITIVE MEMBER GETTERS ===========================================================
#define ROSIDL_DYNAMIC_DATA_GET_VALUE_FN(FunctionT, ValueT) \
  rcutils_ret_t \
  rosidl_dynamic_typesupport_dynamic_data_get_ ## FunctionT ## _value( \
    const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, \
    rosidl_dynamic_typesupport_member_id_t id, \
    ValueT * value) \
  { \
    RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT); \
    RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT); \
    return ( \
      dynamic_data->serialization_support->methods->dynamic_data_get_ ## FunctionT ## _value)( \
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


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_get_string_value(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  char ** value,
  size_t * value_length)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value_length, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_get_string_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, id, value, value_length);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_get_wstring_value(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  char16_t ** value,
  size_t * value_length)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value_length, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_get_wstring_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, id, value, value_length);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_get_fixed_string_value(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  char ** value,
  size_t * value_length,
  size_t string_length)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value_length, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_get_fixed_string_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl,
    id, value, value_length, string_length);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_get_fixed_wstring_value(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  char16_t ** value,
  size_t * value_length,
  size_t wstring_length)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value_length, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_get_fixed_wstring_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl,
    id, value, value_length, wstring_length);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_get_bounded_string_value(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  char ** value,
  size_t * value_length,
  size_t string_bound)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value_length, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_get_bounded_string_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl,
    id, value, value_length, string_bound);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_get_bounded_wstring_value(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  char16_t ** value,
  size_t * value_length,
  size_t wstring_bound)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value_length, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_get_bounded_wstring_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl,
    id, value, value_length, wstring_bound);
}


// DYNAMIC DATA PRIMITIVE MEMBER SETTERS ===========================================================
#define ROSIDL_DYNAMIC_DATA_SET_VALUE_FN(FunctionT, ValueT) \
  rcutils_ret_t \
  rosidl_dynamic_typesupport_dynamic_data_set_ ## FunctionT ## _value( \
    rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, \
    rosidl_dynamic_typesupport_member_id_t id, \
    ValueT value) \
  { \
    RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT); \
    return ( \
      dynamic_data->serialization_support->methods->dynamic_data_set_ ## FunctionT ## _value)( \
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


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_set_string_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  const char * value,
  size_t value_length)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_set_string_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, id, value, value_length);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_set_wstring_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  const char16_t * value,
  size_t value_length)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_set_wstring_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, id, value, value_length);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_set_fixed_string_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  const char * value,
  size_t value_length,
  size_t string_length)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_set_fixed_string_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl,
    id, value, value_length, string_length);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_set_fixed_wstring_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  const char16_t * value,
  size_t value_length,
  size_t wstring_length)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_set_fixed_wstring_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl,
    id, value, value_length, wstring_length);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_set_bounded_string_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  const char * value,
  size_t value_length,
  size_t string_bound)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_set_bounded_string_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl,
    id, value, value_length, string_bound);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_set_bounded_wstring_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  const char16_t * value,
  size_t value_length,
  size_t wstring_bound)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_set_bounded_wstring_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl,
    id, value, value_length, wstring_bound);
}


// DYNAMIC DATA SEQUENCES ==========================================================================
rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_clear_sequence_data(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_clear_sequence_data)(
    dynamic_data->serialization_support->impl, dynamic_data->impl);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_remove_sequence_data(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_remove_sequence_data)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, id);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_insert_sequence_data(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t * out_id)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_insert_sequence_data)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, out_id);
}


#define ROSIDL_DYNAMIC_DATA_INSERT_VALUE_FN(FunctionT, ValueT) \
  rcutils_ret_t \
  rosidl_dynamic_typesupport_dynamic_data_insert_ ## FunctionT ## _value( \
    rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data, \
    ValueT value, \
    rosidl_dynamic_typesupport_member_id_t * out_id) \
  { \
    RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT); \
    return ( \
      dynamic_data->serialization_support->methods-> \
      dynamic_data_insert_ ## FunctionT ## _value)( \
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


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_insert_string_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  const char * value,
  size_t value_length,
  rosidl_dynamic_typesupport_member_id_t * out_id)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(out_id, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_insert_string_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, value, value_length, out_id);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_insert_wstring_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  const char16_t * value,
  size_t value_length,
  rosidl_dynamic_typesupport_member_id_t * out_id)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(out_id, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_insert_wstring_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, value, value_length, out_id);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_insert_fixed_string_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  const char * value,
  size_t value_length,
  size_t string_length,
  rosidl_dynamic_typesupport_member_id_t * out_id)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(out_id, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_insert_fixed_string_value)(
    dynamic_data->serialization_support->impl,
    dynamic_data->impl,
    value,
    value_length,
    string_length,
    out_id);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_insert_fixed_wstring_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  const char16_t * value,
  size_t value_length,
  size_t wstring_length,
  rosidl_dynamic_typesupport_member_id_t * out_id)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(out_id, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_insert_fixed_wstring_value)(
    dynamic_data->serialization_support->impl,
    dynamic_data->impl,
    value,
    value_length,
    wstring_length,
    out_id);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_insert_bounded_string_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  const char * value,
  size_t value_length,
  size_t string_bound,
  rosidl_dynamic_typesupport_member_id_t * out_id)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(out_id, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_insert_bounded_string_value)(
    dynamic_data->serialization_support->impl,
    dynamic_data->impl,
    value,
    value_length,
    string_bound,
    out_id);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_insert_bounded_wstring_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  const char16_t * value,
  size_t value_length,
  size_t wstring_bound,
  rosidl_dynamic_typesupport_member_id_t * out_id)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(out_id, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_insert_bounded_wstring_value)(
    dynamic_data->serialization_support->impl,
    dynamic_data->impl,
    value,
    value_length,
    wstring_bound,
    out_id);
}


// DYNAMIC DATA NESTED =============================================================================
rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_get_complex_value(
  const rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  rosidl_dynamic_typesupport_dynamic_data_t ** value)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  (*value)->serialization_support = dynamic_data->serialization_support;
  return (dynamic_data->serialization_support->methods->dynamic_data_get_complex_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, id, &(*value)->impl);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_set_complex_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_member_id_t id,
  rosidl_dynamic_typesupport_dynamic_data_t * value)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_set_complex_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, id, value->impl);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_insert_complex_value_copy(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  const rosidl_dynamic_typesupport_dynamic_data_t * value,
  rosidl_dynamic_typesupport_member_id_t * out_id)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(out_id, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_insert_complex_value_copy)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, value->impl, out_id);
}


rcutils_ret_t
rosidl_dynamic_typesupport_dynamic_data_insert_complex_value(
  rosidl_dynamic_typesupport_dynamic_data_t * dynamic_data,
  rosidl_dynamic_typesupport_dynamic_data_t * value,
  rosidl_dynamic_typesupport_member_id_t * out_id)
{
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(dynamic_data, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(value, RCUTILS_RET_INVALID_ARGUMENT);
  RCUTILS_CHECK_ARGUMENT_FOR_NULL(out_id, RCUTILS_RET_INVALID_ARGUMENT);
  return (dynamic_data->serialization_support->methods->dynamic_data_insert_complex_value)(
    dynamic_data->serialization_support->impl, dynamic_data->impl, value->impl, out_id);
}
