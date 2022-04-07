#include "BFS.h"

int bfs(graph_t graph, node_t start_node){
  fifo_t q = initzialize_fifo();
  push(q, start_node->index);

  node_t actual_node;
  while(empty(q) <= 0){
    actual_node = get_node_with_index(fifo, peek(q));
    for(int i=0; i<actual_node->paths_count; i++){
      unsigned int connection_index = actual_node->(paths+i)->connection->index;
      if(was_visited(q, node) <= 0) push(q, connection_index);
    }
    pop(q);
  }
}

int was_visited(fifo_t q, unsigned int node){
  //TODO implement in fifo head_index(q)
  for(int i=0; i<head_index(q); i++)
    if(node == get_at_index(q, i)) return 1;
  return 0;
}
