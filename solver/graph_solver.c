#include "graph_solver.h"

#include "../graph/graph.h"
#include "../algorithms/bfs.h"
#include "../algorithms/dijkstra.h"
#include "../algorithms/graph_divider.h"

void solver_get_shortest_path(graph_t graph, unsigned from, unsigned to){
  printf("SHORTEST PATH");
}

void solver_check_graph_consistency(graph_t graph){
  int consistent = bfs(graph, 0);
  if(consistent > 0) printf("GRAF SPOJNY!\n");
  else printf("GRAF niespojny!\n");
}

void solver_divide_graph_into_n_graphs(graph_t graph, unsigned divides){
  divide_graph(graph, divides);
}
