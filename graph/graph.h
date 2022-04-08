#ifndef _GRAPH_H_
#define _GRAPH_H_

#define START_NODES_PATHS_COUNT 4

#define GRAPH_ENLARGE_MULTIPLIER 2

typedef struct path{
  unsigned int connection;
  double value;
} *path_t;

typedef struct node{
  unsigned int index; /* index in array of graph_t->nodes */
  path_t paths;
  unsigned int paths_count;
  unsigned int paths_memory_size;
} *node_t;

typedef struct graph{
  node_t nodes;
  unsigned int size;
  unsigned int memory_size;
} *graph_t;

graph_t initzialize_graph(unsigned int nodes_count);
void enlarge_nodes_memory(graph_t graph, unsigned int enlrage_multiplier);
void enlarge_paths_memory(node_t node, unsigned int enlrage_multiplier);

void clean_graph(graph_t graph);

node_t add_node(graph_t graph);
path_t add_path(node_t node, unsigned int connection, double value);

node_t get_node_with_index(graph_t graph, unsigned int index);

void print_graph(graph_t);

#endif /* _GRAPH_H_ */
