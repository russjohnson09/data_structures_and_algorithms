#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <cstdio>
#include <queue>
#include "dsexceptions.h"
#include <iostream>        // For NULL
using namespace std;

// Red-black tree class
//
// CONSTRUCTION: with negative infinity object also
//               used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x (unimplemented)
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class RedBlackTree
{
  public:
    /**
     * Construct the tree.
     * negInf is a value less than or equal to all others.
     */
    explicit RedBlackTree( const Comparable & negInf )
    {
        nullNode    = new RedBlackNode;
        nullNode->left = nullNode->right = nullNode;
        header      = new RedBlackNode( negInf );
        header->left = header->right = nullNode;
    }

    RedBlackTree( const RedBlackTree & rhs )
    {
        nullNode    = new RedBlackNode;
        nullNode->left = nullNode->right = nullNode;
        header      = new RedBlackNode( rhs.header->element );
        header->left = header->right = nullNode;
        *this = rhs;
    }

    ~RedBlackTree( )
    {
        makeEmpty( );
        delete nullNode;
        delete header;
    }

    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException( );

        RedBlackNode *itr = header->right;

        while( itr->left != nullNode )
            itr = itr->left;

        return itr->element;
    }

    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException( );

        RedBlackNode *itr = header->right;

        while( itr->right != nullNode )
            itr = itr->right;

        return itr->element;
    }

    bool contains( const Comparable & x ) const
    {
        nullNode->element = x;
        RedBlackNode *curr = header->right;

        for( ; ; )
        {
            if( x < curr->element )
                curr = curr->left;
            else if( curr->element < x )
                curr = curr->right;
            else
                return curr != nullNode;
        }
    }

    bool isEmpty( ) const
    {
        return header->right == nullNode;
    }

    void printTree( ) const
    {
        if( header->right == nullNode )
            cout << "Empty tree" << endl;
        else
            printTree( header->right );
    }

    void makeEmpty( )
    {
        reclaimMemory( header->right );
        header->right = nullNode;
    }

    /**
     * Insert item x into the tree. Does nothing if x already prsent.
     */
    void insert( const Comparable & x )
    {
        current = parent = grand = header;
        nullNode->element = x;

        while( current->element != x )
        {
            great = grand; grand = parent; parent = current;
            current = x < current->element ?  current->left : current->right;

                // Check if two red children; fix if so
            if( current->left->color == RED && current->right->color == RED )
                handleReorient( x );
        }

            // Insertion fails if already present
        if( current != nullNode )
            return;
        current = new RedBlackNode( x, nullNode, nullNode );

            // Attach to parent
        if( x < parent->element )
            parent->left = current;
        else
            parent->right = current;
        handleReorient( x );
    }

    void remove( const Comparable & x )
    {
        cout << "Sorry, remove unimplemented; " << x <<
                " still present" << endl;
    }

    enum { RED, BLACK };

    const RedBlackTree & operator=( const RedBlackTree & rhs )
    {
        if( this != &rhs )
        {
            makeEmpty( );
            header->right = clone( rhs.header->right );
        }

        return *this;
    }

    void assignX(){
        if( header->right != nullNode )
            assignX( header->right, 0);
    }

    void assignY(){
        if( header->right != nullNode )
            assignY( header->right, 0);
    }

    void breadthFirst(){
        if( header->right != nullNode )
            breadthFirst( header->right);
    }

  private:
    struct RedBlackNode
    {
        Comparable    element;
        RedBlackNode *left;
        RedBlackNode *right;
        int           color;
        int           x; //x-coordinate
        int           y; //y-coordinate
        

        RedBlackNode( const Comparable & theElement = Comparable( ),
                            RedBlackNode *lt = NULL, RedBlackNode *rt = NULL,
                            int c = BLACK )
          : element( theElement ), left( lt ), right( rt ), color( c ) { }
    };

    RedBlackNode *header;   // The tree header (contains negInf)
    RedBlackNode *nullNode;

        // Used in insert routine and its helpers (logically static)
    RedBlackNode *current;
    RedBlackNode *parent;
    RedBlackNode *grand;
    RedBlackNode *great;

        // Usual recursive stuff
    void reclaimMemory( RedBlackNode *t )
    {
        if( t != t->left )
        {
            reclaimMemory( t->left );
            reclaimMemory( t->right );
            delete t;
        }
    }

    void printTree( RedBlackNode *t ) const
    {
        if( t != t->left )
        {
            printTree( t->left );
            cout << "(";
            cout << t->element;
            cout << ":" << t->x << ", " << t->y << ")";

            printTree( t->right );
        }
    }

    RedBlackNode * clone( RedBlackNode * t ) const
    {
        if( t == t->left )  // Cannot test against nullNode!!!
            return nullNode;
        else
            return new RedBlackNode( t->element, clone( t->left ),
                                     clone( t->right ), t->color );
    }

        // Red-black tree manipulations
    /**
     * Internal routine that is called during an insertion if a node has two red
     * children. Performs flip and rotatons. item is the item being inserted.
     */
    void handleReorient( const Comparable & item )
    {
            // Do the color flip
        current->color = RED;
        current->left->color = BLACK;
        current->right->color = BLACK;

        if( parent->color == RED )   // Have to rotate
        {
            grand->color = RED;
            if( item < grand->element != item < parent->element )
                parent = rotate( item, grand );  // Start dbl rotate
            current = rotate( item, great );
            current->color = BLACK;
        }
        header->right->color = BLACK; // Make root black
    }

    /**
     * Internal routine that performs a single or double rotation.
     * Because the result is attached to the parent, there are four cases.
     * Called by handleReorient.
     * item is the item in handleReorient.
     * theParent is the parent of the root of the rotated subtree.
     * Return the root of the rotated subtree.
     */
    RedBlackNode * rotate( const Comparable & item, RedBlackNode *theParent )
    {
        if( item < theParent->element )
        {
            item < theParent->left->element ?
                rotateWithLeftChild( theParent->left )  :  // LL
                rotateWithRightChild( theParent->left ) ;  // LR
            return theParent->left;
        }
        else
        {
            item < theParent->right->element ?
                rotateWithLeftChild( theParent->right ) :  // RL
                rotateWithRightChild( theParent->right );  // RR
            return theParent->right;
        }
    }

    void rotateWithLeftChild( RedBlackNode * & k2 )
    {
        RedBlackNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2 = k1;
    }

    void rotateWithRightChild( RedBlackNode * & k1 )
    {
        RedBlackNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1 = k2;
    }


    int assignX(RedBlackNode *t, int i) {
        t->x = (t->left == nullNode)?i:assignX(t->left,i);
        return (t->right == nullNode)?(t->x)+1:assignX(t->right,t->x+1);
    }

    void assignY(RedBlackNode *t, int i) {
        if (t != nullNode){
            t->y = i;
            assignY(t->right, i-1);
            assignY(t->left, i-1);
        }

    }

    void breadthFirst(RedBlackNode *t) {
        int x = 0;
        int y = t->y;
        queue<RedBlackNode *> q;
        RedBlackNode *s;
	    q.push(t);
	    while(!q.empty()) {
            s = q.front();
            if (y != s->y) {
                --y;
                printf("\n");
                x=0;
            }
            for (int i = 0; i < s->x - x; i++)
                printf("%6s","");
            x = s->x;
            printf("%i",s->element);
            q.pop();
            if (s->left != nullNode)
                q.push(s->left);
            if (s->right != nullNode)
                q.push(s->right);
        }
    }


};

#endif

