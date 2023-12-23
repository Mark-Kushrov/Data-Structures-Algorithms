/**************************/
/*   heap.h               */
/*   a heap in an array   */
/**************************/


#ifndef _HEAP_
#define _HEAP_


#include "def.h"

/*** Definitions ***/

typedef struct  {
	DATA *keys;
	int  N, count;
}HEAP;


/*** Function prototypes ***/

BOOL H_init(HEAP *H, int N);					// create new heap

int H_insert(HEAP *H, DATA x);					// insert item x

DATA H_delMax(HEAP *H);							// delete maximal value

DATA H_findMax(HEAP *H);						// return maximal value

BOOL H_makeHeap(HEAP *H, int N, DATA* values);	// build a heap with given values

void H_free(HEAP *H);

void H_print(HEAP *H);

#endif