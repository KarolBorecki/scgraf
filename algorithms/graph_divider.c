#include "graph_divider.h"

#include <stdlib.h>
#include <time.h>

#include "../utils/utils.h"
#include "../errors/errors.h"

void divide_graph(graph_t graph, unsigned divides){
  srand(time(NULL));
  unsigned* graph_divide_points = malloc(divides * sizeof(*graph_divide_points));

  for(int i=0; i<divides-1; i++){
    do{
      graph_divide_points[i] = rand() % graph_size(graph);
    }while(is_element_in_array(graph_divide_points, 0, (i>0 ? i-1 : 0), graph_divide_points[i]) == 1);
    divide_graph_into_2(graph, graph_divide_points[i]);
  }

  free(graph_divide_points);
}

void divide_graph_into_2(graph_t graph, unsigned graph_divide_point){
  node_t node;
  unsigned con;
  for(int i=0; i<=graph_divide_point; i++){
    node = graph_get_node_at_index(graph, i);
    for(int j=0; j<graph_get_node_paths_count(node); j++){
      con = graph_get_path_at_index(node, j)->connection;
      if(con > graph_divide_point){
        graph_remove_path_at_index(node, j);
        graph_remove_path_with_connection(graph_get_node_at_index(graph, con), node->index);
      }
    }
  }
}
