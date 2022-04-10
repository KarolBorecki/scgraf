#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include "../FIFO/fifo.h"
#include "../graph/graph.h"

#define INVALID_NODE    UINT_MAX
#define INF             DBL_MAX

typedef struct table{
    unsigned int    node_index;
    unsigned int    previous_nodes;
    double          shortest_distances;
} *table_t;

typedef struct table_pointer{
    table_t elements;
    unsigned int    size;
} *table_t_p;

table_t_p initialize_start_table(graph_t, node_t);
void print_table(table_t_p pointer_to_table);
void free_table(table_t_p);

table_t_p run_dijkstra(graph_t graph_to_analyze, node_t start_node);
double print_shortest_path_from_to(table_t_p table, node_t start_node, node_t destination_node);

void swap_elements(unsigned *pointer1, unsigned *pointer2);
void sort_que(fifo_t que, unsigned start, table_t_p tab);

#endif /* _DIJKSTRA_H_ */
