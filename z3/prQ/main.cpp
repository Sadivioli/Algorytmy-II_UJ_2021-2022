#include "prq.h"
using namespace std;

int MAX_ITERATIONS = 100;
int dataSize = 100;

int main(){
    srand(time(NULL));

    int iteration = 0;

    while(iteration++ < MAX_ITERATIONS){

        PriorityQueue A;

        for(int i = 0; i < dataSize; i++){
            int x = rand() % dataSize;
            A.insert(x);
        }
        if(iteration == 1){
            cout << "A: ";
            A.printQueue();

                
            //funkcja remove zwraca wartość usuwanego elementu, -1 gdy elementu nie udało się usunąć
            cout << "\nUsuwanie " << A.remove() << " z A";
            cout << "\nUsuwanie " << A.remove() << " z A";
            cout << "\nUsuwanie " << A.remove() << " z A";

            cout << "\nA: ";
            A.printQueue();
        }
    
        ofstream rmFile("rm.txt", ios::in | ios::app);

        clock_t rmTime = clock();

        A.remove();

        rmFile << dataSize << ", " << (clock() - rmTime) / (double)CLOCKS_PER_SEC << endl;

        rmFile.close();

        dataSize += 100;
    }

    return 0;
}
