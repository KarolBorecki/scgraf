#include <stdio.h>
#include <stdlib.h>

#include "graph/graph.h"
#include "Algorithms/BFS.h"

int main(int argc, char** argv){
  printf("Graph Handler Tester\n");

  graph_t g = initzialize_graph(5);

  node_t help_node;

  //Node 0
  help_node = graph_add_node(g);
  graph_add_path(help_node, 1, 0.1);
  //graph_add_path(help_node, 2, 0.4);
  graph_add_path(help_node, 3, 0.23);

  //Node 1
  help_node = graph_add_node(g);
  graph_add_path(help_node, 0, 0.11);
  //graph_add_path(help_node, 2, 0.24);
  graph_add_path(help_node, 3, 1.21243);

  //Node 2
  help_node = graph_add_node(g);

  //Node 3
  help_node = graph_add_node(g);
  graph_add_path(help_node, 2, 3.697);
  graph_add_path(help_node, 0, 0.64689);
  graph_add_path(help_node, 1, 3.2343);

  print_graph(g);
  printf("BFS = %d\n\n", bfs(g, 0));
  return 1;
}
