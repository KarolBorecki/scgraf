#include "graph_generator.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "../utils/utils.h"
#include "../utils/config.h"
#include "../graph/graph.h"

graph_t generate_graph_mesh(unsigned width, unsigned height, double max_weight){
    srand(time(NULL));
    graph_t g= initzialize_graph_with_all_nodes(width * height);
    for(int i= 0; i < height; i++){
        for(int j= 0; j < width; j++){
            generate_add_nodes_to_graph(g, width, height, j, i, max_weight);
        }
    }
    graph_set_width_and_height(g, width, height);
    //graph_convert_directed_to_undirected(g);
    update_max_path_value(g);

    return g;
}

graph_t generate_graph_circle(int size){
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

graph_t generate_example_graph(void){
    graph_t g = initzialize_graph(9);
    g->width = 3;
    g->height = 3;
    g->max_path_value = 3;
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

graph_t generate_example_graph_2(void){
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


void generate_add_nodes_to_graph(graph_t graph, unsigned width, unsigned height, unsigned position_on_X_axis, unsigned position_on_Y_axis, double max_weight){
    unsigned node_index= position_on_Y_axis * width + position_on_X_axis;

    node_t help= &(graph->nodes[node_index]);

    if(position_on_X_axis != 0)
        graph_add_path_two_way(graph, help, node_index - 1, rand_double_from_to(0., max_weight));
    if(position_on_X_axis != width - 1)
        graph_add_path_two_way(graph, help, node_index + 1, rand_double_from_to(0., max_weight));
    if(position_on_Y_axis != 0)
        graph_add_path_two_way(graph, help, node_index - width, rand_double_from_to(0., max_weight));
    if(position_on_Y_axis != height - 1)
        graph_add_path_two_way(graph, help, node_index + width, rand_double_from_to(0., max_weight));
}
