#ifndef SET_H
#define SET_H
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stack>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int N = 100;

//the set is implemented using an array of N elements being either [0] or [1]
class setSimple{
    public:
        bool array[N];
        setSimple();
    //metody
        bool insert(int);
        bool remove(int);
        bool contains(int);
    //pomocnicze
        bool isEmpty() const;
        bool isFull() const;
        bool numOfElements();
        bool validIndex(int);
        void print();
    //operacje na zbiorach
        setSimple operator+(const setSimple&);
        setSimple operator*(const setSimple&);
        setSimple operator-(const setSimple&);
        bool operator==(const setSimple&);
};
#endif