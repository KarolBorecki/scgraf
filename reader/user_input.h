#ifndef _USER_INPUT_H_
#define _USER_INPUT_H_

#define MAX_FILE_NAME_LEN 256

typedef struct batch_arguments{
  char* in;
  char* out;
  unsigned from;
  unsigned to;
  unsigned x;
  unsigned y;
  unsigned n;
  unsigned sp;
} *batch_arguments_t;

batch_arguments_t initzialize_arguments_struct();
void free_arguments_struct(batch_arguments_t arg);

batch_arguments_t get_batch_arguments(int argc, char** argv);

void print_arguments(batch_arguments_t arg);

#endif /* _USER_INPUT_H_ */