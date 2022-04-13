#include <stdio.h>
#include <string.h>

#include "tests/tests.h"

int main(int argc, char** argv){
  if(argc < 2) return 1;
  if(strcmp(argc[1], "fifo") == 1)
    test_fifo();
  else if(strcmp(argc[1], "graph") == 1)
    test_fifo();
  else if(strcmp(argc[1], "dijkstra") == 1)
    test_fifo();
  else if(strcmp(argc[1], "bfs") == 1)
    test_fifo();
  else if(strcmp(argc[1], "consistency") == 1)
    test_fifo();
  else return 1;
  return 0;
}
