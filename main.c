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
/*
graph_t get_graph_from_input(char* in){
  graph_t result;
  if(strcmp(in, "") != 0) result = get_graph_from_file(in);
  else {
    printf("TUTAJ WCZYTAMY Z KONSOLI narazie generuje\n");
    result = generate_graph(10);
  }

  return result;
}
*/

graph_t generate_example_graph(){
    graph_t g = initzialize_graph(9);

    node_t help_node;

    //Node 0
    help_node = graph_add_node(g);
    graph_add_path(help_node, 1, 1.4);

    //Node 1
    help_node = graph_add_node(g);
    graph_add_path(help_node, 0, 1.4);
    graph_add_path(help_node, 2, 0.1);
    graph_add_path(help_node, 4, 2.3);

    //Node 2
    help_node = graph_add_node(g);
    graph_add_path(help_node, 1, 0.1);
    graph_add_path(help_node, 5, 0.1);

    //Node 3
    help_node = graph_add_node(g);
    graph_add_path(help_node, 4, 1.3);
    graph_add_path(help_node, 6, 0.1);

    //Node 4
    help_node = graph_add_node(g);
    graph_add_path(help_node, 1, 2.3);
    graph_add_path(help_node, 5, 2.0);
    graph_add_path(help_node, 7, 3.0);
    graph_add_path(help_node, 3, 1.3);

    //Node 5
    help_node = graph_add_node(g);
    graph_add_path(help_node, 2, 0.1);
    graph_add_path(help_node, 4, 2.0);

    //Node 6
    help_node = graph_add_node(g);
    graph_add_path(help_node, 3, 0.1);
    graph_add_path(help_node, 7, 0.2);

    //Node 7
    help_node = graph_add_node(g);
    graph_add_path(help_node, 4, 3.0);
    graph_add_path(help_node, 6, 0.2);
    graph_add_path(help_node, 8, 1.0);

    //Node 8
    help_node = graph_add_node(g);
    graph_add_path(help_node, 7, 1.0);

    return g;
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
    printf("GENERUJE GRAF O WIELKOSCI %d\n", arg->n); //TODO implemente generate_graph;
    if(arg->from != VALUE_NOT_SPECIFIED || arg->to != VALUE_NOT_SPECIFIED)
      throw_warning(arg_bypasing_warning, "Some arguments are being bypassed, for graph generating I only need -x and -y [or -o, -n]!");
  } else {
    printf("CZYTAM GRAF z pliku \n", arg->in); //TODO implemente read_graph_from_file;
    //graph = get_graph_from_input(arg->in);
  }

  graph = generate_example_graph();

  if(arg->execute == SHORTEST_PATH){
    if(arg->x != VALUE_NOT_SPECIFIED || arg->y != VALUE_NOT_SPECIFIED || arg->n != VALUE_NOT_SPECIFIED)
      throw_warning(arg_bypasing_warning, "Some arguments are being bypassed, \nfor shortest path finding I only need -f and -t!");
    solver_get_shortest_path(graph, arg->from, arg->to);
  }
  else if(arg->execute == CHECK_CONSISTENCY){
    if(arg->x != VALUE_NOT_SPECIFIED || arg->y != VALUE_NOT_SPECIFIED || arg->n != VALUE_NOT_SPECIFIED || arg->to != VALUE_NOT_SPECIFIED)
      throw_warning(arg_bypasing_warning, "Some arguments are being bypassed, \nfor graph consistency check I only need -f [or -i]!");
    solver_check_graph_consistency(graph, arg->from);
  }
  else if(arg->execute == DIVIDE_GRAPH){
    if(arg->x != VALUE_NOT_SPECIFIED || arg->y != VALUE_NOT_SPECIFIED || arg->from != VALUE_NOT_SPECIFIED || arg->to != VALUE_NOT_SPECIFIED)
      throw_warning(arg_bypasing_warning, "Some arguments are being bypassed, \nfor graph dviding I only need -n [or -o, -i]!");
    solver_divide_graph_into_n_graphs(graph, arg->n);
  }

  return 0;
}
