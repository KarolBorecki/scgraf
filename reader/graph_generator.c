#include "../reader/graph_generator.h"
#include "../utils/utils.h"

#include <time.h>
#include <stdlib.h>

#define GENERATED_NODE_CONNECTIONS_COUNT 4
#define GENERATED_PATH_MAX_VALUE 10

graph_t generate_graph(unsigned int size){
  srand(time(NULL));

  graph_t graph = initzialize_graph(size);

  for(int i=0; i<size; i++)
    generate_new_node(graph);

  return graph;
}

void generate_new_node(graph_t graph){
  node_t new_node = graph_add_node(graph);
  for(int i=0; i<GENERATED_NODE_CONNECTIONS_COUNT; i++)
    generate_new_path(graph, new_node);
}

void generate_new_path(graph_t graph, node_t node){
  unsigned connection_index = node->index;
  while(connection_index == node->index && graph_get_connection_value(node, connection_index) == -1)
    connection_index = rand() % graph_memory_size(graph);
  graph_add_path(node, connection_index, rand() % 10);
}

graph_t generate_example_graph(void){
    graph_t g = initzialize_graph(9);
    g->width = 3;
    g->height = 3;
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
    graph_add_path(help_node, 8, 1.4);

    //Node 8
    help_node = graph_add_node(g);
    graph_add_path(help_node, 7, 2382.232);

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

graph_t generate_example_graph_mesh(unsigned width, unsigned height, double max_weight){
    srand(time(NULL));

    graph_t g = initzialize_graph(width * height);
    node_t help;
    unsigned node_to_the_right, node_to_the_left, node_below, node_up;

    for(int i= 0; i < height-1; i++){//Bottom layer below the loop
        for(int j= 0; j < width; j++){
            unsigned current_node = i*width + j;
            if(i == 0){//Top row
                if(j == 0){//left top corner
                    node_to_the_right= current_node + 1;
                    node_below= current_node + width;

                    help= graph_add_node(g);
                    graph_add_path(help, node_to_the_right, rand_double_from_to(0., max_weight));
                    graph_add_path(help, node_below, rand_double_from_to(0., max_weight));
                }else if(j == width - 1){//right top corner
                    node_to_the_left= current_node - 1;
                    node_below= current_node + width;

                    help= graph_add_node(g);
                    graph_add_path(help, node_to_the_left, rand_double_from_to(0., max_weight));
                    graph_add_path(help, node_below, rand_double_from_to(0., max_weight));
                }else{
                    node_to_the_left= current_node - 1;
                    node_to_the_right= current_node + 1;
                    node_below= current_node + width;

                    help= graph_add_node(g);
                    graph_add_path(help, node_to_the_left, rand_double_from_to(0., max_weight));
                    graph_add_path(help, node_to_the_right, rand_double_from_to(0., max_weight));
                    graph_add_path(help, node_below, rand_double_from_to(0., max_weight));
                }
            }else if(j == 0 || j == width - 1){//Middle rows, left and right coulmn
                if(j == 0){
                    node_to_the_right= current_node + 1;
                    node_below= current_node + width;
                    node_up= current_node - width;

                    help= graph_add_node(g);
                    graph_add_path(help, node_to_the_right, rand_double_from_to(0., max_weight));
                    graph_add_path(help, node_below, rand_double_from_to(0., max_weight));
                    graph_add_path(help, node_up, rand_double_from_to(0., max_weight));
                }else if(j == width - 1){
                    node_to_the_left= current_node + 1;
                    node_below= current_node + width;
                    node_up= current_node - width;

                    help= graph_add_node(g);
                    graph_add_path(help, node_to_the_left, rand_double_from_to(0., max_weight));
                    graph_add_path(help, node_below, rand_double_from_to(0., max_weight));
                    graph_add_path(help, node_up, rand_double_from_to(0., max_weight));
                }
            }
            else{//Middle vertices that have all conections
                node_to_the_left= current_node - 1;
                node_to_the_right= current_node + 1;
                node_below= current_node + width;
                node_up= current_node - width;

                help= graph_add_node(g);
                graph_add_path(help, node_to_the_left, rand_double_from_to(0., max_weight));
                graph_add_path(help, node_to_the_right, rand_double_from_to(0., max_weight));
                graph_add_path(help, node_below, rand_double_from_to(0., max_weight));
                graph_add_path(help, node_up, rand_double_from_to(0., max_weight));
            }
        }
    }
    //Bottom layer
    for(int i= 0; i<width; i++){
        unsigned current_node= (height - 1)*width + i;
        if(i == 0){
            node_to_the_right= current_node + 1;
            node_up= current_node - width;

            help= graph_add_node(g);
            graph_add_path(help, node_to_the_right, rand_double_from_to(0., max_weight));
            graph_add_path(help, node_up, rand_double_from_to(0., max_weight));
        }else if(i == width - 1){
            node_up= current_node - width;
            node_to_the_left= current_node - 1;

            help= graph_add_node(g);
            graph_add_path(help, node_to_the_left, rand_double_from_to(0., max_weight));
            graph_add_path(help, node_up, rand_double_from_to(0., max_weight));
        }else{
            node_up= current_node - width;
            node_to_the_left= current_node - 1;
            node_to_the_right= current_node + 1;

            help= graph_add_node(g);
            graph_add_path(help, node_to_the_left, rand_double_from_to(0., max_weight));
            graph_add_path(help, node_to_the_right, rand_double_from_to(0., max_weight));
            graph_add_path(help, node_up, rand_double_from_to(0., max_weight));
        }
    }

    graph_set_width_and_height(g, width, height);
    graph_set_max_path_value(g, max_weight);

    return g;
}
