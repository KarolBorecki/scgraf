#include "graph.h"

#include <stdio.h>
#include <stdlib.h>

graph_t initzialize_graph(unsigned nodes_count){
  graph_t graph = malloc(sizeof(*graph));
  graph->size = 0;
  graph->nodes = malloc(nodes_count * sizeof(*(graph->nodes)));
  graph->memory_size = nodes_count;

  return graph;
}

void enlarge_graph_nodes_memory(graph_t graph, unsigned enlrage_multiplier){
  graph->memory_size *= enlrage_multiplier;
  graph->nodes = realloc(graph->nodes, graph->memory_size);
}

void enlarge_graph_paths_memory(node_t node, unsigned enlrage_multiplier){
  node->paths_memory_size *= enlrage_multiplier;
  node->paths = realloc(node->paths, node->paths_memory_size);
}

void clean_graph_path(path_t path){
  free(path);
}

void clean_graph_node(node_t node){
  for(int j=0; j<node->paths_count; j++)
    clean_graph_path(node->paths+j);
  free(node);
}

void clean_graph(graph_t graph){
  for(int i=0; i<graph->size; i++)
    clean_graph_node(graph->nodes+i);
  free(graph);
}

//TODO maybe we should add node of index chosen by user?
node_t graph_add_node(graph_t graph){
  if(graph->size >= graph->memory_size)
    enlarge_graph_nodes_memory(graph, GRAPH_ENLARGE_MULTIPLIER);

  node_t new_node = graph->nodes+graph->size;
  new_node->index = graph->size;
  new_node->paths_count = 0;
  new_node->paths = malloc(START_NODES_PATHS_COUNT * sizeof(*(new_node->paths)));
  new_node->paths_memory_size = START_NODES_PATHS_COUNT;

  graph->size++;

  return new_node;
}

path_t graph_add_path(node_t node, unsigned connection, double value){
  if(node->paths_count >= node->paths_memory_size)
    enlarge_graph_paths_memory(node, GRAPH_ENLARGE_MULTIPLIER);

  path_t new_path = node->paths+node->paths_count;
  new_path->connection = connection;
  new_path->value = value;

  node->paths_count++;

  return new_path;
}

node_t graph_get_node_with_index(graph_t graph, unsigned index){
  return graph->nodes+index;
}

int graph_get_connection_value(node_t node, unsigned node2){
  path_t path;
  for(int i=0; i<graph_get_node_paths_count(node); i++){
    path = graph_get_node_path_at_index(node, i);
    if(path->connection == node2)
      return path->value;
  }
  return -1;
}

unsigned graph_size(graph_t graph){
  return graph->size;
}

unsigned graph_memory_size(graph_t graph){
  return graph->memory_size;
}

unsigned graph_get_node_paths_count(node_t node){
  return node->paths_count;
}

path_t graph_get_node_path_at_index(node_t node, unsigned index){
  return node->paths+index;
}

void print_graph(graph_t graph){
  printf("\n=========Graph=========\n\n");
  printf("    Nodes: %d \n", graph->size);
  printf("    Memory: %d size, %lu bytes per node, %lu bytes used \n\n",
  graph->memory_size,
  sizeof(*(graph->nodes)),
  graph->memory_size * sizeof(*(graph->nodes)));

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
