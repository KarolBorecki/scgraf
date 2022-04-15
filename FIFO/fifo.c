#include "fifo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../errors/errors.h"
#include "../utils/utils.h"
#include "../printer/printer.h"

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

void enlarge_fifo(fifo_t fifo, unsigned enlrage_multiplier){
  fifo->queue = realloc_block(fifo->queue, fifo->memory_size * sizeof(*(fifo->queue)), enlrage_multiplier);
  fifo->memory_size *= enlrage_multiplier;
}

unsigned fifo_head_index(fifo_t fifo){
  return fifo->head;
}

unsigned fifo_queue_size(fifo_t fifo){
  return fifo->queue_size;
}

unsigned fifo_size(fifo_t fifo){
  return fifo->size;
}

int fifo_is_empty(fifo_t fifo){
  return 1-fifo_size(fifo);
}

int fifo_is_queue_empty(fifo_t fifo){
  return 1-fifo_queue_size(fifo);
}

int fifo_queue_contains_value(fifo_t fifo, unsigned value){
  return fifo_contains_value(fifo, value, 0, fifo_queue_size(fifo));
}

int fifo_head_contains_value(fifo_t fifo, unsigned value){
  return fifo_contains_value(fifo, value, 0, fifo_queue_size(fifo));
}

int fifo_contains_value(fifo_t fifo, unsigned value, unsigned search_start, unsigned search_end){
  return is_element_in_array(fifo->queue, search_start, search_end, value);
}

unsigned* fifo_head(fifo_t fifo){
  return fifo->queue + fifo_head_index(fifo);
}

unsigned fifo_peek(fifo_t fifo){
  return (fifo_is_empty(fifo) > 0 ? -1 : *fifo_head(fifo));
}

unsigned fifo_pop(fifo_t fifo){
  unsigned poped_value = fifo_peek(fifo);
  if(poped_value == -1) return -1;
  fifo->size--;
  fifo->head++;

  return poped_value;
}

unsigned fifo_get_at_index(fifo_t fifo, unsigned index){
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
  set_font(PINK);
  set_font(BOLD);
  printf("\n");
  print_in_center("FIFO");
  printf("\n");
  set_font(WHITE);
  set_font(PINK);
  printf("    Size: %d \n", fifo_size(fifo));
  printf("    Memory: %d elements, %lu bytes per element, %lu bytes used\n\n", fifo->memory_size, sizeof(*(fifo->queue)), sizeof(fifo) + fifo->memory_size*sizeof(*(fifo->queue)));
  printf("Queue:\n");
  for(int i=0; i<fifo_queue_size(fifo); i++){
    printf("    %d) %d", i, fifo_get_at_index(fifo, i));
    if(i == fifo_head_index(fifo)) printf(" <-HEAD");
    printf("\n");
  }
  set_font(PINK);
  set_font(BOLD);
  printf("\n");
  print_in_center("FIFO");
  printf("\n");
  set_font(WHITE);
}
