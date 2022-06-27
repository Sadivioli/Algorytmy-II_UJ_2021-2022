#include "linkedlist.h"
using namespace std;

Node::Node(int data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}
List::List(){}

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
    size = 0;
}
int LinkedList::len(){
    return size;
}
bool LinkedList::isEmpty(){
    return size == 0;
}
void LinkedList::printList(){
    Node *curr = head;
    while(curr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

bool LinkedList::contains(int val){
    Node *curr = head;
    while(curr){
        if(curr->data == val){
            return true;
        }
        curr = curr->next;
    }
    return false;
}
int LinkedList::insert(int val){
    Node *curr = head;
    Node *newNode = new Node(val);
    if(isEmpty()){
        head = newNode;
        tail = newNode;
        size++;
        return 1;
    }
    if(contains(val) == true){
        return 0;
    }
    if(val < head->data){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        size++;
        return 1;
    }
    if(val > tail->data){
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        size++;
        return 1;
    }
    while(curr){
        if(val < curr->data){
            newNode->next = curr;
            newNode->prev = curr->prev;
            curr->prev->next = newNode;
            curr->prev = newNode;
            size++;
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

//remove function will remove the item and return it
int LinkedList::remove(int val){
    Node *curr = head;
    while(curr){
        if(curr->data == val){
            if(curr == head){
                head = curr->next;
                head->prev = NULL;
                size--;
                return curr->data;
            }
            if(curr == tail){
                tail = curr->prev;
                tail->next = NULL;
                size--;
                return curr->data;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            size--;
            return curr->data;
        }
        curr = curr->next;
    }
    return -1;
}