#include "bfs.h"

#include <stdio.h>

#include "../FIFO/fifo.h"
#include "../graph/graph.h"
#include "../utils/config.h"

int bfs(graph_t graph, unsigned start_node_index){
  node_t start_node = graph_get_node_at_index(graph, start_node_index);

  fifo_t q = initzialize_fifo();
  fifo_push(q, start_node->index);

  node_t actual_node;
  while(fifo_is_empty(q) == FALSE){
    actual_node = graph_get_node_at_index(graph, fifo_peek(q));
    bfs_add_distinct_connections_of_node_to_queue(q, actual_node);
    fifo_pop(q);
  }

  int result = bfs_is_all_nodes_visited(graph, q);

  clean_fifo(q);

  return result;
}

void bfs_add_distinct_connections_of_node_to_queue(fifo_t q, node_t node){
  for(int i=0; i<node->paths_count; i++){
    unsigned connection_index = graph_get_path_at_index(node, i)->connection;
    if(fifo_queue_contains_value(q, connection_index) == FALSE)
      fifo_push(q, connection_index);
  }
}

int bfs_is_all_nodes_visited(graph_t g, fifo_t q){
  return (fifo_queue_size(q) == graph_size(g)) ? TRUE : FALSE;
}
