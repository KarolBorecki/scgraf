#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdlib.h>

void* realloc_block(void* ptr, size_t ptr_size, unsigned enlarger_muliplier);
int is_element_in_array(unsigned* array, unsigned search_start, unsigned search_end, unsigned element);
void swap_elements(unsigned *p1, unsigned *p2);
double rand_double_from_to(double min, double max);
unsigned pow_(unsigned x, unsigned y);
int is_str_blank(char* str); /* 1 if TRUE and 0 if FALSE */

#endif /* _UTILS_H_ */
