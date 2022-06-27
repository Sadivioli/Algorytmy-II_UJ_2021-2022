#include <fstream>
#include <map>
#include <list>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>  
#include <ctime>  
#include <bits/stdc++.h>

using namespace std;

class ADTgraph {
	
	public:
	
	ADTgraph () {}
	
	void addVertex (string x, int v = 0) {
		Node temp;
		temp.weight = v;
		graph.insert (make_pair (x, temp));
	}
	
	void removeVertex (string x) {
		graph.erase (x);
		
		for (pair<string, Node> pairs : graph) {
			for (typename list<Edge>::iterator p = pairs.second.edges.begin(); p != pairs.second.edges.end(); ++p) {
				if (p->end_node.compare (x) != 0) {
					pairs.second.edges.erase (p);
					break;
				}
			}
		}
	}
	
	bool exist (string x) {
		return (graph.count (x) == 0) ? false : true;
	}
	
	bool adjacent (string x, string y) {
		for (Edge edge : graph.at (x).edges) {
			if (edge.end_node.compare (y) == 0)
				return true;
		}
		return false;
	}
	
	list<string> getVertices () {
		list<string> nodes;
		for (pair<string, Node> node : graph) {
			nodes.push_back (node.first);
		}
		return nodes;
	}
	
	list<string> neighbours (string x) {
		list<string> nodes;
		for (Edge edge : graph.at (x).edges) {
			nodes.push_back (edge.end_node);
		}
		return nodes;
	}
	
	void addEdge (string x, string y, int v = 0) {
		if (graph.count(x) == 1 && graph.count(y) == 1) {
			Edge edge;
			edge.weight = v;
			edge.end_node = y;
			graph.at (x).edges.push_back (edge);
		}
	}
	
	void addUndirectedEdge (string x, string y, int v = 0) {
		if (graph.count(x) == 1 && graph.count(y) == 1) {
			Edge edge;
			edge.weight = v;
			edge.end_node = y;
			graph.at (x).edges.push_back (edge);
			edge.end_node = x;
			graph.at (y).edges.push_back (edge);
		}
	}
	
	void removeEdge (string x, string y) {
		for (typename list<Edge>::iterator p = graph.at (x).edges.begin(); p != graph.at (x).edges.end(); ++p) {
			if (p->end_node == y) {
				graph.at (x).edges.erase (p);
				return;
			}
		}
	}
	
	void setVertexValue (string x, int v) {
		graph.at (x).weight = v;
	}
	
	int getVertexValue (string x) {
		if (graph.count (x) == 0)
			return -1;
		return graph.at (x).weight;
	}
	
	void setEdgeValue (string x, string y, int v) {
		for (Edge edge : graph.at (x).edges) {
			if (edge.end_node == y)
				edge.weight = v;
		}
	}
	
	int getEdgeValue (string x, string y) {
		for (Edge edge : graph.at (x).edges) {
			if (edge.end_node == y)
				return edge.weight;
		}
		return -1;
	}
	
	int size () {
		return graph.size ();
	}
	
	void save (string filename) {
		ofstream plik;
		plik.open (filename + ".txt");
		plik << "digraph G {" << endl;
		for (pair<string, Node> pairs : graph) {
			for (Edge edge : pairs.second.edges) {
				plik << '\t' << pairs.first << " -> " << edge.end_node;
				if (edge.weight > 0)
					plik << " [label=\"" << edge.weight << "\"]" << endl;
				else
					plik << endl;
			}
		}
		plik << "}";
		plik.close ();
	}
	
	struct Edge {
		int weight = 0;
		string end_node;
	};
	
	private:
	
	struct Node {
		int weight = 0;
		list<Edge> edges;
	};
	
	map<string, Node> graph;
};