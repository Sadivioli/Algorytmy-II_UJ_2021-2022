#include <iostream>
#include "graph.h"

using namespace std;


int main () {

    srand(time(NULL));

    ADTgraph graph;

    //create a number of vertices
    graph.addVertex(1);
    //validate if vertex exists
    cout << "Wartość wierzchołka 1 po utworzeniu: " << graph.getVertexValue(1) << endl;
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);

    //assign values to vertices
    graph.setVertexValue(1, 1);
    cout << "Wartość wierzchołka 1 po nadaniu wartości: " << graph.getVertexValue(1) << endl;
    graph.setVertexValue(2, 2);
    graph.setVertexValue(3, 3);
    graph.setVertexValue(4, 4);

    //create edges
    graph.addEdge(1, 3);
    graph.setEdgeValue(1, 3, 5);
    
    cout << "Utworzono krawędź między 1 i 3 z wagą: " << graph.getEdgeValue(1,3) << endl;
    graph.addEdge(3, 1);
    graph.setEdgeValue(3, 1, 7);
    graph.addEdge(1, 2);
    graph.setEdgeValue(1, 2, 9);
    graph.addEdge(1, 3);
    graph.setEdgeValue(1, 3, 2);
    graph.addEdge(2, 1);
    graph.setEdgeValue(2, 1, 2);
    graph.addEdge(2, 3);
    graph.setEdgeValue(2, 3, 4);
    // graph.addEdge(3, 2);
    // graph.setEdgeValue(3, 2, 6);
    graph.addEdge(3, 4);
    graph.setEdgeValue(3, 4, 8);
    graph.addEdge(4, 3);
    graph.setEdgeValue(4, 3, 1);
    graph.addEdge(4, 1);
    graph.setEdgeValue(4, 1, 11);

    //print neighbors of vertex 1
    for (int neighbour : graph.neighbours(1)) {
        cout << "Sąsiad wierzchołka 1: " << neighbour << endl;
		cout << neighbour << endl;
	}
    cout << endl;

    //print graph
    graph.printGraph();

    //remove edge
    graph.removeEdge(1, 3);
    cout << "Usunięto krawędź między 1 i 3" << endl;
    graph.printGraph();

    //remove vertex
    graph.removeVertex(3);
    cout << "Usunięto wierzchołek 3" << endl;
    graph.printGraph();


    graph.dotFile("graph.txt");
    return 0;
}