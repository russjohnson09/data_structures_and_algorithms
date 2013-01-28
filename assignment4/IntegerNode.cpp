#include <iostream>

using namespace std;

class IntegerNode {
    int data;
    IntegerNode* next;

  public:
    IntegerNode() {data = 0; next = NULL;}
    IntegerNode(int newData) {data = newData;}
    int getData() {return data;}
    IntegerNode* getNext() {return next;}
    void setData(int newData) {data = newData;}
    void setNext(IntegerNode* nd) {next = nd;}

  };

int main() {

    IntegerNode *root;       // This won't change, or we would lose the list in memory
    IntegerNode *conductor;  // This will point to each node as it traverses the list

    root = new IntegerNode;  // Sets it to actually point to something
    root->next = NULL;   //  Otherwise it would not work well
    root->x = 12;
    conductor = root; // The conductor points to the first node

    if ( conductor != NULL ) { //Makes sure there is a place to start
      while ( conductor->next != NULL ) {
        cout<< conductor->x;
        conductor = conductor->next;
      }
      cout<< conductor->x << '\n';
    }

    conductor->next = new IntegerNode;  // Creates a node at the end of the list
    conductor = conductor->next; // Points to that node
    conductor->next = NULL;         // Prevents it from going any further
    conductor->x = 42;

}
