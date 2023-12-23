/***********************/
/*   queue.h           */
/*   a dynamic queue   */
/***********************/


#ifndef _QUEUE_
#define _QUEUE_

#include "list.h"


/*** Definitions ***/

// Queue
typedef struct  {
	LIST Q;					// a list of the elements
	NODE *tail;				// a pointer to the list tail
}QUEUE;


/*** Function prototypes ***/

BOOL Q_init(QUEUE* pQue);					// create new queue

BOOL Q_isEmpty(QUEUE* pQue);				// is the queue empty?

BOOL Q_enque(QUEUE* pQue, DATA Value);		// add new element at the queue tail

DATA Q_deque(QUEUE* pQue);					// erase element at the queue head (return its value)

DATA Q_head(QUEUE* pQue);					// return value of the queue head

void Q_free(QUEUE* pQue);					// free queue memory

BOOL Q_print(QUEUE* pQue);					// print the queue content (from the head)

#endif
