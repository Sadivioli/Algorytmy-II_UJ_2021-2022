#include "set.h"
using namespace std;

int MAX_ITERATIONS = 50;
int dataSize = 100;

int main(){
    srand(time(NULL));

    int iteration = 0;

    while(iteration++ < MAX_ITERATIONS){

        setSimple A(dataSize);
        setSimple B(dataSize);
        setSimple C(dataSize); //zbiór C będzie kopią zbioru A, żeby sprawdzić operacje ==
       
        //tworzenie zbiorów
        for(int i = 0; i < dataSize; i++){
            int x = rand() % dataSize;
            A.insert(x);
            C.insert(x);
        }
        for(int i = 0; i < dataSize; i++){
            int x = rand() % dataSize;
            B.insert(x);
        }
        if(iteration == 1){
            cout << "A: ";
            A.print();

            cout << "B: ";
            B.print();

            cout << "A u B: ";
            (A + B).print();

            cout << "A n B: ";
            (A * B).print();

            cout << "A - B: ";
            (A - B).print();

            cout << "B - A: ";
            (B - A).print();


            cout << "A == B: " << (A == B) << endl;
            cout << "A == C: " << (A == C) << endl;
        }
        
        //przeprowazamy operacje dodawania i usuwania elementów ze zbioru
        //do pliku będziemy zapisywać ilość wykonanych operacji

        ofstream insFile("ins.txt", ios::in | ios::app);
        
        int toInsert = rand() % dataSize;
        int insCount = A.insert(toInsert);

        //zapis danych do pliku 
        insFile << dataSize << ", " << insCount << endl;

        insFile.close();

        //usuwanie elementu ze zbioru
        ofstream rmFile("rm.txt", ios::in | ios::app);
        
        int toRemove = rand() % dataSize;
        int rmCount = A.remove(toRemove);

        rmFile << dataSize << ", " << rmCount << endl;

        rmFile.close();

        dataSize += 10000;
    }
   
    return 0;
}