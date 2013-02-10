#include <iostream>
using namespace std;

#include "BinarySearchTree.h"

/**
 * Implements an unbalanced binary search tree.
 * Note that all "matching" is based on the < method.
 */

/**
 * Construct the tree.
 */
template <class Comparable>
BinarySearchTree<Comparable>::BinarySearchTree( const Comparable & notFound ) :
  root( NULL ), ITEM_NOT_FOUND( notFound )
{
}

/**
 * Construct the tree.
 */
template <class Comparable>
BinarySearchTree<Comparable>::
BinarySearchTree( BinaryNode<Comparable> * root_given, const Comparable & notFound ) :
  root( root_given ), ITEM_NOT_FOUND( notFound )
{
}


/**
 * Copy constructor.
 */
template <class Comparable>
BinarySearchTree<Comparable>::
BinarySearchTree( const BinarySearchTree<Comparable> & rhs ) :
  root( NULL ), ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND )
{ 
    *this = rhs;
}

/**
 * Destructor for the tree.
 */
template <class Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree( )
{
    makeEmpty( );
}

/**
 * Insert x into the tree; duplicates are ignored.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::insert( const Comparable & x )
{
    insert( x, root );
}

/**
 * Remove x from the tree. Nothing is done if x is not found.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::remove( const Comparable & x )
{
    remove( x, root );
}


/**
 * Find the smallest item in the tree.
 * Return smallest item or ITEM_NOT_FOUND if empty.
 */
template <class Comparable>
const Comparable & BinarySearchTree<Comparable>::findMin( ) const
{
    return elementAt( findMin( root ) );
}

/**
 * Find the largest item in the tree.
 * Return the largest item of ITEM_NOT_FOUND if empty.
 */
template <class Comparable>
const Comparable & BinarySearchTree<Comparable>::findMax( ) const
{
    return elementAt( findMax( root ) );
}

/**
 * Find item x in the tree.
 * Return the matching item or ITEM_NOT_FOUND if not found.
 */
template <class Comparable>
const Comparable & BinarySearchTree<Comparable>::
                         find( const Comparable & x ) const
{
    return elementAt( find( x, root ) );
}

/**
 * Make the tree logically empty.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::makeEmpty( )
{
    makeEmpty( root );
}

/**
 * Test if the tree is logically empty.
 * Return true if empty, false otherwise.
 */
template <class Comparable>
bool BinarySearchTree<Comparable>::isEmpty( ) const
{
    return root == NULL;
}

/**
 * Print the tree contents in sorted order.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::printTree_inorder( ) const
{
    if( isEmpty( ) )
        cout << "Empty tree" << endl;
    else
        printTree_inorder( root );
}

/**
 * Print the tree contents in postfix order.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::printTree_postorder( ) const
{
    if( isEmpty( ) )
        cout << "Empty tree" << endl;
    else
        printTree_postorder( root );
}

/**
 * Print the tree contents in postfix order.
 */
template <class Comparable>
int BinarySearchTree<Comparable>::height( ) const
{
    return  height( root );
}

/**
 * Deep copy.
 */
template <class Comparable>
const BinarySearchTree<Comparable> &
BinarySearchTree<Comparable>::
operator=( const BinarySearchTree<Comparable> & rhs )
{
    if( this != &rhs )
    {
        makeEmpty( );
        root = clone( rhs.root );
    }
    return *this;
}

/**
 * Internal method to get element field in node t.
 * Return the element field or ITEM_NOT_FOUND if t is NULL.
 */
template <class Comparable>
const Comparable & BinarySearchTree<Comparable>::
elementAt( BinaryNode<Comparable> *t ) const
{
    if( t == NULL )
        return ITEM_NOT_FOUND;
    else
        return t->element;
}

/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the tree.
 * Set the new root.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::
insert( const Comparable & x, BinaryNode<Comparable> * & t ) const
{
    if( t == NULL )
        t = new BinaryNode<Comparable>( x, NULL, NULL );
    else if( x < t->element )
        insert( x, t->left );
    else if( t->element < x )
        insert( x, t->right );
    else
        ;  // Duplicate; do nothing
}

/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the tree.
 * Set the new root.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::
remove( const Comparable & x, BinaryNode<Comparable> * & t ) const
{
    if( t == NULL )
        return;   // Item not found; do nothing
    if( x < t->element )
        remove( x, t->left );
    else if( t->element < x )
        remove( x, t->right );
    else if( t->left != NULL && t->right != NULL ) // Two children
    {
        t->element = findMin( t->right )->element;
        remove( t->element, t->right );
    }
    else
    {
        BinaryNode<Comparable> *oldNode = t;
        t = ( t->left != NULL ) ? t->left : t->right;
        delete oldNode;
    }
}

/**
 * Internal method to find the smallest item in a subtree t.
 * Return node containing the smallest item.
 */
template <class Comparable>
BinaryNode<Comparable> *
BinarySearchTree<Comparable>::findMin( BinaryNode<Comparable> *t ) const
{
    if( t == NULL )
        return NULL;
    if( t->left == NULL )
        return t;
    return findMin( t->left );
}

