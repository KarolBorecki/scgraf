#include "utils.h"

#include "../errors/errors.h"

#include <stdlib.h>
#include <string.h>

void* realloc_block(void* ptr, size_t ptr_size, unsigned enlarger_muliplier){
  void* new_p = malloc(ptr_size * enlarger_muliplier);
  if(new_p == NULL)
    throw_error(memory_error, "The memory block could not be reserved!");
  memcpy(new_p, ptr, ptr_size);

  free(ptr);
  return new_p;
}

void swap_elements(unsigned *p1, unsigned *p2){
    unsigned p3= *p1;
    *p1= *p2;
    *p2= p3;
}
