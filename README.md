# SCGRAF
Program scgraf ma na celu odnalezienie najkrótszej ścieżki na grafie, po sprawdzeniu czy graf jest spójny. Program działa w trybie nieinterakty- wnym/wsadowym. W programie zaimplementowano odczyt z pliku o określonym formacie, który może, albo zostać dostarczony przez użytkownika jako argument, albo zostać wygenerowany losowo. Program scgraf posiada również funkcje wyznaczania najdłuższej ścieżki między dwoma punktami oraz takiej, która odwiedza każdy punkt dokładnie jeden raz (o ile taka istnieje).

# Argumenty wywołania scgraf
- ***-e*** [execute]
  - ***shortest*** [specifies shortest path from (-f) to (-t) which stands for nodes indexes]
  - ***divide*** [divides graph from in (-i) or from console if -i is not specified]
  - ***consistency*** [checks graph if is consistent (cheks from -f which stands for node index, optional argument)]
  - ***generate*** [generates graph with size X (-x) x Y (-y)]
- ***-from*** [argument used in shortest path finding and consistency checking, positive number, which stands for node index]
- ***-to*** [argument used in shortest path finding, positive number, which stands for node index]
- ***-x*** [argument used in graph generating, positive number, which stands for x size of the graph]
- ***-x*** [argument used in graph generating, positive number, which stands for y size of the graph]
- ***-n*** [argument used in graph dividing, positive number greater than 1, which stands for number of graphs which original graph will be divided into]

#Argumenty wywołania scgraf_test
- ***1*** [run test of the right input in test files]
- ***2*** [run test of the right paths in test files]
- ***3*** [run test of the right consistencies in test files]
- ***4*** [run test that compares time of generation on your system] 
- ***5*** [run test of fifo]
- ***6*** [run test of graph] 
- ***7*** [run test of dijkstra algorithm and functions that is uses]
- ***A*** [run all tests]
- ***?*** [print help for using scgraf_test]