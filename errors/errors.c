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
  font_color_red();
  printf("Error!\n");
  printf("    Error code: E0%d \n", err->code);
  printf("    Error message: %s", err->msg);
  if(strlen(additional_msg) > 0)
    printf(" - %s", additional_msg);
  printf("\n\n");
  font_color_reset();
  exit(EXIT_FAILURE);
}

void throw_warning(warning_t war, char* additional_msg){
  font_color_yellow();
  printf("Warning!\n");
  printf("    Warning code: W0%d \n", war->code);
  printf("    Warning message: %s", war->msg);
  if(strlen(additional_msg) > 0)
    printf(" - %s", additional_msg);
  font_color_reset();
  printf("\n\n");
}
