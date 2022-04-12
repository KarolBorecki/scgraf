#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

#include "../FIFO/fifo.h"
#include "../graph/graph.h"
#include "../utils/utils.h"

#define INVALID_NODE    UINT_MAX
#define INF             DBL_MAX
#define ZERO            0
#define BUBBLE          1
#define QUICK           2
#define longest         1
#define SHORTEST        0

typedef struct table{
    unsigned int    node_index;
    unsigned int    previous_nodes;
    double          shortest_distances;
} *table_t;

typedef struct table_pointer{
    table_t elements;
    unsigned int    size;
} *table_t_p;

table_t_p initialize_start_table(graph_t, node_t, unsigned mode_2);
void print_table(table_t_p pointer_to_table);
void free_table(table_t_p);

table_t_p run_dijkstra(graph_t graph_to_analyze, node_t start_node, unsigned mode, unsigned mode_2);
//BUBBLE- with bubblesorting
//QUCIK - with quicksort
//0     - no sorting
double print_shortest_path_from_to(table_t_p table, node_t start_node, node_t destination_node);

void bsort_que(fifo_t que, unsigned start, table_t_p tab, unsigned mode_2);
void qsort_que(unsigned * que, unsigned start, unsigned end, table_t_p tab);
unsigned partition (unsigned * arr, unsigned low, unsigned high, table_t_p tab);

#endif /* _DIJKSTRA_H_ */
