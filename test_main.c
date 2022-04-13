#include <stdio.h>
#include <string.h>

#include "tests/tests.h"

int main(int argc, char** argv){
  if(argc < 2) return 1;
  if(strcmp(argv[1], "fifo") == 0)
    test_fifo();
  else if(strcmp(argv[1], "graph") == 0)
    test_graph();
  else if(strcmp(argv[1], "dijkstra") == 0)
    test_dijkstra();
  else if(strcmp(argv[1], "bfs") == 0)
    test_bfs();
  else if(strcmp(argv[1], "consistency") == 0)
    test_consistency();
  else return 1;
  return 0;
}
