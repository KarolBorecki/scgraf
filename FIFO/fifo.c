#include <stdlib.h>
#include <string.h>

#include "fifo.h"

fifo_t initzialize_fifo(){
  fifo_t fifo = malloc(sizeof(*fifo));
  fifo->queue = malloc(START_QUEUE_SIZE * sizeof(*(fifo->queue)));
  fifo->head = fifo->queue;
  fifo->memory_size = START_QUEUE_SIZE;
  fifo->size = 0;

  return fifo;
}

void clean_fifo(fifo_t fifo){
  free(fifo->queue);
  free(fifo);
}

void enlarge_fifo(fifo_t fifo, int enlrage_multiplier){
  fifo->memory_size *= enlrage_multiplier;
  fifo->queue = realloc(fifo->queue, fifo->memory_size);
}

unsigned int size(fifo_t fifo){
  return fifo->size;
}

unsigned int peek(fifo_t fifo){
  return empty(fifo) > 0 ? -1 : *(fifo->head);
}

int empty(fifo_t fifo){
  return 1-fifo->size;
}

unsigned int pop(fifo_t fifo){
  unsigned int poped_value = peek(fifo);
  if(poped_value == -1) return -1;

  fifo->size--;
  fifo->head++; //TODO Hurrr durr marnowanie pamięci

  //To jest albo genialne albo bardzo głupie
  //W każdym razie bardzo szybkie do napisania xD
  //memcpy(fifo->head, fifo->head+1, fifo->size * sizeof(*(fifo->head)));

  return poped_value;
}

unsigned int get_at_index(fifo_t fifo, unsigned int index){
  if(empty(fifo) > 0 || index > fifo->queue_size) return -1;
  unsigned int got_value = *(fifo->queue+index);

  return got_value;
}

void push(fifo_t fifo, unsigned int value){
  if(size(fifo) >= fifo->memory_size)
    enlarge_fifo(fifo, FIFO_ENLARGE_MULTIPLIER);

  fifo->queue[fifo->size] = value;
  fifo->size++;
  fifo->queue_size++;
}
