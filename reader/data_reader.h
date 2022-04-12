#ifndef _SCGRAF_DATA_READER_H_
#define _SCGRAF_DATA_READER_H_

#include "../graph/graph.h"

int check_if_graph_is_mesh(graph_t graph,unsigned dimension_width, unsigned dimension_height);

int is_node_mesh(node_t node, unsigned dim_width, unsigned max_node_index);

#endif //SCGRAF_DATA_READER_H
