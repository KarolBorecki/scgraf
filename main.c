#include <stdio.h>
#include <stdlib.h>

#include "solver/graph_solver.h"
#include "data_manager/user_input.h"
#include "data_manager/graph_generator.h"
#include "data_manager/data_manager.h"
#include "graph/graph.h"
#include "printer/printer.h"

/*
TODO:
  1. Testy
  2. makefile

  -Refaktoryzacja generowanie GRAFU
  -Uspojnic graph_generator.c
*/

int main(int argc, char** argv){
  graph_t graph;

  initzialize_errors();
  initzialize_warnings();
  print_greetings();

  batch_arguments_t arg = get_batch_arguments(argc, argv);
  check_arguments(arg);
  print_arguments(arg);

  if(arg->execute == UNKNOWN)
    print_help();

  if(arg->execute == GENERATE){
    graph = generate_example_graph_mesh(arg->x, arg->y, arg->max_path_value);
  } else {
    int width, height;
    if(strcmp(arg->in, "") == 0)
      graph = generate_example_graph();
    else
      graph = get_graph_from_file(arg->in);
  }

  if(arg->execute == SHORTEST_PATH)
    solver_get_shortest_path(graph, arg->from, arg->to);
  else if(arg->execute == CHECK_CONSISTENCY)
    solver_check_graph_consistency(graph, arg->from);
  else if(arg->execute == DIVIDE_GRAPH)
    solver_divide_graph_into_n_graphs(graph, arg->n);


  if(strcmp(arg->out, "") != 0)
    solver_graph_to_file(graph, arg->out);

  if(arg->print == 1 ||
  ((arg->execute == DIVIDE_GRAPH || arg->execute == GENERATE) && strcmp(arg->out, "") == 0))
    print_graph(graph, arg->execute == DIVIDE_GRAPH ? "Divided graph" : (arg->execute == GENERATE ? "Generated graph" : "Graph"));

  clean_graph(graph);
  free_arguments_struct(arg);
  free_errors();
  free_warnings();

  print_greetings();
  return 0;
}
