#ifndef _DATA_MANAGER_H_
#define _DATA_MANAGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../graph/graph.h"
#include "../errors/errors.h"
#include "../utils/config.h"

/* data reader */
int check_if_graph_is_mesh(graph_t graph,unsigned dimension_width, unsigned dimension_height);
int is_node_mesh(node_t node, unsigned dim_width, unsigned max_node_index);

/* file printer */
int print_graph_to_file(graph_t g, char * file_name_out); /* return TRUE (config.h) if success */

/* file reader */
FILE * open_file(char * file_name);
graph_t get_graph_from_file(char * file_name);

int is_node_valid(int node, int max_index);
int is_value_valid(double value);
int check_if_empty(char * line);
int read_all_nodes_from_line(char * line);

#endif  /* _DATA_MANAGER_H_ */
