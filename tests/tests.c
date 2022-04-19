#include "tests.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#include "../printer/printer.h"
#include "../utils/config.h"
#include "../utils/utils.h"
#include "../algorithms/dijkstra.h"
#include "../algorithms/bfs.h"

#include "../FIFO/fifo.h"
#include "../graph/graph.h"
#include "../data_manager/graph_generator.h"
#include "../data_manager/data_manager.h"

#define HOW_LONG_DO_U_HAVE 4

int64_t timespecDiff(struct timespec *timeA_p, struct timespec *timeB_p)
{
    return ((timeA_p->tv_sec * 1000000000) + timeA_p->tv_nsec) -
           ((timeB_p->tv_sec * 1000000000) + timeB_p->tv_nsec);
}

void test_fifo(unsigned size, unsigned max_val){
  set_font(BOLD);
  set_font(PINK);
  print_in_center("Test fifo");
  set_font(WHITE);
  fifo_t fifo = initzialize_fifo();

  srand(time(NULL));
  for(int i=0; i<size; i++){
    fifo_push(fifo, rand() % max_val);
    if(rand() % 10 < 5) fifo_pop(fifo);
  }

  print_fifo(fifo);

  clean_fifo(fifo);
  set_font(BOLD);
  set_font(GREEN);
  printf("FIFO clean ok.\n");
  set_font(WHITE);

  printf("FIFO was tested for %d elements with start size = %d\n\n", size, START_QUEUE_SIZE);
  printf("During the test random values from 0 to %d was push to fifo, and randomly taken out\n\n", max_val);

  set_font(BOLD);
  set_font(GREEN);
  printf("TEST DONE, ALL GOOD!\n\n");

  set_font(BOLD);
  set_font(PINK);
  print_in_center("Test fifo");
  set_font(WHITE);
}

void test_graph(unsigned generated_width, unsigned generated_height, double max_weight, unsigned tests_count){
  set_font(BOLD);
  set_font(PINK);
  print_in_center("Test graph");

  graph_t graph = generate_graph_mesh(generated_width, generated_height, max_weight);

  print_graph(graph, "Generated graph");

  set_font(BOLD);
  set_font(GREEN);

  node_t node;
  for(int i=0; i<graph_size(graph); i++){
    node = graph_get_node_at_index(graph, i);
    for(int j=0; j<graph_get_node_paths_count(node); j++)
      graph_get_path_at_index(node, i);
  }
  printf("Nodes and paths ok.\n");

  enlarge_graph_nodes_memory(graph, 2);
  printf("Graph nodes enlarge ok.\n");

  enlarge_graph_paths_memory(graph_get_node_at_index(graph, 0), 2);
  printf("Graph paths enlarge ok.\n");

  clean_graph(graph);
  printf("Graph clean ok.\n");

  printf("Graph was tested for %d elements with width = %d and height = %d\n\n",
          generated_width*generated_height,
          generated_width,
          generated_height);
  set_font(WHITE);
  printf("During the test random graph was generated, all values were get from graph\n");
  printf("Also the enlarge function were tested and graph was cleaned\n\n");
  set_font(GREEN);
  set_font(BOLD);
  printf("TEST DONE, ALL GOOD!\n\n");

  set_font(BOLD);
  set_font(PINK);
  print_in_center("Test graph");
  set_font(WHITE);
}

void test_dijkstra(){
  set_font(BOLD);
  set_font(PINK);
  print_in_center("Test dijkstra");

  print_in_center("Test dijkstra");
  set_font(WHITE);
}

void test_bfs(){
  set_font(BOLD);
  set_font(PINK);
  print_in_center("Test bfs");

  print_in_center("Test bfs");
  set_font(WHITE);
}

void test_consistency(){
  set_font(BOLD);
  set_font(PINK);
  print_in_center("Test consistency");

  print_in_center("Test consistency");
  set_font(WHITE);
}

