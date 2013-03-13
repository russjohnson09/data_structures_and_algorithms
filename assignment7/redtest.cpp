#include "RedBlackTree.h"

int main(){

    RedBlackTree<int> r = RedBlackTree<int>(-100);

    r.insert(80);
    r.insert(70);
    r.insert(40);
    r.insert(15);
    r.insert(30);
    r.insert(20);
    r.insert(10);
    r.insert(25);
    r.insert(25);
    r.insert(90);
    r.insert(95);
    r.insert(60);
    r.insert(45);
    r.insert(55);
    r.insert(65);
    r.insert(50);


    r.assignX();
    r.assignY();

    r.printTree();
    printf("\n");

    r.breadthFirst();

}
