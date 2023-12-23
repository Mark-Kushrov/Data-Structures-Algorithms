#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "BSTree.h"


//////////////////////////////////////////
// Init
// Aim:		create new tree
// Input:	pointer to the tree structure
// Output:	TRUE if succeeded
//////////////////////////////////////////
BOOL T_init(TREE* T)
{
	if ( !T ) return False;

	T->head.key = INT_MAX;	// instead of infinity
	T->head.left = NULL;		// this field will point to the tree
	return True;
}


/**************************************/
//  Auxiliary function
//  The function returns a pointer to the father of x (or its place)
//  Must: v != NULL and v is a predecessor of x in the tree
/**************************************/
NODE2* father(NODE2* v, DATA x)
{
	NODE2* p = ( v->key > x ) ? v->left : v->right ; // p is a son of v in a needed direction
	if ( !p || ( p->key == x ) )			// v is a father of x (or its place)
		return v;
	return father(p, x);
}


//////////////////////////////////////////
// Insert
// Aim:		add a new node to the tree
// Input:	pointer to the tree structure
//          a key of the new node
// Output:	pointer to the new node
//////////////////////////////////////////
NODE2* T_insert(TREE* T, DATA x)
{
	NODE2 *p, *fth;
	NODE2 **ptr;

	if ( !T ) return NULL;		// no tree

	fth = father(&(T->head), x);		// father of x in the tree
	ptr = ( fth->key > x ) ? &(fth->left) : &(fth->right) ;	// pointer to field that points on x

	if ( *ptr )  return NULL;	//  no insertion: x already exists

	if ( !(p = (NODE2*)malloc(sizeof(NODE2))) )  return NULL;  //  allocation error

	p->key = x;					// fill new node
	p->left = p->right = NULL;
	*ptr = p;					// connect it to the tree
	return p;					// the node inserted 
}


///////////////////////////////////////////
// Find
// Aim:		find the given key in the tree
// Input:	pointer to the tree structure
//          a key to be found
// Output:	pointer to the found node
///////////////////////////////////////////
NODE2* T_find(TREE* T, DATA x)
{
	NODE2 *fth;

	if ( !T ) return NULL;		// no tree

	fth = father(&(T->head), x);		// father of x in the tree
	return ( fth->key > x ) ? fth->left : fth->right ;
}


///////////////////////////////////////////
// Delete
// Aim:		erase the given key from the tree
// Input:	pointer to the tree structure
//          a key to be deleted
// Output:	TRUE if succeeded
///////////////////////////////////////////
BOOL T_delete(TREE* T, DATA x)
{
	NODE2 *p, *fth;
	NODE2 **ptr;

	if ( !T ) return False;		// no tree

	fth = father(&(T->head), x);		// father of x in the tree
	ptr = ( fth->key > x ) ? &(fth->left) : &(fth->right) ;	// pointer to field that points on x

	if ( !(p = *ptr) )  return False;  //  no deletion: x does not exist

	if ( p->left && p->right )  {	// the node has 2 sons
		// find successor
		for ( ptr = &(p->right);  (*ptr)->left;  ptr = &((*ptr)->left) ) ;
		p->key = (*ptr)->key;	// keep its key
		p = *ptr;				// make p point on it
	}

	*ptr = ( p->left ) ? p->left : p->right ;	// connect p's son to p's father
	free(p);
	return True;  // x deleted
}




/**************************************/
//  Auxiliary function
//  Frees the tree memory in postorder
/**************************************/
void postorderFree(NODE2* v)
{
	if ( !v ) return;

	postorderFree(v->left);
	postorderFree(v->right);
	free(v);
}


///////////////////////////////////////////
// Free
// Aim:		erase the tree
// Input:	pointer to the tree structure
// Output:	TRUE if succeeded
///////////////////////////////////////////
BOOL T_free(TREE* T)
{
	if ( !T ) return False;		// no tree

	postorderFree(T->head.left);
	T->head.left = NULL;
	return True;
}


/**************************************/
/* 3 traversal functions: each one    */
/* prints the vertex keys in the      */
/* traversal order.                   */
/* Parameter is a pointer to the root */
/**************************************/

/**************************************/
void preorderPC(NODE2* v)
{
	if ( !v )  return;

	printf("%d ", v->key);
	preorderPC(v->left);
	preorderPC(v->right);
}

/**************************************/
void inorderPC(NODE2* v)
{
	if ( !v )  return;

	inorderPC(v->left);
	printf("%d ", v->key);
	inorderPC(v->right);
}

/**************************************/
void postorderPC(NODE2* v)
{
	if ( !v )  return;

	postorderPC(v->left);
	postorderPC(v->right);
	printf("%d ", v->key);
}
