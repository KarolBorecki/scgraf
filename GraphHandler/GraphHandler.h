#ifndef _GRAPH_HANDLER_H_
#define _GRAPH_HANDLER_H_

#define START_GRAPH_NODES_COUNT 20
#define START_NODES_PATHS_COUNT 4

#define GRAPH_ENLARGE_MULTIPLIER 2

typedef struct graph{
  node_t nodes;
  unsigned int size;
  unsigned int memory_size;
} *graph_t;

typedef struct node{
  unsigned int index; /* index in array of graph_t->nodes */
  path_t paths;
  unsigned int paths_count;
} *node_t;

typedef struct path{
  node_t connection;
  unsigned int value;
} *path_t;

graph_t initzialize_graph();

void clean_graph(graph_t graph);

void add_node(graph_t graph, path_t paths, unsigned int paths_count);
void add_path(node_t node, node_t connection, unsigned int value);

node_t get_node_with_index(graph_t graph, unsigned int index);

void print_graph(graph_t);

#endif /* _GRAPH_HANDLER_H_ */
