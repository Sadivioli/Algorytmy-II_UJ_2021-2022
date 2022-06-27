#include "graph.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

int main () {
	
	srand(time(0));
	ofstream plik;
	plik.open ("remove.txt");
	
	for (int i = 1; i < 50; i++) {
		chrono::duration<double> execTime (0.0);
		for (int j = 1; j < 50; j++) {
			ADTgraph graf;
			
			while (graf.size() != i) {
				graf.addVertex (rand() % 50);
				graf.addEdge (rand() % 50, rand() % 50);
			}
			
			int random;
			do {
				random = rand() % 50;
			} while (graf.getVertexValue (random) == -1);
			
			auto start = chrono::system_clock::now();
			graf.removeVertex (random);
			auto end = chrono::system_clock::now();
			
			execTime += end - start;
		}
		plik << i << " " << execTime.count() << endl;
	}
	
	plik.close();
}