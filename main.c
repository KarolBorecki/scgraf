#include <stdio.h>
#include <stdlib.h>

#include "printer.h"
#include "errors/errors.h"
#include "graph/graph.h"
#include "Algorithms/BFS.h"
#include "Algorithms/Dijkstra.h"
#include "reader/graph_generator.h"

void setup_menu(){
  initzialize_errors();
  initzialize_warnings();
}

int main(int argc, char** argv){
  setup_menu();
  
  print_greetings();

  throw_warning(default_value_warning, "");
  throw_error(memory_error, "Not enough memory!");
  return 1;
}
