#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../graph/graph.h"
#include "../reader/graph_generator.h"
#include "../Algorithms/BFS.h"
#include "../Algorithms/Dijkstra.h"
#include "../reader/graph_generator.h"
#include "../solver/graph_solver.h"
#include "../reader/file_reader.h"
#include "../reader/data_reader.h"

graph_t generate_ewidthample_graph(){
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

graph_t generate_ewidthample_graph_circle(int size){
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

graph_t generate_ewidthample_graph_2(){
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

graph_t generate_ewidthample_graph_mesh(){
    graph_t g = initzialize_graph(6);
    node_t help;

    //NODE 0
    help= graph_add_node(g);
    graph_add_path(help, 1, 1);
    graph_add_path(help, 3, 1.2);

    //NODE 1
    help= graph_add_node(g);
    graph_add_path(help, 0, 1);
    graph_add_path(help, 2, 1.2);

    //NODE 2
    help= graph_add_node(g);
    graph_add_path(help, 1, 1.2);
    graph_add_path(help, 5, 7.8);

    //NODE 3
    help= graph_add_node(g);
    graph_add_path(help, 0, 1.2);
    graph_add_path(help, 4, 3.4);

    //NODE 4
    help= graph_add_node(g);
    graph_add_path(help, 3, 3.4);

    //NODE 5
    help= graph_add_node(g);
    graph_add_path(help, 2, 7.8);

    return g;
}

int main(int argc, char** argv){
    graph_t graph= generate_ewidthample_graph_circle(20);//
    graph= generate_ewidthample_graph_2();
    solver_check_graph_consistency(graph);
    //print_graph(graph);

    printf("%d -> bfs\n", bfs(graph, graph->nodes[0].index));
    printf("%d\n", bfs(graph, graph->nodes[0].index));

    table_t_p tab= run_dijkstra(graph, &(graph->nodes[2]), BUBBLE, SHORTEST);
    print_table(tab);


    unsigned int width, height;
    graph= get_graph_from_file("../test_files/mygraph", &width, &height);
    print_graph(graph);

    graph_t graph_mesh= generate_ewidthample_graph_mesh();

    printf("Dimensions of a graph: %d[width] x %d[height]\n", width, height);
    printf("%d <- is graph mesh\n", check_if_graph_is_mesh(graph, width, height));
    printf("Dimensions of a graph: %d[width] x %d[height]\n", height, width);
    printf("%d <- is graph mesh\n", check_if_graph_is_mesh(graph, height, width));
    printf("Dimensions of a graph: %d[width] x %d[height]\n", 3, 2);
    printf("%d <- is graph mesh\n", check_if_graph_is_mesh(graph_mesh, 3, 2));
    printf("Dimensions of a graph: %d[width] x %d[height]\n", 2, 3);
    printf("%d <- is graph mesh\n", check_if_graph_is_mesh(graph_mesh, 2, 3));
    return 1;
}
