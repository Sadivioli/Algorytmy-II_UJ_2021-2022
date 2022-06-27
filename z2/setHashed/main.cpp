#include "set.h"
using namespace std;

const int MAX_ITERATIONS = 50;
int main(){

    int iteration = 0;
    while(iteration++ < MAX_ITERATIONS){
    HashSet setA;
    HashSet setB;
    HashSet setC; //setC is the same as setA

    srand(time(NULL));

    int upperBound = 100;
    for(int i = 0; i < 200; i++){
        int x = rand() % upperBound;
        setA.insert(i);
        setC.insert(i);
    }
    for(int i = 0; i < 200; i++){
        int x = rand() % upperBound;
        setB.insert(i);
    }
    if(iteration == 1){
        cout << "A: ";
        setA.printSet();

        cout << "B: ";
        setB.printSet();

        cout << "A u B: ";
        (setA + setB).printSet();

        cout << "A n B: ";
        (setA * setB).printSet();

        cout << "A - B: ";
        (setA - setB).printSet();

        cout << "B - A: ";
        (setB - setA).printSet();

        cout << "A == B: " << (setA == setB) << endl;
        cout << "A == C: " << (setA == setC) << endl;
    }
     
    ofstream insFile("ins.txt", ios::in | ios::app);
        
        int toInsert = rand() % upperBound;
        int insCount = setA.insert(toInsert);

        //zapis danych do pliku 
        insFile << upperBound << ", " << insCount << endl;

        insFile.close();

        //usuwanie elementu ze zbioru
        ofstream rmFile("rm.txt", ios::in | ios::app);
        
        int toRemove = rand() % upperBound;
        int rmCount = setA.remove(toRemove);

        rmFile << upperBound << ", " << rmCount << endl;

        rmFile.close();

    }

    return 0;
}