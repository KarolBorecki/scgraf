#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../tests/tests.h"
#include "../printer/printer.h"

typedef enum { right_input= '1',
               right_path,
               right_consistency,
               max_size,
               compare_time,
               fifo,
               graph,
               dijkstra,
               bfs
} options;

int main(int argc, char **argv){

    int opt;
    char *input_file;
    double value;
    while((opt = getopt(argc, argv, ":123456789A")) != -1){
        printf("%d <- thats what I got!\n", opt);
        switch(opt){
            case right_input:
                print_in_center("running test_if_right_input()");
                test_format_of_input("../test/graph_for_test_1", 1);
                test_format_of_input("../test/graph_for_test_2", 1);
                test_format_of_input("../test/graph_for_test_3", 0);
                break;
            case right_path:
                print_in_center("running test_if_right_path()");
                test_if_right_path(input_file, value);
                break;
            case right_consistency:
                print_in_center("running test_if_right_consistency()");
                test_if_right_path("../test/graph_for_test_1", 2.7321);
                test_if_right_path("../test/graph_for_test_2", 1.2732);
                break;
            case max_size:
                print_in_center("running test_max_size_generation()");
                test_max_size_generation(MAX_WIDTH, MAX_HEIGHT);
                break;
            case compare_time:
                print_in_center("running test_compare_time()");
                test_compare_time("./tests/results");
                break;
            case fifo:
                test_fifo();
                break;
            case graph:
                test_graph(GRAPH_TEST_WIDTH, GRAPH_TEST_HEIGHT, GRAPH_TEST_MAX_WEIGHT, GRAPH_TEST_TESTS_COUNT);
                break;
            case dijkstra:
                test_dijkstra();
                break;
            case bfs:
                test_bfs();
                break;
            case ':':
                printf("Value required!\n");
            case 'A':
                print_in_center("running all tests");
                run_all_tests();
                break;
            default:
                printf("huh?\n");
                break;
        }
    }
    printf("DONE!\n");

    return 0;
}
