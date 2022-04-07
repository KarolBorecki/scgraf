#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include <float.h>
#include <limits.h>

#define INVALID_NODE UINT_MAX

typedef struct table{
    unsigned int    size;
    unsigned int    *nodes_indexes;
    unsigned int    *previous_nodes;
    unsigned double *shortest_distances;
} *table_t;

void initialize_start_table(table_t, graph_t, node_t);
void print_table(table_t);
void free_table(table_t);

#endif /* _DIJKSTRA_H_ */
