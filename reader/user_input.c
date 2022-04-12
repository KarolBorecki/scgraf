#include "user_input.h"

#include "../errors/errors.h"
#include "../printer/printer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

batch_arguments_t initzialize_arguments_struct(){
  batch_arguments_t arg = malloc(sizeof(*arg));
  arg->execute = UNKNOWN;
  arg->in = malloc(MAX_FILE_NAME_LEN);
  arg->out = malloc(MAX_FILE_NAME_LEN);
  arg->from = -1;
  arg->to = -1;
  arg->x = -1;
  arg->y = -1;
  arg->n = -1;
  return arg;
}

void free_arguments_struct(batch_arguments_t arg){
  free(arg->in);
  free(arg->out);
  free(arg);
}

batch_arguments_t get_batch_arguments(int argc, char** argv){
  batch_arguments_t arg = initzialize_arguments_struct();

  int opt;
  while((opt = getopt(argc, argv, "e:i:o:f:t:x:y:n:")) != -1){
    switch(opt){
      case 'e':
          arg->execute = get_functionallity_from_string(optarg);
        break;
      case 'i': /* in */
        strcpy(arg->in, optarg);
        break;
      case 'o': /* out */
        strcpy(arg->out, optarg);
        break;
      case 'f': /* from */
        arg->from = atoi(optarg);
        if(arg->from < 0)
          throw_error(invalid_value_error, "Specified argument -f is invalid - should be positive!");
        break;
      case 't': /* to */
        arg->to = atoi(optarg);
        if(arg->to < 0)
          throw_error(invalid_value_error, "Specified argument -t is invalid - should be positive!");
        break;
      case 'x': /* x */
        arg->x = atoi(optarg);
        if(arg->x < 0)
          throw_error(invalid_value_error, "Specified argument -x is invalid - should be positive!");
        break;
      case 'y': /* y */
        arg->y = atoi(optarg);
        if(arg->y < 0)
          throw_error(invalid_value_error, "Specified argument -y is invalid - should be positive!");
        break;
      case 'n': /* n */
        arg->n = atoi(optarg);
        if(arg->n < 2)
          throw_error(invalid_value_error, "Specified argument -n is invalid - should be bigger than 1!");
        break;
      default:
        throw_error(invalid_value_error, "Specified invalid argument!");
        exit (EXIT_FAILURE);
        break;
    }
  }
  return arg;
}

enum functionality get_functionallity_from_string(char* str){
  if(strcmp(str, "shortest") == 0)
    return SHORTEST_PATH;
  else if(strcmp(str, "consistency") == 0)
    return CHECK_CONSISTENCY;
  else if(strcmp(str, "divide") == 0)
    return DIVIDE_GRAPH;
  else if(strcmp(str, "generate") == 0)
    return GENERATE;
  else
    throw_warning(default_value_warning, "Specified invalid functionallity on argument -e!");
  return UNKNOWN;
}

char* get_string_from_functionallity(enum functionality func){
  if(func==SHORTEST_PATH)
    return "Shortest path";
  else if(func==CHECK_CONSISTENCY)
    return "Checking graph consistency";
  else if(func==DIVIDE_GRAPH)
    return "Dividing graph";
  else if(func==GENERATE)
    return "Generating graph";

  return "Unknown";
}

void print_arguments(batch_arguments_t arg){
  set_font(LIGHT_BLUE);
  printf("\n=========Arguments=========\n\n");
  printf("    EXECUTING : %s\n", get_string_from_functionallity(arg->execute));
  printf("    IN        : %s\n", arg->in);
  printf("    OUT       : %s\n", arg->out);
  printf("    FROM      : %d\n", arg->from);
  printf("    TO        : %d\n", arg->to);
  printf("    X         : %d\n", arg->x);
  printf("    Y         : %d\n", arg->y);
  printf("    N         : %d\n", arg->n);
  printf("\n=========Arguments=========\n\n");
  set_font(WHITE);
}
