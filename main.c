#include <stdio.h>
#include <stdlib.h>

#include "FIFO/fifo.h"

int main(int argc, char** argv){
  printf("Hello World \n");

  fifo_t fifo = initzialize_fifo();

  printf("Is empty: %d \n\n", empty(fifo));

  for(int i=0; i<30; i++)
    push(fifo, i*i);

  printf("Is empty: %d \n\n", empty(fifo));
  printf("Peek: %d \n", peek(fifo));

  // for(int i=0; i<size(fifo); i++)
  //   printf("%d = %d \n", i, fifo->queue[i]);

  while(empty(fifo) <= 0){
    printf("%d \n", pop(fifo));
    printf("Peek: %d \n", peek(fifo));
    printf("===========\n");
  }

  clean_fifo(fifo);

  return 1;
}
