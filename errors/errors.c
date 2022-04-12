#include "../errors/errors.h"

#include "../printer/printer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initzialize_errors(){
  unknown_error            = new_error(0, "Unknown error");
  invalid_value_error      = new_error(1, "Invalid value");
  calculation_error        = new_error(2, "Calculation error");
  memory_error             = new_error(3, "Memory error");
  file_read_error          = new_error(4, "File reading error");
  file_error               = new_error(5, "File error");
  graph_error              = new_error(6, "Graph error");
  information_needed_error = new_error(7, "Information needed error");
}

void initzialize_warnings(){
  unknown_warning            = new_warning(0, "Unknown warning");
  data_formated_warning      = new_warning(1, "Formated data");
  default_value_warning      = new_warning(2, "Taking default value");
  duplicated_path_warning    = new_warning(3, "Passed duplicated path");
  inconsistent_graph_warning = new_warning(4, "Graph inconsistent");
  node_bypasing_warning      = new_warning(5, "Bypassing node");
  arg_bypasing_warning       = new_warning(6, "Bypassing argument");
}
error_t new_error(unsigned code, char* msg){
  error_t new_err = malloc(sizeof(*new_err));
  new_err->code = code;
  new_err->msg = malloc(MAX_MSG_LENGTH);
  strcpy(new_err->msg, msg);

  return new_err;
}

warning_t new_warning(unsigned code, char* msg){
  warning_t new_war = malloc(sizeof(*new_war));
  new_war->code = code;
  new_war->msg = malloc(MAX_MSG_LENGTH);
  strcpy(new_war->msg, msg);

  return new_war;
}

void throw_error(error_t err, char* additional_msg){
  set_font(RED); set_font(BOLD);
  printf("\nError!\n");
  set_font(WHITE); set_font(RED);
  printf("    Error code: E0%d \n", err->code);
  printf("    Error message: %s", err->msg);
  set_font(BOLD);
  if(strlen(additional_msg) > 0)
    printf("\n    %s", additional_msg);
  printf("\n\n");
  set_font(WHITE);
  exit_program_failure();
}

void throw_warning(warning_t war, char* additional_msg){
  set_font(YELLOW); set_font(BOLD);
  printf("\nWarning!\n");
  set_font(WHITE); set_font(YELLOW);
  printf("    Warning code: W0%d \n", war->code);
  printf("    Warning message: %s", war->msg);
  set_font(BOLD);
  if(strlen(additional_msg) > 0)
    printf("\n    %s", additional_msg);
  set_font(WHITE);
  printf("\n\n");
}

void exit_program_normal(){
  exit(EXIT_SUCCESS);
}

void exit_program_failure(){
  exit(EXIT_FAILURE);
}
