#include <stdio.h>
#include <stdlib.h>

#include "solver/graph_solver.h"
#include "reader/user_input.h"
#include "reader/file_reader.h"
#include "reader/graph_generator.h"
#include "graph/graph.h"
#include "printer/printer.h"

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
/*
TODO:
  1. Zapis do pliku
  2. Testy
  3. makefile
  4. graph_solver - uzupelnienie

-refaktoryzacja generowanie GRAFU
-config.h
*/

  if(arg->execute == GENERATE){
    graph = generate_example_graph_mesh(arg->x, arg->y, arg->max_path_value); //TODO delete
  } else {
    int width, height;
    graph = get_graph_from_file(arg->in); //TODO delete
  }

  if(arg->execute == SHORTEST_PATH)
    solver_get_shortest_path(graph, arg->from, arg->to);
  else if(arg->execute == CHECK_CONSISTENCY)
    solver_check_graph_consistency(graph, arg->from);
  else if(arg->execute == DIVIDE_GRAPH)
    solver_divide_graph_into_n_graphs(graph, arg->n);


  if(arg->execute == DIVIDE_GRAPH || arg->execute == GENERATE){
    if(strcmp(arg->out, "") != 0){
        solver_graph_to_file(graph, arg->out);
    }else
        print_graph(graph);
  }

  return 0;
}
