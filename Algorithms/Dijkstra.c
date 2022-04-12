#include "Dijkstra.h"

table_t_p initialize_start_table(graph_t graph, node_t start_node, unsigned mode_2){
    table_t_p table_p= malloc(graph->size * sizeof(*table_p));
    table_p->size= graph->size;
    table_p->elements= malloc(graph->size * sizeof(*table_p->elements));

    for(int i= 0; i<table_p->size; i++) {
        if(graph->nodes[i].index != start_node->index)
            table_p->elements[i].shortest_distances= (mode_2 == LONGEST ? ZERO : INF);
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

table_t_p run_dijkstra(graph_t graph, node_t start_node, unsigned mode, unsigned mode_2){
    unsigned int popped_from_que= 0, current_vertex;

    table_t_p table= initialize_start_table(graph, start_node, mode_2);
    fifo_t que_to_visit= initzialize_fifo();

    for(int i= 0; i<table->size; i++)
        fifo_push(que_to_visit, i);

    while(fifo_is_empty(que_to_visit) <= 0){
        //print_table(table);
        current_vertex = fifo_pop(que_to_visit);
        popped_from_que++;
        node_t help = graph_get_node_with_index(graph, current_vertex);
        for(unsigned j= 0; j<help->paths_count; j++) {
            double val= help->paths[j].value;
            if (mode_2 == LONGEST
                ?   val + table->elements[current_vertex].shortest_distances > table->elements[help->paths[j].connection].shortest_distances
                :   val + table->elements[current_vertex].shortest_distances < table->elements[help->paths[j].connection].shortest_distances
            ){
                    table->elements[help->paths[j].connection].shortest_distances= val + table->elements[current_vertex].shortest_distances;
                    table->elements[help->paths[j].connection].previous_nodes= current_vertex;
            }

        }
        if(mode == BUBBLE)
            bsort_que(que_to_visit, popped_from_que, table, mode_2);
        else if(mode == QUICK)
            qsort_que(que_to_visit->queue + fifo_head_index(que_to_visit), popped_from_que, table->size-1, table);
    }

    return table;

}

void free_table(table_t_p table){
    free(table->elements);
    free(table);
}

void bsort_que(fifo_t que, unsigned start, table_t_p tab, unsigned mode_2){
/*    printf("\n====QUE PRE SORT====\n");
    print_fifo(que);*/
    for(unsigned i= start; i<tab->size; i++){
        for(unsigned j= i+1; j<tab->size; j++){
            //printf("COMPARING: %lf [i] > %lf [j]\nRES: %d\n", tab->elements[que->queue[i]].shortest_distances, tab->elements[que->queue[j]].shortest_distances,tab->elements[que->queue[i]].shortest_distances > tab->elements[que->queue[j]].shortest_distances);
            if(mode_2 == LONGEST
            ?   tab->elements[que->queue[i]].shortest_distances < tab->elements[que->queue[j]].shortest_distances
            :   tab->elements[que->queue[i]].shortest_distances > tab->elements[que->queue[j]].shortest_distances
            ){
                swap_elements(&que->queue[i], &que->queue[j]);
            }

        }
    }
/*    printf("\n====QUE AFTER SORT====\n");
    print_fifo(que);*/
}

void qsort_que(unsigned * que, unsigned start, unsigned end, table_t_p tab){
    if (start < end){
        unsigned pi = partition(que, start, end, tab);

        qsort_que(que, start, pi - 1, tab);
        qsort_que(que, pi + 1, end, tab);
    }

}

unsigned partition (unsigned * arr, unsigned low, unsigned high, table_t_p tab)
{
    unsigned pivot = tab->elements[high].shortest_distances;    //ostatni element to pivot
    //porownywac elementy z tablicy arr bedziemy za
    //pomoca tab->elements[pivot].shortest_distances
    unsigned i = (low - 1);

    for (unsigned j = low; j <= high- 1; j++){
        if (tab->elements[j].shortest_distances < pivot){
            i++;
            swap_elements(&(arr[i]), &(arr[j]));
        }
    }
    swap_elements(&(arr[i+1]), &(arr[high]));
    return (i + 1);
}

//start_node must be the same node, that Dijkstra' s table was created for
double print_shortest_path_from_to(table_t_p table, node_t start_node, node_t destination_node){
    double path_len= 0.;
    if(start_node->index == destination_node->index) {
        printf("Ur at your destination node!\n");
        return path_len;
    }
    unsigned int i= destination_node->index;
    path_len += table->elements[i].shortest_distances;
    printf("\nPATH FROM VERTEX: [%d] to VERTEX: [%d]\n"
           "%d->%d", start_node->index, destination_node->index, i, table->elements[i].previous_nodes);
    for(i= table->elements[i].previous_nodes; i != start_node->index; i= table->elements[i].previous_nodes){
        printf("->%d", table->elements[i].previous_nodes);
        path_len += table->elements[i].shortest_distances;
    }

    return path_len;
}

double get_shortest_distance_from_to(graph_t graph, unsigned start_node, unsigned destination_node){
    char msg[MAXMSG];
    if(start_node < 0 || start_node > graph->size - 1){
        sprintf(msg, "incorrect start node in function get_shortest_distance_from_to()!\n");
        //throw_error(, msg);
        return -1;
    }
    if(destination_node < 0 || destination_node > graph->size - 1){
        sprintf(msg, "incorrect start node in function get_shortest_distance_from_to()!\n");
        //throw_error(, msg);
        return -1;
    }
    node_t  start=  &(graph->nodes[start_node]);
    node_t  end=    &(graph->nodes[destination_node]);
    double path_len;

    table_t_p dijkstras_table= initialize_start_table(graph, start, SHORTEST);
    dijkstras_table= run_dijkstra(graph, start, BUBBLE, SHORTEST);
    path_len = print_shortest_path_from_to(dijkstras_table, start, end);
    free_table(dijkstras_table);

    return path_len;
}