#include "tests.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../printer/printer.h"

#include "../FIFO/fifo.h"

#define FIFO_TEST_SIZE 100000
#define FIFO_TEST_MAX_VAL 100000

void test_fifo(){
  set_font(BOLD);
  set_font(PINK);
  print_in_center("Test fifo");
  set_font(WHITE);
  fifo_t fifo = initzialize_fifo();

  srand(time(NULL));
  for(int i=0; i<FIFO_TEST_SIZE; i++){
    fifo_push(fifo, rand() % FIFO_TEST_MAX_VAL);
    if(rand() % 10 < 5) fifo_pop(fifo);
  }

  print_fifo(fifo);

  printf("FIFO was tested for %d elements with start size = %d\n\n", FIFO_TEST_SIZE, START_QUEUE_SIZE);
  printf("During the test random values from 0 to %d was push to fifo, and randomly taken out\n\n", FIFO_TEST_MAX_VAL);

  set_font(BOLD);
  set_font(GREEN);
  printf("TEST DONE, ALL GOOD!\n\n");

  set_font(BOLD);
  set_font(PINK);
  print_in_center("Test fifo");
  set_font(WHITE);
}

void test_graph(){
  set_font(BOLD);
  set_font(PINK);
  print_in_center("Test graph");

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