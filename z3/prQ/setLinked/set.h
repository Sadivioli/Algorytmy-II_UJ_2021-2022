
#define SET_H
#include "list/linkedlist.h"
//Implementacja używa posortowanej linked listy typu int
class setLinked{
    public:
        LinkedList *list;
        setLinked();
        ~setLinked();
        int insert(int);
        int remove(int);
        bool contains(int);
        bool isEmpty();
        int numOfElements();
        void printSet();
        int getFirst();
        setLinked operator+(setLinked&);
        setLinked operator*(setLinked&);
        setLinked operator-(setLinked&);
        bool operator==(setLinked&);
};