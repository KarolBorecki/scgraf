#ifndef _ERRORS_H_
#define _ERRORS_H_

#define MAX_MSG_LENGTH 20

typedef struct error{
  unsigned code;
  char* msg;
} *error_t;

typedef struct warning{
  unsigned code;
  char* msg;
} *warning_t;

error_t unknown_error;
error_t invalid_value_error;
error_t calculation_error;
error_t memory_error;
error_t file_read_error;
error_t file_error;
error_t graph_error;
error_t information_needed_error;

warning_t unknown_warning;
warning_t data_formated_warning;
warning_t default_value_warning;
warning_t duplicated_path_warning;
warning_t inconsistent_graph_warning;
warning_t node_bypasing_warning;
warning_t arg_bypasing_warning;

void initzialize_errors();

void initzialize_warnings();

error_t new_error(unsigned code, char* msg);
warning_t new_warning(unsigned code, char* msg);

void throw_error(error_t err, char* additional_msg);
void throw_warning(warning_t war, char* additional_msg);

void exit_program_normal();
void exit_program_failure();


#endif /* _ERRORS_H_ */
