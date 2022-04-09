#include "Dijkstra.h"
#include <stdio.h>
#include <stdlib.h>

#include "../FIFO/fifo.h"
#include "../graph/graph.h"

table_t_p initialize_start_table(graph_t graph, node_t start_node){
    table_t_p table_p= malloc(graph->size * sizeof(*table_p));
    table_p->size= graph->size;
    table_p->elements= malloc(graph->size * sizeof(*table_p->elements));

    for(int i= 0; i<table_p->size; i++) {
        if(graph->nodes[i].index != start_node->index)
            table_p->elements[i].shortest_distances= 10;
        else
            table_p->elements[i].shortest_distances= 0;
        table_p->elements[i].previous_nodes = INVALID_NODE;
    }

    return table_p;
}

void print_table(table_t_p table){
    fprintf(stdout, "\n=======DIJKSTRA' S TABLE========\n\n"
                    "NODE_index\tSHORTEST_PATH\tPREV_NODE\n");
    for(int i= 0; i<table->size; i++)
        fprintf(stdout, "%d\t\t\t%lf\t\t\t%d\n", i, table->elements[i].shortest_distances, table->elements[i].previous_nodes);
}

//TODO Finds path only from vertex 0
//Quicksort not working
table_t_p run_dijkstra(graph_t graph, node_t start_node){
    unsigned int popped_from_que= 0, current_vertex;

    table_t_p table= initialize_start_table(graph, start_node);
    fifo_t que_to_visit= initzialize_fifo();

    for(int i= 0; i<table->size; i++)
        fifo_push(que_to_visit, i);

    while(fifo_is_empty(que_to_visit) <= 0){
        print_table(table);
        current_vertex = fifo_pop(que_to_visit);
        popped_from_que++;
        node_t help = graph_get_node_with_index(graph, current_vertex);
        printf("\nNode: %d has connections to: \n", current_vertex);
        for(unsigned j= 0; j<help->paths_count; j++) {
                double val= help->paths[j].value;
                printf("\t Node %d with value %lf\n", help->paths[j].connection, help->paths[j].value);
                printf("%lf (val) + %lf (shortest distance) <(?) %lf(shortest path for %d)\n", val
                       ,    table->elements[current_vertex].shortest_distances//table->shortest_distances[current_vertex],
                       ,    table->elements[help->paths[j].connection].shortest_distances,
                            current_vertex);
                if (val + table->elements[current_vertex].shortest_distances < table->elements[help->paths[j].connection].shortest_distances){
                    table->elements[help->paths[j].connection].shortest_distances= val + table->elements[current_vertex].shortest_distances;
                    table->elements[help->paths[j].connection].previous_nodes= current_vertex;
                }

        }
        //if(popped_from_que != table->size)
            //qsort(table->elements + popped_from_que, table->size, sizeof(*table->elements), comp_for_qsort);
    }

    return table;

}

double get_value_for_connection(graph_t graph, unsigned current_vertex, unsigned connected_to){ //returns -1 if there is no connection
    ;
}

void free_table(table_t_p table){
    free(table->elements);
    free(table);
}

int comp_for_qsort(const void *a, const void *b){
    table_t a_p= (table_t) a;
    table_t b_p= (table_t) b;
    if(a_p->shortest_distances > b_p->shortest_distances)
        return 1;
    else if(a_p->shortest_distances == b_p->shortest_distances)
        return 0;
    else
        return -1;
}