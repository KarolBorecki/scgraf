#include "errors.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../data_manager/user_input.h"
#include "../graph/graph.h"
#include "../printer/printer.h"
#include "../utils/utils.h"
#include "../utils/config.h"

char* error_msgs[8] = {"Unknown error", "Invalid value", "Calculation error",
                       "Memory error", "File reading error", "File error",
                       "Graph error", "Information needed error"};

char* warning_msgs[8] = {"Unknown warning", "Formated data", "Taking default value",
                         "Passed duplicated path", "Graph inconsistent", "Bypassing node",
                         "Bypassing argument", "Invalid value"};

void throw_exception(char** msgs_tab, char* color, char* caption, char code_prefix, unsigned code, char* additional_msg){
  set_font(color); set_font(BOLD);
  printf("\%s!\n", caption);
  set_font(WHITE); set_font(color);
  printf("    %s code: %c0%d \n", caption, code_prefix, code);
  printf("    %s message: %s", caption, msgs_tab[code]);
  set_font(BOLD);
  if(is_str_blank(additional_msg) == 0)
    printf("\n    %s", additional_msg);
  printf("\n\n");
  set_font(WHITE);
}

void throw_error(unsigned err_code, char* additional_msg){
  throw_exception(error_msgs, RED, "Error", 'E', err_code, additional_msg);
}

void throw_error_and_exit(unsigned err_code, char* additional_msg, graph_t graph, batch_arguments_t arg){
  throw_error(err_code, additional_msg);
  exit_program_failure(graph, arg);
}

void throw_warning(unsigned war_code, char* additional_msg){
  throw_exception(warning_msgs, YELLOW, "Warning", 'W', war_code, additional_msg);
}

void exit_program_normal(graph_t graph, batch_arguments_t arg){
  clean_graph(graph);
  free_arguments_struct(arg);
  exit(EXIT_SUCCESS);
}

void exit_program_failure(graph_t graph, batch_arguments_t arg){
  clean_graph(graph);
  free_arguments_struct(arg);
  exit(EXIT_FAILURE);
}
