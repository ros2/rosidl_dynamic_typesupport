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

#include <impl/tree_traverse_impl.h>

#include <assert.h>
#include <stdbool.h>


// =================================================================================================
// Utils
// =================================================================================================
bool
_check_terminator(const char * tok, const char * terminator)
{
  return strcmp(tok + strlen(tok) - strlen(terminator), terminator) == 0;
}


int
_get_idx_from_idx_token(const char * tok, const char * terminator)
{
  int idx;
  int idx_len = strlen(tok) - strlen(terminator);

  char * idx_str = malloc(sizeof(char) * idx_len + 1);
  strncpy(idx_str, tok, idx_len);
  idx_str[idx_len] = '\0';

  idx = atoi(idx_str);
  free(idx_str);

  return idx;
}


/// Get field_type_id from a field_type_id GNode
int
_get_field_type_id(GNode * field_type_id_node)
{
  // Only works with field_type_id nodes!
  assert(strcmp(field_type_id_node->data, "field_type_id") == 0);
  return atoi(field_type_id_node->children[0].data);
}


// =================================================================================================
// glib Tree Traversal Functions
// =================================================================================================
gboolean
_g_node_data_strcmp(GNode * node, gpointer data)
{
  gpointer * d = data;
  if (strcmp(*d, node->data) != 0) {return FALSE;}
  *(++d) = node;
  return TRUE;
}


GNode *
_g_node_str_depth_find(
  GNode * root, GTraverseType order, GTraverseFlags flags, char * str,
  int depth)
{
  gpointer d[2];

  g_return_val_if_fail(root != NULL, NULL);
  g_return_val_if_fail(order <= G_LEVEL_ORDER, NULL);
  g_return_val_if_fail(flags <= G_TRAVERSE_MASK, NULL);

  d[0] = str;
  d[1] = NULL;

  g_node_traverse(root, order, flags, depth, _g_node_data_strcmp, d);

  return d[1];
}
