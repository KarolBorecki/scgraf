#include "user_input.h"

//#include "../errors/errors.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

batch_arguments_t initzialize_arguments_struct(){
  batch_arguments_t arg = malloc(sizeof(*arg));
  arg->in = malloc(MAX_FILE_NAME_LEN);
  arg->out = malloc(MAX_FILE_NAME_LEN);
  arg->from = 0;
  arg->to = 0;
  arg->x = 0;
  arg->y = 0;
  arg->n = 0;
  arg->sp = 0;

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
  while((opt = getopt(argc, argv, "i:o:f:t:x:y:n:c:")) != -1){
    switch(opt){
    case 'i': /* in */
      strcpy(arg->in, optarg);
      break;
    case 'o': /* out */
      strcpy(arg->out, optarg);
      break;
    case 'f': /* from */
      arg->from = atoi(optarg);
      break;
    case 't': /* to */
      arg->to = atoi(optarg);
      break;
    case 'x': /* x */
      arg->x = atoi(optarg);
      break;
    case 'y': /* y */
      arg->y = atoi(optarg);
      break;
    case 'n': /* n */
      arg->n = atoi(optarg);
      break;
    case 'c': /* sp */
      arg->sp = atoi(optarg);
      break;
    default:
      //throw_error(invalid_value_error, "Specified invalid argument!");
      exit (EXIT_FAILURE);
      break;
    }
  }
  return arg;
}

void print_arguments(batch_arguments_t arg){
  printf("\n=========Arguments=========\n\n");
  printf("    IN   = %s\n", arg->in);
  printf("    OUT  = %s\n", arg->out);
  printf("    FROM = %d\n", arg->from);
  printf("    TO   = %d\n", arg->to);
  printf("    X    = %d\n", arg->x);
  printf("    Y    = %d\n", arg->y);
  printf("    N    = %d\n", arg->n);
  printf("    SP   = %d\n", arg->sp);
  printf("\n=========Arguments=========\n\n");

}
