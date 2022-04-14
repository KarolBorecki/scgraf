#include "file_printer.h"

void print_graph_to_file(graph_t g, char * file_name_out){
  FILE * OUT = fopen(file_name_out, "w");

  if(OUT == NULL)
    throw_error(file_read_error, "cannot create file to open!\n");


  fprintf(OUT, "%d %d\n", g->width, g->height);
  for(int i= 0; i<g->size; i++){
    fprintf(OUT, "\t");
    for(int j= 0; j<g->nodes[i].paths_count; j++){
      fprintf(OUT, "%d :%lf ", g->nodes[i].paths[j].connection, g->nodes[i].paths[j].value);
    }
    if(i != g->size - 1)
      fprintf(OUT, "\n");
  }
  fclose(OUT);

}
