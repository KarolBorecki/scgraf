#include "GraphHandler.h"

graph_t initzialize_graph(){
  graph_t graph = malloc(sizeof(*graph));
  graph->size = 0;
  graph->nodes = initzialize_nodes(START_GRAPH_NODES_COUNT);
  graph->memory_size = START_GRAPH_NODES_COUNT;
}

node_t initzialize_nodes(unsigned int size){
  node_t nodes = malloc(size * sizeof(*nodes)));
  for(int i=0; i<size; i++){
    (nodes+i)->index = i;
    (nodes+i)->paths = initzialize_paths(START_NODES_PATHS_COUNT);
    (nodes+i)->paths_count = START_NODES_PATHS_COUNT;
  }

  return nodes;
}

path_t initzialize_paths(unsigned int size){
  path_t paths = malloc(size * sizeof(*paths));
  for(int i=0; i<size; i++){
    (paths+i)->connection = NULL;
    (paths+i)->value = 0
  }
}

void clean_graph(graph_t graph);
void add_node(graph_t graph, path_t paths, unsigned int paths_count);
void add_path(node_t node, node_t connection, unsigned int value);

node_t get_node_with_index(graph_t graph, unsigned int index);

void print_graph(graph_t);
