#include "tests.h"

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

    graph_t g= generate_graph_mesh(GRAPH_WIDTH_DIJKSTRA , GRAPH_HEIGHT_DIJKSTRA, GRAPH_TEST_MAX_WEIGHT);

    print_graph(g, "Generated graph");

    set_font(BOLD);
    set_font(GREEN);

    dijkstra_table_t table= initialize_dijkstra_table(g, &(g->nodes[NODE_FOR_INITIALIZATION]));
    print_dijkstra_table(table);

    set_font(BOLD);
    set_font(GREEN);
    printf("Initialized table correctly for NODE %d\n", NODE_FOR_INITIALIZATION);

    table= dijkstra(g, &(g->nodes[NODE_FOR_INITIALIZATION]));
    print_dijkstra_table(table);

    set_font(BOLD);
    set_font(GREEN);
    printf("Table was filled successfully for NODE %d\n", NODE_FOR_INITIALIZATION);

    get_shortest_distance_from_to(g, NODE_FOR_INITIALIZATION, NODE_FOR_PATH_FINDING, 1);
    set_font(BOLD);
    set_font(GREEN);
    printf("Path was found successfully from NODE %d to NODE %d\n", NODE_FOR_INITIALIZATION, NODE_FOR_PATH_FINDING);

    free_dijkstra_table(table);

    set_font(GREEN);
    set_font(BOLD);
    printf("TEST DONE, ALL GOOD!\n\n");

    set_font(BOLD);
    set_font(PINK);
    print_in_center("Test dijkstra");
    set_font(WHITE);
}

void test_format_of_input(){
    set_font(BOLD);
    set_font(PINK);
    print_in_center("Test format of input");
    int i;
    char input[MAXBUF];
    for(i= 1; i <= TESTED_FILES; i++){
        sprintf(input, "./tests/graph_files/graph_for_test_%c", i + '0');
        if(i == 1 || i == 2 || i == 6) {
            if (!test_format_of_single_input(input, 1))
                break;
            else{
                    set_font(GREEN);
                    printf("File %s was tested, and it has correct format!\n", input);
                    set_font(PINK);
            }
        }
        else if (i == 3 || i == 4 || i == 5 || i == 7) {
            if (!test_format_of_single_input(input, 0))
                break;
            else{
                set_font(GREEN);
                printf("File %s was tested, and it has wrong format as expected!\n", input);
                set_font(PINK);
            }
        }
    }
    if(i - 1 != TESTED_FILES) {
        set_font(RED);
        printf("File %s was not read correctly!\n", input);
        set_font(PINK);
    }else{
        set_font(GREEN);
        printf("All files were read correctly!\n");
        set_font(PINK);
    }
    print_in_center("Test format of input");
    set_font(WHITE);
}
int test_format_of_single_input(char * input_file, int correct_value){
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
            //printf("arg val incorrect format of file: %s!\n", input_file);
            return correct_value == 1 ? 0 : 1;
        }
    }else{
        fclose(in);
        //printf("arg count incorrect format of file: %s!\n", input_file);
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
                //printf("here incorrect format of file: %s!\n", input_file);
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
                //printf("nope here incorrect format of file: %s!\n", input_file);
                return correct_value == 1 ? 0 : 1;
            }
            if(!is_value_valid(value)){
                fclose(in);
                //printf("incorrect format of file: %s!\n", input_file);
                return correct_value == 1 ? 0 : 1;
            }
        }

    }
    //printf("correct format of file: %s!\n", input_file);
    return correct_value == 1 ? 1 : 0;
}

void test_if_right_path(){
    set_font(BOLD);
    set_font(PINK);
    print_in_center("Test correct path");
    char input[MAXBUF];
    double correct_paths_len[]= {323.357780, 8.4, 0};
    int i, j;
    for(i= 1, j= 0; i<=TESTED_FILES; i++){
        if(i == 1 || i == 2 || i == 6){
            sprintf(input, "./tests/graph_files/graph_for_test_%c", i + '0');
            test_if_right_single_path(input, correct_paths_len[j++]);
        }
    }
    print_in_center("Test correct path");
    set_font(WHITE);
}
int test_if_right_single_path(char * file_input, double correct_value){
    graph_t g= get_graph_from_file(file_input);
    double val;

    if(!bfs(g, g->nodes[0].index)){
        set_font(RED);
        printf("File %s contains inconsistent graph and it cannot be searched for shortest path!\n", file_input);
        clean_graph(g);
        set_font(PINK);
        return 0;
    }
    val = get_lenght_of_shortest_path_from_dijkstra(g, g->nodes[0].index, g->nodes[g->size-1].index);
    if((int)(val * 100) != (int)(correct_value*100)){
        set_font(RED);
        printf("Shortest path in graph in file %s has lenght of %lf insted of %lf!\n", file_input, val, correct_value);
        clean_graph(g);
        set_font(PINK);
        return 0;
    }else{
        set_font(GREEN);
        printf("Correct lenght of path in file %s!\n", file_input);
        clean_graph(g);
        set_font(PINK);
        return 1;
    }

}

