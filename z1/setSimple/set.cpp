#include "set.h"

using namespace std;

setSimple::setSimple(){
    for(int i = 0; i < N; i++){
        array[i] = 0;
    }
}
bool setSimple::validIndex(int x){
    if(x < 0 || x > N){
        return false;
    } else {
        return true;
    }
}
bool setSimple::isEmpty() const{
    for(int i = 0; i < N; i++){
        if(array[i] == 1){
            return false;
        }
    }
    return true;
}
bool setSimple::isFull() const{
    for(int i = 0; i < N; i++){
        if(array[i] == 0){
            return false;
        }
    }
    return true;
}
bool setSimple::insert(int x){
    if(validIndex(x)){
        array[x] = 1;
        return true;
    } else {
        return false;
    }
}
bool setSimple::remove(int x){
    if(validIndex(x)){
        array[x] = 0;
        return true;
    } else {
        return false;
    }
}
bool setSimple::contains(int x){
    if(validIndex(x)){
        return array[x];
    } else {
        return false;
    }
}
bool setSimple::numOfElements(){
    int counter = 0;
    for(int i = 0; i < N; i++){
        if(array[i] == 1){
            counter++;
        }
    }
    return counter;
}
setSimple setSimple::operator+(const setSimple& x){
    setSimple result;
    for(int i = 0; i < N; i++){
        if(array[i] == 1 || x.array[i] == 1){
            result.array[i] = 1;
        }
    }
    return result;
    
}
setSimple setSimple::operator*(const setSimple& x){
    setSimple result;
    for(int i = 0; i < N; i++){
        if(array[i] == 1 && x.array[i] == 1){
            result.array[i] = 1;
        }
    }
    return result;
}
setSimple setSimple::operator-(const setSimple& x){
    setSimple result;
    for(int i = 0; i < N; i++){
        if(array[i] == 1 && x.array[i] == 0){
            result.array[i] = 1;
        }
    }
    return result;
}
bool setSimple::operator==(const setSimple& x){
    for(int i = 0; i < N; i++){
        if(array[i] != x.array[i]){
            return false;
        }
    }
    return true;
}
void setSimple::print(){
    for(int i = 0; i < N; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}