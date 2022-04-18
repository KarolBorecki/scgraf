#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "../utils/config.h"

typedef struct path{
  unsigned connection;
  double value;
} *path_t;

typedef struct node{
  unsigned index; /* index in array of graph_t->nodes */
  path_t paths;
  unsigned paths_count;
  unsigned paths_memory_size;
} *node_t;

typedef struct graph{
  node_t nodes;
  unsigned size;
  unsigned memory_size;
  double max_path_value;
  unsigned width;
  unsigned height;
} *graph_t;

graph_t initzialize_graph(unsigned nodes_count);
graph_t initzialize_graph_with_all_nodes(unsigned nodes_count);

void graph_set_max_path_value(graph_t graph, double value);
void graph_set_width_and_height(graph_t graph, unsigned width, unsigned height);
void enlarge_graph_nodes_memory(graph_t graph, unsigned enlarge_multiplier);
void enlarge_graph_paths_memory(node_t node, unsigned enlarge_multiplier);

void clean_graph(graph_t graph);

node_t graph_add_node(graph_t graph);
path_t graph_add_path(node_t node, unsigned connection, double value);

void graph_remove_path_at_index(node_t node, unsigned index);
void graph_remove_path_with_connection(node_t node, unsigned connection);

node_t graph_get_node_at_index(graph_t graph, unsigned index);
path_t graph_get_path_at_index(node_t node, unsigned index);

int graph_get_connection_value(node_t node, unsigned node2); /* returns -1 if connection does not exists */

unsigned graph_size(graph_t graph);
unsigned graph_memory_size(graph_t graph);

unsigned graph_get_node_paths_count(node_t node);

void graph_add_path_two_way(graph_t graph, node_t node, unsigned connection, double value);
int graph_check_if_path_between_exists(graph_t graph, unsigned node_index, unsigned connection_index);

void graph_make_existing_path_two_way(graph_t graph, unsigned node_index, unsigned connection);
path_t graph_get_path_for_node_index(node_t node_from, unsigned destination_node_index);
double update_max_path_value(graph_t graph);

void graph_convert_directed_to_undirected(graph_t graph);

unsigned graph_get_memory_size_for_paths(graph_t graph);

void print_graph(graph_t graph, char* caption);

#endif /* _GRAPH_H_ */
