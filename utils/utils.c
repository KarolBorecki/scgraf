#include "utils.h"

#include "../errors/errors.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

void* realloc_block(void* ptr, size_t ptr_size, unsigned enlarger_muliplier){
  void* new_p = malloc(ptr_size * enlarger_muliplier);
  if(new_p == NULL)
    throw_error(memory_error, "The memory block could not be reserved!");
  memcpy(new_p, ptr, ptr_size);

  free(ptr);
  return new_p;
}

int is_element_in_array(unsigned* array, unsigned search_start, unsigned search_end, unsigned element){
  for(int i=search_start; i<search_end; i++)
    if(array[i] == element) return 1;
  return 0;
}

void swap_elements(unsigned *p1, unsigned *p2){
    unsigned p3= *p1;
    *p1= *p2;
    *p2= p3;
}

double rand_double_from_to(double min, double max){
    srand(time(NULL));
    double value = min + ((double) rand() / (double)RAND_MAX) * max;
    return value;
}
