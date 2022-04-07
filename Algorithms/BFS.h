#ifndef _BFS_H_
#define _BFS_H_

#include "../FIFO/fifo.h"
#include "../GraphHandler/GraphHandler.h"

int bfs(graph_t graph, node_t start_node);
int was_visited(fifo_t q, unsigned int node);


#endif /* _BFS_H_ */
