#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdlib.h>

void* realloc_block(void* ptr, size_t ptr_size, unsigned enlarger_muliplier);
int is_element_in_array(unsigned* array, unsigned search_start, unsigned search_end, unsigned element);
void swap_elements(unsigned *p1, unsigned *p2);

#endif /* _UTILS_H_ */
