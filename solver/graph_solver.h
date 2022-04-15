#ifndef _SOLVER_H_
#define _SOLVER_H_

#include "../graph/graph.h"

void solver_get_shortest_path(graph_t graph, unsigned from, unsigned to);
void solver_check_graph_consistency(graph_t graph, unsigned start);
void solver_divide_graph_into_n_graphs(graph_t graph, unsigned divides);
void solver_graph_to_file(graph_t graph, char * out_file);
graph_t solver_generate_graph(unsigned width, unsigned height, double max_weight);
graph_t solver_generate_example_graph();
graph_t solver_get_graph_from_file(char* in);
void solver_graph_to_undirected(graph_t graph);
#endif /* _SOLVER_H_ */
