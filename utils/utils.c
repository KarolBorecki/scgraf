#include "utils.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../errors/errors.h"
#include "config.h"

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
    if(array[i] == element) return TRUE;
  return FALSE;
}

void swap_elements(unsigned *p1, unsigned *p2){
    unsigned p3= *p1;
    *p1= *p2;
    *p2= p3;
}

double rand_double_from_to(double min, double max){
    double value = min + ((double) rand() / (double)RAND_MAX) * max;
    return value;
}

unsigned pow_(unsigned x, unsigned y){
    unsigned res= 1;
    if(y == 0 && x != 0)
        return 1;
    for(int i= 0; i<y; i++)
        res *= x;

    return res;
}

int is_str_blank(char* str){
  return str == NULL || strlen(str) == 0 || str[0] == '\0' ? TRUE : FALSE;
}
