#include <stdio.h>
#include <stdlib.h>

#include "printer/printer.h"
//#include "errors/errors.h"
#include "graph/graph.h"
#include "Algorithms/BFS.h"
#include "Algorithms/Dijkstra.h"
#include "reader/graph_generator.h"
#include "reader/user_input.h"

void setup_menu(){
  //initzialize_errors();
  //initzialize_warnings();
}

int main(int argc, char** argv){
  setup_menu();
  
  print_greetings();

  batch_arguments_t arg = get_batch_arguments(argc, argv);
  print_arguments(arg);
  return 1;
}
