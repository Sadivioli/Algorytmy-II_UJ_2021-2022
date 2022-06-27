#ifndef BIN_H
#define BIN_H
#pragma once
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>  
#include <ctime>  
#include <bits/stdc++.h>
using namespace std;

//Binary heap implementation

class BinaryHeap{
    public:
        int *heap;
        int size;
        int capacity;
        BinaryHeap(int capacity);
        void insert(int);

        //remove and return the element
        int remove(int);
        void printHeap();
        void heapify(int);
        int getParent(int);
        int getLeft(int);
        int getRight(int);
        int getMin();
};


#endif