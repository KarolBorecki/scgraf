#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../graph/graph.h"
#include "../reader/graph_generator.h"
#include "../algorithms/bfs.h"
#include "../algorithms/dijkstra.h"
#include "../reader/graph_generator.h"
#include "../solver/graph_solver.h"
#include "../reader/file_reader.h"
#include "../reader/data_reader.h"

int main(int argc, char** argv){
    graph_t graph= generate_example_graph_circle(20);//
    graph= generate_example_graph_2();
    solver_check_graph_consistency(graph);
    //print_graph(graph);

    printf("%d -> bfs\n", bfs(graph, graph->nodes[0].index));
    printf("%d\n", bfs(graph, graph->nodes[0].index));

    table_t_p tab= run_dijkstra(graph, &(graph->nodes[2]), BUBBLE, SHORTEST);
    print_table(tab);


    unsigned int width, height;
    graph= get_graph_from_file("../test_files/mygraph", &width, &height);
    print_graph(graph);
    tab= run_dijkstra(graph, &(graph->nodes[9]), BUBBLE, SHORTEST);
    print_table(tab);

    graph_t graph_mesh= generate_example_graph_mesh(3, 2);

    printf("Dimensions of a graph: %d[width] x %d[height]\n", width, height);
    printf("%d <- is graph mesh\n", check_if_graph_is_mesh(graph, width, height));
    printf("Dimensions of a graph: %d[width] x %d[height]\n", height, width);
    printf("%d <- is graph mesh\n", check_if_graph_is_mesh(graph, height, width));
    printf("Dimensions of a graph: %d[width] x %d[height]\n", 3, 2);
    printf("%d <- is graph mesh\n", check_if_graph_is_mesh(graph_mesh, 3, 2));
    printf("Dimensions of a graph: %d[width] x %d[height]\n", 2, 3);
    printf("%d <- is graph mesh\n", check_if_graph_is_mesh(graph_mesh, 2, 3));

    graph_mesh= generate_example_graph_mesh(3, 2);
    print_graph(graph_mesh);
    printf("%d [is mesh]\n", check_if_graph_is_mesh(graph_mesh, 3, 2));

    graph_t new_graph= generate_example_graph();
    print_graph(graph);
    //graph_make_existing_path_two_way(new_graph, 7, 8);
    graph_convert_directed_to_undirected(graph);
    print_graph(graph);

    new_graph = generate_example_graph_mesh(10, 10);
    printf("\n%lf [path len]", get_shortest_distance_from_to(new_graph, 10, 78));
    return 1;
}
