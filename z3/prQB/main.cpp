#include "prq.h"

using namespace std;

//int MAX_ITERATIONS = 1000;
int dataSize = 100;

int main(){
    srand(time(NULL));

        PriorityQueue A;

        for(int i = 0; i < dataSize; i++){
            int x = rand() % dataSize;
            A.insert(x);
        }
            cout << "A: ";
            A.printQueue();

            //funkcja remove zwraca wartość usuwanego elementu, -1 gdy elementu nie udało się usunąć
            //delete usuwa roota a na jego miejsce wstawia ostatni element z kopca.
            //traktujemy root jako element o najniższym priorytecie
            cout << "\nUsuwanie " << A.remove() << " z A";
            cout << "\nA: ";
            A.printQueue();
            cout << "\nUsuwanie " << A.remove() << " z A";
            cout << "\nA: ";
            A.printQueue();
            cout << "\nUsuwanie " << A.remove() << " z A";
            cout << "\nA: ";
            A.printQueue();
            
}