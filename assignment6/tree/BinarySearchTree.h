#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

  // Binary node and forward declaration because g++ does
  // not understand nested classes.
template <class Comparable>
class BinarySearchTree;

template <class Comparable>
class BinaryNode
{
    Comparable element;
    BinaryNode *left;
    BinaryNode *right;

  public:
    BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
      : element( theElement ), left( lt ), right( rt ) { }
  friend class BinarySearchTree<Comparable>;
};


// BinarySearchTree class
//
// CONSTRUCTION: with ITEM_NOT_FOUND object used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// Comparable find( x )   --> Return item that matches x
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order

template <class Comparable>
class BinarySearchTree
{
  public:
    explicit BinarySearchTree( const Comparable & notFound );
    BinarySearchTree( const BinarySearchTree & rhs );
    BinarySearchTree( BinaryNode<Comparable> * root_given, const Comparable & notFound );
    ~BinarySearchTree( );

    const Comparable & findMin( ) const;
    const Comparable & findMax( ) const;
    const Comparable & find( const Comparable & x ) const;
    bool isEmpty( ) const;
    void printTree_inorder( ) const;
    void printTree_postorder( ) const;
    int height( ) const;

    void makeEmpty( );
    void insert( const Comparable & x );
    void remove( const Comparable & x );

    const BinarySearchTree & operator=( const BinarySearchTree & rhs );

    void printTree_preorder() const;
    int nodes() const;
    int leaves() const;
    int fullNodes() const;

    bool isBST() const;



  private:
    BinaryNode<Comparable> *root;
    const Comparable ITEM_NOT_FOUND;

    const Comparable & elementAt( BinaryNode<Comparable> *t ) const;

    void insert( const Comparable & x, BinaryNode<Comparable> * & t ) const;
    void remove( const Comparable & x, BinaryNode<Comparable> * & t ) const;
    BinaryNode<Comparable> * findMin( BinaryNode<Comparable> *t ) const;
    BinaryNode<Comparable> * findMax( BinaryNode<Comparable> *t ) const;
    BinaryNode<Comparable> * find( const Comparable & x, BinaryNode<Comparable> *t ) const;
    void makeEmpty( BinaryNode<Comparable> * & t ) const;
    void printTree_inorder( BinaryNode<Comparable> *t ) const;
    void printTree_postorder( BinaryNode<Comparable> *t ) const;
    int height( BinaryNode<Comparable> *t ) const;
    BinaryNode<Comparable> * clone( BinaryNode<Comparable> *t ) const;

    void printTree_preorder( const BinaryNode<Comparable> * t ) const;
    int nodes( const BinaryNode<Comparable> * t ) const;
    int leaves( const BinaryNode<Comparable> * t ) const;
    int fullNodes( const BinaryNode<Comparable> * t ) const;

    bool isBST( const BinaryNode<Comparable> * t ) const;
    bool isBSTUtil( const BinaryNode<Comparable> * t, Comparable min, Comparable max ) const;

};

#include "BinarySearchTree.cpp"
#endif
