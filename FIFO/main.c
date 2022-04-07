#include <stdio.h>
#include <stdlib.h>

#include "FIFO/fifo.h"

int main(int argc, char** argv){
  printf("Hello World \n");

  fifo_t fifo = initzialize_fifo();

  for(int i=0; i<30; i++){
    printf("DODAJE na %d wartosc %d \n", i, i*i);
    push(fifo, i*i);
  }
  printf("\n===========\n");
  printf("===========\n");
  printf("===========\n\n");

  while(empty(fifo) <= 0){
    printf("QUEUE:\n");
    for(int i=0; i<fifo->queue_size; i++){
      printf("%d)   %d ", i, get_at_index(fifo, i));
      if(fifo->head-fifo->queue == i) printf("HEAD");
      printf("\n");
    }
    printf("UZYWAM POP: %d \n", pop(fifo));
    if(empty(fifo) <= 0)printf("Peek: %d \n", peek(fifo));
    printf("===========\n");
  }

  clean_fifo(fifo);

  return 1;
}
