#ifndef _GRAPH_GENERATOR_H_
#define _GRAPH_GENERATOR_H_

#include "../graph/graph.h"

graph_t generate_graph(unsigned int size);
void generate_new_node(graph_t graph, unsigned int index);
void generate_new_path(node_t node);

#endif /* _GRAPH_GENERATOR_H_ */
