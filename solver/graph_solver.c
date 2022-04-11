#include "graph_solver.h"

#include "../graph/graph.h"
#include "../algorithms/bfs.h"

void solver_get_shortest_path(graph_t graph, unsigned from, unsigned to){
  printf("SHORTEST PATH");
}

void solver_check_graph_consistency(graph_t graph){
  printf("solver_check_graph_consistency 1\n");
  int consistent = bfs(graph, 0);
  printf("solver_check_graph_consistency 2\n");
  if(consistent > 0) printf("GRAF SPOJNY!\n");
  else printf("GRAF niespojny!\n");
}

graph_t solver_divide_graph_into_n_graphs(graph_t graph, unsigned n){
  graph_t g = initzialize_graph(0);
  printf("DIVIDE GRAPH");
  return g;
}
