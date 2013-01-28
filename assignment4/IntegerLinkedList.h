#ifndef INTEGERNODE_H
#define INTEGERNODE_H

class IntegerLinkedList {
    IntegerNode head;
    int numberOfItems;

  public:
    IntegerLinkedList() {head = NULL; numberOfItems = 0;}
    int getNumberOfItems() {return numberOfItems;}
    void insert(int value) {IntegerNode nd(value); nd.setNext(head); head = nd; ++numberOfItems;}
    bool remove(int value) {
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

    ostream& operator <<(ostream & out, const IntegerLinkedList & list)
    
    string s = " factorial = ";
    out << s << b;
    return out;

  };

#endif  /* INTEGERNODE_H */

public class IntegerLinkedList
{

  public String toString( )
  {
    String listString = "";
    IntegerNode current = head;
    for ( int i = 0; i < numberOfItems; i++ )
    {
      listString += current.getData( ) + "  ";
      current = current.getNext( );
    }
    return listString;
  }
}