/**
 * Internal method to find the largest item in a subtree t.
 * Return node containing the largest item.
 */
template <class Comparable>
BinaryNode<Comparable> *
BinarySearchTree<Comparable>::findMax( BinaryNode<Comparable> *t ) const
{
    if( t != NULL )
        while( t->right != NULL )
            t = t->right;
    return t;
}

/**
 * Internal method to find an item in a subtree.
 * x is item to search for.
 * t is the node that roots the tree.
 * Return node containing the matched item.
 */
template <class Comparable>
BinaryNode<Comparable> *
BinarySearchTree<Comparable>::
find( const Comparable & x, BinaryNode<Comparable> *t ) const
{
    if( t == NULL )
        return NULL;
    else if( x < t->element )
        return find( x, t->left );
    else if( t->element < x )
        return find( x, t->right );
    else
        return t;    // Match
}
/****** NONRECURSIVE VERSION*************************
template <class Comparable>
BinaryNode<Comparable> *
BinarySearchTree<Comparable>::
find( const Comparable & x, BinaryNode<Comparable> *t ) const
{
    while( t != NULL )
        if( x < t->element )
            t = t->left;
        else if( t->element < x )
            t = t->right;
        else
            return t;    // Match

    return NULL;   // No match
}
*****************************************************/

/**
 * Internal method to make subtree empty.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::
makeEmpty( BinaryNode<Comparable> * & t ) const
{
    if( t != NULL )
    {
        makeEmpty( t->left );
        makeEmpty( t->right );
        delete t;
    }
    t = NULL;
}

/**
 * Internal method to print a subtree rooted at t in sorted order.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::
printTree_inorder( BinaryNode<Comparable> *t ) const
{
    if( t != NULL )
    {
        cout << " (";
        printTree_inorder( t->left );
        cout << t->element;
        printTree_inorder( t->right );
        cout << ") ";
    }
}

/**
 * Internal method to print a subtree rooted at t in post-order.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::
printTree_postorder( BinaryNode<Comparable> *t ) const
{
    if( t != NULL )
    {
        cout << " (";
        printTree_postorder( t->left );
        printTree_postorder( t->right );
        cout << t->element;
        cout << ") ";
    }
}

/**
 * Internal method to compute the height of a subtree rooted at t.
 */
template <class Comparable>
int BinarySearchTree<Comparable>::
height( BinaryNode<Comparable> *t ) const
{
    return  t == NULL ? -1 : 1 + max(height(t->left), height(t->right));
}

/**
 * Internal method to clone subtree.
 */
template <class Comparable>
BinaryNode<Comparable> *
BinarySearchTree<Comparable>::clone( BinaryNode<Comparable> * t ) const
{
    if( t == NULL )
        return NULL;
    else
        return new BinaryNode<Comparable>( t->element, clone( t->left ), clone( t->right ) );
}



/**
 * Print the tree contents in prefix order.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::printTree_preorder( ) const
{
    if( isEmpty( ) )
        cout << "Empty tree" << endl;
    else
        printTree_preorder( root );
}

/**
 * Print the tree contents in prefix order.
 */
template <class Comparable>
void BinarySearchTree<Comparable>::printTree_preorder( const BinaryNode<Comparable> * t ) const
{
    if( t != NULL )
    {
        cout << " (";
        cout << t->element;
        printTree_preorder( t->left );
        printTree_preorder( t->right );
        cout << ") ";
    }
}

/**
 * Number of nodes in tree.
 */
template <class Comparable>
int BinarySearchTree<Comparable>::nodes( ) const 
{
    if( isEmpty( ) )
        return 0;
    else
        return nodes(root);
}


/**
 * Number of nodes in tree.
 */
template <class Comparable>
int BinarySearchTree<Comparable>::nodes( const BinaryNode<Comparable> * t ) const
{
    if ( t == NULL )
        return 0;
    else
        return 1 + nodes(t->left) + nodes(t->right);
}

/**
 * Number of leaves.
 */
template <class Comparable>
int BinarySearchTree<Comparable>::leaves( ) const 
{
    if( isEmpty( ) )
        return 0;
    else
        return leaves(root);
}


/**
 * Number of leaves.
 */
template <class Comparable>
int BinarySearchTree<Comparable>::leaves( const BinaryNode<Comparable> * t ) const 
{
    if( t == NULL )
        return 0;
    if ( t->left == NULL && t->right == NULL )
        return 1;
    else
        return leaves(t->left) + leaves(t->right);
}

/**
 * Number of full nodes.
 */
template <class Comparable>
int BinarySearchTree<Comparable>::fullNodes( ) const 
{
    if( isEmpty( ) )
        return 0;
    else
        return fullNodes(root);
}

/**
 * Number of full nodes.
 */
template <class Comparable>
int BinarySearchTree<Comparable>::fullNodes( const BinaryNode<Comparable> * t ) const 
{

    if ( t == NULL )
        return 0;
    if ( t->left == NULL)
        return fullNodes(t->right);
    if ( t->right == NULL )
        return fullNodes(t->left);

    return 1 + fullNodes(t->left) + fullNodes(t->right);
}
