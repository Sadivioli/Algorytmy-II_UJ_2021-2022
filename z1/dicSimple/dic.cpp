#include "dic.h"

using namespace std;

Dictionary::Dictionary(){
    numOfElements = 0;
}
Dictionary::~Dictionary(){
}
bool Dictionary::isEmpty(){
    return numOfElements == 0;
}
void Dictionary::printDictionary(){
    for(int i = 0; i < numOfElements; i++){
        cout << data[i] << endl;
    }
}

int Dictionary::insert(string x){
    if(numOfElements == MAX_SIZE){
        return -1;
    }
    data[numOfElements] = x;
    numOfElements++;
    return 0;
}

int Dictionary::remove(string x){
    int index = -1;
    for(int i = 0; i < numOfElements; i++){
        if(data[i] == x){
            index = i;
            break;
        }
    }
    if(index == -1){
        return -1;
    }
    for(int i = index; i < numOfElements - 1; i++){
        data[i] = data[i + 1];
    }
    numOfElements--;
    return 0;
}

bool Dictionary::contains(string x){
    for(int i = 0; i < numOfElements; i++){
        if(data[i] == x){
            return true;
        }
    }
    return false;
}