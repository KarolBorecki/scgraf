#include <stdio.h>
#include <stdlib.h>

#include "FIFO/fifo.h"

int main(int argc, char** argv){
  printf("Hello World \n");

  fifo_t fifo = initzialize_fifo();

  clean_fifo(fifo);

  return 1;
}
