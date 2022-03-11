#include "set.h"
using namespace std;

const int dataSize = 20;

int main(){
    setSimple A;
    setSimple B;
    setSimple C; //zbiór C będzie kopią zbioru A, żeby sprawdzić operacje ==

    double timeSum[dataSize], timeProd[dataSize], timeDiff[dataSize], timeEqual[dataSize];

    int iteration = 0;

    while(iteration++ < dataSize){
        
    }
    
    srand(time(NULL));
    for(int i = 0; i < N; i++){
        int x = rand() % N;
        A.insert(x);
        C.insert(x);
    }
    for(int i = 0; i < N; i++){
        int x = rand() % N;
        B.insert(x);
    }
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
    return 0;
}