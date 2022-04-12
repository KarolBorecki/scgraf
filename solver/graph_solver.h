#ifndef _SOLVER_H_
#define _SOLVER_H_

#include "../graph/graph.h"

#include <stdio.h>

void solver_get_shortest_path(graph_t graph, unsigned from, unsigned to);

void solver_check_graph_consistency(graph_t graph, unsigned start);

void solver_divide_graph_into_n_graphs(graph_t graph, unsigned divides);


#endif /* _SOLVER_H_ */
