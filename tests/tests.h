#ifndef _TESTS_H_
#define _TESTS_H_

void test_fifo();
void test_graph();
void test_dijkstra();
void test_bfs();
void test_consistency();

void test_format_of_input(char * input_file);
void test_if_right_path(char * input_file, double * value);
void test_if_right_consistancy(char * input_file, int is_consistant);
void test_compare_time(void);

#endif /* _TESTS_H_ */
