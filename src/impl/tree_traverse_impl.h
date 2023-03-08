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

#include <glib.h>
#include <regex.h>
#include <stdbool.h>


// =================================================================================================
// Utils
// =================================================================================================
/// Check if string is terminated by terminator
bool
_check_terminator(const char * tok, const char * terminator);

/// Get index from suffixed char pointers, like "5]", where "]" is the terminator
int
_get_idx_from_idx_token(const char * tok, const char * terminator);

/// Get field_type_id from a field_type_id GNode
int
_get_field_type_id(GNode * field_type_id_node);

// =================================================================================================
// glib Tree Traversal Functions
// =================================================================================================
/// Per-node comparison function to pass to _g_node_str_find to extract the matching node
gboolean
_g_node_data_strcmp(GNode * node, gpointer data);

/// Find node in glib N-ary tree with node data matching a string
GNode *
_g_node_str_depth_find(
  GNode * root, GTraverseType order, GTraverseFlags flags, char * str,
  int depth);
