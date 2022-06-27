#include "prq.h"
using namespace std;

PriorityQueue::PriorityQueue(){
    set = new setLinked();
}
PriorityQueue::~PriorityQueue(){
    delete set;
}
int PriorityQueue::insert(int value){
    set->insert(value);
    return 0;
}
int PriorityQueue::remove(){
    //get the value of the item with the lowest priority, which is the first item in the set
    int value = set->getFirst();
    return set->remove(value);
}
void PriorityQueue::printQueue(){
    set->printSet();
}
bool PriorityQueue::contains(int value){
    return set->contains(value);
}
bool PriorityQueue::isEmpty(){
    return set->isEmpty();
}
int PriorityQueue::numOfElements(){
    return set->numOfElements();
}
int PriorityQueue::priority(int value){
    return value;
}
int PriorityQueue::getFirst(){
    return set->getFirst();
}