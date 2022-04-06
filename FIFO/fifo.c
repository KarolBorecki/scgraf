#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void enlarge_fifo(fifo_t fifo, int enlrage_multiplier){
  fifo->real_size *= enlrage_multiplier;
  fifo->queue = realloc(fifo->queue, fifo->real_size);
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

unsigned int pop(fifo_t fifo){
  unsigned int poped_value = *(fifo->queue);

  fifo->size--;
  //To jest albo genialne albo bardzo głupie
  //W każdym razie bardzo szybkie do napisania xD
  memcpy(fifo->queue, fifo->queue+1, fifo->size * sizeof(*(fifo->queue)));

  return poped_value;
}

void push(fifo_t fifo, unsigned int value){
  if(size(fifo) >= fifo->real_size)
    enlarge_fifo(fifo, FIFO_ENLARGE_MULTIPLIER);

  fifo->queue[fifo->size] = value;
  fifo->size++;
}
