#include "BFS.h"

#include <stdio.h>

#include "../FIFO/fifo.h"
#include "../graph/graph.h"

int bfs(graph_t graph, unsigned int start_node_index){
  node_t start_node = graph_get_node_with_index(graph, start_node_index);
  fifo_t q = initzialize_fifo();
  fifo_push(q, start_node->index);
  node_t actual_node;
  while(fifo_is_empty(q) <= 0){
    print_fifo(q);
    actual_node = graph_get_node_with_index(graph, fifo_peek(q));
    add_connections_of_node_to_queue(q, actual_node);
    fifo_pop(q);
  }
  return is_all_nodes_visited(graph, q);
}

void add_connections_of_node_to_queue(fifo_t q, node_t node){
  for(int i=0; i<node->paths_count; i++){
    unsigned int connection_index = (node->paths+i)->connection;
    if(fifo_queue_contains_value(q, connection_index) == 0)
      fifo_push(q, connection_index);
  }
}
//TODO it is O(n^2) - try to do it better
int is_all_nodes_visited(graph_t g, fifo_t q){
  //return fifo_queue_size(q) == 0 ? 1 : 0; /* this is probably enough, but more tests are needed */
  for(int i=0; i<fifo_queue_size(q); i++)
    if(fifo_contains_value(q, i, 0, fifo_head_index(q)) <= 0)
      return 0;
  return 1;
}
