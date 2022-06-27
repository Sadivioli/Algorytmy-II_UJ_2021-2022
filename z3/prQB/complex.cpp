#include "prq.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

int main(){
    srand(time(0));
    ofstream rmFile;
    rmFile.open("rm.txt");

    for (int i = 1; i < 100; i++) {
		chrono::duration<double> execTime (0.0);
		for (int j = 1; j < 100; j++) {
			PriorityQueue A;
			
			while (A.numOfElements() < i) {
				A.insert(rand() % 100);
			}
			
			auto start = chrono::system_clock::now();
			A.remove();
			auto end = chrono::system_clock::now();
			
			execTime += end - start;
		}
		rmFile << i << " " << execTime.count() << endl;
	}
	
	rmFile.close();
}