#ifndef _BFS_H_
#define _BFS_H_

#include "../FIFO/fifo.h"
#include "../graph/graph.h"

int bfs(graph_t graph, unsigned start_node_index);
void bfs_add_distinct_connections_of_node_to_queue(fifo_t q, node_t node);
int bfs_is_all_nodes_visited(graph_t g, fifo_t q);

#endif /* _BFS_H_ */
