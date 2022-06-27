#include "list/linkedlist.h"
using namespace std;

//implementation of a hashed Set data structure using a sorted linked list
//set will be represented as an array
//values will be hashed, based on thier hash value index will be assigned, if more than one element has the same hash value a linked list will be created
//duplicate elements are not allowed in a set`
const int SIZE=100;
class HashSet{
    public:
        HashSet();
        ~HashSet();
        int len();
        bool isEmpty();
        void printSet();

        //checks whether a value is in the set
        bool contains(int);

        //inserts a given value if this value is not already in the set
        int insert(int);
        
        //removes a given value if this value is in the set
        int remove(int);
        int hash(int);

        HashSet operator+(HashSet&);
        HashSet operator-(HashSet&);
        HashSet operator*(HashSet&);
        bool operator==(HashSet&);
    private:
        struct Node{
            int key;
            int value;
            Node * next;
        };
        Node* array[SIZE];
        int size;
};
