#ifndef _PRINTER_H_
#define _PRINTER_H_

#include "../utils/config.h"

#include <stdint.h>
#include <stdio.h>
#include <time.h>

#define WHITE      "\033[0m"
#define GREY       "\033[37m"
#define LIGHT_BLUE "\033[36m"
#define PINK       "\033[35m"
#define BLUE       "\033[34m"
#define RED        "\033[31m"
#define YELLOW     "\033[33m"
#define GREEN      "\033[32m"
#define BOLD       "\033[1m"

void set_font(char* font);
void print_in_center(char* str);

void print_greetings();
void print_help();

void print_argument_list(char* name, char* desc);

void print_consistency_greeting(unsigned start);
void print_shortest_path_greeting(unsigned from, unsigned to);
void print_graph_division_greeting(unsigned divisions);
void print_file_output_greetings(char * out_file_name);
void print_graph_generating_greetings(unsigned width, unsigned height, double max_weight);
void print_graph_example_generating_greetings();
void print_get_graph_from_file_greeting();
void print_convert_graph_to_undirected_greetings();
void print_done_greeting();

void print_graph_consistent_result(int result);

/* functions used in test.c */
void print_line_results(FILE *output, int iteration, unsigned width, unsigned height, uint64_t timeElapsed);
void print_greetings_to_output(FILE * output, const char *line);
void print_format_to_output(FILE * output, const char * line);
void print_closing_to_output(FILE * output, uint64_t time_elapsed, char * file_with_results);

void print_help_for_test(void);

#endif /* _PRINTER_H_ */
