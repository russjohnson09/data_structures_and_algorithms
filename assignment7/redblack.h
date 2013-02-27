#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

/*
    Each child of the Red Black Tree
*/
class Node
{
public:
    char *data; /*data*/
    char color;    /*color*/
    Node *left, *right, *parent; /*lelf, right, parent*/

    /*copy constructor*/
    Node(char *data)
    {
        this->data = new char[strlen(data) + 1];
        strcpy(this->data, data);
        color = NULL;
    }

    /*constructor*/
    Node()
    {
        this->data = new char[1];
        color = NULL;
    }

    /*destructor*/
    ~Node()
    {
        delete (this->data);
        color = NULL;
    }
};

/*
    This is a class of Red Black Tre
*/
class RedBlackTree
{
private:
    Node    *Root;    /*root*/
    Node    *Nil;    /*leaf*/

public:
    /*constructor*/
    RedBlackTree            ();

    /*destructor*/
    ~RedBlackTree            ();

    Node*    tree_successor    ( Node* x );

            /*left rotate*/
    int        leftRotate        ( Node *x );
           
            /*right rotate*/
    int        rightRotate        ( Node *x );

            /*insert key*/
    int        insert_key        ( char *data );

            /*fix up*/
    int        fixup            ( Node *z );

            /*delete key*/
    int        delete_key        ( Node *z );

            /*delete fixup*/
    int        delete_fixup    ( Node *x );

            /*in order traverse*/
    void    inOrderTraverse    ( Node *n );

            /*post order delete*/
    void    postOrderDelete    ( Node *n );
};
