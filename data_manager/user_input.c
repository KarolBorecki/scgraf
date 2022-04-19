#include "user_input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "../errors/errors.h"
#include "../utils/config.h"
#include "../printer/printer.h"

batch_arguments_t initzialize_arguments_struct(){
  batch_arguments_t arg = malloc(sizeof(*arg));
  arg->execute = UNKNOWN;
  arg->in = malloc(MAX_FILE_NAME_LEN);
  arg->out = malloc(MAX_FILE_NAME_LEN);
  arg->from = VALUE_NOT_SPECIFIED;
  arg->to = VALUE_NOT_SPECIFIED;
  arg->x = VALUE_NOT_SPECIFIED;
  arg->y = VALUE_NOT_SPECIFIED;
  arg->n = VALUE_NOT_SPECIFIED;
  arg->max_path_value = VALUE_NOT_SPECIFIED;
  arg->print = 0;
  return arg;
}

void free_arguments_struct(batch_arguments_t arg){
  if(arg == NULL) return;
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
  char msg[MAX_ERR_ADDITIONAL_MSG_LENGTH];
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
  if(arg->max_path_value == VALUE_NOT_SPECIFIED){
    arg->max_path_value = DEFAULT_MAX_PATH_VAL;
    if(arg->execute == GENERATE){
      sprintf(msg, "The -v value is not specified, taking default value v = %d", DEFAULT_MAX_PATH_VAL);
      throw_warning(default_value_warning, msg);
    }
  }
}
void check_arguments_for_bypassing(batch_arguments_t arg){
  if(arg->execute == GENERATE && (arg->from != VALUE_NOT_SPECIFIED || arg->to != VALUE_NOT_SPECIFIED ))
    throw_warning(arg_bypasing_warning, "Some arguments are being bypassed, for graph generating I only need -x and -y [or -o, -n]!");
  if(arg->execute == SHORTEST_PATH && (arg->x != VALUE_NOT_SPECIFIED || arg->y != VALUE_NOT_SPECIFIED || arg->n != VALUE_NOT_SPECIFIED || arg->max_path_value != VALUE_NOT_SPECIFIED))
    throw_warning(arg_bypasing_warning, "Some arguments are being bypassed, for shortest path finding I only need -f and -t!");
  if(arg->execute == CHECK_CONSISTENCY && (arg->x != VALUE_NOT_SPECIFIED || arg->y != VALUE_NOT_SPECIFIED || arg->n != VALUE_NOT_SPECIFIED || arg->to != VALUE_NOT_SPECIFIED || arg->max_path_value != VALUE_NOT_SPECIFIED))
    throw_warning(arg_bypasing_warning, "Some arguments are being bypassed, for graph consistency check I only need -f [or -i]!");
  if(arg->execute == DIVIDE_GRAPH && (arg->x != VALUE_NOT_SPECIFIED || arg->y != VALUE_NOT_SPECIFIED || arg->from != VALUE_NOT_SPECIFIED || arg->to != VALUE_NOT_SPECIFIED || arg->max_path_value != VALUE_NOT_SPECIFIED))
    throw_warning(arg_bypasing_warning, "Some arguments are being bypassed, for graph dviding I only need -n [or -o, -i]!");
  if(arg->execute == MAKE_UNDIRECTED && (arg->x != VALUE_NOT_SPECIFIED || arg->y != VALUE_NOT_SPECIFIED || arg->from != VALUE_NOT_SPECIFIED || arg->to != VALUE_NOT_SPECIFIED || arg->max_path_value != VALUE_NOT_SPECIFIED || arg->n != VALUE_NOT_SPECIFIED))
    throw_warning(arg_bypasing_warning, "Some arguments are being bypassed, for graph dviding I only need -n [or -o, -i]!");

  if(arg->execute != GENERATE && strncmp(arg->in, BLANK_STR, strlen(BLANK_STR)) == 0){
    throw_warning(default_value_warning, "The in file is not specified, the example graph will be taken.");
  }
  if(strncmp(arg->out, BLANK_STR, strlen(BLANK_STR)) == 0 && arg->execute != SHORTEST_PATH && arg->execute != CHECK_CONSISTENCY)
    throw_warning(default_value_warning, "Out file is not specified, the output will be shown in the console!");

}

