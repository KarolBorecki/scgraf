#ifndef _GRAPH_GENERATOR_H_
#define _GRAPH_GENERATOR_H_

#include "../graph/graph.h"

graph_t generate_graph_mesh(unsigned width, unsigned height, double max_weight);

graph_t generate_graph_circle(int size);

graph_t generate_example_graph(void);
graph_t generate_example_graph_2(void);

void generate_add_nodes_to_graph(graph_t graph, unsigned width, unsigned height, unsigned position_on_X_axis, unsigned position_on_Y_axis, double max_weight);

#endif /* _GRAPH_GENERATOR_H_ */