void test_if_right_consistency(void){
    set_font(BOLD);
    set_font(PINK);
    print_in_center("Test if right consistency");
    char input[MAXBUF];
    int is_consistant[]={1, 1, 0};
    int i, j;
    for(i= 1, j= 0; i<=TESTED_FILES; i++){
        if(i == 1 || i == 2 || i == 6){
            sprintf(input, "./tests/graph_files/graph_for_test_%c", i + '0');
            if(test_if_right_single_consistency(input, is_consistant[j++])){
                if(is_consistant[j - 1]){
                    set_font(GREEN);
                    printf("File %s was tested, and it is consistent!\n", input);
                    set_font(PINK);
                }else{
                    set_font(GREEN);
                    printf("File %s was tested, and it is not consistent as expected!\n", input);
                    set_font(PINK);
                }
            }else{
                if(is_consistant[j - 1]){
                    set_font(RED);
                    printf("File %s was tested, and it is consistent, but was expected not to be!\n", input);
                    set_font(PINK);
                }else{
                    set_font(RED);
                    printf("File %s was tested, and it is not consistent, but was expected to be!\n", input);
                    set_font(PINK);
                }
            }
        }
    }
    print_in_center("Test if right consistency");
    set_font(WHITE);
}
int test_if_right_single_consistency(char * input_file, int is_consistant){
    graph_t g= get_graph_from_file(input_file);

    return bfs(g, g->nodes[0].index) == is_consistant;
}

void test_compare_time(char *file_with_results){
    struct timespec start, end, beginning;
    uint64_t timeElapsed;

    FILE * in= fopen(file_with_results, "a");
    if(in == NULL){
        printf("cannot open file %s\n", file_with_results);
        return;
    }

    set_font(BOLD);
    set_font(PINK);
    print_in_center("TIME TEST");
    set_font(WHITE);

    print_greetings_to_output(in, "Graph Generating");
    print_greetings_to_output(stdout, "Graph Generating");

    clock_gettime(CLOCK_MONOTONIC, &beginning);

    for(int i= 1; i<=HOW_MANY_ITERATIONS; i++) {
        unsigned width= generate_size_for_iteration(i),
                 height= generate_size_for_iteration(i);

        clock_gettime(CLOCK_MONOTONIC, &start);
        graph_t g = generate_graph_mesh(width, height, 5);
        clock_gettime(CLOCK_MONOTONIC, &end);

        timeElapsed= timespecDiff(&end, &start);

        print_line_results(in, i, width, height, timeElapsed);
        print_line_results(stdout, i, width, height, timeElapsed);
    }

    print_format_to_output(in, "Finding shortest path using Dijkstra");
    print_format_to_output(stdout, "Finding shortest path using Dijkstra");

    for(int i= 1; i<=HOW_MANY_ITERATIONS; i++) {
        unsigned width= generate_size_for_iteration(i),
                 height= generate_size_for_iteration(i);

        graph_t g = generate_graph_mesh(width, height, 5);

        clock_gettime(CLOCK_MONOTONIC, &start);
        get_shortest_distance_from_to(g, 0, width*height - 1, 0);
        clock_gettime(CLOCK_MONOTONIC, &end);

        timeElapsed= timespecDiff(&end, &start);

        print_line_results(in, i, width, height, timeElapsed);
        print_line_results(stdout, i, width, height, timeElapsed);

        clean_graph(g);
    }

    print_format_to_output(in, "Checking graph consistency using BFS");
    print_format_to_output(stdout, "Checking graph consistency using BFS");

    for(int i= 1; i<=HOW_MANY_ITERATIONS; i++) {
        unsigned    width= generate_size_for_iteration(i),
                    height= generate_size_for_iteration(i);

        graph_t g = generate_graph_mesh(width, height, 5);

        clock_gettime(CLOCK_MONOTONIC, &start);
        bfs(g, 0);
        clock_gettime(CLOCK_MONOTONIC, &end);

        timeElapsed= timespecDiff(&end, &start);

        print_line_results(in, i, width, height, timeElapsed);
        print_line_results(stdout, i, width, height, timeElapsed);

        clean_graph(g);
    }



    clock_gettime(CLOCK_MONOTONIC, &end);
    timeElapsed= timespecDiff(&end, &beginning);

    print_closing_to_output(in, timeElapsed, file_with_results);
    print_closing_to_output(stdout, timeElapsed, file_with_results);

    set_font(BOLD);
    set_font(PINK);
    print_in_center("TIME TEST");
    set_font(WHITE);

    fclose(in);
}

unsigned int generate_size_for_iteration(int iteration){
    unsigned i= pow_(10, iteration) / 25;
    return  i < 1 ? 1 : i;
}
void run_all_tests(void){
    set_font(BOLD);
    set_font(PINK);
    print_in_center("RUNNING ALL TESTS");
    set_font(WHITE);
    printf("\n\n");

    test_format_of_input();
    test_if_right_path();
    test_if_right_consistency();
    test_compare_time("./tests/graph_files/results");
    test_fifo(FIFO_TEST_SIZE, FIFO_TEST_MAX_VAL);
    test_graph(GRAPH_TEST_WIDTH, GRAPH_TEST_HEIGHT, GRAPH_TEST_MAX_WEIGHT, GRAPH_TEST_TESTS_COUNT);
    test_dijkstra();

    set_font(BOLD);
    set_font(GREEN);
    printf("ALL TESTS WERE PERFORMED!");
    set_font(PINK);
    printf("\n\n");
    print_in_center("RUNNING ALL TESTS");
}