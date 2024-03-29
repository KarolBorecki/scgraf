#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/utils.h"
#include "../errors/errors.h"
#include "../printer/printer.h"

graph_t initzialize_graph(unsigned nodes_count){
  graph_t graph = calloc(1, sizeof(*graph));
  graph->size = 0;
  graph->nodes = calloc(nodes_count, sizeof(*(graph->nodes)));
  graph->memory_size = nodes_count;
  graph->max_path_value = 0;
  graph->height= 0;
  graph->width= 0;
  return graph;
}

graph_t initzialize_graph_with_all_nodes(unsigned nodes_count){
    graph_t graph = initzialize_graph(nodes_count);

    node_t help_node;
    for(int i= 0; i < nodes_count; i++)
        help_node= graph_add_node(graph);

    return graph;
}

void graph_set_width_and_height(graph_t graph, unsigned width, unsigned height){
  graph->height= height;
  graph->width= width;
}

void graph_set_max_path_value(graph_t graph, double value){
  graph->max_path_value = value;
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
  if(graph == NULL) return;
  for(int i=0; i<graph_size(graph); i++)
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
  if(index < 0 || index > graph_get_node_paths_count(node)){
    throw_error(memory_error, "Index out of bounds in node");
    return;
  }
  if(index < node->paths_count-1)
    memcpy(node->paths+index, node->paths+index+1, (node->paths_count-index-1) * sizeof(*(node->paths)));
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
        if(!graph_check_if_path_between_exists(graph, node->index, connection))//there is already path, so we dont add another one
            graph_add_path(&(graph->nodes[connection]), node->index, value);
}

//Function can be only used once all nodes in the graph were initialized
int graph_check_if_path_between_exists(graph_t graph, unsigned node_index, unsigned connection_index){
    node_t node_1= &(graph->nodes[node_index]);
    node_t node_2= &(graph->nodes[connection_index]);

    for(int i= 0; i<node_1->paths_count; i++)
        if(node_1->paths[i].connection == node_2->index)
            return 1;

    for(int i= 0; i<node_2->paths_count; i++)
        if(node_2->paths[i].connection == node_1->index)
            return 1;

    return 0;
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

double update_max_path_value(graph_t graph){
  int initialized= 0;
  for(int i= 0; i<graph->size; i++) {
      !initialized ? graph->nodes[i].paths_count ? graph->max_path_value = graph->nodes[i].paths[0].value && initialized++ : (0) : (0);
      for (int j = 0; j < graph->nodes[i].paths_count; j++)
          if (graph->nodes[i].paths[j].value > graph->max_path_value)
              graph->max_path_value = graph->nodes[i].paths[j].value;
  }

  return graph->max_path_value;
}

void graph_convert_directed_to_undirected(graph_t graph){
    for(int i= 0; i<graph->size; i++){
        for(int j= 0; j<graph->nodes[i].paths_count; j++)
            graph_make_existing_path_two_way(graph, graph->nodes[i].index, graph->nodes[i].paths[j].connection);
    }
}

unsigned graph_get_memory_size_for_paths(graph_t graph){
  unsigned size = 0;
  for(int i=0; i<graph_size(graph); i++)
    size += graph_get_node_at_index(graph, i)->paths_memory_size;
  return size;
}

void print_graph(graph_t graph, char* caption){
  set_font(LIGHT_BLUE);
  set_font(BOLD);
  printf("\n");
  print_in_center(caption);
  printf("\n");
  set_font(WHITE);
  set_font(LIGHT_BLUE);
  printf("    Nodes: %d \n", graph->size);
  printf("    Max path weight: %f \n\n", graph->max_path_value);
  printf("    Memory: %d slots for nodes, %d slots for paths\n",
  graph->memory_size,
  graph_get_memory_size_for_paths(graph));
  printf("    Memory: around %lu bytes per node and %lu bytes per path\n",
  sizeof(*(graph->nodes)),
  sizeof(*(graph->nodes->paths)));
  printf("    Memory: %lu bytes used \n\n",
  sizeof(*graph) +
  sizeof(*(graph->nodes)) *  graph->memory_size +
  sizeof(*(graph->nodes->paths)) * graph_get_memory_size_for_paths(graph));

  printf("Nodes:\n");
  node_t n;
  path_t p;
  for(int i=0; i<graph_size(graph); i++){
    n = graph_get_node_at_index(graph, i);
    printf("   %d) %d -> ", i, n->index);
    for(int j=0; j<graph_get_node_paths_count(n); j++){
      p = graph_get_path_at_index(n, j);
      printf("%d(", p->connection);
      if(p->value <= graph->max_path_value)
        set_font(RED);
      if(p->value < graph->max_path_value*2/3)
        set_font(YELLOW);
      if(p->value < graph->max_path_value/3)
        set_font(GREEN);
      printf("%.4f", p->value);
      set_font(LIGHT_BLUE);
      printf(")");
      if(j != n->paths_count-1) printf(" - ");
    }
    printf("\n");
  }
  set_font(LIGHT_BLUE);
  set_font(BOLD);
  printf("\n");
  print_in_center(caption);
  printf("\n");
  set_font(WHITE);
}
