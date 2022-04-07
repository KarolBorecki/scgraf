#ifndef _GRAPH_HANDLER_H_
#define _GRAPH_HANDLER_H_

typedef struct graph{
  node_t nodes;
  unsigned int size;
  unsigned int memory_size;
} *graph_t;

typedef struct node{
  path_t paths;
  unsigned int paths_count;
} *node_t;

typedef struct path{
  node_t connection;
  unsigned int value;
} *path_t;


#endif /* _GRAPH_HANDLER_H_ */
