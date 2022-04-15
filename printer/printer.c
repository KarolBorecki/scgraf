#include "printer.h"

#include <stdio.h>
#include <string.h>

#include "../errors/errors.h"

void set_font(char* font){
  printf("%s", font);
}

void print_in_center(char* str){
  unsigned len = CONSOLE_OUTPUT_LEN - strlen(str);
  for(int i=0; i<len/2; i++)
    printf("=");
  printf("%s", str);
  for(int i=0; i<len/2; i++)
    printf("=");
  printf("\n");
}

void print_argument_list(char* name, char* desc){
  set_font(BOLD);
  set_font(PINK);
  printf("    %s ", name);
  set_font(GREY);
  printf(" - %s\n", desc);
}

void print_execute_option_list(char* name, char* desc){
  set_font(BOLD);
  set_font(BLUE);
  printf("        %s", name);
  set_font(GREY);
  printf(" - %s\n", desc);

}

void print_greetings(){
  set_font(BOLD);
  set_font(GREEN);
  printf("\n");
  print_in_center("SCGRAF");
  printf("\n");
  set_font(WHITE);
}

void print_help(){
  set_font(BOLD);
  set_font(WHITE);
  print_in_center("SCGRAF ARGUMENTS");
  printf("\n");
  set_font(WHITE);
  print_argument_list("-e", "specify the functionallity You want to execute.\n");
  print_execute_option_list("generate", "generate graph of width [-x] height [-y] and max path weight [-v].\n");
  print_execute_option_list("divide", "divide input graph [-i] into n [-n] subgraphs \n                (if input graph is not specified, the example graph will be taken).\n");
  print_execute_option_list("consistency", "check input graph [-i] consistency.\n");
  print_execute_option_list("shortest", "find shortest path in input graph [-i] from node [-f] to node [-t].\n\n");

  print_argument_list("-i", "specify input file.\n");
  print_argument_list("-o", "specify output file (used only with generate and divide functionallity).\n");
  print_argument_list("-f", "argument used in shortest path finding and consistency checking, \n         positive number, which stands for node index.\n");
  print_argument_list("-t", "argument used in shortest path finding, positive number, \n         which stands for node index.\n");
  print_argument_list("-x", "argument used in graph generating, positive number, \n         which stands for x size of the graph.\n");
  print_argument_list("-y", "argument used in graph generating, positive number, \n         which stands for y size of the graph.\n");
  print_argument_list("-v", "argument used in graph generating, positive floating point number, \n         which stands for maximum path weight.\n");
  print_argument_list("-n", "argument used in graph dividing, positive number greater than 1, \n         which stands for number of graphs which original graph will be divided into.\n");
  print_argument_list("-p", "specify if You want to print graph in the console\n");


  set_font(BOLD);
  set_font(WHITE);
  print_in_center("SCGRAF ARGUMENTS");
  set_font(WHITE);
  print_greetings();
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

void print_file_output_greetings(char * out_file_name){
  set_font(BOLD);
  printf("\nPrinting output to file \"%s\"...\n\n", out_file_name);
  set_font(WHITE);
}

void print_done_greeting(){
  set_font(BOLD);
  printf("Done!\n\n");
  set_font(WHITE);
}

void print_graph_consistent_result(int result){
  if(result > 0){
    set_font(GREEN);
    printf("Graph is consistent!\n\n");
  }else{
    set_font(RED);
    printf("Graph is inconsistent!\n\n");
  }
  set_font(WHITE);
}
