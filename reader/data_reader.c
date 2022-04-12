#include "../reader/data_reader.h"
//#include <stdio.h>

int check_if_graph_is_mesh(graph_t graph,unsigned dimension_width, unsigned dimension_height){
    for(int i= 0; i<dimension_height; i++){
        for(int j= 0; j<dimension_width; j++){
            unsigned current_node= i*dimension_width + j;
            //printf("i[%d] * j[%d] + j[%d] == %d < c_node\n", i, j, j, current_node);
            //printf("[%d] <- node [%d] <- paths count", graph->nodes[current_node].index, graph->nodes[current_node].paths_count);
            if(!is_node_mesh(&(graph->nodes[current_node]), dimension_width, graph->size-1))
                return 0;
        }
    }

    return 1;
}

int is_node_mesh(node_t node, unsigned dim_width, unsigned max_node_index){
    //printf("I got node: [%d] that has [%d] paths\n", node->index, node->paths_count);
    for(int i= 0; i < node->paths_count; i++){
        //printf("\tchecking connection: [%d]\n", node->paths[i].connection);
        if( node->paths[i].connection >= 0
        &&  node->paths[i].connection <= max_node_index
        &&  node->paths[i].connection != node->index - 1
        &&  node->paths[i].connection != node->index + 1
        &&  node->paths[i].connection != node->index - dim_width
        &&  node->paths[i].connection != node->index + dim_width
        ){
            return 0;
        }
    }
    return 1;
}