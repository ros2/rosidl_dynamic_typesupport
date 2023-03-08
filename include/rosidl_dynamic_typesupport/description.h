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

/// Traversible type description struct, with construction and printing utils

#ifndef ROSIDL_DYNAMIC_TYPESUPPORT__DESCRIPTION_H_
#define ROSIDL_DYNAMIC_TYPESUPPORT__DESCRIPTION_H_

#include <rosidl_dynamic_typesupport/types.h>
#include <glib.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// =================================================================================================
// Structs
// =================================================================================================
// NOTE(methylDragon): Do NOT include this in any rmw or rcl libraries, it'll break extern C linking

// TYPE DESCRIPTION FIELD ==========================================================================
struct type_description_field_s
{
  // Loosely based off
  // https://github.com/ros2/rcl_interfaces/pull/146
  char * field_name;
  uint8_t field_type_id;

  uint64_t field_length;
  uint64_t field_string_length;
  char * nested_type_name;

  // TODO(methylDragon): !!! We need a nested field array size (e.g. for string bounds)
};

type_description_field_t *
get_zero_initialized_type_description_field(void);

bool
type_description_field_fini(type_description_field_t * type_description_field);


// INDIVIDUAL TYPE DESCRIPTION =====================================================================
struct individual_type_description_s
{
  char * type_name;
  char * type_version_hash;

  type_description_field_t ** fields;
  size_t field_count;
};

individual_type_description_t *
get_zero_initialized_individual_type_description(void);

bool
individual_type_description_fini(individual_type_description_t * individual_type_description);


// TYPE DESCRIPTION ================================================================================
struct type_description_s
{
  // TODO(methylDragon): !!! We need serialization metadata

  individual_type_description_t * type_description;

  // Hash-table of char * -> individual_type_description_t *
  // Keyed by referenced type_name
  //
  // We can also get the count of referenced_type_descriptions with
  // g_hash_table_size()
  GHashTable * referenced_type_descriptions;
};

type_description_t *
get_zero_initialized_type_description(void);

bool
type_description_fini(type_description_t * type_description);


// =================================================================================================
// Construction
// =================================================================================================
individual_type_description_t *
populate_individual_type_description(
  individual_type_description_t * individual_description_struct,
  GNode * description_node);

type_description_t *
populate_type_description(type_description_t * description_struct, GNode * full_description_node);

type_description_t *
create_type_description_from_yaml_tree(GNode * root);

type_description_t *
create_type_description_from_yaml_file(const char * path);

/// Create a new type_description_t with a referenced individual_type_description_t in the description field
///
/// This pulls the info from the passed in full_description and copies the pointers
/// It is NOT a deep copy! Just free the resulting type_description_t * when done
type_description_t *
get_ref_description_as_type_description(type_description_t * full_description, const char * key);


// =================================================================================================
// Printing
// =================================================================================================
void
print_type_description_field(type_description_field_t * input);

void
print_individual_type_description(individual_type_description_t * input);

void
print_type_description(type_description_t * input);

#ifdef __cplusplus
}
#endif

#endif  // ROSIDL_DYNAMIC_TYPESUPPORT__DESCRIPTION_H_
