#include <stdio.h>
#include <stdlib.h>

#include "graph/graph.h"
#include "Algorithms/BFS.h"
#include "reader/graph_generator.h"

graph_t generate_example_graph(){
  graph_t g = initzialize_graph(9);

  node_t help_node;

  //Node 0
  help_node = graph_add_node(g);
  graph_add_path(help_node, 1, 1.4);

  //Node 1
  help_node = graph_add_node(g);
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
  graph_t graph = generate_graph(5);

  print_graph(graph);
  return 1;
}
