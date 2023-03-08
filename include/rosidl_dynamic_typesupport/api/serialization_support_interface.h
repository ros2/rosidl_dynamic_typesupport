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

#ifndef ROSIDL_DYNAMIC_TYPESUPPORT__API__SERIALIZATION_INTERFACE_H_
#define ROSIDL_DYNAMIC_TYPESUPPORT__API__SERIALIZATION_INTERFACE_H_

#include <stddef.h>
#include <stdint.h>
#include <wchar.h>

#include <rosidl_dynamic_typesupport/types.h>

#ifdef __cplusplus
extern "C" {
#endif


/// This interface must be adopted by all downstream serialization library implementations

// =================================================================================================
// Interface
// =================================================================================================
struct rosidl_dynamic_typesupport_serialization_support_interface_s
{
  /// Interfaces mimicking the XTypes spec (Section 7.5: Language Binding)
  /// https://www.omg.org/spec/DDS-XTypes/1.1/PDF
  ///
  /// Luckily for us, FastRTPS mimics the spec quite well

  /* TODOS??? (though these are just bonuses...)
   * DynamicType::get_type_descriptor / DynamicType::get_descriptor (and the TypeDescriptor class)
   *
   */

  // NOTE(methylDragon): I'm not sure when to return a value vs use an out-param...
  //
  //                     Also I'm pretty sure I should be using return codes, but I don't know if I
  //                     should be using ROS flavored ones?

  // CORE
  const char * library_identifier;
  void (* serialization_support_impl_handle_fini)(rosidl_dynamic_typesupport_serialization_support_impl_t * impl);


  // ===============================================================================================
  // DYNAMIC TYPE
  // ===============================================================================================

  // DYNAMIC TYPE UTILS
  bool (* dynamic_type_equals)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_type_impl_t * type, const rosidl_dynamic_typesupport_dynamic_type_impl_t * other);
  size_t (* dynamic_type_get_member_count)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_type_impl_t * dynamic_type);  // "member" from XTypes spec


  // DYNAMIC TYPE CONSTRUCTION
  rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * (* dynamic_type_builder_init)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const char * name, size_t name_length);
  rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * (* dynamic_type_builder_clone)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * other);

  void (* dynamic_type_builder_fini)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder);

  rosidl_dynamic_typesupport_dynamic_type_impl_t * (* dynamic_type_init_from_dynamic_type_builder)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder);
  rosidl_dynamic_typesupport_dynamic_type_impl_t * (* dynamic_type_init_from_description)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, type_description_t * description);
  rosidl_dynamic_typesupport_dynamic_type_impl_t * (* dynamic_type_clone)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_type_impl_t * other);
  void (* dynamic_type_fini)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_impl_t * type);

  char * (* dynamic_type_get_name)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_type_impl_t * dynamic_type);
  char * (* dynamic_type_builder_get_name)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder);
  void (* dynamic_type_builder_set_name)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, const char * name, size_t name_length);


  // DYNAMIC TYPE PRIMITIVE MEMBERS
  void (* dynamic_type_builder_add_bool_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_byte_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_char_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_wchar_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_float32_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_float64_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_float128_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_int8_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_uint8_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_int16_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_uint16_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_int32_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_uint32_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_int64_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_uint64_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_string_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_wstring_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  // void (* dynamic_type_builder_add_fixed_string_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  // void (* dynamic_type_builder_add_fixed_wstring_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_bounded_string_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t string_bound);
  void (* dynamic_type_builder_add_bounded_wstring_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t wstring_bound);


  // DYNAMIC TYPE STATIC ARRAY MEMBERS
  void (* dynamic_type_builder_add_bool_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  void (* dynamic_type_builder_add_byte_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  void (* dynamic_type_builder_add_char_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  void (* dynamic_type_builder_add_wchar_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  void (* dynamic_type_builder_add_float32_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  void (* dynamic_type_builder_add_float64_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  void (* dynamic_type_builder_add_float128_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  void (* dynamic_type_builder_add_int8_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  void (* dynamic_type_builder_add_uint8_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  void (* dynamic_type_builder_add_int16_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  void (* dynamic_type_builder_add_uint16_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  void (* dynamic_type_builder_add_int32_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  void (* dynamic_type_builder_add_uint32_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  void (* dynamic_type_builder_add_int64_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  void (* dynamic_type_builder_add_uint64_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  void (* dynamic_type_builder_add_string_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  void (* dynamic_type_builder_add_wstring_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  // void (* dynamic_type_builder_add_fixed_string_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  // void (* dynamic_type_builder_add_fixed_wstring_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t array_length);
  void (* dynamic_type_builder_add_bounded_string_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t string_bound, size_t array_length);
  void (* dynamic_type_builder_add_bounded_wstring_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t wstring_bound, size_t array_length);


  // DYNAMIC TYPE UNBOUNDED SEQUENCE MEMBERS
  void (* dynamic_type_builder_add_bool_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_byte_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_char_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_wchar_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_float32_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_float64_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_float128_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_int8_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_uint8_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_int16_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_uint16_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_int32_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_uint32_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_int64_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_uint64_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_string_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_wstring_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  // void (* dynamic_type_builder_add_fixed_string_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  // void (* dynamic_type_builder_add_fixed_wstring_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length);
  void (* dynamic_type_builder_add_bounded_string_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t string_bound);
  void (* dynamic_type_builder_add_bounded_wstring_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t wstring_bound);


  // DYNAMIC TYPE BOUNDED SEQUENCE MEMBERS
  void (* dynamic_type_builder_add_bool_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  void (* dynamic_type_builder_add_byte_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  void (* dynamic_type_builder_add_char_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  void (* dynamic_type_builder_add_wchar_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  void (* dynamic_type_builder_add_float32_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  void (* dynamic_type_builder_add_float64_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  void (* dynamic_type_builder_add_float128_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  void (* dynamic_type_builder_add_int8_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  void (* dynamic_type_builder_add_uint8_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  void (* dynamic_type_builder_add_int16_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  void (* dynamic_type_builder_add_uint16_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  void (* dynamic_type_builder_add_int32_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  void (* dynamic_type_builder_add_uint32_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  void (* dynamic_type_builder_add_int64_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  void (* dynamic_type_builder_add_uint64_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  void (* dynamic_type_builder_add_string_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  void (* dynamic_type_builder_add_wstring_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  // void (* dynamic_type_builder_add_fixed_string_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  // void (* dynamic_type_builder_add_fixed_wstring_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t sequence_bound);
  void (* dynamic_type_builder_add_bounded_string_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t string_bound, size_t sequence_bound);
  void (* dynamic_type_builder_add_bounded_wstring_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, size_t wstring_bound, size_t sequence_bound);


  // DYNAMIC TYPE NESTED MEMBERS
  void (* dynamic_type_builder_add_complex_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, rosidl_dynamic_typesupport_dynamic_type_impl_t * nested_struct);
  void (* dynamic_type_builder_add_complex_array_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, rosidl_dynamic_typesupport_dynamic_type_impl_t * nested_struct, size_t array_length);
  void (* dynamic_type_builder_add_complex_unbounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, rosidl_dynamic_typesupport_dynamic_type_impl_t * nested_struct);
  void (* dynamic_type_builder_add_complex_bounded_sequence_member)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder, rosidl_dynamic_typesupport_member_id_t id, const char * name, size_t name_length, rosidl_dynamic_typesupport_dynamic_type_impl_t * nested_struct, size_t sequence_bound);


  // ===============================================================================================
  // DYNAMIC DATA
  // ===============================================================================================

  // DYNAMIC DATA UTILS
  void (* dynamic_data_clear_all_values)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data);
  void (* dynamic_data_clear_nonkey_values)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data);
  void (* dynamic_data_clear_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, rosidl_dynamic_typesupport_member_id_t id);

  bool (* dynamic_data_equals)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, const rosidl_dynamic_typesupport_dynamic_data_impl_t * other);

  size_t (* dynamic_data_get_item_count)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data);  // "item" from XTypes
  rosidl_dynamic_typesupport_member_id_t (* dynamic_data_get_member_id_by_name)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, const char * name, size_t name_length);
  rosidl_dynamic_typesupport_member_id_t (* dynamic_data_get_member_id_at_index)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, size_t index);
  rosidl_dynamic_typesupport_member_id_t (* dynamic_data_get_array_index)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, size_t index);

  rosidl_dynamic_typesupport_dynamic_data_impl_t * (* dynamic_data_loan_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_return_loaned_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, const rosidl_dynamic_typesupport_dynamic_data_impl_t * inner_data);

  void (* dynamic_data_print)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data);

  char * (* dynamic_data_get_name)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data);


  // DYNAMIC DATA CONSTRUCTION
  rosidl_dynamic_typesupport_dynamic_data_impl_t * (* dynamic_data_init_from_dynamic_type_builder)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_builder_impl_t * dynamic_type_builder);
  rosidl_dynamic_typesupport_dynamic_data_impl_t * (* dynamic_data_init_from_dynamic_type)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_type_impl_t * type);
  rosidl_dynamic_typesupport_dynamic_data_impl_t * (* dynamic_data_clone)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data);
  void (* dynamic_data_fini)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data);


  // DYNAMIC DATA PRIMITIVE MEMBER GETTERS
  void (* dynamic_data_get_bool_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, bool * value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_get_byte_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, uint8_t * value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_get_char_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, char * value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_get_wchar_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, wchar_t * value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_get_float32_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, float * value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_get_float64_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, double * value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_get_float128_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, long double * value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_get_int8_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, int8_t * value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_get_uint8_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, uint8_t * value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_get_int16_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, int16_t * value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_get_uint16_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, uint16_t * value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_get_int32_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, int32_t * value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_get_uint32_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, uint32_t * value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_get_int64_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, int64_t * value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_get_uint64_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, uint64_t * value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_get_string_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, const char ** value, size_t * value_length, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_get_wstring_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, const wchar_t ** value, size_t * value_length, rosidl_dynamic_typesupport_member_id_t id);
  // void (* dynamic_data_get_fixed_string_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, const <WHAT TYPE TO USE?> ** value, rosidl_dynamic_typesupport_member_id_t id);
  // void (* dynamic_data_get_fixed_wstring_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, const <WHAT TYPE TO USE?> ** value, rosidl_dynamic_typesupport_member_id_t id);


  // DYNAMIC DATA PRIMITIVE MEMBER SETTERS
  void (* dynamic_data_set_bool_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, bool value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_set_byte_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, uint8_t value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_set_char_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, char value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_set_wchar_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, wchar_t value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_set_float32_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, float value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_set_float64_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, double value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_set_float128_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, long double value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_set_int8_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, int8_t value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_set_uint8_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, uint8_t value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_set_int16_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, int16_t value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_set_uint16_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, uint16_t value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_set_int32_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, int32_t value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_set_uint32_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, uint32_t value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_set_int64_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, int64_t value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_set_uint64_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, uint64_t value, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_set_string_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, const char * value, size_t value_length, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_set_wstring_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, const wchar_t * value, size_t value_length, rosidl_dynamic_typesupport_member_id_t id);
  // void (* dynamic_data_set_fixed_string_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, const <WHAT TYPE TO USE?> * value, rosidl_dynamic_typesupport_member_id_t id);
  // void (* dynamic_data_set_fixed_wstring_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, const <WHAT TYPE TO USE?> * value, rosidl_dynamic_typesupport_member_id_t id);


  // DYNAMIC DATA SEQUENCES
  void (* dynamic_data_clear_sequence_data)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data);
  void (* dynamic_data_remove_sequence_data)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, rosidl_dynamic_typesupport_member_id_t id);
  void (* dynamic_data_insert_sequence_data)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, rosidl_dynamic_typesupport_member_id_t * out_id);

  void (* dynamic_data_insert_bool_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, bool value, rosidl_dynamic_typesupport_member_id_t * out_id);
  void (* dynamic_data_insert_byte_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, uint8_t value, rosidl_dynamic_typesupport_member_id_t * out_id);
  void (* dynamic_data_insert_char_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, char value, rosidl_dynamic_typesupport_member_id_t * out_id);
  void (* dynamic_data_insert_wchar_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, wchar_t value, rosidl_dynamic_typesupport_member_id_t * out_id);
  void (* dynamic_data_insert_float32_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, float value, rosidl_dynamic_typesupport_member_id_t * out_id);
  void (* dynamic_data_insert_float64_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, double value, rosidl_dynamic_typesupport_member_id_t * out_id);
  void (* dynamic_data_insert_float128_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, long double value, rosidl_dynamic_typesupport_member_id_t * out_id);
  void (* dynamic_data_insert_int8_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, int8_t value, rosidl_dynamic_typesupport_member_id_t * out_id);  // TODO
  void (* dynamic_data_insert_uint8_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, uint8_t value, rosidl_dynamic_typesupport_member_id_t * out_id);  // TODO
  void (* dynamic_data_insert_int16_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, int16_t value, rosidl_dynamic_typesupport_member_id_t * out_id);
  void (* dynamic_data_insert_uint16_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, uint16_t value, rosidl_dynamic_typesupport_member_id_t * out_id);
  void (* dynamic_data_insert_int32_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, int32_t value, rosidl_dynamic_typesupport_member_id_t * out_id);
  void (* dynamic_data_insert_uint32_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, uint32_t value, rosidl_dynamic_typesupport_member_id_t * out_id);
  void (* dynamic_data_insert_int64_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, int64_t value, rosidl_dynamic_typesupport_member_id_t * out_id);
  void (* dynamic_data_insert_uint64_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, uint64_t value, rosidl_dynamic_typesupport_member_id_t * out_id);
  void (* dynamic_data_insert_string_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, const char * value, size_t value_length, rosidl_dynamic_typesupport_member_id_t * out_id);
  void (* dynamic_data_insert_wstring_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, const wchar_t * value, size_t value_length, rosidl_dynamic_typesupport_member_id_t * out_id);
  // void (* dynamic_data_insert_fixed_string_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, const <WHAT TYPE TO USE?> * value, rosidl_dynamic_typesupport_member_id_t * out_id);
  // void (* dynamic_data_insert_fixed_wstring_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, const <WHAT TYPE TO USE?> * value, rosidl_dynamic_typesupport_member_id_t * out_id);


  // DYNAMIC DATA NESTED
  void (* dynamic_data_get_complex_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, const rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, rosidl_dynamic_typesupport_dynamic_data_impl_t ** value, rosidl_dynamic_typesupport_member_id_t id);  // Copies
  void (* dynamic_data_set_complex_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, rosidl_dynamic_typesupport_dynamic_data_impl_t * value, rosidl_dynamic_typesupport_member_id_t id);

  void (* dynamic_data_insert_const_complex_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, const rosidl_dynamic_typesupport_dynamic_data_impl_t * value, rosidl_dynamic_typesupport_member_id_t * out_id);
  void (* dynamic_data_insert_complex_value)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, rosidl_dynamic_typesupport_dynamic_data_impl_t * value, rosidl_dynamic_typesupport_member_id_t * out_id);
  void (* dynamic_data_insert_complex_value_ptr)(rosidl_dynamic_typesupport_serialization_support_impl_t * serialization_support, rosidl_dynamic_typesupport_dynamic_data_impl_t * dynamic_data, rosidl_dynamic_typesupport_dynamic_data_impl_t * value, rosidl_dynamic_typesupport_member_id_t * out_id);
};


#ifdef __cplusplus
}
#endif

#endif  // ROSIDL_DYNAMIC_TYPESUPPORT__API__SERIALIZATION_INTERFACE_H_
