#include "graph.h"

#include <stdio.h>
#include <stdlib.h>

graph_t initzialize_graph(unsigned int nodes_count){
  graph_t graph = malloc(sizeof(*graph));
  graph->size = 0;
  graph->nodes = malloc(nodes_count * sizeof(*(graph->nodes)));
  graph->memory_size = nodes_count;

  return graph;
}

void enlarge_nodes_memory(graph_t graph, unsigned int enlrage_multiplier){
  graph->memory_size *= enlrage_multiplier;
  graph->nodes = realloc(graph->nodes, graph->memory_size);
}

void enlarge_paths_memory(node_t node, unsigned int enlrage_multiplier){
  node->paths_memory_size *= enlrage_multiplier;
  node->paths = realloc(node->paths, node->paths_memory_size);
}

//TODO refactor
void clean_graph(graph_t graph){
  for(int i=0; i<graph->size; i++){
    for(int j=0; j<graph->nodes[i].paths_count; j++)
      free(graph->nodes[i].paths+j);
    free(graph->nodes+i);
  }
  free(graph);
}

//TODO maybe we should add node of index chosen by user?
node_t add_node(graph_t graph){
  if(graph->size >= graph->memory_size)
    enlarge_nodes_memory(graph, GRAPH_ENLARGE_MULTIPLIER);

  node_t new_node = graph->nodes+graph->size;
  new_node->index = graph->size;
  new_node->paths_count = 0;
  new_node->paths = malloc(START_NODES_PATHS_COUNT * sizeof(*(new_node->paths)));
  new_node->paths_memory_size = START_NODES_PATHS_COUNT;

  graph->size++;

  return new_node;
}

path_t add_path(node_t node, unsigned int connection, float value){
  if(node->paths_count >= node->paths_memory_size)
    enlarge_paths_memory(node, GRAPH_ENLARGE_MULTIPLIER);

  path_t new_path = node->paths+node->paths_count;
  new_path->connection = connection;
  new_path->value = value;

  node->paths_count++;

  return new_path;
}

node_t get_node_with_index(graph_t graph, unsigned int index){
  return graph->nodes+index;
}

void print_graph(graph_t graph){
  printf("\n=========Graph=========\n\n");
  printf("    Nodes: %d \n", graph->size);
  printf("    Memory: %d size, %lu bytes per node, %lu bytes used \n\n", graph->memory_size, sizeof(*(graph->nodes)), graph->memory_size * sizeof(*(graph->nodes)));
  printf("Nodes:\n");
  for(int i=0; i<graph->size; i++){
    printf("   %d) %d -> ", i, graph->nodes[i].index);
    for(int j=0; j<graph->nodes[i].paths_count; j++){
      printf("%d(%.4f)", graph->nodes[i].paths[j].connection, graph->nodes[i].paths[j].value);
      if(j!=graph->nodes[i].paths_count-1) printf(" - ");
    }
    printf("\n");
  }
  printf("\n=========Graph=========\n\n");
}
