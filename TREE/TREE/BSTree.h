/******************************************/
/*   BSTree.h                             */
/*   a binary search tree with a header   */
/******************************************/


#ifndef _BSTREE_
#define _BSTREE_

#include "def.h"


/*** Type definitions ***/
typedef struct node2  {
	DATA key;
	struct node2 *left, *right;
}NODE2;

// Tree
typedef struct  {
	NODE2 head;
}TREE;


/*** Function prototypes ***/

BOOL T_init(TREE* T);				// create new tree

NODE2* T_insert(TREE* T, DATA x);	// add a new node to the tree

NODE2* T_find(TREE* T, DATA x);		// find the given key in the tree

BOOL T_delete(TREE* T, DATA x);		// erase the given key from the tree

BOOL T_free(TREE* T);				// free the tree memory

void preorderPC(NODE2* v);
void inorderPC(NODE2* v);
void postorderPC(NODE2* v);
#endif