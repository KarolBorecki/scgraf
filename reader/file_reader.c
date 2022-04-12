#include "../reader/file_reader.h"

#include <limits.h>

FILE * open_file(char * file_name){
    FILE * IN = fopen(file_name, "r");
    return IN;
}

graph_t get_graph_from_file(char * file_name, unsigned * dim_width, unsigned * dim_height){
    FILE * IN= open_file(file_name);
    printf("\n====READING GRAPH====\n"
           "Reading from file: \"%s\"\n", file_name);
    node_t help_node;
    graph_t graph;
    double max_weight= 0.;

    unsigned width, height, lines= 0, amount_of_nodes, max_node_index;
    char msg[WARNING_SIZE];
    char line[MAXBUF];

    fgets(line, MAXBUF, IN);
    //printf("%s", line);

    if(sscanf(line, "%d %d", &width, &height) == 2){
        lines++;
        if(width <= 0 || height <= 0) {
            sprintf(msg, "not positive dimensions of graph in line: %d", lines);
            throw_error(file_error, msg);
            return NULL;
        }
        amount_of_nodes = width * height;
        max_node_index  = amount_of_nodes - 1;
        graph= initzialize_graph(amount_of_nodes);
    }else{
        sprintf(msg, "expected 2 positive integers in the 1st line in line: %d", lines);
        throw_error(file_error, msg);
        return NULL;
    }

    for(int i= 0; i < amount_of_nodes; i++) {
        unsigned node_index, read_nodes, offset1;
        double value;
        fgets(line, MAXBUF, IN);
        //printf("%s", line);
        lines++;
        if ((read_nodes = read_all_nodes_from_line(line)) < 1) {
            if (!check_if_empty(line)) {
                sprintf(msg, "incorrect line format at line: %d", lines);
                throw_error(file_error, msg);
                return NULL;
            } else {          //empty line, so it' s okay for now
                continue;   //but we won' t be adding nothing to graph
            }
        }
        char *p= line;
        help_node = graph_add_node(graph);
        for(int j= 0; j<read_nodes; j++){
            sscanf(p, "%d%n :%lf%n ", &node_index, &offset1, &value, &offset1);
            p += offset1;
            int cond1;
            if( (cond1 = is_node_valid(node_index, max_node_index)) && is_value_valid(value)){
                graph_add_path(help_node, node_index, value);
                if(value > max_weight)
                    max_weight= value;
            }else if(!cond1){
                sprintf(msg, "incorrect node_index in line: %d", lines);
                throw_error(file_error, msg);
                return NULL;
            }else if(is_value_valid(value)){
                sprintf(msg, "incorrect node_index in line %d", lines);
                throw_error(file_error, msg);
                return NULL;
            }
        }

    }
    printf("\n====READING FINISHED====\n"
           "Declared size: %d x %d\n"
           "Read lines: %d\n"
           "Read nodes: %d\n"
           "Max weight value: %lf\n", width, height, lines, amount_of_nodes, max_weight);

    *dim_width=     width;
    *dim_height=    height;
    graph_set_max_path_value(graph, max_weight);
    return graph;
}

int is_node_valid(int node, int max_index){
    return (node >= 0 && node <= max_index) ? 1 : 0;
}

int is_value_valid(double value){
    return (value > 0. && value < 1.) ? 1 : 0;
}

int check_if_empty(char * line){
    int i= 0;
    while(line[i] != '\0' && line[i] != EOF){
        if(line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
            i++;
        else
            return 0;
    }
    return 1;
}

int read_all_nodes_from_line(char * line){
    char *p= line;
    int node_index, offset1, old_index= INT_MAX;
    double value;

    int read_nodes= 0;
    if(check_if_empty(line))
        return 0;
    while(sscanf(p, "%d%n :%lf%n ", &node_index, &offset1, &value, &offset1) == 2) {
        if(old_index != INT_MAX){
            if(node_index == old_index)
                break;                  //break if we read the same node 2nd time (kinda hotfix)
        }
        read_nodes++;
        old_index= node_index;
        p+= offset1;
    }
    return read_nodes;
}
