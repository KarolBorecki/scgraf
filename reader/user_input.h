#ifndef _USER_INPUT_H_
#define _USER_INPUT_H_

#define MAX_FILE_NAME_LEN 256 /* TODO propably should be in utils.h */

#define DEFAULT_FROM 0
#define DEFAULT_TO 10
#define DEFAULT_X 5
#define DEFAULT_Y 5
#define DEFAULT_N 2

#define VALUE_NOT_SPECIFIED -1

typedef enum functionality{
  UNKNOWN,
  SHORTEST_PATH,
  CHECK_CONSISTENCY,
  DIVIDE_GRAPH,
  GENERATE
} func_t;

typedef struct batch_arguments{
  func_t execute;
  char* in;
  char* out;
  int from;
  int to;
  int x;
  int y;
  int n;
} *batch_arguments_t;

batch_arguments_t initzialize_arguments_struct();
void free_arguments_struct(batch_arguments_t arg);

void check_arguments(batch_arguments_t arg);

void check_arguments_for_defaults(batch_arguments_t arg);
void check_arguments_for_bypassing(batch_arguments_t arg);

batch_arguments_t get_batch_arguments(int argc, char** argv);

func_t get_functionallity_from_string(char* str);
char* get_string_from_functionallity(func_t func);

void print_arguments(batch_arguments_t arg);

#endif /* _USER_INPUT_H_ */
