#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../tests/tests.h"
#include "../printer/printer.h"
#include "../data_manager/graph_generator.h"

//TODO:
//      -generate files for path checking
//      -generate files for consistency checking
//      -function that checks if max_size generation is valid without waiting eons
//      -refactor right path
//      -refactor test_compare_time()!!!!!!!!!!!!

int main(int argc, char **argv){

    int opt;
    char *input_file;
    double value;
    if(argc == 1)
        print_help_for_test();
    while((opt = getopt(argc, argv, ":1234567A")) != -1){
        switch(opt){
            case right_input:
                test_format_of_input();
                break;
            case right_path:
                test_if_right_path();
                break;
            case right_consistency:
                test_if_right_consistency();
                break;
            case compare_time:
                test_compare_time("./tests/results");
                break;
            case fifo:
                test_fifo(FIFO_TEST_SIZE, FIFO_TEST_MAX_VAL);
                break;
            case graph:
                test_graph(GRAPH_TEST_WIDTH, GRAPH_TEST_HEIGHT, GRAPH_TEST_MAX_WEIGHT, GRAPH_TEST_TESTS_COUNT);
                break;
            case dijkstra_op:
                test_dijkstra();
                break;
            case ':':
                printf("Value required!\n");
            case 'A':
                run_all_tests();
                break;
            default:
                print_help_for_test();
                break;
        }
    }
    return 0;
}
