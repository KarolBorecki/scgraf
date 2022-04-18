#include "errors.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../printer/printer.h"
#include "../utils/config.h"


char* error_msgs[8] = {"Unknown error", "Invalid value", "Calculation error",
                       "Memory error", "File reading error", "File error",
                       "Graph error", "Information needed error"};

char* warning_msgs[8] = {"Unknown warning", "Formated data", "Taking default value",
                         "Passed duplicated path", "Graph inconsistent", "Bypassing node",
                         "Bypassing argument", "Invalid value"};

void throw_error(unsigned err_code, char* additional_msg){
  set_font(RED); set_font(BOLD);
  printf("\nError!\n");
  set_font(WHITE); set_font(RED);
  printf("    Error code: E0%d \n", err_code);
  printf("    Error message: %s", error_msgs[err_code]);
  set_font(BOLD);
  if(strlen(additional_msg) > 0)
    printf("\n    %s", additional_msg);
  printf("\n\n");
  set_font(WHITE);
  exit_program_failure();
}

void throw_warning(unsigned war_code, char* additional_msg){
  set_font(YELLOW); set_font(BOLD);
  printf("\nWarning!\n");
  set_font(WHITE); set_font(YELLOW);
  printf("    Warning code: W0%d \n", war_code);
  printf("    Warning message: %s", warning_msgs[war_code]);
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
