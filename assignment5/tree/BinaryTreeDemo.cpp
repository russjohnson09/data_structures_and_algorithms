#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "BinarySearchTree.h"

using namespace std;

void printTime(double);

int
main()
{

	clock_t t;
    int i;

    BinarySearchTree<string> bt     // only a binary tree, not a BST
        (
        new BinaryNode<string>("Lee",
                new BinaryNode<string>("Christie",
                        new BinaryNode<string>("Russ",NULL,NULL),
                        new BinaryNode<string>("Andrew",NULL,NULL)
                        ),
                new BinaryNode<string>("Tom",
                        new BinaryNode<string>("Conner",NULL,NULL),
                        new BinaryNode<string>("Ellie",NULL,NULL)
                        )
                ),
        ""
        );

    cout << "bt.printTree_inorder() :\n";
    bt.printTree_inorder();
    cout << '\n';
    cout << "bt.printTree_postorder() :\n";
    bt.printTree_postorder();
    cout << '\n';
    cout << "bt.printTree_preorder() :\n";
    bt.printTree_preorder();
    cout << '\n';

    cout << "Tree # of nodes: ";
    t = clock();
    for (i = 0; i < 10000000; ++i)
        bt.nodes();
    cout << bt.nodes() << endl;
    t = clock() - t;
    printTime((double)t);
    cout << "Tree # of leaves: ";
    t = clock();
    for (i = 0; i < 10000000; ++i)
        bt.leaves();
    cout << bt.leaves() << endl;
    t = clock() - t;
    printTime((double)t);
    cout << "Tree # of full nodes: ";
    t = clock();
    for (i = 0; i < 10000000; ++i)
        bt.fullNodes();
    cout << bt.fullNodes() << endl;
    t = clock() - t;
    printTime((double)t);
}


void printTime(double t) {
   printf("Time in Seconds for 1000 executions: %lf\n",t/CLOCKS_PER_SEC);
}
