#ifndef _FIFO_H_
#define _FIFO_H_

#define START_QUEUE_SIZE 20
#define FIFO_ENLARGE_MULTIPLIER 2

typedef struct fifo{
  unsigned* queue;
  unsigned head;
  unsigned size;
  unsigned queue_size;
  unsigned memory_size;
} *fifo_t;

fifo_t initzialize_fifo();
void clean_fifo(fifo_t fifo);
void enlarge_fifo(fifo_t fifo, unsigned enlrage_multiplier);

unsigned fifo_head_index(fifo_t fifo);
unsigned fifo_queue_size(fifo_t fifo);
unsigned fifo_size(fifo_t fifo);
int fifo_is_empty(fifo_t fifo); /* returns > 0 if fifo is empty */

int fifo_queue_contains_value(fifo_t fifo, unsigned value);
int fifo_head_contains_value(fifo_t fifo, unsigned value);
int fifo_contains_value(fifo_t fifo, unsigned value, unsigned search_start, unsigned search_end);

unsigned* fifo_head(fifo_t fifo);
unsigned fifo_peek(fifo_t fifo); /* return -1 if queue is empty */
unsigned fifo_pop(fifo_t fifo); /* return -1 if queue is empty, queue = head*/
void fifo_push(fifo_t fifo, unsigned value);

unsigned fifo_get_at_index(fifo_t fifo, unsigned index); /* return -1 if queue is empty, queue != head*/

void print_fifo(fifo_t fifo);

#endif /* _FIFO_H_ */
