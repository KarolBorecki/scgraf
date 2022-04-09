#ifndef _DATA_READER_H_
#define _DATA_READER_H_

#include "../graph/graph.h"

typedef struct graph_raw{
  unsigned   size;
  unsigned** connections; /* connection for node of adaquet index*/
  double**   connections_values;
} *graph_raw_t;

graph_t interprete_raw_data(graph_raw_t data){

}

#endif /* _DATA_READER_H_ */
