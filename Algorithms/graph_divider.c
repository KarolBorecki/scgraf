#include "graph_divider.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../utils/utils.h"

void divide_graph(graph_t graph, unsigned divides){
  srand(time(NULL));
  unsigned* graph_divide_points = malloc(divides * sizeof(*graph_divide_points));

  for(int i=0; i<divides-1; i++){
    do{
      graph_divide_points[i] = rand() % graph_size(graph);
      printf("losuje %d i dostalem = %d\n", i, graph_divide_points[i]);
    }while(is_element_in_array(graph_divide_points, 0, (i>0 ? i-1 : 0), graph_divide_points[i]) == 1);
    divide_graph_into_2(graph, graph_divide_points[i]);
  }
  free(graph_divide_points);
}

void divide_graph_into_2(graph_t graph, unsigned graph_divide_point){
  node_t node;
  node_t other_node;
  path_t path;
  path_t other_path;
  for(int i=0; i<=graph_divide_point; i++){
    node = graph_get_node_at_index(graph, i);
    for(int j=0; j<graph_get_node_paths_count(node); j++){
      path = graph_get_path_at_index(node, j);
      if(path->connection > graph_divide_point){
        other_node = graph_get_node_at_index(graph, path->connection);
        graph_remove_path_at_index(node, j);
        for(int k=0; k<graph_get_node_paths_count(other_node); k++){
          other_path = graph_get_path_at_index(other_node, k);
          if(other_path->connection == node->index){
            graph_remove_path_at_index(other_node, k);
            break;
          }
        }
      }
    }
  }
}
