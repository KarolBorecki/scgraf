#ifndef _TESTS_H_
#define _TESTS_H_

#define MAX_WIDTH   100
#define MAX_HEIGHT  100

void test_fifo();
void test_graph();
void test_dijkstra();
void test_bfs();
void test_consistency();

void test_format_of_input(char * input_file, int is_correct);
void test_if_right_path(char * input_file, double value);
void test_if_right_consistency(char * input_file, int is_consistant);
void test_max_size_generation(unsigned width, unsigned height);
void test_compare_time(char *file_with_results);

void run_all_tests(void);

#endif /* _TESTS_H_ */
