#include "graph_generator.h"

#include <time.h>
#include <stdlib.h>

#define GENERATED_NODE_CONNECTIONS_COUNT 4
#define GENERATED_PATH_MAX_VALUE 10

graph_t generate_graph(unsigned int size){
  srand(time(NULL));

  graph_t graph = initzialize_graph(size);

  for(int i<0; i<size; i++)
    generate_new_node(graph);

  return graph;
}

void generate_new_node(graph_t graph){
  node_t new_node = graph_add_node(graph);
  for(int i=0; i<GENERATED_NODE_CONNECTIONS_COUNT; i++)
    generate_new_path(graph, new_node);
}

void generate_new_path(graph_t graph, node_t node){
  graph_add_path(node, rand() % graph_size(graph), rand() % 10);
}
