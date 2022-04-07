#include "GraphHandler.h"

graph_t initzialize_graph(){
  graph_t graph = malloc(sizeof(*graph));
  graph->size = 0;
  graph->nodes = malloc(START_GRAPH_NODES_COUNT * sizeof(*nodes)));
  graph->memory_size = START_GRAPH_NODES_COUNT;
}

void enlarge_nodes_memory(graph_t graph, unsigned int enlrage_multiplier){

}

void enlarge_paths_memory(node_t node, unsigned int enlrage_multiplier){

}

void clean_graph(graph_t graph){

}

void add_node(graph_t graph){
  if(graph->size >= graph->memory_size)
    enlarge_nodes_memory(graph, GRAPH_ENLARGE_MULTIPLIER);

  node_t new_node = graph->nodes+graph->size;
  new_node->index = graph->size;
  new_node->paths = malloc(START_NODES_PATHS_COUNT * sizeof(*(new_node->paths)));
  new_node->paths_count = paths_count;

  graph->size++;
}

void add_path(node_t node, node_t connection, unsigned int value){

}

node_t get_node_with_index(graph_t graph, unsigned int index){

}

void print_graph(graph_t){

}
