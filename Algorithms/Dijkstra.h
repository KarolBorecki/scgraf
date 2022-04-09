#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include <float.h>
#include <limits.h>
#include "../FIFO/fifo.h"
#include "../graph/graph.h"

#define INVALID_NODE    UINT_MAX
#define INF             DBL_MAX



typedef struct table{
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
void print_shortest_path(table_t pointer_to_table, node_t start_node);

int comp_for_qsort(const void *a, const void *b);

double get_value_for_connection(graph_t, unsigned , unsigned);

#endif /* _DIJKSTRA_H_ */
