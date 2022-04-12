#ifndef _SCGRAF_FILE_READER_H_
#define _SCGRAF_FILE_READER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../graph/graph.h"
#include "../errors/errors.h"

#define MAXBUF        8192
#define MAXLINES      8192
#define WARNING_SIZE  126

FILE * open_file(char * file_name);

graph_t get_graph_from_file(char * file_name, unsigned * dimension_height, unsigned * dimension_width, double * max_weight);

int is_node_valid(int node, int max_index);
int is_value_valid(double value);
int check_if_empty(char * line);
int read_all_nodes_from_line(char * line);

#endif /* _SCGRAF_FILE_READER_H_ */
