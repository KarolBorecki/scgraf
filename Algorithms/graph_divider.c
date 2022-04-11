#include "graph_divider.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

graph_t divide_graph(graph_t graph, unsigned divides){
  unsigned graph_divide_point = rand() % graph_size(graph);
  printf("Dzielenie grafu wzgledem punktu: %d\n", graph_divide_point);
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
