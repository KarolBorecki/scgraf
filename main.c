#include <stdio.h>
#include <stdlib.h>

#include "GraphHandler/GraphHandler.h"

int main(int argc, char** argv){
  printf("Graph Handler Tester\n");

  graph_t g = initzialize_graph(5);

  node_t help_node;

  //Node 0
  help_node = add_node(g);
  add_path(help_node, 1, 0.1);
  add_path(help_node, 2, 0.4);
  add_path(help_node, 3, 0.23);

  //Node 1
  help_node = add_node(g);
  add_path(help_node, 0, 0.11);
  add_path(help_node, 2, 0.24);
  add_path(help_node, 3, 1.21243);

  //Node 2
  help_node = add_node(g);
  add_path(help_node, 3, 21.37);
  add_path(help_node, 0, 21.2345);
  add_path(help_node, 1, 1.314);

  //Node 3
  help_node = add_node(g);
  add_path(help_node, 2, 3.697);
  add_path(help_node, 0, 0.64689);
  add_path(help_node, 1, 3.2343);

  print_graph(g);
  return 1;
}
