#ifndef _PRINTER_H_
#define _PRINTER_H_

#include "../utils/config.h"

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

void print_consistency_greeting(unsigned start);
void print_shortest_path_greeting(unsigned from, unsigned to);
void print_graph_division_greeting(unsigned divisions);
void print_file_output_greetings(char * out_file_name);
void print_done_greeting();

void print_graph_consistent_result(int result);

#endif /* _MENU_PRINTER_H_ */
