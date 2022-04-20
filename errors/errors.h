#ifndef _ERRORS_H_
#define _ERRORS_H_

#include "../utils/config.h"
#include "../data_manager/user_input.h"
#include "../graph/graph.h"

#define unknown_error 0
#define invalid_value_error 1
#define calculation_error 2
#define memory_error 3
#define file_read_error 4
#define file_error 5
#define graph_error 6
#define information_needed_error 7

#define unknown_warning 0
#define data_formated_warning 1
#define default_value_warning 2
#define duplicated_path_warning 3
#define inconsistent_graph_warning 4
#define node_bypasing_warning 5
#define arg_bypasing_warning 6
#define invalid_value_warning 7

void throw_exception(char** msgs_tab, char* color, char* caption, char code_prefix, unsigned code, char* additional_msg);

void throw_error(unsigned err_code, char* additional_msg);
void throw_error_and_exit(unsigned err_code, char* additional_msg, graph_t graph, batch_arguments_t arg);
void throw_warning(unsigned war_code, char* additional_msg);

void exit_program_normal(graph_t graph, batch_arguments_t arg);
void exit_program_failure(graph_t graph, batch_arguments_t arg);

void free_warnings();
void free_errors();

#endif /* _ERRORS_H_ */
