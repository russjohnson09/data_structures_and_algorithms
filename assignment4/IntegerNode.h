#ifndef INTEGERNODE_H
#define INTEGERNODE_H

class IntegerNode {
    int data;
    IntegerNode next;

  public:
    IntegerNode() {data = 0; next = NULL;}
    IntegerNode(int newData) {data = newData;}
    int getData() {return data;}
    IntegerNode getNext() {return next;}
    void setData(int newData) {data = newData;}
    void setNext(IntegerNode nd) {next = nd;}

  };

#endif  /* INTEGERNODE_H */
