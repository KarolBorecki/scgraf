#include "GraphHandler.h"

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
