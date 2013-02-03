#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int
main()
{
    BinarySearchTree<string> bt     // only a binary tree, not a BST
        (
        new BinaryNode<string>("Margaret",
                new BinaryNode<string>("John",
                        new BinaryNode<string>("Hugh",NULL,NULL),
                        new BinaryNode<string>("Amy",NULL,NULL)
                        ),
                new BinaryNode<string>("Kay",
                        new BinaryNode<string>("Peter",NULL,NULL),
                        new BinaryNode<string>("Craig",NULL,NULL)
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

    cout << "bt.height(): " << bt.height() << '\n';

    BinarySearchTree<int> bti     // only a binary tree, not a BST
        (
        new BinaryNode<int>(13,
                new BinaryNode<int>(17,
                        new BinaryNode<int>(19,NULL,NULL),
                        new BinaryNode<int>(20,NULL,NULL)
                        ),
                new BinaryNode<int>(23,
                        new BinaryNode<int>(24,NULL,NULL),
                        new BinaryNode<int>(25,NULL,NULL)
                        )
                ),
        ""
        );

}
