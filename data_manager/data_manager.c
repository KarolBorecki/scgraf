#include "data_manager.h"

#include <limits.h>

/* data reader */

int check_if_graph_is_mesh(graph_t graph, unsigned dimension_width, unsigned dimension_height){
    for(int i= 0; i<dimension_height; i++){
        for(int j= 0; j<dimension_width; j++){
            unsigned current_node= i*dimension_width + j;
            //printf("i[%d] * j[%d] + j[%d] == %d < c_node\n", i, j, j, current_node);
            //printf("[%d] <- node [%d] <- paths count", graph->nodes[current_node].index, graph->nodes[current_node].paths_count);
            if(!is_node_mesh(&(graph->nodes[current_node]), dimension_width, graph->size-1))
                return 0;
        }
    }

    return 1;
}

int is_node_mesh(node_t node, unsigned dim_width, unsigned max_node_index){
    //printf("I got node: [%d] that has [%d] paths\n", node->index, node->paths_count);
    for(int i= 0; i < node->paths_count; i++){
        //printf("\tchecking connection: [%d]\n", node->paths[i].connection);
        if( node->paths[i].connection >= 0
        &&  node->paths[i].connection <= max_node_index
        &&  node->paths[i].connection != node->index - 1
        &&  node->paths[i].connection != node->index + 1
        &&  node->paths[i].connection != node->index - dim_width
        &&  node->paths[i].connection != node->index + dim_width
        ){
            return 0;
        }
    }
    return 1;
}


/* file printer */

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

/* file reader */

FILE * open_file(char * file_name){
    FILE * IN = fopen(file_name, "r");
    return IN;
}

graph_t get_graph_from_file(char * file_name){
    FILE * IN= open_file(file_name);
    if(IN == NULL){
        throw_error(file_read_error, "Couldnt open file!");
        return NULL;
    }
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
                sprintf(msg, "incorrect value in line %d", lines);
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

    graph_set_width_and_height(graph, width, height);
    return graph;
}

int is_node_valid(int node, int max_index){
    return (node >= 0 && node <= max_index) ? 1 : 0;
}

int is_value_valid(double value){
    return (value > 0. /*&& value < max_value*/) ? 1 : 0;
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
