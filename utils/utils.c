#include "utils.h"

void swap_elements(unsigned *p1, unsigned *p2){
    unsigned p3= *p1;
    *p1= *p2;
    *p2= p3;
}
