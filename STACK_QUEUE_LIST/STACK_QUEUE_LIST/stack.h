/***********************/
/*   stack.h           */
/*   a dynamic stack   */
/***********************/


#ifndef _STACK_
#define _STACK_

#include "def.h"


/*** Definitions ***/

// Stack
typedef struct  {
	NODE* head;
}STACK;


/*** Function prototypes ***/

BOOL S_init(STACK* pStk);						// create new stack

BOOL S_isEmpty(STACK* pStk);					// is the stack empty?

BOOL S_push(STACK* pStk, DATA Value);			// add new element at the stack head

DATA S_pop(STACK* pStk);						// erase element at the stack head (return its value)

DATA S_top(STACK* pStk);						// return value of the stack head

void S_free(STACK* pStk);						// free stack memory

BOOL S_print(STACK* pStk);						// print the stack content (from the head)

#endif
