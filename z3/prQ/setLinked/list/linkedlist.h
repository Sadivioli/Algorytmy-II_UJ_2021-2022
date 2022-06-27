#ifndef LLIST_H
#define LLIST_H
#pragma once
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>  
#include <ctime>  
#include <bits/stdc++.h>
using namespace std;

//Zmodyfikowana implementacja linkedList
//Lista auto-sortowana

class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data);
};

class List{
    public:
        List();

        virtual int len(){return 0;}
        virtual bool isEmpty(){return false;}
        virtual void printList(){}

        virtual bool contains(int){return false;};
        virtual int insert(int){return -1;}
        virtual int remove(){return -1;}
};

class LinkedList : public List{
    public:
        Node *head;
        Node *tail;
        int size;
        LinkedList();
        int len();
        bool isEmpty();
        void printList(); 

        bool contains(int);
        int insert(int); //inserts element to the list at correct position in ascending order 
        
        //remove function will remove the item with the lowest priority and return its value
        int remove(int);
};

#endif