#include "RedBlackTree.h"

int main(){

    RedBlackTree<int> r = RedBlackTree<int>(-100);

    r.insert(1);
    r.insert(2);
    r.insert(-1);
    r.insert(-5);
    r.insert(-6);
    r.insert(-7);
    r.insert(-8);


    r.assignX();
    r.assignY();

    r.printTree();



}
