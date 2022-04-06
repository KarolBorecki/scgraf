#include <stdio.h>
#include <stdlib.h>

#include "FIFO/fifo.h"

int main(int argc, char** argv){
  printf("Hello World \n");

  fifo_t fifo = initzialize_fifo();

  for(int i=0; i<30; i++)
    push(fifo, i*i);

  for(int i=0; i<30; i++)
    printf("%d = %d \n", i, fifo->queue[i]);

  clean_fifo(fifo);

  return 1;
}
