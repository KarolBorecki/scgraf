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
void clean_fifo(fifo_t fifo);
void enlarge_fifo(fifo_t fifo, int enlrage_multiplier);

unsigned int fifo_head_index(fifo_t fifo);
unsigned int fifo_queue_size(fifo_t fifo);
unsigned int fifo_size(fifo_t fifo);
int fifo_is_empty(fifo_t fifo); /* returns > 0 if fifo is empty */

int fifo_queue_contains_value(fifo_t fifo, unsigned int value);
int fifo_head_contains_value(fifo_t fifo, unsigned int value);
int fifo_contains_value(fifo_t fifo, unsigned int value, unsigned int search_start, unsigned int search_end);

unsigned int fifo_peek(fifo_t fifo); /* return -1 if queue is empty */
unsigned int fifo_pop(fifo_t fifo); /* return -1 if queue is empty, queue = head*/
unsigned int fifo_get_at_index(fifo_t fifo, unsigned int index); /* return -1 if queue is empty, queue != head*/

void fifo_push(fifo_t fifo, unsigned int value);

void print_fifo(fifo_t fifo);

#endif /* _FIFO_H_ */
