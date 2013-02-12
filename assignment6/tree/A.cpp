#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "BinarySearchTree.h"

using namespace std;

BinaryNode<int>* balancedUtil(int x,int* ints) {
    BinaryNode<int>* bt;
    if (x == 1) {
        bt = new BinaryNode<int>(*ints,0,0);
    }
    else {
        bt = new BinaryNode<int>(ints[x/2],balancedUtil(x/2,ints),balancedUtil(x/2,ints+x/2+1));
    }
        return bt;

}

BinarySearchTree<int> balanced (int k) {
    
    if (k < 0)
        return BinarySearchTree<int>(-1);

    int x = pow(2,k+1) - 1;
    int* ints = (int*) malloc (x * sizeof (int));
    int i = 0;
    while (i < x) {
        ints[i] = i+1;
        i++;
        }

    return  BinarySearchTree<int>(balancedUtil(x,ints),-1);
}

int main(int argc, char* argv[])
{
    BinarySearchTree<int> bt = balanced(atoi(argv[1]));

    bt.printTree_inorder();

    cout << '\n';

    


}
