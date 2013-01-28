//LinkedList.cpp
#include "Node.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

void LinkedList::insert(int value) {
    Node *p = new Node(value, head);
    head = p;
    ++numberOfItems;
}

bool LinkedList::remove(int value) {
    Node *current = head;
    Node *previous;
    while (current != 0 && current->getData() != value) {
        previous = current;
        current = current->getNext();
    }

    if (current==0)
        return false;

    if (current == head)
        head = head->getNext();
    else
        previous->setNext(current->getNext());

    --numberOfItems;
    return true;
}

ostream & operator<<(ostream & os, const LinkedList & l) {
    Node *p = l.getHead();
    while(p!=0){
        os << p->getData() << "  ";
        p = p->getNext();
    }
    
    return  os;
}
