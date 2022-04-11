#include <stdio.h>
#include <stdlib.h>

#include "../graph/graph.h"
#include "../reader/graph_generator.h"
#include "../algorithms/BFS.h"
#include "../algorithms/Dijkstra.h"
#include "../reader/graph_generator.h"
#include "../solver/graph_solver.h"

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
    graph_t graph= generate_graph(20);//generate_example_graph();//
    print_graph(graph);
    printf("%d -> bfs\n", bfs(graph, graph->nodes[0].index));
    /*do{
        graph =
    }while(!bfs(graph, graph->nodes[0].index));*/
    printf("%d\n", bfs(graph, graph->nodes[0].index));
    table_t_p tab= run_dijkstra(graph, &(graph->nodes[0]));
    print_table(tab);
    //printf("\n%lf", print_shortest_path_from_to(tab, &(graph->nodes[0]), &(graph->nodes[8])));

    printf("\n\n===========Example graph:\n");
    graph = generate_example_graph();
    print_graph(graph);
    solver_check_graph_consistency(graph);
    printf("\n\n===========20 graph:\n");
    graph = generate_graph(20);
    //print_graph(graph);
    solver_check_graph_consistency(graph);

    printf("\n\n===========30 graph:\n");
    graph = generate_graph(30);
    //print_graph(graph);
    solver_check_graph_consistency(graph);

    printf("\n\n===========50 graph:\n");
    graph = generate_graph(50);
    //print_graph(graph);
    solver_check_graph_consistency(graph);

    printf("\n\n===========80 graph:\n");
    graph = generate_graph(80);
    //print_graph(graph);
    solver_check_graph_consistency(graph);

    printf("\n\n===========100 graph:\n");
    graph = generate_graph(100);
    //print_graph(graph);
    solver_check_graph_consistency(graph);

    printf("\n\n===========150 graph:\n");
    graph = generate_graph(150);
    //print_graph(graph);
    solver_check_graph_consistency(graph);
      return 1;
}
