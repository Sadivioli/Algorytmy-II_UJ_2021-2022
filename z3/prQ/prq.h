#ifndef SET_H
#define SET_H
#include <stdio.h>
#include "setLinked/set.h"
#include "setLinked/list/linkedlist.h"
//priority queue is an setLinked object with slightly modified remove function
//priority of an item will be detrmined by the value of an item, so item with value 1 has the lowest priority

class PriorityQueue{
    public:
        setLinked *set;
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

        //return the first item in the queue
        int getFirst();
};


#endif