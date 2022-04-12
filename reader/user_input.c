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

void check_arguments(batch_arguments_t arg){
  if(arg->execute == UNKNOWN) return;
  check_arguments_for_bypassing(arg);
  check_arguments_for_defaults(arg);
}

void check_arguments_for_defaults(batch_arguments_t arg){
  char msg[MAX_FILE_NAME_LEN];
  if(arg->x == VALUE_NOT_SPECIFIED){
    arg->x = DEFAULT_X;
    if(arg->execute == GENERATE){
      sprintf(msg, "The -x value is not specified, taking default value x = %d", DEFAULT_X);
      throw_warning(default_value_warning, msg);
    }
  }
  if(arg->y == VALUE_NOT_SPECIFIED){
    arg->y = DEFAULT_Y;
    if(arg->execute == GENERATE){
      sprintf(msg, "The -y value is not specified, taking default value y = %d", DEFAULT_Y);
      throw_warning(default_value_warning, msg);
    }
  }
  if(arg->from == VALUE_NOT_SPECIFIED){
    arg->from = DEFAULT_FROM;
    if(arg->execute == SHORTEST_PATH || arg->execute == CHECK_CONSISTENCY){
      sprintf(msg, "The -f value is not specified, taking default value from = %d", DEFAULT_FROM);
      throw_warning(default_value_warning, msg);
    }
  }
  if(arg->to == VALUE_NOT_SPECIFIED){
    arg->to = DEFAULT_TO;
    if(arg->execute == SHORTEST_PATH){
      sprintf(msg, "The -t value is not specified, taking default value to = %d", DEFAULT_TO);
      throw_warning(default_value_warning, msg);
    }
  }
  if(arg->n == VALUE_NOT_SPECIFIED){
    arg->n = DEFAULT_N;
    if(arg->execute == DIVIDE_GRAPH){
      sprintf(msg, "The -n value is not specified, taking default value n = %d", DEFAULT_N);
      throw_warning(default_value_warning, msg);
    }
  }
}
void check_arguments_for_bypassing(batch_arguments_t arg){
  char msg[MAX_FILE_NAME_LEN];

  if(arg->execute == GENERATE && (arg->from != VALUE_NOT_SPECIFIED || arg->to != VALUE_NOT_SPECIFIED))
    throw_warning(arg_bypasing_warning, "Some arguments are being bypassed, for graph generating I only need -x and -y [or -o, -n]!");
  if(arg->execute == SHORTEST_PATH && (arg->x != VALUE_NOT_SPECIFIED || arg->y != VALUE_NOT_SPECIFIED || arg->n != VALUE_NOT_SPECIFIED))
    throw_warning(arg_bypasing_warning, "Some arguments are being bypassed, \nfor shortest path finding I only need -f and -t!");
  if(arg->execute == CHECK_CONSISTENCY && (arg->x != VALUE_NOT_SPECIFIED || arg->y != VALUE_NOT_SPECIFIED || arg->n != VALUE_NOT_SPECIFIED || arg->to != VALUE_NOT_SPECIFIED))
    throw_warning(arg_bypasing_warning, "Some arguments are being bypassed, \nfor graph consistency check I only need -f [or -i]!");
  if(arg->execute == DIVIDE_GRAPH && (arg->x != VALUE_NOT_SPECIFIED || arg->y != VALUE_NOT_SPECIFIED || arg->from != VALUE_NOT_SPECIFIED || arg->to != VALUE_NOT_SPECIFIED))
    throw_warning(arg_bypasing_warning, "Some arguments are being bypassed, \nfor graph dviding I only need -n [or -o, -i]!");

  if(arg->execute != GENERATE && strcmp(arg->in, "") == 0){
    sprintf(msg, "The in file is not specified, the random graph will be generated with x = %d and y = %d", arg->x, arg->y);
    throw_warning(default_value_warning, msg);
  }
  if(strcmp(arg->out, "") == 0)
    throw_warning(default_value_warning, "Out file is not specified, the output will be shown in the console!");

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
  set_font(BOLD);
  printf("\n");
  print_in_center("Arguments");
  printf("\n");
  set_font(WHITE);
  set_font(LIGHT_BLUE);
  printf("    EXECUTING : %s\n", get_string_from_functionallity(arg->execute));
  printf("    IN        : %s\n", strcmp(arg->in, "") == 0 ? "-" : arg->in);
  printf("    OUT       : %s\n", strcmp(arg->out, "") == 0 ? "-" : arg->out);
  printf("    FROM      : %d\n", arg->from);
  printf("    TO        : %d\n", arg->to);
  printf("    X         : %d\n", arg->x);
  printf("    Y         : %d\n", arg->y);
  printf("    N         : %d\n", arg->n);
  set_font(BOLD);
  printf("\n");
  print_in_center("Arguments");
  printf("\n");
  set_font(WHITE);
  printf("\n");
}
