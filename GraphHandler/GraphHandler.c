#include "GraphHandler.h"

graph_t initzialize_graph(){
  graph_t graph = malloc(sizeof(*graph));
  graph->size = 0;
  graph->nodes = malloc(START_GRAPH_NODES_COUNT * sizeof(*nodes)));
  graph->memory_size = START_GRAPH_NODES_COUNT;
}

void clean_graph(graph_t graph);

void add_node(graph_t graph, path_t paths, unsigned int paths_count);
void add_path(node_t node, node_t connection, unsigned int value);

node_t get_node_with_index(graph_t graph, unsigned int index);

void print_graph(graph_t);
