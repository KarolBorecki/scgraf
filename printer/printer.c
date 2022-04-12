#include "printer.h"

#include <stdio.h>
#include <string.h>

#include "../errors/errors.h"

void set_font(char* font){
  printf("%s", font);
}

void print_in_center(char* str){
  unsigned len = CENTER_LEN - strlen(str);
  for(int i=0; i<len/2; i++)
    printf("=");
  printf("%s", str);
  for(int i=0; i<len/2; i++)
    printf("=");
  printf("\n");
}

void print_greetings(){
  set_font(BOLD);
  printf("\n");
  print_in_center("SCGRAF");
  printf("\n");
  set_font(WHITE);
}

void print_help(){
  set_font(BOLD);
  set_font(RED);
  printf("TODO ->>>> scrgraf help <<<<- TODO\n");
  set_font(WHITE);
  exit_program_normal();
}

void print_consistency_greeting(unsigned start){
  set_font(BOLD);
  printf("\nChecking graph consistency starting from node %d...\n\n", start);
  set_font(WHITE);
}

void print_shortest_path_greeting(unsigned from, unsigned to){
  set_font(BOLD);
  printf("\nLooking for shortest path from node %d to node %d...\n\n", from, to);
  set_font(WHITE);
}

void print_graph_division_greeting(unsigned divisions){
  set_font(BOLD);
  printf("\nDividing graph into %d subgraphs...\n\n", divisions);
  set_font(WHITE);
}

void print_graph_consistent_result(int result){
  if(result > 1){
    set_font(GREEN);
    printf("Graph is consistent!\n\n");
  }else{
    set_font(RED);
    printf("Graph is inconsistent!\n\n");
  }
  set_font(WHITE);
}
