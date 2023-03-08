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

// Modified from source: https://stackoverflow.com/a/621451
// Modified to support sequence elements and switch cases

#include <stdio.h>
#include <assert.h>

#include <rosidl_dynamic_typesupport/yaml_parser.h>


enum storage_flags { VAR, VAL }; // "Store as" switch

void process_layer(yaml_parser_t * parser, GNode * data, bool seq)
{
  GNode * last_leaf = data;
  yaml_event_t event;
  int storage = VAR;   // mapping cannot start with VAL definition w/o VAR key

  while (1) {
    yaml_parser_parse(parser, &event);
    assert(event.type != YAML_NO_EVENT /* MESSAGE */); // Invalid yaml

    switch (event.type) {
      case YAML_SCALAR_EVENT:
        if (storage & VAL && seq) {
          // If this is just a bare value in a sequence, append it, populated
          data = g_node_append(last_leaf, g_node_new(g_strdup((gchar *) "-")));
          g_node_append(data, g_node_new(g_strdup((gchar *) event.data.scalar.value)));
          break;
        }

        if (storage & VAL) {
          // Add data
          g_node_append_data(last_leaf, g_strdup((gchar *) event.data.scalar.value));
        } else {
          // Point data to new node with data
          last_leaf = g_node_append(data, g_node_new(g_strdup((gchar *) event.data.scalar.value)));
        }
        storage ^= VAL;    // Flip VAR/VAL switch for the next event
        break;

      case YAML_SEQUENCE_START_EVENT:
        seq = true;
        break;

      case YAML_SEQUENCE_END_EVENT:
        seq = false;
        break;

      case YAML_MAPPING_START_EVENT:
        // Add new layer if sequence encountered
        if (seq) {
          process_layer(
            parser,
            g_node_append(last_leaf, g_node_new(g_strdup((gchar *) "-"))),
            false
          );
        } else {
          // Otherwise, append to last leaf
          process_layer(parser, last_leaf, seq);
        }
        storage ^= VAL;  // Flip VAR/VAL
        break;

      case YAML_MAPPING_END_EVENT:
      case YAML_STREAM_END_EVENT:
        yaml_event_delete(&event);
        return;

      default:  // Ignore the rest
        break;
    }
  }
}


GNode * parse_yaml_file(char * path)
{
  GNode * root = g_node_new(path);
  yaml_parser_t parser;

  FILE * source = fopen(path, "rb");

  yaml_parser_initialize(&parser);
  yaml_parser_set_input_file(&parser, source);

  process_layer(&parser, root, false);  // Recursive parsing

  yaml_parser_delete(&parser);
  fclose(source);

  return root;
}
