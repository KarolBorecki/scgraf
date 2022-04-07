#include "BFS.h"

int bfs(graph_t graph, node_t start_node){
  fifo_t q = initzialize_fifo();
  push(q, start_node->index);

  node_t actual_node;
  while(empty(q) <= 0){
    actual_node = get_node_with_index(fifo, peek(q));
    add_connections_of_node_to_queue(q, actual_node);
    pop(q);
  }
}

int was_visited(fifo_t q, unsigned int node){
  for(int i=0; i<head_index(q); i++)
    if(node == get_at_index(q, i)) return 1;
  return 0;
}

void add_connections_of_node_to_queue(fifo_t q, node_t node){
  for(int i=0; i<node->paths_count; i++){
    unsigned int connection_index = node->(paths+i)->connection->index;
    if(was_visited(q, connection_index) <= 0) push(q, connection_index);
  }
}
