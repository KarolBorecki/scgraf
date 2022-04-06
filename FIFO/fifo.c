#include "fifo.h"

fifo_t initzialize_fifo(){
  fifo_t fifo = malloc(sizeof(*fifo));
  fifo->queue = malloc(START_QUEUE_SIZE * sizeof(*(fifo->queue)));
  fifo->real_size = START_QUEUE_SIZE;
  fifo->size = 0;

  return fifo;
}
