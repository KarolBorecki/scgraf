#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../tests/tests.h"
#include "../printer/printer.h"

int main(int argc, char **argv){

    int opt;
    char *input_file;
    double value;
    while((opt = getopt(argc, argv, ":12345:A")) != -1){
        switch(opt){
            case '1':
                print_in_center("running test_if_right_input()");
                test_format_of_input("../test/graph_for_test_1", 1);
                test_format_of_input("../test/graph_for_test_2", 1);
                test_format_of_input("../test/graph_for_test_3", 0);
                break;
            case '2':
                print_in_center("running test_if_right_path()");
                test_if_right_path(input_file, value);
                break;
            case '3':
                print_in_center("running test_if_right_consistancy()");
                test_if_right_path("../test/graph_for_test_1", 2.7321);
                test_if_right_path("../test/graph_for_test_2", 1.2732);
                break;
            case '4':
                print_in_center("running test_max_size_generation()");
                test_max_size_generation(MAX_WIDTH, MAX_HEIGHT);
                break;
            case '5':
                print_in_center("running test_compare_time()");
                test_compare_time(input_file);
                break;
            case ':':
                printf("Value required!\n");
            case 'A':
                print_in_center("running all tests");
                run_all_tests();
                break;
        }
    }
    printf("Im done!\n");

    return 0;
}
