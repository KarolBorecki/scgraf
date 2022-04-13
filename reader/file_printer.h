#ifndef _FILE_PRINTER_H_
#define _FILE_PRINTER_H_

#include "../graph/graph.h"
#include "../errors/errors.h"

#include <stdlib.h>
#include <stdio.h>

void print_graph_to_file(graph_t g, char * file_name_out);

#endif  /* _FILE_PRINTER_H_ */
