#include "prq.h"

using namespace std;

#define MAX_SIZE 100

PriorityQueue::PriorityQueue(){
    heap = new BinaryHeap(MAX_SIZE);
}
PriorityQueue::~PriorityQueue(){
    delete heap;
}
int PriorityQueue::insert(int element){
    heap->insert(element);
    return element;
}
int PriorityQueue::remove(){
    return heap->remove(heap->getMin());
}
int PriorityQueue::numOfElements(){
    return heap->size;
}
void PriorityQueue::printQueue(){
    heap->printHeap();
}