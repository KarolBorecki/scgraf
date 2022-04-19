#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

#include "../FIFO/fifo.h"
#include "../graph/graph.h"
#include "../utils/utils.h"
#include "../utils/config.h"

typedef struct dijkstra_data{
    unsigned int    node_index;
    unsigned int    previous_nodes;
    double          shortest_distances;
} *dijkstra_data_t;

typedef struct dijkstra_table{
    dijkstra_data_t elements;
    unsigned int    size;
} *dijkstra_table_t;

dijkstra_table_t initialize_dijkstra_table(graph_t, node_t);
void free_dijkstra_table(dijkstra_table_t);

dijkstra_table_t dijkstra(graph_t graph, node_t start_node);

void set_fifo_head(fifo_t fifo, dijkstra_table_t tab);
void bsort_que(fifo_t que, unsigned start, dijkstra_table_t tab);

void get_shortest_distance_from_to(graph_t graph, unsigned start_node_index, unsigned destination_node_index, int print_in_terminal);

//start_node must be the same node, that Dijkstra' s table was created for
void print_shortest_path_from_to(dijkstra_table_t table, node_t start_node, node_t destination_node);
void print_dijkstra_table(dijkstra_table_t pointer_to_table);

#endif /* _DIJKSTRA_H_ */
