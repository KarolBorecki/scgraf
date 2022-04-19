#include "dijkstra.h"

#include "bfs.h"
#include "../errors/errors.h"
#include "../printer/printer.h"

dijkstra_table_t initialize_dijkstra_table(graph_t graph, node_t start_node){
    dijkstra_table_t table_p= malloc(graph->size * sizeof(*table_p));
    table_p->size= graph->size;
    table_p->elements= malloc(graph->size * sizeof(*table_p->elements));

    for(int i= 0; i<table_p->size; i++) {
        if(graph->nodes[i].index != start_node->index)
            table_p->elements[i].shortest_distances = INF;
        else
            table_p->elements[i].shortest_distances = 0;
        table_p->elements[i].previous_nodes = INVALID_NODE;
        table_p->elements[i].node_index = i;
    }

    return table_p;
}

dijkstra_table_t dijkstra(graph_t graph, node_t start_node){
  unsigned int popped_from_que = 0, current_vertex;

  dijkstra_table_t table = initialize_dijkstra_table(graph, start_node);
  fifo_t que_to_visit= initzialize_fifo();

  for(int i= 0; i<graph_size(graph); i++)
    fifo_push(que_to_visit, i);

  int k = 0;
  while(fifo_is_empty(que_to_visit) <= 0){
    current_vertex = fifo_pop(que_to_visit);
    popped_from_que++;
    node_t node = graph_get_node_at_index(graph, current_vertex);
    for(unsigned j= 0; j<node->paths_count; j++){
      double val= node->paths[j].value;
      if (val + table->elements[current_vertex].shortest_distances < table->elements[node->paths[j].connection].shortest_distances){
          table->elements[node->paths[j].connection].shortest_distances= val + table->elements[current_vertex].shortest_distances;
          table->elements[node->paths[j].connection].previous_nodes= current_vertex;
      }
    }
    set_fifo_head(que_to_visit, table);
  }
  return table;
}

void set_fifo_head(fifo_t fifo, dijkstra_table_t tab){
  double min_distance = INF;
  double actual_distance = 0;
  unsigned min_distance_index = fifo_head_index(fifo);
  for(int i=fifo_head_index(fifo); i<fifo_queue_size(fifo); i++){
    actual_distance = tab->elements[fifo_get_at_index(fifo, i)].shortest_distances;
    if(actual_distance < min_distance){
      min_distance = actual_distance;
      min_distance_index = i;
    }
  }
  swap_elements(fifo->queue+fifo_head_index(fifo), fifo->queue+min_distance_index);
}

void bsort_que(fifo_t que, unsigned start, dijkstra_table_t tab){
  for(unsigned i= start; i<tab->size; i++)
    for(unsigned j= i+1; j<tab->size; j++)
      if(tab->elements[que->queue[i]].shortest_distances > tab->elements[que->queue[j]].shortest_distances)
        swap_elements(&que->queue[i], &que->queue[j]);
}

void get_shortest_distance_from_to(graph_t graph, unsigned start_node, unsigned destination_node){
    char msg[MAX_ERR_ADDITIONAL_MSG_LENGTH];

    if(start_node < 0 || start_node >= graph_size(graph)){
        sprintf(msg, "incorrect start node (node %d) in graph of size %d!\n", start_node, graph_size(graph));
        throw_error(invalid_value_error, msg);
    }

    if(destination_node < 0 || destination_node >= graph_size(graph)){
        sprintf(msg, "incorrect destination node (node %d) in graph of size %d!\n", destination_node, graph_size(graph));
        throw_error(invalid_value_error, msg);
    }
    print_consistency_greeting(start_node);
    int is_consistent = bfs(graph, start_node);
    if(is_consistent <= 0)
      throw_error(graph_error, "Graph is not consistant, You can not search for shortest path.");
    else print_graph_consistent_result(is_consistent);

    node_t start = &(graph->nodes[start_node]);
    node_t end = &(graph->nodes[destination_node]);
    double path_len;

    dijkstra_table_t dijkstras_table = initialize_dijkstra_table(graph, start);
    dijkstras_table = dijkstra(graph, start);

    print_shortest_path_from_to(dijkstras_table, start, end);

    free_dijkstra_table(dijkstras_table);
}

void free_dijkstra_table(dijkstra_table_t table){
    free(table->elements);
    free(table);
}

void print_shortest_path_from_to(dijkstra_table_t table, node_t start_node, node_t destination_node){
    double path_len= 0.;
    set_font(BOLD);
    set_font(LIGHT_BLUE);
    print_in_center("Shortest path");
    set_font(WHITE);
    set_font(LIGHT_BLUE);
    if(start_node->index == destination_node->index)
        throw_warning(data_formated_warning, "running dijkstra with start node exacly the same as destination node!");

    unsigned int i= destination_node->index;
    path_len += table->elements[i].shortest_distances;
    printf("\n    Path from node %d to node %d:\n"
           "      *node %d\n      *node %d", start_node->index, destination_node->index, i, table->elements[i].previous_nodes);
    for(i= table->elements[i].previous_nodes; i != start_node->index; i= table->elements[i].previous_nodes){
        printf("\n      *node %d", table->elements[i].previous_nodes);
        path_len += table->elements[i].shortest_distances;
    }
    printf("\n\n    Length of the following path = %.4lf\n\n", path_len);
    set_font(BOLD);
    set_font(LIGHT_BLUE);
    print_in_center("Shortest path");
    set_font(WHITE);
}

void print_dijkstra_table(dijkstra_table_t table){
  set_font(BOLD);
  set_font(PINK);
  print_in_center("Dijkstra's table");
  set_font(WHITE);
  set_font(PINK);
  fprintf(stdout, "Node index\tShortests path\tPrev node\n");
  for(int i= 0; i<table->size; i++)
      fprintf(stdout, "%d\t\t\t%lf\t\t\t%d\n"
              , table->elements[i].node_index
              , table->elements[i].shortest_distances > 9999999999.0 ? -999 : table->elements[i].shortest_distances
              , table->elements[i].previous_nodes);
  set_font(BOLD);
  set_font(PINK);
  print_in_center("Dijkstra's table");
  set_font(WHITE);
}
