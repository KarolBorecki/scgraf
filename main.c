#include <stdio.h>
#include <stdlib.h>

#include "printer/printer.h"
#include "errors/errors.h"
#include "graph/graph.h"
#include "algorithms/bfs.h"
#include "algorithms/dijkstra.h"
#include "reader/graph_generator.h"
#include "reader/user_input.h"
#include "reader/file_reader.h"
#include "solver/graph_solver.h"

void setup_menu(){
  initzialize_errors();
  initzialize_warnings();
}

graph_t get_graph_from_input(char* in){
  graph_t result;
  if(strcmp(in, "") != 0) result = get_graph_from_file(in);
  else {
    printf("TUTAJ WCZYTAMY Z KONSOLI narazie generuje\n");
    result = generate_graph(10);
  }

  return result;
}

//TODO obsluzyc bledy wywolan w solverze i generate_graph
int main(int argc, char** argv){
  graph_t graph;

  setup_menu();
  print_greetings();

  batch_arguments_t arg = get_batch_arguments(argc, argv);
  print_arguments(arg);

  if(arg->execute == UNKNOWN)
    print_help();

  if(arg->execute == GENERATE){
    generate_graph(arg->n);
    if(arg->from != VALUE_NOT_SPECIFIED || arg->to != VALUE_NOT_SPECIFIED)
      throw_warning(arg_bypasing_warning, "Some arguments are being bypassed, for graph generating I only need -x and -y [or -o, -n]!");
  } else graph = get_graph_from_input(arg->in);

  if(arg->execute == SHORTEST_PATH){
    solver_get_shortest_path(graph, arg->from, arg->to);
    if(arg->x != VALUE_NOT_SPECIFIED || arg->y != VALUE_NOT_SPECIFIED || arg->n != VALUE_NOT_SPECIFIED)
      throw_warning(arg_bypasing_warning, "Some arguments are being bypassed, for shortest path finding I only need -f and -t!");
  }
  else if(arg->execute == CHECK_CONSISTENCY){
    solver_check_graph_consistency(graph);
    if(arg->x != VALUE_NOT_SPECIFIED || arg->y != VALUE_NOT_SPECIFIED || arg->n != VALUE_NOT_SPECIFIED || arg->to != VALUE_NOT_SPECIFIED)
      throw_warning(arg_bypasing_warning, "Some arguments are being bypassed, for graph consistency check I only need -f [or -i]!");
  }
  else if(arg->execute == DIVIDE_GRAPH){
    solver_divide_graph_into_n_graphs(graph, arg->n);
    if(arg->x != VALUE_NOT_SPECIFIED || arg->y != VALUE_NOT_SPECIFIED || arg->from != VALUE_NOT_SPECIFIED || arg->to != VALUE_NOT_SPECIFIED)
      throw_warning(arg_bypasing_warning, "Some arguments are being bypassed, for graph dviding I only need -n [or -o, -i]!");
  }

  return 0;
}
