#include "graph_solver.h"

#include "../graph/graph.h"
#include "../algorithms/bfs.h"
#include "../algorithms/dijkstra.h"
#include "../algorithms/graph_divider.h"
#include "../printer/printer.h"
#include "../utils/config.h"
#include "../data_manager/data_manager.h"
#include "../data_manager/graph_generator.h"

void solver_get_shortest_path(graph_t graph, batch_arguments_t arg){
  char msg[MAX_ERR_ADDITIONAL_MSG_LENGTH];
  print_shortest_path_greeting(arg->from, arg->to);
  if(arg->from < 0 || arg->from >= graph_size(graph)){
      sprintf(msg, "incorrect start node (node %d) in graph of size %d!\n", arg->from, graph_size(graph));
      throw_error_and_exit(invalid_value_error, msg, graph, arg);
  }
  if(arg->to < 0 || arg->to >= graph_size(graph)){
      sprintf(msg, "incorrect destination node (node %d) in graph of size %d!\n", arg->to, graph_size(graph));
      throw_error_and_exit(invalid_value_error, msg, graph, arg);
  }
  print_consistency_greeting(arg->to);
  int is_consistent = bfs(graph, arg->from);
  if(is_consistent <= 0)
    throw_error_and_exit(graph_error, "Graph is not consistant, You can not search for shortest path.", graph, arg);

  else print_graph_consistent_result(is_consistent);

  get_shortest_distance_from_to(graph, arg->from, arg->to, 1);
  print_done_greeting();
}

void solver_check_graph_consistency(graph_t graph, batch_arguments_t arg){
  print_consistency_greeting(arg->from);
  int consistent = bfs(graph, arg->from);
  print_done_greeting();
  print_graph_consistent_result(consistent);
}

void solver_divide_graph_into_n_graphs(graph_t graph, batch_arguments_t arg){
  print_graph_division_greeting(arg->n);
  if(arg->n > graph->size)
    throw_error_and_exit(invalid_value_error, "Division numbers is too big!", graph, arg);
  
  divide_graph(graph, arg->n);
  print_done_greeting();
}

void solver_graph_to_file(graph_t graph, batch_arguments_t arg){
  print_file_output_greetings(arg->out);
  print_graph_to_file(graph, arg->out);
  print_done_greeting();
}

graph_t solver_generate_graph(graph_t graph, batch_arguments_t arg){
  print_graph_generating_greetings(arg->x, arg->y, arg->max_path_value);
  graph_t g = generate_graph_mesh(arg->x, arg->y, arg->max_path_value);
  print_done_greeting();
  return g;
}

graph_t solver_generate_example_graph(graph_t graph, batch_arguments_t arg){
  print_graph_example_generating_greetings();
  graph_t g = generate_example_graph();
  print_done_greeting();
  return g;
}

graph_t solver_get_graph_from_file(graph_t graph, batch_arguments_t arg){
  print_get_graph_from_file_greeting();
  graph_t g = get_graph_from_file(arg->in);
  if(g == NULL)
    throw_error_and_exit(file_read_error, "Could not read graph from file, bye bye!", graph, arg);
  print_done_greeting();
  return g;
}

void solver_graph_to_undirected(graph_t graph, batch_arguments_t arg){
  print_convert_graph_to_undirected_greetings();
  graph_convert_directed_to_undirected(graph);
  print_done_greeting();
}
