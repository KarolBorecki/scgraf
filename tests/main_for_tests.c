#include <stdio.h>
#include <stdlib.h>

#include "../tests/tests.h"
#include "../printer/printer.h"

int main(int argc, char **argv){

    int op;
    while((opt = getopt(argc, argv, "12345A") != -1){
        switch(opt){
            case '1':

                break;
            case '2':
                break;
            case '3':
                print_in_center("test_if_right_consistancy");
                test_if_right_consistancy("../test/graph_for_test_1", 1);
                test_if_right_consistancy("../test/graph_for_test_2", 0);
                break;
            case '4':
                break;
            case '5':
                break;
            case 'A':
                break;
        }
    }


}
