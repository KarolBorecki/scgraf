#include "printer.h"

#include <stdio.h>

void set_font(char* font){
  printf("%s", font);
}

void print_greetings(){
  set_font(BOLD);
  printf("=========scgraf======\n\n");
  set_font(WHITE);
}
void print_help(){
  printf("TODO ->>>> scrgraf help <<<<- TODO\n");
}
