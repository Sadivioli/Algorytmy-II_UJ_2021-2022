#include "set.h"
using namespace std;

HashSet::HashSet(){
    this->size = SIZE;
    for(int i = 0; i < SIZE; i++){
        array[i] = new Node;
        array[i]->key = 0;
        array[i]->next = NULL;
    }
}

HashSet::~HashSet(){
    for(int i = 0; i < SIZE; i++){
        Node * temp = array[i];
        while(temp != NULL){
            Node * temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
    }
}

int HashSet::hash(int key){
    return key % size;
}

int HashSet::len(){
    int count = 0;
    for(int i = 0; i < size; i++){
        Node * temp = array[i];
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
    }
    return count;
}
bool HashSet::isEmpty(){
    return len() == 0;
}
void HashSet::printSet(){
    for(int i = 0; i < size; i++){
        Node * temp = array[i];
        while(temp != NULL){
            cout << temp->key << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}

bool HashSet::contains(int val){
    int index = hash(val);
    Node * temp = array[index];
    while(temp != NULL){
        if(temp->key == val){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int HashSet::insert(int val){
    int index = hash(val);
    Node * temp = array[index];
    if(temp->key == 0){
        temp->key = val;
        return 1;
    }
    while(temp->next != NULL){
        if(temp->key == val){
            return 0;
        }
        temp = temp->next;
    }
    if(temp->key == val){
        return 0;
    }
    Node * newNode = new Node;
    newNode->key = val;
    newNode->next = NULL;
    temp->next = newNode;
    return 1;
}

int HashSet::remove(int val){
    int index = hash(val);
    Node * temp = array[index];
    if(temp->key == 0){
        return 0;
    }
    if(temp->key == val){
        array[index]->key = 0;
        return 1;
    }
    while(temp->next != NULL){
        if(temp->next->key == val){
            Node * temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

HashSet HashSet::operator+(HashSet& set){
    HashSet newSet;
    for(int i = 0; i < size; i++){
        Node * temp = array[i];
        while(temp != NULL){
            newSet.insert(temp->key);
            temp = temp->next;
        }
    }
    for(int i = 0; i < set.size; i++){
        Node * temp = set.array[i];
        while(temp != NULL){
            newSet.insert(temp->key);
            temp = temp->next;
        }
    }
    return newSet;
}

HashSet HashSet::operator-(HashSet& set){
    HashSet newSet;
    for(int i = 0; i < size; i++){
        Node * temp = array[i];
        while(temp != NULL){
            newSet.insert(temp->key);
            temp = temp->next;
        }
    }
    for(int i = 0; i < set.size; i++){
        Node * temp = set.array[i];
        while(temp != NULL){
            newSet.remove(temp->key);
            temp = temp->next;
        }
    }
    return newSet;
}

HashSet HashSet::operator*(HashSet& set){
    HashSet newSet;
    for(int i = 0; i < size; i++){
        Node * temp = array[i];
        while(temp != NULL){
            if(set.contains(temp->key)){
                newSet.insert(temp->key);
            }
            temp = temp->next;
        }
    }
    return newSet;
}

bool HashSet::operator==(HashSet& set){
    if(len() != set.len()){
        return false;
    }
    for(int i = 0; i < size; i++){
        Node * temp = array[i];
        while(temp != NULL){
            if(!set.contains(temp->key)){
                return false;
            }
            temp = temp->next;
        }
    }
    return true;
}