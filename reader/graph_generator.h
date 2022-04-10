#ifndef _GRAPH_GENERATOR_H_
#define _GRAPH_GENERATOR_H_

#include "../graph/graph.h"

graph_t generate_graph(unsigned int size);
void generate_new_node(graph_t graph);
void generate_new_path(graph_t graph, node_t node);

#endif /* _GRAPH_GENERATOR_H_ */
