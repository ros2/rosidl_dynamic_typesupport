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
#include <rosidl_dynamic_typesupport/api/dynamic_type.h>
#include <rosidl_dynamic_typesupport/types.h>

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

void
rosidl_dynamic_typesupport_dynamic_type_builder_fini(rosidl_dynamic_typesupport_dynamic_type_builder_t * dynamic_type_builder)
{
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
rosidl_dynamic_typesupport_dynamic_type_init_from_description(rosidl_dynamic_typesupport_serialization_support_t * serialization_support, type_description_t * description)
{
  rosidl_dynamic_typesupport_dynamic_type_t * out = calloc(1, sizeof(rosidl_dynamic_typesupport_dynamic_type_t));
  out->serialization_support = serialization_support;
  out->impl = (serialization_support->interface->dynamic_type_init_from_description)(serialization_support->impl, description);
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
