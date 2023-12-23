/***************/
/*   queue.c   */
/***************/


#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "list.h"


//////////////////////////////////////////
// Init
// Aim:		create new queue
// Input:	pointer to the queue structure
// Output:	TRUE if succeeded
//////////////////////////////////////////
BOOL Q_init(QUEUE* pQue)
{
	if ( !pQue ) return False;

	L_init(&(pQue->Q));
	pQue->tail = &(pQue->Q.head);	// in an empty queue tail points to the list header
	return True;
}


/////////////////////////////////////////////
// isEmpty
// Aim:		check whether the queue is empty
// Input:	pointer to the queue structure
// Output:	TRUE if empty
/////////////////////////////////////////////
BOOL Q_isEmpty(QUEUE* pQue)
{
	return ( !pQue || !(pQue->Q.head.next) );
}


/////////////////////////////////////////////////
// Enque
// Aim:		add new element at the queue tail
// Input:	pointer to the queue structure
//			a value to be stored in the new element
// Output:	TRUE if succeeded
/////////////////////////////////////////////////
BOOL Q_enque(QUEUE* pQue, DATA Value)
{
	NODE* tmp;

	if ( !pQue ) return False;

	if ( !(tmp = L_insert(pQue->tail, Value)) ) return False;	// can't add element
	pQue->tail = tmp;
	return True;
}


/////////////////////////////////////////////
// Head
// Aim:		return value from the queue head
// Input:	pointer to the queue structure
// Output:	the value from the queue head
////////////////////////////////////////////
DATA Q_head(QUEUE* pQue)
{
	if ( Q_isEmpty(pQue) ) return EMPTY;

	return pQue->Q.head.next->key;
}


////////////////////////////////////////////
// Deque
// Aim:		erase element at the queue head
// Input:	pointer to the queue structure
// Output:	the erased value
///////////////////////////////////////////
DATA Q_deque(QUEUE* pQue)
{
	DATA	Value = Q_head(pQue);

	if ( Value == EMPTY ) return EMPTY;

	L_delete(&(pQue->Q.head));
	if ( Q_isEmpty(pQue) )		// if the last element is deleted,
		pQue->tail = &(pQue->Q.head);	// let the tail point to the list header
	return Value;
}


////////////////////////////////////////////////
// Free (additional function)
// Aim:		free the queue memory
// Input:	pointer to the queue structure
// Output:	none
////////////////////////////////////////////////
void Q_free(QUEUE* pQue)
{
	L_free(&(pQue->Q));
}


////////////////////////////////////////////////
// Print (additional function)
// Aim:		print the queue content
// Input:	pointer to the queue structure
// Output:	TRUE if succeeded
////////////////////////////////////////////////
BOOL Q_print(QUEUE* pQue)
{
	if ( !pQue ) return False;

	L_print(&(pQue->Q));
	return True;
}