int test_format_of_input(char * input_file, int correct_value){
    char line[MAXBUF];
    int lines= 0;
    int width, height, amount_of_nodes, max_node_index;
    FILE *in= fopen(input_file, "r");

    if(in == NULL)
        return -1;

    fgets(line, MAXBUF, in);

    if(sscanf(line, "%d %d", &width, &height) == 2){
        lines++;
        if(width <= 0 || height <= 0) {
            fclose(in);
            return correct_value == 1 ? 0 : 1;
        }
    }else{
        fclose(in);
        return correct_value == 1 ? 0 : 1;
    }

    amount_of_nodes= width * height;
    max_node_index= amount_of_nodes - 1;

    for(int i= 0; i < amount_of_nodes; i++) {
        unsigned node_index, read_nodes, offset1;
        double value;
        fgets(line, MAXBUF, in);
        lines++;
        if ((read_nodes = read_all_nodes_from_line(line)) < 1) {
            if (!check_if_empty(line)) {
                fclose(in);
                return correct_value == 1 ? 0 : 1;
            } else {          //empty line, so it' s okay for now
                continue;   //but we won' t be adding nothing to graph
            }
        }
        char *p= line;
        for(int j= 0; j<read_nodes; j++){
            sscanf(p, "%d%n :%lf%n ", &node_index, &offset1, &value, &offset1);
            p += offset1;
            if(!is_node_valid(node_index, max_node_index)){
                fclose(in);
                return correct_value == 1 ? 0 : 1;
            }
            if(!is_value_valid(value)){
                fclose(in);

            }
        }

    }
    return correct_value == 1 ? 1 : 0;
}
void test_if_right_path(char * input_file, double value){
    ;
}
void test_if_right_consistency(char * input_file, int is_consistant){
    ;
}
void test_max_size_generation(unsigned width, unsigned height){
    ;
}
void test_compare_time(char *file_with_results){
    struct timespec start, end;
    struct tm curr_time;
    uint64_t timeElapsed;
    time_t t= time(NULL);

    curr_time= *(localtime(&t));

    FILE * in= fopen(file_with_results, "a");
    if(in == NULL){
        printf("cannot open file %s\n", file_with_results);
        return;
    }

    for(int i= 0; i<2; i++)
        fprintf((i % 2 == 0 ? in : stdout),"======================================================\n"
               "Performing tests. Date of tests: %d.%d.%d %d:%d:%d\n"
               "======================================================\n"
               "Test type: Graph generating\n"
               "==================================\n",
               curr_time.tm_year + 1900, curr_time.tm_mon + 1, curr_time.tm_mday,
               curr_time.tm_hour, curr_time.tm_min, curr_time.tm_sec);

    for(int i= 1; i<HOW_LONG_DO_U_HAVE; i++) {
        unsigned width= pow_(10, i) / 3, height= pow_(10, i) / 3;
        clock_gettime(CLOCK_MONOTONIC, &start);
        graph_t g = generate_graph_mesh(pow_(10, i), pow_(10, i), 5);
        clock_gettime(CLOCK_MONOTONIC, &end);

        timeElapsed= timespecDiff(&end, &start);
        fprintf(in, "%d. iteration, size: %d x %d\n"
                    "time elapsed: %lf seconds\n\n", i, width, height, timeElapsed/ (double) 1000000000);
    }
    for(int i= 0; i<2; i++)
        fprintf((i % 2 == 0 ? in :stdout),"==================================\n"
               "Finished\n"
               "==================================\n"
               "Test type: Finding shortest path in graph\n"
               "==================================\n");

    for(int i= 1; i<HOW_LONG_DO_U_HAVE; i++) {
        unsigned width= pow_(10, i) / 3, height= pow_(10, i) / 3;
        graph_t g = generate_graph_mesh(width, height, 5);

        clock_gettime(CLOCK_MONOTONIC, &start);
        get_shortest_distance_from_to(g, 0, width*height - 1, 0);
        clock_gettime(CLOCK_MONOTONIC, &end);

        timeElapsed= timespecDiff(&end, &start);
        fprintf(in, "%d. iteration, size: %d x %d\n"
                    "time elapsed: %lf seconds\n\n", i, width, height, timeElapsed/ (double) 1000000000);

        clean_graph(g);
    }
    for(int i= 0; i<2; i++)
        fprintf((i % 2 == 0 ? in :stdout),"==================================\n"
                                          "Finished\n"
                                          "==================================\n"
                                          "Test type: Checking consistency using bfs\n"
                                          "==================================\n");

    for(int i= 1; i<HOW_LONG_DO_U_HAVE; i++) {
        unsigned width= pow_(10, i) / 3, height= pow_(10, i) / 3;
        graph_t g = generate_graph_mesh(width, height, 5);

        clock_gettime(CLOCK_MONOTONIC, &start);
        bfs(g, 0);
        clock_gettime(CLOCK_MONOTONIC, &end);

        timeElapsed= timespecDiff(&end, &start);
        fprintf(in, "%d. iteration, size: %d x %d\n"
                    "time elapsed: %lf seconds\n\n", i, width, height, timeElapsed/ (double) 1000000000);

        clean_graph(g);
    }

    fclose(in);

}

void run_all_tests(void){
    ;
}
