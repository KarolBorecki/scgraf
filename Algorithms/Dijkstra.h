#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include <float.h>
#include <limits.h>
#include "../FIFO/fifo.h"
#include "../graph/graph.h"

#define INVALID_NODE    UINT_MAX
#define INF             DBL_MAX

typedef struct table{
    unsigned int    size;
    unsigned int    *nodes_indexes;
    unsigned int    *previous_nodes;
    double *shortest_distances;
} *table_t;

table_t initialize_start_table(graph_t, node_t);
void print_table(table_t);
void free_table(table_t);

void dijkstra(table_t, graph_t, node_t);
void print_shortest_path(table_t, node_t);

#endif /* _DIJKSTRA_H_ */
