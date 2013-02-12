#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "BinarySearchTree.h"

using namespace std;

void printTime(double);

BinaryNode<int>* balancedUtil(int x,int* ints) {
    BinaryNode<int>* bt;
    if (x == 1) {
        bt = new BinaryNode<int>(ints[0],NULL,NULL);
    }
    else {
        bt = new BinaryNode<int>(ints[x/2],balancedUtil(x/2,ints),balancedUtil(x/2,ints+x/2+1));
    }
        return bt;

}

BinarySearchTree<int> balanced (int k) {
    if (k < 0) 
        return BinarySearchTree<int>(NULL);
    int x = pow(2,k+1) - 1;
    int* ints;
        for (int i = 0; i < x; i++)
            ints[i] = i+1;

    return  BinarySearchTree<int>(balancedUtil(x,ints));
}


BinarySearchTree<int> balanced(int);

int
main()
{

	clock_t t;
    int i;



    BinarySearchTree<string> bt
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

    BinarySearchTree<string> bt2
        (
        new BinaryNode<string>("Russ",
                new BinaryNode<string>("Christie",
                        new BinaryNode<string>("Andrew",NULL,NULL),
                        new BinaryNode<string>("Lee",
                            new BinaryNode<string>("Conner",NULL,
                                new BinaryNode<string>("Ellie",NULL,NULL)),
                            NULL)
                        ),
                new BinaryNode<string>("Tom",NULL,NULL)
                ),
        ""
        );

    BinarySearchTree<string> bt3
        (
        new BinaryNode<string>("A",
            new BinaryNode<string>("B",
                new BinaryNode<string>("D",NULL,NULL),
                new BinaryNode<string>("E",NULL,NULL)
                ),
            new BinaryNode<string>("C",
                new BinaryNode<string>("F",NULL,NULL),
                NULL
            )
        ),
    ""
    );

    BinarySearchTree<string> bt4
        (
        new BinaryNode<string>("D",
            new BinaryNode<string>("B",
                new BinaryNode<string>("A",NULL,NULL),
                new BinaryNode<string>("C",NULL,NULL)
                ),
            new BinaryNode<string>("F",
                new BinaryNode<string>("E",NULL,NULL),
                NULL
            )
        ),
    ""
    );

    BinarySearchTree<string> bt5
        (
        new BinaryNode<string>("D",
            new BinaryNode<string>("G",
                new BinaryNode<string>("A",NULL,NULL),
                new BinaryNode<string>("B",NULL,NULL)
                ),
            new BinaryNode<string>("F",
                new BinaryNode<string>("E",NULL,NULL),
                NULL
            )
        ),
    ""
    );

    BinarySearchTree<string> bt6
        (
        new BinaryNode<string>("D",
            new BinaryNode<string>("B",
                new BinaryNode<string>("A",NULL,NULL),
                new BinaryNode<string>("G",NULL,NULL)
                ),
            new BinaryNode<string>("F",
                new BinaryNode<string>("E",NULL,NULL),
                NULL
            )
        ),
    ""
    );

    BinarySearchTree<string> bt7
        (
        new BinaryNode<string>("D",
            new BinaryNode<string>("C",
                new BinaryNode<string>("A",NULL,NULL),
                new BinaryNode<string>("B",NULL,NULL)
                ),
            new BinaryNode<string>("F",
                new BinaryNode<string>("E",NULL,NULL),
                NULL
            )
        ),
    ""
    );


    cout << isBST(bt);
    cout << '\n';
    cout << '\n';

    bt.printTree_inorder();
    cout << '\n';
    bt2.printTree_inorder();
    cout << '\n';
    bt3.printTree_inorder();
    cout << '\n';

    bt4.printTree_inorder();
    cout << '\n';
    bt5.printTree_inorder();
    cout << '\n';
    bt6.printTree_inorder();
    cout << '\n';
    bt7.printTree_inorder();
    cout << '\n';


}

bool isBST(BinarySearchTree<string> t) {
    
}


void printTime(double t) {
   printf("Time in Seconds for 1000 executions: %lf\n",t/CLOCKS_PER_SEC);
}
