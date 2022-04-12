#include <stdio.h>
#include <stdlib.h>

#include "printer/printer.h"
#include "errors/errors.h"
#include "graph/graph.h"
#include "algorithms/bfs.h"
#include "algorithms/dijkstra.h"
#include "reader/graph_generator.h"
#include "reader/user_input.h"

void setup_menu(){
  initzialize_errors();
  initzialize_warnings();
}

graph_t get_graph_from_input(char* in){
  graph_t result;
  if(strcmp(in, "") == 0) result = get_graph_from_file(in);
  else {
    printf("TUTAJ WCZYTAMY Z KONSOLI narazie generuje\n");
    result = graph_generator(10);
  }

  return result;
}

/*
CO MOZE WYWOLAC UZYTKOWNIK:
-znalezc najkrotsza droge w grafie
  WARUNKI:
    *Podanie -from lub -to (Jezeli nie poda ktoregos z nich to wywolanie z domyslnym arg)
    *[Podanie in] - zaladuje z pliku (jesli nie poda to z konsoli)
    *[Podanie out] - wpisze wynik do pliku (jesli nie poda to wypisze na konsole)
-sprawdzic czy podany graf jest SPOJNY
  WARUNKI:
    *Podanie -sp
    *[Podanie in] - zaladuje z pliku (jesli nie poda to z konsoli)
-podzielic graf na n grafow
  WARUNKI:
    *Podanie -n (divides)
    *[Podanie in] - zaladuje z pliku (jesli nie poda to z konsoli)
    *[Podanie out] - wpisze wynik do pliku (jesli nie poda to wypisze na konsole)
-wygenerowac losowy graf
  WARUNKI:
    *Podanie -x -y (Jezeli nie poda ktoregos z nich to wywolanie z domyslnym arg)
    *[Podanie out] - wpisze wynik do pliku (jesli nie poda to wypisze na konsole)
*/

//if(arg->in != NULL) -> wczytaj GRAF
//if(x != Null && y != null) -> generuj GRAF
//if(out != null && x != Null && y != null) -> zapisz graf do pliku
//if()

/*
typedef struct batch_arguments{
  char* in;
  char* out;
  unsigned from;
  unsigned to;
  unsigned x;
  unsigned y;
  unsigned n;
  unsigned sp;
} *batch_arguments_t;
*/
int main(int argc, char** argv){
  graph_t graph;

  setup_menu();
  print_greetings();

  batch_arguments_t arg = get_batch_arguments(argc, argv);
  print_arguments(arg);

  if(arg->execute == UNKNOWN)
    print_help();

  if(arg->execute == GENERATE){
    printf("TUTAJ GENERUJEMY\n");
    if(arg->from )
  } else graph = get_graph_from_input(arg->in);

  if(arg->execute == SHORTEST_PATH){
    solver_get_shortest_path(graph, arg->from, arg->to);
  }
  else if(arg->execute == CHECK_CONSISTENCY){
    solver_check_graph_consistency(graph);
  }
  else if(arg->execute == DIVIDE_GRAPH){
    solver_divide_graph_into_n_graphs(graph, arg->n);
  }

  return 0;
}
