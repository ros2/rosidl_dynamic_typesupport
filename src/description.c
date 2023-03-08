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

#include <rosidl_dynamic_typesupport/types.h>
#include <rosidl_dynamic_typesupport/description.h>
#include <rosidl_dynamic_typesupport/tree_traverse.h>
#include <rosidl_dynamic_typesupport/yaml_parser.h>


// =================================================================================================
// Structs
// =================================================================================================
// TYPE DESCRIPTION FIELD ==========================================================================
type_description_field_t *
get_zero_initialized_type_description_field(void)
{
  type_description_field_t * out = malloc(sizeof(type_description_field_t));
  if (out == NULL) {
    printf("Could not allocate type_description_field!\n");
    return NULL;
  }

  out->field_name = NULL;
  out->field_type_id = 0;

  out->field_length = 0;
  out->field_string_length = 0;
  out->nested_type_name = NULL;

  return out;
}


bool
type_description_field_fini(type_description_field_t * type_description_field)
{
  free(type_description_field->field_name);
  free(type_description_field->nested_type_name);

  free(type_description_field);
  return true;
}


// INDIVIDUAL TYPE DESCRIPTION =====================================================================
individual_type_description_t *
get_zero_initialized_individual_type_description(void)
{
  individual_type_description_t * out = malloc(sizeof(individual_type_description_t));
  if (out == NULL) {
    printf("Could not allocate individual_type_description!\n");
    return NULL;
  }

  out->type_name = NULL;
  out->type_version_hash = NULL;

  out->fields = NULL;
  out->field_count = 0;

  return out;
}


bool
individual_type_description_fini(individual_type_description_t * individual_type_description)
{
  free(individual_type_description->type_name);
  free(individual_type_description->type_version_hash);

  for (size_t i = 0; i < individual_type_description->field_count; i++) {
    if (type_description_field_fini(individual_type_description->fields[i]) != true) {
      printf("Could not finalize individual_type_description!\n");
      return false;
    }
  }
  free(individual_type_description->fields);

  free(individual_type_description);
  return true;
}


// TYPE DESCRIPTION ================================================================================
void
_free_data(gpointer data)
{
  free(data);
}


void
_free_individual_type_description(gpointer data)
{
  if (individual_type_description_fini((individual_type_description_t *) data) != true) {
    printf("Could not finalize individual_type_description!\n");
  }
}


type_description_t *
get_zero_initialized_type_description(void)
{
  type_description_t * out = malloc(sizeof(type_description_t));
  if (out == NULL) {
    printf("Could not allocate type_description!\n");
    return NULL;
  }
  out->type_description = get_zero_initialized_individual_type_description();
  out->referenced_type_descriptions = g_hash_table_new_full(
    g_str_hash, g_str_equal, _free_data, _free_individual_type_description
  );

  return out;
}


bool
type_description_fini(type_description_t * type_description)
{
  g_hash_table_destroy(type_description->referenced_type_descriptions);

  if (!individual_type_description_fini(type_description->type_description)) {
    return false;
  }

  free(type_description);
  return true;
}


// =================================================================================================
// Construction
// =================================================================================================
individual_type_description_t *
populate_individual_type_description(
  individual_type_description_t * individual_description_struct,
  GNode * description_node)
{
  // TODO(methylDragon):: We need to populate the hash

  individual_description_struct->type_name =
    strdup(get_child_value_by_key(description_node, "type_name"));

  GNode * _fields = get_child_by_key(description_node, "fields");
  GNode * _field = g_node_nth_child(_fields, 0);

  individual_description_struct->field_count = g_node_n_children(_fields);
  individual_description_struct->fields =
    malloc(sizeof(type_description_field_t) * individual_description_struct->field_count);

  size_t _field_counter = 0;

  while (_field != NULL) {
    // Ideally we'd do some try-catch here to finalize the field if we failed
    type_description_field_t * _field_struct = get_zero_initialized_type_description_field();

    _field_struct->field_name = strdup(get_child_value_by_key(_field, "field_name"));
    _field_struct->field_type_id = atoi(get_child_value_by_key(_field, "field_type_id"));
    _field_struct->field_length = atoi(get_child_value_by_key(_field, "field_length"));
    _field_struct->field_string_length =
      atoi(get_child_value_by_key(_field, "field_string_length"));

    // Treat "~" as null
    char * _nested_type_name =
      nullify_string(get_child_value_by_key(_field, "nested_type_name"), "~");
    if (_nested_type_name != NULL) {
      _field_struct->nested_type_name = strdup(_nested_type_name);
    }  // NULL by default from zero initialization

    individual_description_struct->fields[_field_counter++] = _field_struct;
    _field = _field->next;
  }

  return individual_description_struct;
}


