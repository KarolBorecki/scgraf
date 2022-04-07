#include "Dijkstra.h"
#include <stdio.h>

#include "../FIFO/fifo.h"
#include "../graph/graph.h"



void initialize_start_table(table_t table, graph_t graph, node_t start_node){
    table->size= graph->size;

    table->nodes_indexes= malloc(sizeof(graph->nodes->index) * graph->size);
    if(table->nodes_indexes == NULL)
        return;

    table->previous_nodes= malloc(sizeof(graph->nodes->index) * graph->size);
    if(table->previous_nodes == NULL)
        return;

    table->shortest_distances= malloc(sizeof(graph->nodes->paths->value) * graph->size);
    if(table->shortest_distances == NULL)
        return;

    for(int i= 0; i<graph->size; i++) {
        if(graph->nodes[i].index != start_node->index)
            table->shortest_distances[i] = DBL_MAX;
        else
            table->shortest_distances[i] = 0;
        table->nodes_indexes[i] = graph->nodes[i].index;
        table->previous_nodes[i] = INVALID_NODE;
    }
}

void print_table(table_t table){
    fprintf(stdout, "\n=======DIJKSTRA' S TABLE========\n\n"
                    "NODE_index\tSHORTEST_PATH\tPREV_NODE\n");
    for(int i= 0; i<table->size; i++)
        fprintf(stdout, "%d\t%lf\t%d",
                        table->nodes_indexes[i],
                        table->shortest_distances[i],
                        table->previous_nodes[i]);
}

void free_table(table_t table){
    free(table->shortest_distances);
    free(table->previous_nodes);
    free(table->nodes_indexes);

    free(table);
}
