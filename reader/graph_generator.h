#ifndef _GRAPH_GENERATOR_H_
#define _GRAPH_GENERATOR_H_

#include "../graph/graph.h"

graph_t generate_graph(unsigned int size);

void generate_new_node(graph_t graph);
void generate_new_path(graph_t graph, node_t node);

graph_t generate_example_graph(void);
graph_t generate_example_graph_2(void);

graph_t generate_example_graph_circle(int size);
graph_t generate_example_graph_mesh(unsigned width, unsigned height, double max_weight);

#endif /* _GRAPH_GENERATOR_H_ */
