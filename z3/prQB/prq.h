#ifndef PRQ
#define PRQ
#pragma once
#include "binHeap/heap.h"

class PriorityQueue{
    public:
        BinaryHeap *heap;
        PriorityQueue();
        ~PriorityQueue();
        int insert(int);
        
        //remove function will remove the item with the lowest priority and return its value
        int remove();
        bool contains(int);
        bool isEmpty();
        int numOfElements();
        void printQueue();

        //return the priority of an item, simply returns the value of the item
        int priority(int);
};

#endif