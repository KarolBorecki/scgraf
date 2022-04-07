#include "BFS.h"

#include <stdio.h>

#include "../FIFO/fifo.h"
#include "../graph/graph.h"

int bfs(graph_t graph, unsigned int start_node_index){
  node_t start_node = get_node_with_index(graph, start_node_index);
  fifo_t q = initzialize_fifo();
  push(q, start_node->index);
  node_t actual_node;
  while(fifo_is_empty(q) <= 0){
    print_fifo(q);
    actual_node = get_node_with_index(graph, peek(q));
    add_connections_of_node_to_queue(q, actual_node);
    fifo_pop(q);
  }
  return is_all_nodes_visited(graph, q);
}

int was_visited(fifo_t q, unsigned int node){
  for(int i=0; i<fifo_head_index(q); i++)
    if(node == fifo_get_at_index(q, i)) return 1;
  return 0;
}

void add_connections_of_node_to_queue(fifo_t q, node_t node){
  for(int i=0; i<node->paths_count; i++){
    unsigned int connection_index = (node->paths+i)->connection;
    if(was_visited(q, connection_index) <= 0 && fifo_head_contains_value(q, connection_index) > 0)
      fifo_push(q, connection_index);
  }
}
//TODO it is O(n^2) - try to do it better
int is_all_nodes_visited(graph_t g, fifo_t q){
  //return fifo_queue_size(q) == 0 ? 1 : 0; /* this is probapbly enough, but more tests are needed */
  for(int i=0; i<fifo_queue_size(q); i++)
    if(was_visited(q, i) <= 0)
      return 0;
  return 1;
}
