#include "heap.h"
using namespace std;

BinaryHeap::BinaryHeap(int capacity){
    this->capacity = capacity;
    heap = new int[capacity];
    size = 0;
}


void BinaryHeap::insert(int element){
    if(size == capacity)
    {
        //cout << "Heap is full" << endl;
        return;
    }
    heap[size] = element;
    int i = size;
    while(i > 0 && heap[i] > heap[getParent(i)])
    {
        swap(heap[i], heap[getParent(i)]);
        i = getParent(i);
    }
    size++;
}

int BinaryHeap::remove(int element){
    if(size == 0)
    {
        cout << "Heap is empty" << endl;
        return -1;
    }
    int i = 0;
    while(heap[i] != element)
    {
        i++;
    }
    swap(heap[i], heap[size-1]);
    size--;
    heapify(i);
    return heap[size];
}

int BinaryHeap::getParent(int i){
    return (i-1)/2;
}
int BinaryHeap::getLeft(int i){
    return 2*i + 1;
}
int BinaryHeap::getRight(int i){
    return 2*i + 2;
}

void BinaryHeap::heapify(int i){
    int l = getLeft(i);
    int r = getRight(i);
    int smallest = i;
    if(l < size && heap[l] < heap[i])
    {
        smallest = l;
    }
    if(r < size && heap[r] < heap[smallest])
    {
        smallest = r;
    }
    if(smallest != i)
    {
        swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}

void BinaryHeap::printHeap(){
    for(int i = 0; i < size; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}
int BinaryHeap::getMin(){
    return heap[0];
}