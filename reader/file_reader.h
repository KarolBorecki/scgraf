#ifndef SCGRAF_FILE_READER_H
#define SCGRAF_FILE_READER_H

#include <stdio.h>
#include "../graph/graph.h"

#define MAXBUF      20000000
#define MAXLINES    1000000

graph_t file_read(char *buf[], FILE *IN);
char * get_buf_from_file(FILE *IN);

#endif //SCGRAF_FILE_READER_H
