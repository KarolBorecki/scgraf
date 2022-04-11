#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "graph/graph.h"
#include "reader/graph_generator.h"
#include "algorithms/bfs.h"
#include "algorithms/dijkstra.h"
#include "reader/graph_generator.h"
#include "solver/graph_solver.h"
#include "printer/printer.h"
#include "errors/errors.h"
#include "reader/user_input.h"

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

graph_t generate_example_graph_circle(int size){
    graph_t graph= initzialize_graph(size);

    node_t help_n;
    help_n = graph_add_node(graph);
    graph_add_path(help_n, 1, 1.4);
    graph_add_path(help_n, size-1, 1.4);
    for(int i= 1; i<size-1; i++){
        help_n = graph_add_node(graph);
        graph_add_path(help_n, i+1, 1.4);
        graph_add_path(help_n, i-1, 1.4);
    }
    help_n = graph_add_node(graph);
    graph_add_path(help_n, 0, 1.4);
    graph_add_path(help_n, size-2, 1.4);
    return graph;
}

int main(int argc, char** argv){
  graph_t g = generate_example_graph_circle(atoi(argv[1]));
  solver_check_graph_consistency(g);
  clean_graph(g);
  return 1;
}
