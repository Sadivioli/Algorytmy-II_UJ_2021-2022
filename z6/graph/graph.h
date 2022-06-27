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
	
	ADTgraph ();
	void addVertex(int x);
	
	void removeVertex (int x);
	
	bool adjacent (int x, int y);
	
	list<int> neighbours (int x);
	
	void addEdge (int x, int y);
	
	void removeEdge (int x, int y);
	
	void setVertexValue (int x, int v);
	
	int getVertexValue (int x);
	
	void setEdgeValue (int x, int y, int v);
	
	int getEdgeValue (int x, int y);

	int size();
	
	void dotFile(string filename);

	void printGraph();
	
	struct Edge {
		int weight = 0;
		int end_node = -1;
	};
	
	private:
	
	struct Node {
		int weight = 0;
		list<Edge> edges;
	};
	
	map<int, Node> graph;
};