batch_arguments_t get_batch_arguments(int argc, char** argv){
  char msg[MAX_ERR_ADDITIONAL_MSG_LENGTH];
  batch_arguments_t arg = initzialize_arguments_struct();

  int opt;
  while((opt = getopt(argc, argv, "e:i:o:f:t:x:y:n:v:p:")) != -1){
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
        if(atof(optarg) != atoi(optarg)){
          sprintf(msg, "Formated -f value from %f to %d", atof(optarg), arg->from);
          throw_warning(data_formated_warning, msg);
        }
        if(arg->from < 0)
          throw_error(invalid_value_error, "Specified argument -f is invalid - should be positive!");
        break;
      case 't': /* to */
        arg->to = atoi(optarg);
        if(atof(optarg) != atoi(optarg)){
          sprintf(msg, "Converted -t value from %f to %d", atof(optarg), arg->to);
          throw_warning(data_formated_warning, msg);
        }
        if(arg->to < 0)
          throw_error(invalid_value_error, "Specified argument -t is invalid - should be positive!");
        break;
      case 'x': /* x */
        arg->x = atoi(optarg);
        if(atof(optarg) != atoi(optarg)){
          sprintf(msg, "Converted -x value from %f to %d", atof(optarg), arg->x);
          throw_warning(data_formated_warning, msg);
        }
        if(arg->x < 0)
          throw_error(invalid_value_error, "Specified argument -x is invalid - should be positive!");
        break;
      case 'y': /* y */
        arg->y = atoi(optarg);
        if(atof(optarg) != atoi(optarg)){
          sprintf(msg, "Converted -y value from %f to %d", atof(optarg), arg->y);
          throw_warning(data_formated_warning, msg);
        }
        if(arg->y < 0)
          throw_error(invalid_value_error, "Specified argument -y is invalid - should be positive!");
        break;
      case 'n': /* n */
        arg->n = atoi(optarg);
        if(atof(optarg) != atoi(optarg)){
          sprintf(msg, "Converted -n value from %f to %d", atof(optarg), arg->n);
          throw_warning(data_formated_warning, msg);
        }
        if(arg->n < 2)
          throw_error(invalid_value_error, "Specified argument -n is invalid - should be bigger than 1!");
        break;
      case 'v': /* n */
        arg->max_path_value = atof(optarg);
        if(arg->max_path_value <= 0)
          throw_error(invalid_value_error, "Specified argument -v is invalid - should be bigger than 0!");
        break;
      case 'p':
        arg->print = 1;
        break;
      default:
        throw_error(invalid_value_error, "Specified invalid argument!");
        exit (EXIT_FAILURE);
        break;
    }
  }
  return arg;
}

func_t get_functionallity_from_string(char* str){
  if(strcmp(str, SHORTEST_PATH_EXEC) == 0)
    return SHORTEST_PATH;
  else if(strcmp(str, CONSISTENCY_EXEC) == 0)
    return CHECK_CONSISTENCY;
  else if(strcmp(str, DIVIDE_EXEC) == 0)
    return DIVIDE_GRAPH;
  else if(strcmp(str, GENERATE_EXEC) == 0)
    return GENERATE;
  else if(strcmp(str, MAKE_UNDIRECTED_EXEC) == 0)
    return MAKE_UNDIRECTED;
  else
    throw_warning(invalid_value_warning, "Specified invalid functionallity on argument -e!");
  return UNKNOWN;
}

char* get_string_from_functionallity(func_t func){
  if(func==SHORTEST_PATH)
    return "Shortest path";
  else if(func==CHECK_CONSISTENCY)
    return "Checking graph consistency";
  else if(func==DIVIDE_GRAPH)
    return "Dividing graph";
  else if(func==GENERATE)
    return "Generating graph";
  else if(func==MAKE_UNDIRECTED)
    return "Converting graph to be consistent";

  return "Unknown";
}

void print_arguments(batch_arguments_t arg){
  set_font(BLUE);
  set_font(BOLD);
  printf("\n");
  print_in_center("Passed Arguments");
  printf("\n");
  set_font(WHITE);
  set_font(BLUE);
  printf("    EXECUTING    : %s\n", get_string_from_functionallity(arg->execute));
  printf("    IN           : %s\n", strncmp(arg->in, BLANK_STR, strlen(BLANK_STR)) == 0 ? "-" : arg->in);
  printf("    OUT          : %s\n", strncmp(arg->out, BLANK_STR, strlen(BLANK_STR)) == 0 ? "-" : arg->out);
  printf("    FROM         : %d\n", arg->from);
  printf("    TO           : %d\n", arg->to);
  printf("    X            : %d\n", arg->x);
  printf("    Y            : %d\n", arg->y);
  printf("    N            : %d\n", arg->n);
  printf("    MAX_PATH_VAL : %lf\n", arg->max_path_value);
  set_font(BOLD);
  printf("\n");
  print_in_center("Passed Arguments");
  printf("\n");
  set_font(WHITE);
}
