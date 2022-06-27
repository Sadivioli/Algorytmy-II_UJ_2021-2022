#include "set.h"
using namespace std;

int MAX_ITERATIONS = 100;
int dataSize = 100;

int main(){
    srand(time(NULL));

    int iteration = 0;

    while(iteration++ < MAX_ITERATIONS){
            
        setLinked A;
        setLinked B;
        setLinked C; //zbiór C będzie kopią zbioru A, żeby sprawdzić operacje ==

        

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
            A.printSet();
    
            cout << "B: ";
            B.printSet();
    
            cout << "A u B: ";
            (A + B).printSet();
    
            cout << "A n B: ";
            (A * B).printSet();
    
            cout << "A - B: ";
            (A - B).printSet();
    
            cout << "B - A: ";
            (B - A).printSet();

            cout << "A == B: " << (A == B) << endl;
            cout << "A == C: " << (A == C) << endl;
        }
        
        
        ofstream insFile("ins.txt", ios::in | ios::app);
        int toInsert = rand() % dataSize;

        clock_t insTime = clock();

        A.insert(toInsert);

        insFile << dataSize << ", " << (clock() - insTime) / (double)CLOCKS_PER_SEC << endl;
        
        insFile.close();


        ofstream delFile("del.txt", ios::in | ios::app);
        int toDelete = rand() % dataSize;

        clock_t delTime = clock();

        int delCount = A.remove(toDelete);

        delFile << dataSize << ", " << (clock() - delTime) / (double)CLOCKS_PER_SEC << endl;
        
        delFile.close();

        dataSize += 100;
    }
    return 0;
}