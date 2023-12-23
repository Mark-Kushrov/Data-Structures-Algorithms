/***************/
/*   stack.c   */
/***************/


#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


//////////////////////////////////////////
// Init
// Aim:		create new stack
// Input:	pointer to the stack structure
// Output:	TRUE if succeeded
//////////////////////////////////////////
BOOL S_init(STACK* pStk)
{
	if ( !pStk ) return False;

	pStk->head = NULL;
	return True;
}


/////////////////////////////////////////////
// isEmpty
// Aim:		check whether the stack is empty
// Input:	pointer to the stack structure
// Output:	TRUE if empty
/////////////////////////////////////////////
BOOL S_isEmpty(STACK* pStk)
{
	return ( ( pStk == NULL ) || ( pStk->head == NULL ) );
}


/////////////////////////////////////////////////
// Push
// Aim:		add new element at the stack head
// Input:	pointer to the stack structure
//			a value to be added
// Output:	TRUE if succeeded
/////////////////////////////////////////////////
BOOL S_push(STACK* pStk, DATA Value)
{
	NODE* tmp;

	if ( !pStk ) return False;

	if ( (tmp = (NODE*)malloc(sizeof(NODE))) == NULL ) return False;

	tmp->key = Value;
	tmp->next = pStk->head;
	pStk->head = tmp;
	return True;
}


////////////////////////////////////////////
// Pop
// Aim:		erase element at the stack head
// Input:	pointer to the stack structure
// Output:	the erased value
///////////////////////////////////////////
DATA S_pop(STACK* pStk)
{
	NODE	*tmp;
	DATA	Value;

	if ( S_isEmpty(pStk) ) return EMPTY;

	tmp = pStk->head;
	Value = tmp->key;
	pStk->head = tmp->next;
	free(tmp);
	return Value;
}


/////////////////////////////////////////////
// Top
// Aim:		return value from the stack head
// Input:	pointer to the stack structure
// Output:	the value from the stack head
////////////////////////////////////////////
DATA S_top(STACK* pStk)
{
	if ( S_isEmpty(pStk) ) return EMPTY;

	return pStk->head->key;
}


////////////////////////////////////////////////
// Free (additional function)
// Aim:		free the stack memory
// Input:	pointer to the stack structure
// Output:	none
////////////////////////////////////////////////
void S_free(STACK* pStk)
{
	while ( S_pop(pStk) != EMPTY ) ;
}


////////////////////////////////////////////////
// Print (additional function)
// Aim:		print the stack content (assume DATA is int)
// Input:	pointer to the stack structure
// Output:	TRUE if succeeded
////////////////////////////////////////////////
BOOL S_print(STACK* pStk)
{
	NODE *tmp;

	if ( !pStk ) return False;

	printf("\n");
	for ( tmp = pStk->head;  tmp;  tmp = tmp->next )
		printf(" %d ", tmp->key);
	printf("\n");
	return True;
}
