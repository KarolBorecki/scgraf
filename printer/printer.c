#include "printer.h"

#include <stdio.h>
#include <string.h>

#include "../errors/errors.h"

void set_font(char* font){
  printf("%s", font);
}

void print_in_center(char* str){
  unsigned len = CONSOLE_OUTPUT_LEN - strlen(str);
  for(int i=0; i<len/2; i++)
    printf("=");
  printf("%s", str);
  for(int i=0; i<len/2; i++)
    printf("=");
  printf("\n");
}

void print_argument_list(char* name, char* desc){
  set_font(BOLD);
  set_font(PINK);
  printf("    %s ", name);
  set_font(GREY);
  printf(" - %s\n", desc);
}

void print_execute_option_list(char* name, char* desc){
  set_font(BOLD);
  set_font(BLUE);
  printf("        %s", name);
  set_font(GREY);
  printf(" - %s\n", desc);

}

void print_greetings(){
  set_font(BOLD);
  set_font(GREEN);
  printf("\n");
  print_in_center("scgraf");
  printf("\n");
  set_font(WHITE);
}

void print_help(){
  set_font(BOLD);
  set_font(GREY);
  print_in_center("scgraf arguments");
  printf("\n");
  set_font(WHITE);
  print_argument_list("-e", "specify the functionallity You want to execute.\n");
  print_execute_option_list(GENERATE_EXEC, "generate graph of width [-x] height [-y] and max path weight [-v].\n");
  print_execute_option_list(DIVIDE_EXEC, "divide input graph [-i] into n [-n] subgraphs \n                (if input graph is not specified, the example graph will be taken).\n");
  print_execute_option_list(CONSISTENCY_EXEC, "check input graph [-i] consistency.\n");
  print_execute_option_list(SHORTEST_PATH_EXEC, "find shortest path in input graph [-i] from node [-f] to node [-t].\n");
  print_execute_option_list(MAKE_UNDIRECTED_EXEC, "converts input graph [-i] paths to not be single-way \n                         (makes graph undirected).\n");
  print_execute_option_list(PRINT_EXEC, "prints input graph [-i] to the console, no matter out argument [-o].\n\n");

  print_argument_list("-i", "specify input file.\n");
  print_argument_list("-o", "specify output file (used only with generate and divide functionallity).\n");
  print_argument_list("-f", "argument used in shortest path finding and consistency checking, \n         positive number, which stands for node index.\n");
  print_argument_list("-t", "argument used in shortest path finding, positive number, \n         which stands for node index.\n");
  print_argument_list("-x", "argument used in graph generating, positive number, \n         which stands for x size of the graph.\n");
  print_argument_list("-y", "argument used in graph generating, positive number, \n         which stands for y size of the graph.\n");
  print_argument_list("-v", "argument used in graph generating, positive floating point number, \n         which stands for maximum path weight.\n");
  print_argument_list("-n", "argument used in graph dividing, positive number greater than 1, \n         which stands for number of graphs which original graph will be divided into.\n");
  print_argument_list("-p", "specify if You want to print graph in the console\n");

  set_font(WHITE);
  set_font(BOLD);
  printf("\n    Made by Karol Borecki & Tomasz Tkaczyk | 2022\n\n");
  set_font(BOLD);
  set_font(GREY);
  print_in_center("scgraf arguments");
  set_font(WHITE);
  print_greetings();
}

void print_consistency_greeting(unsigned start){
  set_font(BOLD);
  printf("\nChecking graph consistency starting from node %d... \n", start);
  set_font(WHITE);
}

void print_shortest_path_greeting(unsigned from, unsigned to){
  set_font(BOLD);
  printf("\nLooking for shortest path from node %d to node %d... \n", from, to);
  set_font(WHITE);
}

void print_graph_division_greeting(unsigned divisions){
  set_font(BOLD);
  printf("\nDividing graph into %d subgraphs... \n", divisions);
  set_font(WHITE);
}

void print_file_output_greetings(char * out_file_name){
  set_font(BOLD);
  printf("\nPrinting output to file \"%s\"...\n", out_file_name);
  set_font(WHITE);
}

