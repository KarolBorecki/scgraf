#ifndef _FIFO_H_
#define _FIFO_H_

#define START_QUEUE_SIZE 20

typedef struct fifo{
  unsigned int* queue;
  unsigned int size;
  unsigned int real_size;
} *fifo_t;

fifo_t initzialize_fifo();
void clean_fifo();
unsigned int size(fifo_t fifo);
int empty(fifo_t fifo); /* returns > 0 if fifo is empty */

unsigned int peek(fifo_t fifo);
void pop(fifo_t fifo);
void push(fifo_t fifo, unsigned int value);

#endif /* _FIFO_H_ */