type_description_t *
populate_type_description(type_description_t * description_struct, GNode * full_description_node)
{
  GNode * type_description_node = get_child_by_key(full_description_node, "type_description");
  populate_individual_type_description(description_struct->type_description, type_description_node);

  // Referenced descriptions
  GHashTable * ref_description_map = description_struct->referenced_type_descriptions;

  GNode * referenced_type_descriptions =
    get_child_by_key(full_description_node, "referenced_type_descriptions");
  GNode * ref_description = g_node_nth_child(referenced_type_descriptions, 0);

  if (g_node_n_children(ref_description) == 0) {
    return description_struct;
  }

  while (ref_description != NULL) {
    individual_type_description_t * individual_ref_decription_struct =
      get_zero_initialized_individual_type_description();

    populate_individual_type_description(individual_ref_decription_struct, ref_description);
    g_hash_table_insert(
      ref_description_map,
      get_child_value_by_key(ref_description, "type_name"),
      individual_ref_decription_struct
    );

    ref_description = ref_description->next;
  }

  return description_struct;
}


type_description_t *
create_type_description_from_yaml_tree(GNode * root)
{
  // Create type description struct
  type_description_t * description_struct = get_zero_initialized_type_description();
  populate_type_description(description_struct, root);

  return description_struct;
}


type_description_t *
create_type_description_from_yaml_file(const char * path)
{
  char * path_ = strdup(path);
  GNode * root = parse_yaml_file(path_);

  g_free(path_);

  type_description_t * out = create_type_description_from_yaml_tree(root);

  // Cleanup parsed tree (This is ok since the population function copies any relevant data)
  g_node_traverse(root, G_PRE_ORDER, G_TRAVERSE_ALL, -1, gnode_free_node_data_fn, NULL);
  g_node_destroy(root);

  return out;
}


type_description_t *
get_ref_description_as_type_description(type_description_t * full_description, const char * key)
{
  // Ensure referenced type exists
  void * ref_lookup =
    g_hash_table_lookup(full_description->referenced_type_descriptions, key);

  if (ref_lookup == NULL) {
    printf("Referenced type description: [%s] could not be found in description!", key);
    return NULL;
  }

  type_description_t * out = malloc(sizeof(type_description_t));
  if (out == NULL) {
    printf("Could not allocate type_description!\n");
    return NULL;
  }

  out->type_description = (individual_type_description_t *)(ref_lookup);
  out->referenced_type_descriptions = full_description->referenced_type_descriptions;

  return out;
}


// =================================================================================================
// Printing
// =================================================================================================
void
print_type_description_field(type_description_field_t * input)
{
  printf(
    "[FIELD]\n"
    "  field_name: %s\n"
    "  field_type_id: %d\n"
    "  field_length: %ld\n"
    "  field_string_length: %ld\n"
    "  nested_type_name: %s\n",
    input->field_name, input->field_type_id,
    input->field_length, input->field_string_length,
    input->nested_type_name
  );
}


void
print_individual_type_description(individual_type_description_t * input)
{
  printf(
    "\n[INDIVIDUAL DESCRIPTION]\n"
    "  type_name: %s\n"
    "  type_version_hash: %s\n"
    "  field_count: %ld\n",
    input->type_name, input->type_version_hash, input->field_count
  );

  for (size_t i = 0; i < input->field_count; i++) {
    print_type_description_field(input->fields[i]);
  }
}


static void
_print_type_description_foreach(gpointer key, gpointer value, gpointer user_data)
{
  (void)key;
  (void)user_data;
  print_individual_type_description((individual_type_description_t *) value);
}


void
print_type_description(type_description_t * input)
{
  printf("\n\n---\n\n");

  printf("= [PRINTING TYPE DESCRIPTION] =\n");
  printf(
    "  referenced_type_descriptions_count: %d\n",
    g_hash_table_size(input->referenced_type_descriptions)
  );

  printf("\n== [MAIN DESCRIPTION] ==\n");
  print_individual_type_description(input->type_description);

  printf("\n== [REFERENCED DESCRIPTIONS] ==\n");
  g_hash_table_foreach(input->referenced_type_descriptions, _print_type_description_foreach, NULL);

  printf("\n---\n\n");
}
