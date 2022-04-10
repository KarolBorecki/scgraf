#include "dijkstra.h"

table_t_p initialize_start_table(graph_t graph, node_t start_node){
    table_t_p table_p= malloc(graph->size * sizeof(*table_p));
    table_p->size= graph->size;
    table_p->elements= malloc(graph->size * sizeof(*table_p->elements));

    for(int i= 0; i<table_p->size; i++) {
        if(graph->nodes[i].index != start_node->index)
            table_p->elements[i].shortest_distances= INF;
        else
            table_p->elements[i].shortest_distances= 0;
        table_p->elements[i].previous_nodes = INVALID_NODE;
        table_p->elements[i].node_index= i;
    }

    return table_p;
}

void print_table(table_t_p table){
    fprintf(stdout, "\n=======DIJKSTRA' S TABLE========\n\n"
                    "NODE_index\tSHORTEST_PATH\tPREV_NODE\n");
    for(int i= 0; i<table->size; i++)
        fprintf(stdout, "%d\t\t\t%lf\t\t\t%d\n"
                , table->elements[i].node_index
                , table->elements[i].shortest_distances
                , table->elements[i].previous_nodes);
}

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
        for(unsigned j= 0; j<help->paths_count; j++) {
                double val= help->paths[j].value;
                if (val + table->elements[current_vertex].shortest_distances < table->elements[help->paths[j].connection].shortest_distances){
                    table->elements[help->paths[j].connection].shortest_distances= val + table->elements[current_vertex].shortest_distances;
                    table->elements[help->paths[j].connection].previous_nodes= current_vertex;
                }

        }
        if(popped_from_que != table->size)
            sort_que(que_to_visit, start_node->index, table);
    }

    return table;

}

void free_table(table_t_p table){
    free(table->elements);
    free(table);
}

void sort_que(fifo_t que, unsigned start, table_t_p tab){
    for(int i= start; i<que->size; i++){
        for(int j= i+1; j<que->size; j++){
            if(tab->elements[que->queue[i]].shortest_distances > tab->elements[que->queue[j]].shortest_distances)
                swap_elements(&que->queue[i], &que->queue[j]);
        }
    }
}

void swap_elements(unsigned *p1, unsigned int *p2){
    unsigned p3= *p1;
    *p1= *p2;
    *p2= p3;
}

//start_node must be the same node, that Dijkstra' s table was created for
void print_shortest_path_from_to(table_t_p table, node_t start_node, node_t destination_node){
    if(start_node->index == destination_node->index) {
        printf("Ur at your destination node!\n");
        return;
    }
    unsigned int i= destination_node->index;
    printf("\nPATH FROM VERTEX: [%d] to VERTEX: [%d]\n"
           "%d->%d", start_node->index, destination_node->index, i, table->elements[i].previous_nodes);
    i= table->elements[i].previous_nodes;
    for(; i != start_node->index; i= table->elements[i].previous_nodes){
        printf("->%d", table->elements[i].previous_nodes);
    }
}
