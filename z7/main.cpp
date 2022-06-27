#include <map>
#include <iostream>

#include "graph/graph.h"

using namespace std;

map<string, int> graphColoring (ADTgraph& graph) {
	map<string, int> colors;
	
	list<string> nodes = graph.getVertices ();
	while (nodes.size() > 0) {
		long unsigned int max_neighbours = 0;
		string max_node;
		for (string node : nodes) {
			long unsigned int neighbours = graph.neighbours (node).size();
			if (neighbours >= max_neighbours) {
				max_node = node;
				max_neighbours = neighbours;
			}
		}
		
		int color = 0;
		bool allVisted = false;
		while (!allVisted) {
			allVisted = true;
			for (string neighbour : graph.neighbours (max_node)) {
				if (colors.count (neighbour) == 1 && colors[neighbour] == color) {
					color++;
					allVisted = false;
					break;
				}
			}
		}
		
		colors[max_node] = color;
		nodes.remove (max_node);
	}
	
	return colors;
}

int main () {
	
	ADTgraph graph;
	graph.addVertex ("A-B");
	graph.addVertex ("A-C");
	graph.addVertex ("A-D");
	graph.addVertex ("B-A");
	graph.addVertex ("B-C");
	graph.addVertex ("B-D");
	graph.addVertex ("D-A");
	graph.addVertex ("D-B");
	graph.addVertex ("D-C");
	graph.addVertex ("E-A");
	graph.addVertex ("E-B");
	graph.addVertex ("E-C");
	graph.addVertex ("E-D");
	graph.addUndirectedEdge ("A-B", "E-A");
	graph.addUndirectedEdge ("A-B", "B-D");
	graph.addUndirectedEdge ("A-B", "B-C");
	graph.addUndirectedEdge ("A-B", "D-A");
	graph.addUndirectedEdge ("A-B", "E-B");
	graph.addUndirectedEdge ("A-B", "D-B");
	graph.addUndirectedEdge ("A-C", "E-A");
	graph.addUndirectedEdge ("A-C", "B-D");
	graph.addUndirectedEdge ("A-C", "B-C");
	graph.addUndirectedEdge ("A-C", "E-B");
	graph.addUndirectedEdge ("A-C", "E-C");
	graph.addUndirectedEdge ("A-C", "D-A");
	graph.addUndirectedEdge ("A-C", "D-B");
	graph.addUndirectedEdge ("A-C", "D-C");
	graph.addUndirectedEdge ("A-D", "E-A");
	graph.addUndirectedEdge ("A-D", "E-B");
	graph.addUndirectedEdge ("A-D", "E-C");
	graph.addUndirectedEdge ("A-D", "E-D");
	graph.addUndirectedEdge ("A-D", "B-D");
	graph.addUndirectedEdge ("B-A", "D-A");
	graph.addUndirectedEdge ("B-A", "E-A");
	graph.addUndirectedEdge ("B-C", "E-B");
	graph.addUndirectedEdge ("B-C", "D-A");
	graph.addUndirectedEdge ("B-C", "D-B");
	graph.addUndirectedEdge ("B-C", "D-C");
	graph.addUndirectedEdge ("B-C", "E-C");
	graph.addUndirectedEdge ("B-D", "D-A");
	graph.addUndirectedEdge ("B-D", "E-B");
	graph.addUndirectedEdge ("B-D", "E-C");
	graph.addUndirectedEdge ("B-D", "E-D");
	graph.addUndirectedEdge ("D-A", "E-C");
	graph.addUndirectedEdge ("D-A", "E-B");
	graph.addUndirectedEdge ("D-A", "E-A");
	graph.addUndirectedEdge ("D-B", "E-C");
	graph.addUndirectedEdge ("D-B", "E-B");
	graph.addUndirectedEdge ("D-C", "E-C");
	
	map<string, int> colors = graphColoring (graph);
	
	for (pair<string, int> pairs : colors) {
		cout << pairs.first << " - " << pairs.second << endl;
	}
}