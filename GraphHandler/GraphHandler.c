#include "GraphHandler.h"

graph_t initzialize_graph(unsigned int nodes_count){
  graph_t graph = malloc(sizeof(*graph));
  graph->size = 0;
  graph->nodes = malloc(nodes_count * sizeof(*nodes)));
  graph->memory_size = nodes_count;
}

void enlarge_nodes_memory(graph_t graph, unsigned int enlrage_multiplier){
  graph->memory_size *= enlrage_multiplier;
  graph->nodes = realloc(graph->nodes, graph->memory_size);
}

void enlarge_paths_memory(node_t node, unsigned int enlrage_multiplier){
  node->memory_size *= enlrage_multiplier;
  node->paths = realloc(node->paths, node->memory_size);
}

void clean_graph(graph_t graph){

}

//TODO maybe we should add node of index chosen by user?
void add_node(graph_t graph){
  if(graph->size >= graph->memory_size)
    enlarge_nodes_memory(graph, GRAPH_ENLARGE_MULTIPLIER);

  node_t new_node = graph->nodes+graph->size;
  new_node->index = graph->size;
  new_node->paths_count = 0;
  new_node->paths = malloc(START_NODES_PATHS_COUNT * sizeof(*(new_node->paths)));
  new_node->paths_memory_size = START_NODES_PATHS_COUNT;

  graph->size++;
}

void add_path(node_t node, unsigned int connection, unsigned int value){
  if(node->paths_count >= node->paths_memory_size)
    enlarge_paths_memory(node, GRAPH_ENLARGE_MULTIPLIER);

  path_t new_path = node->paths+node->paths_count;
  new_path->connection = connection;
  new_path->value = value;

  node->paths_count++;
}

node_t get_node_with_index(graph_t graph, unsigned int index){

}

void print_graph(graph_t){

}
