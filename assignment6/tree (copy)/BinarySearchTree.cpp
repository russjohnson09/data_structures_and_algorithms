#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

using namespace std;

template <class Comparable>
class BinarySearchTree;

template <class Comparable>
class BinaryNode
{
  public:
    Comparable data;
    BinaryNode *left;
    BinaryNode *right;

    BinaryNode( Comparable d, BinaryNode *lt, BinaryNode *rt )
      : data( d ), left( lt ), right( rt ) { }
};

template <class Comparable>
class BinarySearchTree {

    public:
        BinaryNode<Comparable> *root;
        BinarySearchTree( BinaryNode<Comparable> * rt): root(rt) { }

    bool isBST() {
          return(isBSTUtil(root, INT_MIN, INT_MAX));
        }

    bool isBSTUtil(struct BinaryNode<Comparable>* t, int min, int max)
    {
      if (t==NULL)
         return true;
      if (t->data < min || t->data > max)
         return 0; 
      return
        isBSTUtil(t->left, min, t->data) &&
        isBSTUtil(t->right, t->data, max);
    } 


};


int main() {

    BinarySearchTree<int> bt
        (
        new BinaryNode<int>(1,
                new BinaryNode<int>(2,
                        new BinaryNode<int>(3,NULL,NULL),
                        new BinaryNode<int>(4,NULL,NULL)
                        ),
                new BinaryNode<int>(5,
                        new BinaryNode<int>(6,NULL,NULL),
                        new BinaryNode<int>(7,NULL,NULL)
                        )
                )
        );

    BinarySearchTree<int> bt2
        (
        new BinaryNode<int>(4,
                new BinaryNode<int>(1,
                        new BinaryNode<int>(0,NULL,NULL),
                        new BinaryNode<int>(3,NULL,NULL)
                        ),
                new BinaryNode<int>(7,
                        new BinaryNode<int>(6,NULL,NULL),
                        new BinaryNode<int>(8,NULL,NULL)
                        )
                )
        );

    BinarySearchTree<int> bt3
        (
        new BinaryNode<int>(1,NULL,NULL)
        );

    BinarySearchTree<int> bt4
        (
        new BinaryNode<int>(5,
            new BinaryNode<int>(1,NULL,NULL),
            new BinaryNode<int>(8,NULL,NULL)
        )
        );

    BinarySearchTree<string> bt5     // only a binary tree, not a BST
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
                )
        );

    cout << bt.isBST() << '\n';
    cout << bt2.isBST() << '\n';
  cout << bt3.isBST() << '\n';
  cout << bt4.isBST() << '\n';
  cout << bt5.isBST() << '\n';


}
