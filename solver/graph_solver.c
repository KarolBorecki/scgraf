#include "graph_solver.h"

#include "../graph/graph.h"
#include "../algorithms/bfs.h"
#include "../algorithms/dijkstra.h"
#include "../algorithms/graph_divider.h"
#include "../printer/printer.h"
#include "../data_manager/data_manager.h"
#include "../data_manager/graph_generator.h"

void solver_get_shortest_path(graph_t graph, unsigned from, unsigned to){
  print_shortest_path_greeting(from, to);
  get_shortest_distance_from_to(graph, from, to);
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

graph_t solver_generate_graph(unsigned width, unsigned height, double max_weight){
  print_graph_generating_greetings(width, height, max_weight);
  graph_t graph = generate_graph_mesh(width, height, max_weight);
  print_done_greeting();

  return graph;
}

graph_t solver_generate_example_graph(){
  print_graph_example_generating_greetings();
  graph_t graph = generate_example_graph();
  print_done_greeting();

  return graph;
}

graph_t solver_get_graph_from_file(char* in){
  print_get_graph_from_file_greeting();
  graph_t graph = get_graph_from_file(in);
  print_done_greeting();

  return graph;
}

void solver_graph_to_undirected(graph_t graph){
  print_convert_graph_to_undirected_greetings();
  graph_convert_directed_to_undirected(graph);
  print_done_greeting();
}
