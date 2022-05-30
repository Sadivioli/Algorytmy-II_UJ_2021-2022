//Dictionary data structure implemented using a one-dimensional array.
//Array has a size N, where N is the number of elements in the dictionary.
//Array will contain 50 character long strings

#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <chrono>

using namespace std;

static const int MAX_SIZE = 100;

class Dictionary{
    public:
        Dictionary();
        ~Dictionary();
        bool isEmpty();
        void printDictionary();
        bool contains(string x);
        int insert(string x);
        int remove(string x);
    private:
        string data[MAX_SIZE];
        int numOfElements;
};

#endif