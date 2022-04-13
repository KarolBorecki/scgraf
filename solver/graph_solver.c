#include "graph_solver.h"

#include "../graph/graph.h"
#include "../algorithms/bfs.h"
#include "../algorithms/dijkstra.h"
#include "../algorithms/graph_divider.h"
#include "../printer/printer.h"
#include "../reader/file_printer.h"

void solver_get_shortest_path(graph_t graph, unsigned from, unsigned to){
  print_shortest_path_greeting(from, to);
  get_shortest_distance_from_to(graph, from, to);
  print_done_greeting();
}

void solver_check_graph_consistency(graph_t graph, unsigned start){
  print_consistency_greeting(start);
  int consistent = bfs(graph, start);
  print_graph_consistent_result(consistent);
  print_done_greeting();
}

void solver_divide_graph_into_n_graphs(graph_t graph, unsigned divides){
  print_graph_division_greeting(divides);
  divide_graph(graph, divides);
  print_done_greeting();
}

void solver_graph_to_file(graph_t graph, char * out_file){
  print_file_output_greetings(out_file);
  print_graph_to_file(graph, out_file);
  print_done_greeting();
}
