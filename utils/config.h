#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <limits.h>

#define TRUE 1
#define FALSE 0

/* user_input.h */
#define SHORTEST_PATH_EXEC "shortest"
#define CONSISTENCY_EXEC "consistency"
#define DIVIDE_EXEC "divide"
#define GENERATE_EXEC "generate"
#define PRINT_EXEC "print"
#define MAKE_UNDIRECTED_EXEC "make_undirected"

/* dijkstra.h */
#define INVALID_NODE    UINT_MAX
#define INF             DBL_MAX
#define ZERO            0

/* fifo.h */
#define START_QUEUE_SIZE 20
#define FIFO_ENLARGE_MULTIPLIER 2

/* graph.h */
#define START_NODES_PATHS_COUNT 4
#define GRAPH_ENLARGE_MULTIPLIER 2

/* printer.h */
#define CONSOLE_OUTPUT_LEN 90

/* file_reader.h */
#define MAXBUF        8192
#define MAXLINES      8192
#define WARNING_SIZE  126

/* graph_generator.h */
#define GENERATED_NODE_CONNECTIONS_COUNT 5
#define GENERATED_PATH_MAX_VALUE 10

/* user_input.h */
#define MAX_FILE_NAME_LEN 256

#define DEFAULT_FROM 0
#define DEFAULT_TO 5
#define DEFAULT_X 5
#define DEFAULT_Y 5
#define DEFAULT_N 2
#define DEFAULT_MAX_PATH_VAL 1

#define VALUE_NOT_SPECIFIED -1

/* errors.h */
#define MAX_ERR_MSG_LENGTH 20
#define MAX_ERR_ADDITIONAL_MSG_LENGTH 100


#endif /* _CONFIG_H_ */
