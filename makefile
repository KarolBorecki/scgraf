main:
	cc -c -o exec/main.o main.c
	cc -c -o exec/bfs.o algorithms/bfs.c
	cc -c -o exec/dijkstra.o algorithms/dijkstra.c
	cc -c -o exec/graph_divider.o algorithms/graph_divider.c
	cc -c -o exec/errors.o errors/errors.c
	cc -c -o exec/fifo.o FIFO/fifo.c
	cc -c -o exec/graph.o graph/graph.c
	cc -c -o exec/printer.o printer/printer.c
	cc -c -o exec/data_manager.o data_manager/data_manager.c
	cc -c -o exec/graph_generator.o data_manager/graph_generator.c
	cc -c -o exec/user_input.o data_manager/user_input.c
	cc -c -o exec/graph_solver.o solver/graph_solver.c
	cc -c -o exec/utils.o utils/utils.c
	cc -o scgraf.out exec/main.o exec/bfs.o exec/dijkstra.o exec/errors.o exec/fifo.o exec/graph.o exec/graph_divider.o exec/printer.o exec/data_manager.o exec/graph_generator.o exec/user_input.o exec/graph_solver.o exec/utils.o

test_fifo:
	cc -c -o exec/tests.o tests/tests.c
	cc -c -o exec/test_main.o test_main.c
	cc -o test.out exec/test_main.o exec/tests.o exec/bfs.o exec/dijkstra.o exec/errors.o exec/fifo.o exec/graph.o exec/graph_divider.o exec/printer.o exec/data_manager.o exec/graph_generator.o exec/user_input.o exec/graph_solver.o exec/utils.o
	./test.out fifo
	-rm exec/tests.o exec/test_main.o ./test.out

test_graph:
	cc -c -o exec/tests.o tests/tests.c
	cc -c -o exec/test_main.o test_main.c
	cc -o test.out exec/test_main.o exec/tests.o exec/bfs.o exec/dijkstra.o exec/errors.o exec/fifo.o exec/graph.o exec/graph_divider.o exec/printer.o exec/data_manager.o exec/graph_generator.o exec/user_input.o exec/graph_solver.o exec/utils.o
	./test.out graph
	-rm exec/tests.o exec/test_main.o ./test.out

test_bfs:
	cc -c -o exec/tests.o tests/tests.c
	cc -c -o exec/test_main.o test_main.c
	cc -o test.out exec/test_main.o exec/tests.o exec/bfs.o exec/dijkstra.o exec/errors.o exec/fifo.o exec/graph.o exec/graph_divider.o exec/printer.o exec/data_manager.o exec/graph_generator.o exec/user_input.o exec/graph_solver.o exec/utils.o
	./test.out bfs
	-rm exec/tests.o exec/test_main.o ./test.out

test_consistency:
	cc -c -o exec/tests.o tests/tests.c
	cc -c -o exec/test_main.o test_main.c
	cc -o test.out exec/test_main.o exec/tests.o exec/bfs.o exec/dijkstra.o exec/errors.o exec/fifo.o exec/graph.o exec/graph_divider.o exec/printer.o exec/data_manager.o exec/graph_generator.o exec/user_input.o exec/graph_solver.o exec/utils.o
	./test.out consistency
	-rm exec/tests.o exec/test_main.o ./test.out

test_dijkstra:
	cc -c -o exec/tests.o tests/tests.c
	cc -c -o exec/test_main.o test_main.c
	cc -o test.out exec/test_main.o exec/tests.o exec/bfs.o exec/dijkstra.o exec/errors.o exec/fifo.o exec/graph.o exec/graph_divider.o exec/printer.o exec/data_manager.o exec/graph_generator.o exec/user_input.o exec/graph_solver.o exec/utils.o
	./test.out dijkstra
	-rm exec/tests.o exec/test_main.o ./test.out

clean:
	-rm exec/*.o

clean_all:
	-rm exec/*.o exec/*.out ./*.out *.txt

clean_txt:
	-rm *.txt
