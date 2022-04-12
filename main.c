#include <stdio.h>
#include <stdlib.h>

#include "solver/graph_solver.h"
#include "reader/user_input.h"
#include "reader/file_reader.h"
#include "reader/graph_generator.h"
#include "graph/graph.h"
#include "printer/printer.h"

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
    printf("TUTAJ OBSLUZYC GENEROWANIE GRAFU O WIELKOSCI %d x %d (tak naprawde teraz to generuje przykladowy)\n", arg->x, arg->y); //TODO implemente generate_graph;
    graph = generate_example_graph();
  } else {
    printf("TUTAJ OBSLUZYC CZYTANIE GRAFU Z PLIKU %s (tak naprawde teraz to generuje przykladowy)\n", arg->in); //TODO implemente read_graph_from_file;
    graph = generate_example_graph();
    //graph = get_graph_from_input(arg->in);
  }

  if(arg->execute == SHORTEST_PATH)
    solver_get_shortest_path(graph, arg->from, arg->to);
  else if(arg->execute == CHECK_CONSISTENCY)
    solver_check_graph_consistency(graph, arg->from);
  else if(arg->execute == DIVIDE_GRAPH)
    solver_divide_graph_into_n_graphs(graph, arg->n);


  if(arg->execute == DIVIDE_GRAPH || arg->execute == GENERATE){
    if(strcmp(arg->out, "") != 0) printf("TUTAJ OBSLUZYC ZAPIS DO PLIKU!\n");
    else print_graph(graph);
  }

  return 0;
}
