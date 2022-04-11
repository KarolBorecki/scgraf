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

graph_t generate_example_graph_2(){
    graph_t g = initzialize_graph(6);
    node_t help;

    //NODE 0
    help= graph_add_node(g);
    graph_add_path(help, 1, 0.7);

    //NODE 1
    help= graph_add_node(g);
    graph_add_path(help, 0, 0.7);
    graph_add_path(help, 3, 1.2);

    //NODE 2
    help= graph_add_node(g);
    graph_add_path(help, 3, 3.4);
    graph_add_path(help, 4, 7.8);
    graph_add_path(help, 5, 1.2);

    //NODE 3
    help= graph_add_node(g);
    graph_add_path(help, 1, 1.2);
    graph_add_path(help, 2, 3.4);
    graph_add_path(help, 3, 9.0);

    //NODE 4
    help= graph_add_node(g);
    graph_add_path(help, 2, 7.8);

    //NODE 5
    help= graph_add_node(g);
    graph_add_path(help, 3, 3.4);
    graph_add_path(help, 2, 1.2);

    return g;
}

int main(int argc, char** argv){
    graph_t graph= generate_example_graph_circle(20);//
    graph= generate_example_graph_2();
    solver_check_graph_consistency(graph);
    //print_graph(graph);

    printf("%d -> bfs\n", bfs(graph, graph->nodes[0].index));
    printf("%d\n", bfs(graph, graph->nodes[0].index));

    table_t_p tab= run_dijkstra(graph, &(graph->nodes[2]), BUBBLE, SHORTEST);
    print_table(tab);

    /*for(int i= 0; i<tab->size; i++) {
        double len= print_shortest_path_from_to(tab, &(graph->nodes[0]), &(graph->nodes[i]));
        printf("\nlen of that path = %lf\n", tab->elements[i].shortest_distances);
    }*/

    //for(int i= 0; i<9; i++)
        //printf("\n%lf", print_shortest_path_from_to(tab, &(graph->nodes[0]), &(graph->nodes[i])));

    /*printf("\n\n===========Example graph:\n");
    graph = generate_example_graph();
    print_graph(graph);
    solver_check_graph_consistency(graph);

    printf("\n\n===========20 graph:\n");
    graph = generate_graph(20);
    //print_graph(graph);
    solver_check_graph_consistency(graph);

    *//*printf("\n\n===========30 graph:\n");
    graph = generate_graph(30);
    //print_graph(graph);
    solver_check_graph_consistency(graph);*//*

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
    solver_check_graph_consistency(graph);*/
    return 1;
}
