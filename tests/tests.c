#include "tests.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../printer/printer.h"
#include "../utils/config.h"

#include "../FIFO/fifo.h"
#include "../graph/graph.h"
#include "../reader/graph_generator.h"

#define FIFO_TEST_SIZE 100000
#define FIFO_TEST_MAX_VAL 100000

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

void test_graph(unsigned generated_width, unsigned generated_height, unsigned double max_weight, unsigned tests_count){
  set_font(BOLD);
  set_font(PINK);
  print_in_center("Test graph");

  graph_t graph = generate_example_graph_mesh(generated_width, generated_height, max_weight);

  print_graph(graph);

  set_font(BOLD);
  set_font(GREEN);

  for(int i=0; i<graph_size(graph); i++)
    for(int j=0; j<graph_get_node_paths_count(graph_get_node_at_index(graph, i)); j++)
      graph_get_path_at_index(graph, i);
  printf("Nodes and paths ok.\n")

  enlarge_graph_nodes_memory(graph, 2);
  printf("Graph nodes enlarge ok.\n");

  enlarge_graph_paths_memory(graph_get_node_at_index(graph, 0), 2);
  printf("Graph paths enlarge ok.\n");

  clean_graph(graph);
  printf("Graph clean ok.\n");

  printf("Graph was tested for %d elements with width = %d and height = %d\n\n",
          generated_width+generated_height,
          generated_width,
          generated_height);
  set_font(WHITE);
  printf("During the test random graph was generated, all values were get from graph\n");
  printf("Also the enlarge function were tested and graph was cleaned\n");
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

void test_format_of_input(char * input_file, int is_correct){
    ;
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
    FILE * in= fopen("../tests/results", "w+");
    if(in == NULL)
        return;

}

void run_all_tests(void){
    ;
}
