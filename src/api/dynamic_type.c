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

#include <rcutils/logging_macros.h>

#include <rosidl_dynamic_typesupport/api/dynamic_type.h>
#include <rosidl_dynamic_typesupport/types.h>

#include <rosidl_runtime_c/type_description/field__functions.h>
#include <rosidl_runtime_c/type_description/field__struct.h>
#include <rosidl_runtime_c/type_description/field_type__functions.h>
#include <rosidl_runtime_c/type_description/field_type__struct.h>
#include <rosidl_runtime_c/type_description/individual_type_description__functions.h>
#include <rosidl_runtime_c/type_description/individual_type_description__struct.h>
#include <rosidl_runtime_c/type_description/type_description__functions.h>
#include <rosidl_runtime_c/type_description/type_description__struct.h>
#include <rosidl_runtime_c/type_description_utils.h>


// =================================================================================================
// DYNAMIC TYPE
// =================================================================================================

// DYNAMIC TYPE UTILS ==============================================================================
bool
rosidl_dynamic_typesupport_dynamic_type_equals(rosidl_dynamic_typesupport_dynamic_type_t * dynamic_type, rosidl_dynamic_typesupport_dynamic_type_t * other)
{
  assert(dynamic_type->serialization_support->library_identifier == other->serialization_support->library_identifier);
  return (dynamic_type->serialization_support->interface->dynamic_type_equals)(dynamic_type->serialization_support->impl, dynamic_type->impl, other->impl);
}


size_t
rosidl_dynamic_typesupport_dynamic_type_get_member_count(const rosidl_dynamic_typesupport_dynamic_type_t * dynamic_type)
{
  return (dynamic_type->serialization_support->interface->dynamic_type_get_member_count)(dynamic_type->serialization_support->impl, dynamic_type->impl);
}


// DYNAMIC TYPE CONSTRUCTION =======================================================================
rosidl_dynamic_typesupport_dynamic_type_builder_t *
rosidl_dynamic_typesupport_dynamic_type_builder_init(rosidl_dynamic_typesupport_serialization_support_t * serialization_support, const char * name, size_t name_length)
{
  rosidl_dynamic_typesupport_dynamic_type_builder_t * out = calloc(1, sizeof(rosidl_dynamic_typesupport_dynamic_type_builder_t));
  out->serialization_support = serialization_support;
  out->impl = (serialization_support->interface->dynamic_type_builder_init)(serialization_support->impl, name, name_length);
  return out;
}


rosidl_dynamic_typesupport_dynamic_type_builder_t *
rosidl_dynamic_typesupport_dynamic_type_builder_clone(const rosidl_dynamic_typesupport_dynamic_type_builder_t * other)
{
  rosidl_dynamic_typesupport_dynamic_type_builder_t * out = calloc(1, sizeof(rosidl_dynamic_typesupport_dynamic_type_builder_t));
  out->serialization_support = other->serialization_support;
  out->impl = (other->serialization_support->interface->dynamic_type_builder_clone)(other->serialization_support->impl, other->impl);
  return out;
}


