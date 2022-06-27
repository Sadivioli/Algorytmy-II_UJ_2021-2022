#include "set.h"
using namespace std;

setLinked::setLinked(){
    list = new LinkedList();
}
setLinked::~setLinked(){
    delete list;
}
bool setLinked::isEmpty(){
    return list->isEmpty();
}
int setLinked::numOfElements(){
    return list->len();
}
void setLinked::printSet(){
    list->printList();
}
bool setLinked::contains(int x){
    return list->contains(x);
}
//contains returns true if the list contains the element with value val
int setLinked::insert(int val){
    return list->insert(val);
}
int setLinked::remove(int val){
    return list->remove(val);
}

setLinked setLinked::operator+(setLinked &set){
    setLinked set2;
    Node *curr = list->head;
    while(curr){
        set2.insert(curr->data);
        curr = curr->next;
    }
    curr = set.list->head;
    while(curr){
        set2.insert(curr->data);
        curr = curr->next;
    }
    return set2;
}
setLinked setLinked::operator*(setLinked &set){
    setLinked set2;
    Node *curr = list->head;
    while(curr){
        if(set.contains(curr->data) == true){
            set2.insert(curr->data);
        }
        curr = curr->next;
    }
    return set2;
}
bool setLinked::operator==(setLinked &set){
    if(list->len() != set.list->len()){
        return false;
    }
    Node *curr = list->head;
    while(curr){
        if(set.contains(curr->data) == false){
            return false;
        }
        curr = curr->next;
    }
    return true;
}

setLinked setLinked::operator-(setLinked &set){
    setLinked set2;
    Node *curr = list->head;
    while(curr){
        if(set.contains(curr->data) == false){
            set2.insert(curr->data);
        }
        curr = curr->next;
    }
    return set2;
}
int setLinked::getFirst(){
    return list->head->data;
}