#include <stdlib.h>

#include "fifo.h"

fifo_t initzialize_fifo(){
  fifo_t fifo = malloc(sizeof(*fifo));
  fifo->queue = malloc(START_QUEUE_SIZE * sizeof(*(fifo->queue)));
  fifo->real_size = START_QUEUE_SIZE;
  fifo->size = 0;

  return fifo;
}

void clean_fifo(fifo_t fifo){
  free(fifo->queue);
  free(fifo);
}

unsigned int size(fifo_t fifo){
  return fifo->size;
}

unsigned int peek(fifo_t fifo){
  return *(fifo->queue);
}

int empty(fifo_t fifo){
  return 1-fifo->size;
}

void pop(fifo_t fifo){
  //TODO
}

void push(fifo_t fifo, unsigned int value){
  //TODO
}
