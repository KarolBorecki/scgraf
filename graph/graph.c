#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/utils.h"
#include "../errors/errors.h"
#include "../printer/printer.h"

graph_t initzialize_graph(unsigned nodes_count){
  graph_t graph = malloc(sizeof(*graph));
  graph->size = 0;
  graph->nodes = malloc(nodes_count * sizeof(*(graph->nodes)));
  graph->memory_size = nodes_count;

  return graph;
}

void enlarge_graph_nodes_memory(graph_t graph, unsigned enlarge_multiplier){
  graph->nodes = realloc_block(graph->nodes, graph->memory_size * sizeof(*(graph->nodes)), enlarge_multiplier);
  graph->memory_size *= enlarge_multiplier;
}

void enlarge_graph_paths_memory(node_t node, unsigned enlarge_multiplier){
  node->paths = realloc_block(node->paths, node->paths_memory_size * sizeof(*(node->paths)), enlarge_multiplier);
  node->paths_memory_size *= enlarge_multiplier;
}

void clean_graph(graph_t graph){
  for(int i=0; i<graph->size; i++)
    free(graph_get_node_at_index(graph, i)->paths);

  free(graph->nodes);
  free(graph);
}

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

  path_t new_path = node->paths+(node->paths_count);
  new_path->connection = connection;
  new_path->value = value;
  node->paths_count++;

  return new_path;
}

void graph_remove_path_at_index(node_t node, unsigned index){
  if(index < node->paths_count-1)
    memcpy(node->paths+index, node->paths+index+1, (node->paths_count-index) * sizeof(*(node->paths)));
  node->paths_count--;
}

void graph_remove_path_with_connection(node_t node, unsigned connection){
  for(int i=0; i<graph_get_node_paths_count(node); i++)
    if(graph_get_path_at_index(node, i)->connection == connection){
      graph_remove_path_at_index(node, i);
      return;
    }
}

node_t graph_get_node_at_index(graph_t graph, unsigned index){
  if(index>=graph_size(graph))
    throw_error(memory_error, "Out of bounds!");
  return graph->nodes+index;
}

path_t graph_get_path_at_index(node_t node, unsigned index){
  return node->paths+index;
}

int graph_get_connection_value(node_t node, unsigned node2){
  path_t path;
  for(int i=0; i<graph_get_node_paths_count(node); i++){
    path = graph_get_path_at_index(node, i);
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

//Function can be only used once all nodes in the graph were initialized
void graph_add_path_two_way(graph_t graph, node_t node, unsigned connection, double value){
    graph_add_path(node, connection, value);
    if(&(graph->nodes[connection]) != NULL)
        graph_add_path(&(graph->nodes[connection]), node->index, value);
}

path_t graph_get_path_for_node_index(node_t node_from, unsigned destination_node_index){
    for(int i= 0; i<node_from->paths_count; i++)
        if(node_from->paths[i].connection == destination_node_index)
            return &(node_from->paths[i]);
    
    return NULL;
}

void graph_make_existing_path_two_way(graph_t graph, unsigned node_index, unsigned connection){
    path_t path_to_connection= graph_get_path_for_node_index(&(graph->nodes[node_index]), connection);
    path_t path_to_node= graph_get_path_for_node_index(&(graph->nodes[connection]), node_index);

    if( path_to_node != NULL && path_to_connection != NULL) {
        path_to_connection->value= path_to_node->value;
    }
}

void graph_convert_directed_to_undirected(graph_t graph){
    for(int i= 0; i<graph->size; i++){
        for(int j= 0; j<graph->nodes[i].paths_count; j++)
            graph_make_existing_path_two_way(graph, graph->nodes[i].index, graph->nodes[i].paths[j].connection);
    }
}

void print_graph(graph_t graph){
  set_font(BLUE);
  set_font(BOLD);
  printf("\n");
  print_in_center("Graph");
  printf("\n");
  set_font(WHITE);
  set_font(BLUE);
  printf("    Nodes: %d \n", graph->size);
  printf("    Memory: %d size, %lu bytes per node, %lu bytes used \n\n",
  graph->memory_size,
  sizeof(*(graph->nodes)),
  graph->memory_size * sizeof(*(graph->nodes)));

  printf("Nodes:\n");
  node_t n;
  path_t p;
  for(int i=0; i<graph_size(graph); i++){
    n = graph_get_node_at_index(graph, i);
    printf("   %d) %d -> ", i, n->index);
    for(int j=0; j<graph_get_node_paths_count(n); j++){
      p = graph_get_path_at_index(n, j);
      printf("%d(%.4f)", p->connection, p->value);
      if(j != n->paths_count-1) printf(" - ");
    }
    printf("\n");
  }
  set_font(BLUE);
  set_font(BOLD);
  printf("\n");
  print_in_center("Graph");
  printf("\n");
  set_font(WHITE);
}
