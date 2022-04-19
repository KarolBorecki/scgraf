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
  -napisac help
*/

int main(int argc, char** argv){
  graph_t graph;
  graph = NULL;

  print_greetings();

  batch_arguments_t arg;
  arg = get_batch_arguments(argc, argv);
  check_arguments(arg);

  if(arg->execute == UNKNOWN){
    print_help();
    exit_program_normal(graph, arg);
  }

  print_arguments(arg);

  if(arg->execute == GENERATE){
    graph = solver_generate_graph(graph, arg);
  } else {
    if(strncmp(arg->in, BLANK_STR, strlen(BLANK_STR)) == 0)
      graph = solver_generate_example_graph(graph, arg);
    else
      graph = solver_get_graph_from_file(graph, arg);
  }

  if(arg->execute == SHORTEST_PATH)
    solver_get_shortest_path(graph, arg);
  else if(arg->execute == CHECK_CONSISTENCY)
    solver_check_graph_consistency(graph, arg);
  else if(arg->execute == DIVIDE_GRAPH)
    solver_divide_graph_into_n_graphs(graph, arg);
  else if(arg->execute == MAKE_UNDIRECTED)
    solver_graph_to_undirected(graph, arg);


  if(strncmp(arg->out, BLANK_STR, strlen(BLANK_STR)) != 0)
    solver_graph_to_file(graph, arg);

  if(arg->print == 1 ||
  ((arg->execute == DIVIDE_GRAPH || arg->execute == GENERATE) && strncmp(arg->out, BLANK_STR, strlen(BLANK_STR)) == 0))
    print_graph(graph, arg->execute == DIVIDE_GRAPH ? "Divided Graph" : (arg->execute == GENERATE ? "Generated Graph" : "Graph"));

  print_greetings();
  exit_program_normal(graph, arg);
  return 0;
}