void print_graph_generating_greetings(unsigned width, unsigned height, double max_weight){
  set_font(BOLD);
  printf("\nGenerating graph with width = %d, height = %d and max path weigth = %lf... \n", width, height, max_weight);
  set_font(WHITE);
}

void print_graph_example_generating_greetings(){
  set_font(BOLD);
  printf("\nGenerating example graph... \n");
  set_font(WHITE);
}

void print_get_graph_from_file_greeting(){
  set_font(BOLD);
  printf("\nGetting graph from file... \n\n");
  set_font(WHITE);
}

void print_convert_graph_to_undirected_greetings(){
  set_font(BOLD);
  printf("\nConverting graph to undirected... \n");
  set_font(WHITE);
}

void print_done_greeting(){
  set_font(BOLD);
  printf("Done!\n\n");
  set_font(WHITE);
}

void print_graph_consistent_result(int result){
  if(result > 0){
    set_font(GREEN);
    printf("Graph is consistent!\n\n");
  }else{
    set_font(RED);
    printf("Graph is inconsistent!\n\n");
  }
  set_font(WHITE);
}

/*functions used for printing in test.c*/

void print_line_results(FILE *in, int i, unsigned width, unsigned height, uint64_t timeElapsed){

    fprintf(in, "%d. iteration, size: %d x %d\n"
                "time elapsed: %lf seconds\n", i, width, height, timeElapsed/ (double) 1000000000);

}

void print_greetings_to_output(FILE * in, const char *line){
    struct tm curr_time;
    time_t t= time(NULL);
    curr_time= *(localtime(&t));

    if(in == NULL){
        throw_error(file_read_error, "cannot write to file!");
        return;
    }
    set_font(PINK);
    fprintf(in, "==========================================================\n"
                "Performing tests. Date of tests: %d.%d.%d %d:%d:%d\n"
                "==========================================================\n",
            curr_time.tm_year + 1900, curr_time.tm_mon + 1, curr_time.tm_mday,
            curr_time.tm_hour, curr_time.tm_min, curr_time.tm_sec);
    set_font(WHITE);
    fprintf(in,"Test type: %s\n"
               "================================================\n", line);
}

void print_format_to_output(FILE * in, const char * line){
    if(in == NULL){
        throw_error(file_read_error, "cannot write to file!");
        return;
    }
    set_font(WHITE);
    fprintf(in,"================================================\n");
    set_font(GREEN);
    fprintf(in, "Finished\n");
    set_font(WHITE);
    fprintf(in, "================================================\n"
                "Test type: %s\n"
                "================================================\n", line);
}

void print_closing_to_output(FILE * in, uint64_t timeElapsed, char * file_with_results){
    fprintf(in,"================================================\n");
    set_font(GREEN);
    fprintf(in,"Finished\n");
    set_font(PINK);
    fprintf(in,"==========================================================\n"
               "Finished all tests\nTime Elapsed for all tests: %lf seconds\n"
               "==========================================================\n", timeElapsed/ (double) 1000000000);
    if(in == stdout)
        fprintf(in, "You can find your results, and all the others in this file:\n"
                    "%s\n", file_with_results);
    set_font(WHITE);
}

void print_help_for_test(void){
    set_font(BOLD);
    set_font(GREY);
    print_in_center("scgraf_test arguments");
    printf("\n");
    set_font(WHITE);
    print_argument_list("-1", "run test of the right input in test files");
    print_argument_list("-2", "run test of the right paths in test files");
    print_argument_list("-3", "run test of the right consistencies in test files");
    print_argument_list("-4", "run test that compares time of generation on your system");
    print_argument_list("-5", "run test of fifo");
    print_argument_list("-6", "run test of graph");
    print_argument_list("-7", "run test of dijkstra algorithm and functions that is uses");
    print_argument_list("-A", "run all tests");
    print_argument_list("-?", "print help for using scgraf_test");
    set_font(BOLD);
    set_font(GREY);
    print_in_center("scgraf_test arguments");
    printf("\n");
    set_font(WHITE);
}
