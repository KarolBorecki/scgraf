#ifndef _GRAPH_H_
#define _GRAPH_H_

#define START_NODES_PATHS_COUNT 4
#define GRAPH_ENLARGE_MULTIPLIER 2

typedef struct path{
  unsigned connection;
  double value;
} *path_t;

typedef struct node{
  unsigned int index; /* index in array of graph_t->nodes */
  path_t paths;
  unsigned paths_count;
  unsigned paths_memory_size;
} *node_t;

typedef struct graph{
  node_t nodes;
  unsigned size;
  unsigned memory_size;
} *graph_t;

graph_t initzialize_graph(unsigned int nodes_count);
void enlarge_graph_nodes_memory(graph_t graph, unsigned enlrage_multiplier);
void enlarge_graph_paths_memory(node_t node, unsigned enlrage_multiplier);

void clean_graph_path(path_t path);
void clean_graph_node(node_t node);
void clean_graph(graph_t graph);

node_t graph_add_node(graph_t graph);
path_t graph_add_path(node_t node, unsigned connection, double value);

node_t graph_get_node_with_index(graph_t graph, unsigned index);

int graph_get_connection_value(node_t node, unsigned node2); /* returns -1 if connection does not exists */

unsigned graph_size(graph_t graph);
unsigned graph_memory_size(graph_t graph);

unsigned graph_get_node_paths_count(node_t node);
path_t graph_get_node_path_at_index(node_t node, unsigned index);

void print_graph(graph_t);

#endif /* _GRAPH_H_ */
