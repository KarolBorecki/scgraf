#include "../reader/file_reader.h"

#include "user_input.h"
#include "../errors/errors.h"
#include <string.h>
#include <stdlib.h>

graph_t get_graph_from_file(FILE *IN){
    unsigned x, y;

    char *buf;
    buf= get_buf_from_file(IN);
    if(fscanf(buf, "%d %d", &x, &y) != 2){
        if(x <= 0 || y <= 0)
            throw_error(invalid_value_error, "not positive dimensions of graph!");
    }
    for(int i= 0; i < x * y; i++){

        if(fscanf())
    }
}

char * get_buf_from_file(FILE *IN){
    char *buf_l= malloc(MAXBUF);
    char c;
    for(int i= 0; (c = fgetc(IN)) != '\n' && c != EOF; i++)
        buf_l[i]= c;
    return buf_l;
}

