#include "graph.h"

using namespace std;

ADTgraph::ADTgraph() {}

void ADTgraph::addVertex(int x) {
    Node temp;
	graph.insert (make_pair (x, temp));
}

void ADTgraph::removeVertex (int x) {
    graph.erase (x);
    
    for (pair<int, Node> pair : graph) {
        for (list<Edge>::iterator p = pair.second.edges.begin(); p != pair.second.edges.end(); ++p) {
            if (p->end_node == x) {
                pair.second.edges.erase (p);
                break;
            }
        }
    }
}

bool ADTgraph::adjacent (int x, int y) {
    for (Edge edge : graph.at (x).edges) {
        if (edge.end_node == y)
            return true;
    }
    return false;
}

list<int> ADTgraph::neighbours (int x) {
    list<int> nodes;
    for (Edge edge : graph.at (x).edges) {
        nodes.push_back (edge.end_node);
    }
    return nodes;
}

void ADTgraph::addEdge (int x, int y) {
    if (graph.count(x) == 1 && graph.count(y) == 1) {
        Edge edge;
        edge.end_node = y;
        graph.at (x).edges.push_back (edge);
    }
}

void ADTgraph::removeEdge (int x, int y) {
    for (list<Edge>::iterator p = graph.at (x).edges.begin(); p != graph.at (x).edges.end(); ++p) {
        if (p->end_node == y) {
            graph.at (x).edges.erase (p);
            return;
        }
    }
}

void ADTgraph::setVertexValue (int x, int v) {
    graph.at (x).weight = v;
}

int ADTgraph::getVertexValue (int x) {
    if (graph.count (x) == 0)
        return -1;
    return graph.at (x).weight;
}

void ADTgraph::setEdgeValue (int x, int y, int v) {
    for (Edge edge : graph.at (x).edges) {
        if (edge.end_node == y)
            edge.weight = v;
    }
}

int ADTgraph::getEdgeValue (int x, int y) {
    for (Edge edge : graph.at (x).edges) {
        if (edge.end_node == y)
            return edge.weight;
    }
    return -1;
}

int ADTgraph::size () {
    return graph.size ();
}

void ADTgraph::dotFile(string filename) {
    ofstream plik;
    plik.open (filename);
    plik << "digraph G {" << endl;

    for (pair<int, Node> pair : graph) {
        for (Edge edge : pair.second.edges) {
            plik << '\t' << pair.first << " -> " << edge.end_node << ";" << endl;
        }
    }

    plik << "}";
    plik.close ();
}

void ADTgraph::printGraph() {
    for (pair<int, Node> pair : graph) {
        cout << pair.first << ": ";
        for (Edge edge : pair.second.edges) {
            cout << edge.end_node << " ";
        }
        cout << endl;
    }
}