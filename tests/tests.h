#ifndef _TESTS_H_
#define _TESTS_H_

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
#include "../printer/printer.h"

#define FIFO_TEST_SIZE 100000
#define FIFO_TEST_MAX_VAL 100000

#define GRAPH_TEST_WIDTH 1000
#define GRAPH_TEST_HEIGHT 1000
#define GRAPH_TEST_MAX_WEIGHT 10
#define GRAPH_TEST_TESTS_COUNT 10000

#define MAX_WIDTH   100000
#define MAX_HEIGHT  100000

#define GRAPH_HEIGHT_DIJKSTRA  100
#define GRAPH_WIDTH_DIJKSTRA   10

#define TESTED_FILES 7
#define TESTED_FILES_CORRECT_INPUT 3

#define NODE_FOR_INITIALIZATION 0
#define NODE_FOR_PATH_FINDING GRAPH_HEIGHT_DIJKSTRA - 1

#define HOW_MANY_ITERATIONS 4


typedef enum { right_input= '1',
    right_path,
    right_consistency,
    compare_time,
    fifo,
    graph,
    dijkstra_op
} options;

void test_fifo(unsigned size, unsigned max_val);
void test_graph(unsigned generated_width, unsigned generated_height, double max_weight, unsigned tests_count);
void test_dijkstra(void);

void test_format_of_input(void);
int test_format_of_single_input(char * input_file, int is_correct);

void test_if_right_path(void);
int test_if_right_single_path(char * input_file, double correct_value);

void test_if_right_consistency(void);
int test_if_right_single_consistency(char * input_file, int is_consistant);

void test_compare_time(char *file_with_results);

void run_all_tests(void);

unsigned generate_size_for_iteration(int iteration);
#endif /* _TESTS_H_ */
