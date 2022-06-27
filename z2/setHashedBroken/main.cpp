#include "hashTable/hash.h"
using namespace std;


int main(){
    srand(time(NULL));
    HashTable<int> hashSetA(SIZE);
    HashTable<int> hashSetB(SIZE);

    const int upperBound = SIZE * 2;
    for(int i = 0; i < upperBound; i++){
        int x = rand() % upperBound;
        hashSetA.insert(x);
    }

    for(int i = 0; i < upperBound; i++){
        int x = rand() % upperBound;
        hashSetB.insert(x);
    }

    cout << "\nhashSetA: ";
    hashSetA.printHashTable();

    cout << "\nhashSetB: ";
    hashSetB.printHashTable();
    return 0;
}