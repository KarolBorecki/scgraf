#ifndef _FIFO_H_
#define _FIFO_H_

#define START_QUEUE_SIZE 20
#define FIFO_ENLARGE_MULTIPLIER 2

typedef struct fifo{
  unsigned int* queue;
  unsigned int* head;
  unsigned int size;
  unsigned int queue_size;
  unsigned int memory_size;
} *fifo_t;

fifo_t initzialize_fifo();
void clean_fifo(fifo_t);
void enlarge_fifo(fifo_t, int);
unsigned int size(fifo_t);
int empty(fifo_t); /* returns > 0 if fifo is empty */

unsigned int peek(fifo_t); /* return -1 if queue is empty */
unsigned int pop(fifo_t); /* return -1 if queue is empty, queue = head*/
unsigned int get_at_index(fifo_t, unsigned int); /* return -1 if queue is empty, queue != head*/
void push(fifo_t, unsigned int);

#endif /* _FIFO_H_ */
