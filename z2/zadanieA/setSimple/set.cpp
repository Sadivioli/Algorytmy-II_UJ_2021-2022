#include "set.h"

using namespace std;

setSimple::setSimple(int N){
    size = N;
    array = new bool[size];
    for(int i = 0; i < size; i++){
        array[i] = 0;
    }
    
}
bool setSimple::validIndex(int x){
    if(x < 0 || x > this->size){
        return false;
    } else {
        return true;
    }
}
bool setSimple::isEmpty() const{
    for(int i = 0; i < size; i++){
        if(array[i] == 1){
            return false;
        }
    }
    return true;
}
bool setSimple::isFull() const{
    for(int i = 0; i < size; i++){
        if(array[i] == 0){
            return false;
        }
    }
    return true;
}
int setSimple::insert(int x){
    int counter = 0;
    if(validIndex(x)){
        if(array[x] == 0){
            array[x] = 1;
            counter++;
        }
        //cout << "Stan countera " << counter << endl;
        return counter;

    }
    return counter;
}
int setSimple::remove(int x){
    int counter = 0;
    if(validIndex(x)){
        if(array[x] == 1){
            array[x] = 0;
            counter++;
        }
        return counter;
    } else {
        return counter;
    }
}
bool setSimple::contains(int x){
    if(validIndex(x)){
        return array[x];
    } else {
        return false;
    }
}
int setSimple::numOfElements(){
    int counter = 0;
    for(int i = 0; i < size; i++){
        if(array[i] == 1){
            counter++;
        }
    }
    return counter;
}
setSimple setSimple::operator+(const setSimple& x){
    setSimple result = setSimple(size);
    for(int i = 0; i < size; i++){
        if(array[i] == 1 || x.array[i] == 1){
            result.array[i] = 1;
        }
    }
    return result;
    
}
setSimple setSimple::operator*(const setSimple& x){
    setSimple result = setSimple(size);
    for(int i = 0; i < size; i++){
        if(array[i] == 1 && x.array[i] == 1){
            result.array[i] = 1;
        }
    }
    return result;
}
setSimple setSimple::operator-(const setSimple& x){
    setSimple result = setSimple(size);
    for(int i = 0; i < size; i++){
        if(array[i] == 1 && x.array[i] == 0){
            result.array[i] = 1;
        }
    }
    return result;
}
bool setSimple::operator==(const setSimple& x){
    for(int i = 0; i < size; i++){
        if(array[i] != x.array[i]){
            return false;
        }
    }
    return true;
}
void setSimple::print(){
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}