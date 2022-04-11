#include "fifo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

fifo_t initzialize_fifo(){
  fifo_t fifo = malloc(sizeof(*fifo));
  fifo->queue = malloc(START_QUEUE_SIZE * sizeof(*(fifo->queue)));
  fifo->head = 0;
  fifo->memory_size = START_QUEUE_SIZE;
  fifo->size = 0;
  fifo->queue_size = 0;

  return fifo;
}

void clean_fifo(fifo_t fifo){
  free(fifo->queue);
  free(fifo);
}

void enlarge_fifo(fifo_t fifo, int enlrage_multiplier){
  fifo->memory_size *= enlrage_multiplier;
  fifo->queue = realloc(fifo->queue, fifo->memory_size);
  if(fifo->queue == NULL) printf("-----CO\n");
  print_fifo(fifo);
}

unsigned int fifo_head_index(fifo_t fifo){
  return fifo->head;
}

unsigned int fifo_queue_size(fifo_t fifo){
  return fifo->queue_size;
}

unsigned int fifo_size(fifo_t fifo){
  return fifo->size;
}

int fifo_is_empty(fifo_t fifo){
  return 1-fifo_size(fifo);
}

int fifo_is_queue_empty(fifo_t fifo){
  return 1-fifo_queue_size(fifo);
}

int fifo_queue_contains_value(fifo_t fifo, unsigned int value){
  return fifo_contains_value(fifo, value, 0, fifo_queue_size(fifo));
}

int fifo_head_contains_value(fifo_t fifo, unsigned int value){
  return fifo_contains_value(fifo, value, 0, fifo_queue_size(fifo));
}

int fifo_contains_value(fifo_t fifo, unsigned int value, unsigned int search_start, unsigned int search_end){
  for(int i=search_start; i<search_end; i++){
    if(fifo_get_at_index(fifo, i) == value) return 1;
  }
  return 0;
}

unsigned int* fifo_head(fifo_t fifo){
  return fifo->queue + fifo_head_index(fifo);
}

unsigned int fifo_peek(fifo_t fifo){
  return (fifo_is_empty(fifo) > 0 ? -1 : *fifo_head(fifo));
}

unsigned int fifo_pop(fifo_t fifo){
  unsigned int poped_value = fifo_peek(fifo);
  if(poped_value == -1) return -1;
  //printf("POP val(%d) size(%d) head(%d) maxsize(%d)\n", poped_value, fifo->size, fifo->head, fifo->queue_size);
  fifo->size--;
  fifo->head++;

  return poped_value;
}

unsigned int fifo_get_at_index(fifo_t fifo, unsigned int index){
  if(index >= fifo_queue_size(fifo)) return -1;
  return *(fifo->queue+index);
}

void fifo_push(fifo_t fifo, unsigned value){
  if(fifo_queue_size(fifo) >= fifo->memory_size)
    enlarge_fifo(fifo, FIFO_ENLARGE_MULTIPLIER);
  *(fifo->queue+fifo_queue_size(fifo)) = value;
  fifo->size++;
  fifo->queue_size++;
}

void print_fifo(fifo_t fifo){
  printf("\n=========FIFO=========\n\n");
  printf("    Size: %d \n", fifo_size(fifo));
  printf("    Memory: %d elements, %lu bytes per element, %lu bytes used\n\n", fifo->memory_size, sizeof(*(fifo->queue)), fifo->memory_size*sizeof(*(fifo->queue)));
  printf("Queue:\n");
  for(int i=0; i<fifo_queue_size(fifo); i++){
    printf("    %d) %d", i, fifo_get_at_index(fifo, i));
    if(i == fifo_head_index(fifo)) printf(" <-HEAD");
    printf("\n");
  }

  printf("\n\n=========FIFO=========\n\n");
}
