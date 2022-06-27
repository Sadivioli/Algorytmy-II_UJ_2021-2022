#include "graph.h"

using namespace std;

#define dataSize 500

int main(){
    srand(time(NULL));
    ofstream rmFile;
    rmFile.open("rm.txt");

    for (int i = 1; i < dataSize; i++) {
        ADTGraph A(dataSize);

        while (A.sizeOfGraph() < i) {
            A.addVertex(rand() % dataSize);
            A.addEdge(rand() % dataSize, rand() % dataSize);
        }

        int random;
        do{
            random = rand() % dataSize ;
        } while(!A.getVertexValue(random));

        auto start = std::chrono::system_clock::now();

        A.removeVertex(random);

        auto end = std::chrono::system_clock::now();

        std::chrono::duration<double> execTime = end - start;

        rmFile << i << " " << execTime.count() << endl;
    }

    rmFile.close();

    return 0;
}