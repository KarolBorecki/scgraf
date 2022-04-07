#ifndef _BFS_H_
#define _BFS_H_

int bfs(graph_t, node_t);
int was_visited(fifo_t, unsigned int );
void add_connections_of_node_to_queue(fifo_t, node_t);
int is_all_nodes_visited(graph_t, fifo_t);


#endif /* _BFS_H_ */
