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

/// Utilities for traversing a GLib N-ary tree

#ifndef ROSIDL_DYNAMIC_TYPESUPPORT__TREE_TRAVERSE_H_
#define ROSIDL_DYNAMIC_TYPESUPPORT__TREE_TRAVERSE_H_

#include <rosidl_dynamic_typesupport/types.h>

#include <glib.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// =================================================================================================
// Utils
// =================================================================================================
/// Index into a node's children via key-value semantics and get node
GNode *
get_child_by_key(GNode * node, char * key);

/// Index into a node's children via key-value semantics and get key
gpointer
get_child_value_by_key(GNode * node, char * key);

/// String representation printing function for GNodes
gboolean gnode_print_fn(GNode * n, gpointer data);

/// Data freeing function for GNodes
/// g_node_destroy deallocates the tree but not the data stored in each node!
gboolean gnode_free_node_data_fn(GNode * n, gpointer data);

/// If input string fully matches a string, replace it with NULL
char *
nullify_string(char * input, char * match);


// =================================================================================================
// glib Tree Traversal Functions
// =================================================================================================
/// Find node in glib N-ary tree with node data matching a string
GNode *
g_node_str_tree_find(GNode * root, GTraverseType order, GTraverseFlags flags, char * data);

/// Find immediate child node in glib N-ary tree with node data matching a string
GNode *
g_node_str_child_find(GNode * root, GTraverseType order, GTraverseFlags flags, char * data);

/// Get GNode from glib N-ary tree by string reference
/// Also redirects nested types to referenced_type_descriptions!
bool
get_gnode_by_str_ref(char * ref, GNode * root, GNode ** out_node);

#ifdef __cplusplus
}
#endif

#endif  // ROSIDL_DYNAMIC_TYPESUPPORT__TREE_TRAVERSE_H_
