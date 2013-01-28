#include "IntegerNode.cpp"
#include <cstddef>

using namespace stddef;

class IntegerLinkedList {
    IntegerNode head;
    int numberOfItems;

  public:
    IntegerLinkedList() {head = NULL; numberOfItems = 0;}
    int getNumberOfItems() {return numberOfItems;}
    void insert(int value);
    bool remove(int value);

  };


bool IntegerLinkedList::remove(int value) {
    IntegerNode current = head;
    IntegerNode previous = NULL;
    while (current != NULL && current.getData() != value) {
        previous = current;
        current = current.getNext();
    }

    if (current==NULL) //not found
        return false;
    else {
        if (current == head)
            head = head.getNext();
        else
            previous.setNext(current.getNext());
    --numberOfItems;
    return true;
}

void IntegerLinkedList::insert(int value) {
    IntegerNode nd(value);
    nd.setNext(head);
    head = nd; 
    ++numberOfItems;
    }


int main() {
    IntegerLinkedList numbers = IntegerLinkedList;
}
