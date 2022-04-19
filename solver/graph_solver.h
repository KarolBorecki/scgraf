#ifndef _SOLVER_H_
#define _SOLVER_H_

#include "../graph/graph.h"
#include "../data_manager/user_input.h"

void solver_get_shortest_path(graph_t graph, batch_arguments_t arg);
void solver_check_graph_consistency(graph_t graph, batch_arguments_t arg);
void solver_divide_graph_into_n_graphs(graph_t graph, batch_arguments_t arg);
void solver_graph_to_file(graph_t graph, batch_arguments_t arg);
graph_t solver_generate_graph(graph_t graph, batch_arguments_t arg);
graph_t solver_generate_example_graph(graph_t graph, batch_arguments_t arg);
graph_t solver_get_graph_from_file(graph_t graph, batch_arguments_t arg);
void solver_graph_to_undirected(graph_t graph, batch_arguments_t arg);
#endif /* _SOLVER_H_ */
