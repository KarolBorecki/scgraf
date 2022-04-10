#include "printer.h"

#include <stdio.h>

void font_color_red(){
  printf("\033[0;31m");
}

void font_color_yellow(){
  printf("\033[0;33m");
}

void font_color_green(){
  printf("\033[0;32m");
}

void font_bold(){
  printf("\033[1m");
}

void font_color_reset(){
  printf("\033[0m");
}

void print_greetings(){
  font_bold();
  printf("=========scgraf======\n\n");
  font_color_reset();
}
void print_help(){
  printf("TODO ->>>> scrgraf help <<<<- TODO\n");
}