rosidl_dynamic_typesupport_dynamic_type_builder_t *
rosidl_dynamic_typesupport_dynamic_type_builder_init_from_description(rosidl_dynamic_typesupport_serialization_support_t * serialization_support, const rosidl_runtime_c__type_description__TypeDescription * description)
{
  rosidl_dynamic_typesupport_dynamic_type_builder_t * out;

  // Short-circuit if the serialization support library has its own implementation
  if (serialization_support->interface->dynamic_type_builder_init_from_description) {
    out = calloc(1, sizeof(rosidl_dynamic_typesupport_dynamic_type_builder_t));
    out->serialization_support = serialization_support;
    out->impl = (serialization_support->interface->dynamic_type_builder_init_from_description)(serialization_support->impl, description);
    return out;
  }

  const rosidl_runtime_c__type_description__IndividualTypeDescription * main_description =
    &description->type_description;
  out = rosidl_dynamic_typesupport_dynamic_type_builder_init(
    serialization_support, main_description->type_name.data, main_description->type_name.size);

  for (size_t i = 0; i < main_description->fields.size; i++) {
    rosidl_runtime_c__type_description__Field * field = &main_description->fields.data[i];

    switch (field->type.type_id) {
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_NOT_SET:
        RCUTILS_LOG_ERROR("Field type_impl not set for field [%s]", field->name.data);
        rosidl_dynamic_typesupport_dynamic_type_builder_fini(out);
        return NULL;
        break;

      // PRIMITIVES
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_BOOLEAN:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_bool_member(out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_BYTE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_byte_member(out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_CHAR:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_char_member(out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_FLOAT32:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_float32_member(out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_FLOAT64:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_float64_member(out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_INT8:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_int8_member(out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_UINT8:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_uint8_member(out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_INT16:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_int16_member(out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_UINT16:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_uint16_member(out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_INT32:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_int32_member(out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_UINT32:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_uint32_member(out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_INT64:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_int64_member(out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_UINT64:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_uint64_member(out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_STRING:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_string_member(out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_WSTRING:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_wstring_member(out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_BOUNDED_STRING:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_string_member(
          out, i, field->name.data, field->name.size,
          field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_BOUNDED_WSTRING:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_wstring_member(
          out, i, field->name.data, field->name.size,
          field->type.capacity);
        break;

      // STATIC ARRAYS
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_BOOLEAN_ARRAY:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_bool_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_BYTE_ARRAY:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_byte_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_CHAR_ARRAY:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_char_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_FLOAT32_ARRAY:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_float32_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_FLOAT64_ARRAY:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_float64_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_INT8_ARRAY:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_int8_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_UINT8_ARRAY:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_uint8_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_INT16_ARRAY:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_int16_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_UINT16_ARRAY:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_uint16_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_INT32_ARRAY:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_int32_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_UINT32_ARRAY:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_uint32_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_INT64_ARRAY:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_int64_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_UINT64_ARRAY:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_uint64_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_STRING_ARRAY:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_string_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_WSTRING_ARRAY:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_wstring_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_BOUNDED_STRING_ARRAY:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_string_array_member(
          out, i, field->name.data, field->name.size,
          field->type.string_capacity, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_BOUNDED_WSTRING_ARRAY:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_wstring_array_member(
          out, i, field->name.data, field->name.size,
          field->type.string_capacity, field->type.capacity);
        break;

      // UNBOUNDED SEQUENCES
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_BOOLEAN_UNBOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_bool_unbounded_sequence_member(
          out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_BYTE_UNBOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_byte_unbounded_sequence_member(
          out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_CHAR_UNBOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_char_unbounded_sequence_member(
          out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_FLOAT32_UNBOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_float32_unbounded_sequence_member(
          out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_FLOAT64_UNBOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_float64_unbounded_sequence_member(
          out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_INT8_UNBOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_int8_unbounded_sequence_member(
          out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_UINT8_UNBOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_uint8_unbounded_sequence_member(
          out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_INT16_UNBOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_int16_unbounded_sequence_member(
          out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_UINT16_UNBOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_uint16_unbounded_sequence_member(
          out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_INT32_UNBOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_int32_unbounded_sequence_member(
          out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_UINT32_UNBOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_uint32_unbounded_sequence_member(
          out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_INT64_UNBOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_int64_unbounded_sequence_member(
          out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_UINT64_UNBOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_uint64_unbounded_sequence_member(
          out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_STRING_UNBOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_string_unbounded_sequence_member(
          out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_WSTRING_UNBOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_wstring_unbounded_sequence_member(
          out, i, field->name.data, field->name.size);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_BOUNDED_STRING_UNBOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_string_unbounded_sequence_member(
          out, i, field->name.data, field->name.size, field->type.string_capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_BOUNDED_WSTRING_UNBOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_wstring_unbounded_sequence_member(
          out, i, field->name.data, field->name.size, field->type.string_capacity);
        break;

      // BOUNDED SEQUENCES
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_BOOLEAN_BOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_bool_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_BYTE_BOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_byte_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_CHAR_BOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_char_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_FLOAT32_BOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_float32_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_FLOAT64_BOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_float64_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_INT8_BOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_int8_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_UINT8_BOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_uint8_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_INT16_BOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_int16_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_UINT16_BOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_uint16_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_INT32_BOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_int32_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_UINT32_BOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_uint32_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_INT64_BOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_int64_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_UINT64_BOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_uint64_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_STRING_BOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_string_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_WSTRING_BOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_wstring_array_member(
          out, i, field->name.data, field->name.size, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_BOUNDED_STRING_BOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_string_array_member(
          out, i, field->name.data, field->name.size,
          field->type.string_capacity, field->type.capacity);
        break;
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_BOUNDED_WSTRING_BOUNDED_SEQUENCE:
        rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_wstring_array_member(
          out, i, field->name.data, field->name.size,
          field->type.string_capacity, field->type.capacity);
        break;

      // NESTED
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_NESTED_TYPE:
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_NESTED_TYPE_ARRAY:
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE:
      case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE:
        {
          if (field->type.nested_type_name.data == NULL) {
            RCUTILS_LOG_ERROR(
              "Nested type_impl name is missing in description for field [%s]", field->name.data);
            rosidl_dynamic_typesupport_dynamic_type_builder_fini(out);
            return NULL;
          }

          // Create a new type description to pass to the next layer
          rosidl_runtime_c__type_description__TypeDescription * recurse_desc = NULL;
          rosidl_runtime_c__type_description__IndividualTypeDescription * recurse_indiv_desc = NULL;

          // NOTE(methylDragon): recurse_indiv_desc borrows from
          //                     description->referenced_type_descriptions.
          //                     It is NOT a copy!!
          rosidl_runtime_c_type_description_utils_find_referenced_type_description(
            &description->referenced_type_descriptions,
            field->type.nested_type_name.data,
            &recurse_indiv_desc);
          if (recurse_indiv_desc == NULL) {
            rosidl_dynamic_typesupport_dynamic_type_builder_fini(out);
            return NULL;
          }

          rosidl_runtime_c_type_description_utils_get_referenced_type_description_as_type_description(  // NOLINT
            &description->referenced_type_descriptions,
            recurse_indiv_desc,
            &recurse_desc,
            true);  // Coerce to valid
          if (recurse_desc == NULL) {
            rosidl_runtime_c__type_description__IndividualTypeDescription__destroy(
              recurse_indiv_desc);
            rosidl_dynamic_typesupport_dynamic_type_builder_fini(out);
            return NULL;
          }

          // Recurse
          rosidl_dynamic_typesupport_dynamic_type_t * nested_type =
            rosidl_dynamic_typesupport_dynamic_type_init_from_description(
              serialization_support, recurse_desc);
          rosidl_runtime_c__type_description__TypeDescription__destroy(recurse_desc);

          if (nested_type == NULL) {
            RCUTILS_LOG_ERROR(
              "Could not construct nested type_impl for field [%s]", field->name.data);
            rosidl_runtime_c__type_description__IndividualTypeDescription__destroy(
              recurse_indiv_desc);
            rosidl_runtime_c__type_description__TypeDescription__destroy(recurse_desc);
            rosidl_dynamic_typesupport_dynamic_type_builder_fini(out);
            return NULL;
          }

          switch (field->type.type_id) {
            case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_NESTED_TYPE:
              rosidl_dynamic_typesupport_dynamic_type_builder_add_complex_member(
                out, i, field->name.data, field->name.size, nested_type);
              break;

            case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_NESTED_TYPE_ARRAY:
              rosidl_dynamic_typesupport_dynamic_type_builder_add_complex_array_member(
                out, i, field->name.data, field->name.size, nested_type, field->type.capacity);
              break;

            case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE:
              rosidl_dynamic_typesupport_dynamic_type_builder_add_complex_unbounded_sequence_member(
                out, i, field->name.data, field->name.size, nested_type);
              break;

            case ROSIDL_DYNAMIC_TYPESUPPORT_FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE:
              rosidl_dynamic_typesupport_dynamic_type_builder_add_complex_bounded_sequence_member(
                out, i, field->name.data, field->name.size, nested_type, field->type.capacity);
              break;
          }
        }
        break;

      default:
        RCUTILS_LOG_ERROR("Invalid field type_impl: %d !", field->type.type_id);
        break;
    }
  }

  return out;
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_fini(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder)
{
  if (!dynamic_type_builder) {
    return;
  }
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_fini)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl);
  free(dynamic_type_builder);
}


rosidl_dynamic_typesupport_dynamic_type_t *
rosidl_dynamic_typesupport_dynamic_type_init_from_dynamic_type_builder(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder)
{
  rosidl_dynamic_typesupport_dynamic_type_t * out = calloc(1, sizeof(rosidl_dynamic_typesupport_dynamic_type_t));
  out->serialization_support = dynamic_type_builder->serialization_support;
  out->impl = (dynamic_type_builder->serialization_support->interface->dynamic_type_init_from_dynamic_type_builder)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl);
  return out;
}


rosidl_dynamic_typesupport_dynamic_type_t *
rosidl_dynamic_typesupport_dynamic_type_init_from_description(rosidl_dynamic_typesupport_serialization_support_t * serialization_support, const rosidl_runtime_c__type_description__TypeDescription * description)
{
  rosidl_dynamic_typesupport_dynamic_type_t * out;

  // Short-circuit if the serialization support library has its own implementation
  if (serialization_support->interface->dynamic_type_init_from_description) {
    out = calloc(1, sizeof(rosidl_dynamic_typesupport_dynamic_type_t));
    out->serialization_support = serialization_support;
    out->impl = (serialization_support->interface->dynamic_type_init_from_description)(serialization_support->impl, description);
    return out;
  }

  rosidl_dynamic_typesupport_dynamic_type_builder_t * builder =
    rosidl_dynamic_typesupport_dynamic_type_builder_init_from_description(
      serialization_support, description);

  out = rosidl_dynamic_typesupport_dynamic_type_init_from_dynamic_type_builder(builder);
  rosidl_dynamic_typesupport_dynamic_type_builder_fini(builder);

  return out;
}


rosidl_dynamic_typesupport_dynamic_type_t *
rosidl_dynamic_typesupport_dynamic_type_clone(const rosidl_dynamic_typesupport_dynamic_type_t * other)
{
  rosidl_dynamic_typesupport_dynamic_type_t * out = calloc(1, sizeof(rosidl_dynamic_typesupport_dynamic_type_t));
  out->serialization_support = other->serialization_support;
  out->impl = (other->serialization_support->interface->dynamic_type_clone)(other->serialization_support->impl, other->impl);
  return out;
}


void
rosidl_dynamic_typesupport_dynamic_type_fini(rosidl_dynamic_typesupport_dynamic_type_t * dynamic_type)
{
  if (!dynamic_type) {
    return;
  }
  (dynamic_type->serialization_support->interface->dynamic_type_fini)(dynamic_type->serialization_support->impl, dynamic_type->impl);
  free(dynamic_type);
}


char *
rosidl_dynamic_typesupport_dynamic_type_get_name(const rosidl_dynamic_typesupport_dynamic_type_t * dynamic_type)
{
  return (dynamic_type->serialization_support->interface->dynamic_type_get_name)(dynamic_type->serialization_support->impl, dynamic_type->impl);
}


char *
rosidl_dynamic_typesupport_dynamic_type_builder_get_name(const rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder)
{
  return (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_get_name)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_set_name(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_set_name)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, name, name_length);
}


// DYNAMIC TYPE PRIMITIVE MEMBERS ==================================================================
void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bool_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_bool_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_byte_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_byte_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_char_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_char_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_wchar_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_wchar_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float32_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_float32_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float64_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_float64_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float128_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_float128_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int8_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_int8_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint8_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_uint8_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int16_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_int16_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint16_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_uint16_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int32_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_int32_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint32_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_uint32_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int64_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_int64_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint64_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_uint64_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_string_member(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_string_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_wstring_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder,
  rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_wstring_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_string_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder,
  rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t string_sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_bounded_string_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, string_sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_wstring_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder,
  rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t wstring_sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_bounded_wstring_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, wstring_sequence_bound);
}


// DYNAMIC TYPE STATIC ARRAY MEMBERS ===============================================================
void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bool_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_bool_array_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_byte_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_byte_array_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_char_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_char_array_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_wchar_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_wchar_array_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float32_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_float32_array_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float64_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_float64_array_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float128_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_float128_array_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int8_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_int8_array_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint8_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_uint8_array_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int16_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_int16_array_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint16_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_uint16_array_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int32_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_int32_array_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint32_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_uint32_array_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int64_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_int64_array_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint64_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_uint64_array_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_string_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_string_array_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_wstring_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_wstring_array_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_string_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length,
  size_t string_bound, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_bounded_string_array_member)(
    dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, string_bound, array_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_wstring_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length,
  size_t wstring_bound, size_t array_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_bounded_wstring_array_member)(
    dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, wstring_bound, array_length);
}


// DYNAMIC TYPE UNBOUNDED SEQUENCE MEMBERS =========================================================
void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bool_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_bool_unbounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_byte_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_byte_unbounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_char_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_char_unbounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_wchar_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_wchar_unbounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float32_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_float32_unbounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float64_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_float64_unbounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float128_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_float128_unbounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int8_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_int8_unbounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint8_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_uint8_unbounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int16_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_int16_unbounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint16_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_uint16_unbounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int32_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_int32_unbounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint32_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_uint32_unbounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int64_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_int64_unbounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint64_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_uint64_unbounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_string_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_string_unbounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_wstring_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_wstring_unbounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_string_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t string_sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_bounded_string_unbounded_sequence_member)(
    dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, string_sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_wstring_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t wstring_sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_bounded_wstring_unbounded_sequence_member)(
    dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, wstring_sequence_bound);
}


// DYNAMIC TYPE BOUNDED SEQUENCE MEMBERS ===========================================================
void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bool_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_bool_bounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_byte_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_byte_bounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_char_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_char_bounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_wchar_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_wchar_bounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float32_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_float32_bounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float64_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_float64_bounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_float128_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_float128_bounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int8_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_int8_bounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint8_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_uint8_bounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int16_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_int16_bounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint16_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_uint16_bounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int32_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_int32_bounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint32_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_uint32_bounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_int64_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_int64_bounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_uint64_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_uint64_bounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_string_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_string_bounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_wstring_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_wstring_bounded_sequence_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_string_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length,
  size_t string_bound, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_bounded_string_bounded_sequence_member)(
    dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, string_bound, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_bounded_wstring_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length,
  size_t wstring_bound, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_bounded_wstring_bounded_sequence_member)(
    dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, wstring_bound, sequence_bound);
}


// DYNAMIC TYPE NESTED MEMBERS =====================================================================
void
rosidl_dynamic_typesupport_dynamic_type_builder_add_complex_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder,
  rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, rosidl_dynamic_typesupport_dynamic_type_t * nested_struct)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_complex_member)(dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, nested_struct->impl);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_complex_array_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length,
  rosidl_dynamic_typesupport_dynamic_type_t * nested_struct, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_complex_array_member)(
    dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, nested_struct->impl, sequence_bound);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_complex_unbounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, rosidl_dynamic_typesupport_dynamic_type_t * nested_struct)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_complex_unbounded_sequence_member)(
    dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, nested_struct->impl);
}


void
rosidl_dynamic_typesupport_dynamic_type_builder_add_complex_bounded_sequence_member(
  rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length,
  rosidl_dynamic_typesupport_dynamic_type_t * nested_struct, size_t sequence_bound)
{
  (dynamic_type_builder->serialization_support->interface->dynamic_type_builder_add_complex_bounded_sequence_member)(
    dynamic_type_builder->serialization_support->impl, dynamic_type_builder->impl, id, name, name_length, nested_struct->impl, sequence_bound);
}
