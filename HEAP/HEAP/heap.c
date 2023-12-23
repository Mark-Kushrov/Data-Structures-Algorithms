/**************/
/*   heap.c   */
/**************/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "Heap.h"


/**************************************/
//  Auxiliary functions
/**************************************/

// return father's index
int father(int i)		
{ return i / 2; }

// return left son's index
int son(int i)			
{ return i * 2; }

// swap values between two array cells
void swap(HEAP *H, int i, int j)	
{
	DATA tmp = H->keys[i];
	H->keys[i] = H->keys[j];
	H->keys[j] = tmp;
}

// fix heap order by pushing value up
int sift_up(HEAP *H, int i)			
{
	int j = father(i);
	if ( ( j < 1 ) || ( H->keys[i] <= H->keys[j] ) )  return i; // no need to go on
	swap(H, i, j);
	return sift_up(H, j);
}

// fix heap order by pushing value down
int sift_down(HEAP *H, int i)		
{
	int j = son(i);					// left son

	if ( j > H->count )  return i;	// no sons
	if ( ( j < H->count ) && ( H->keys[j] < H->keys[j+1] ) )  j++;	// the right son

	if ( H->keys[i] >= H->keys[j] )  return i;	// father is greater than sons

	swap(H, i, j);
	return sift_down(H, j);
}


//////////////////////////////////////////
// Init
// Aim:		create new heap
// Input:	pointer to the heap structure
// Output:	TRUE if succeeded
//////////////////////////////////////////
BOOL H_init(HEAP *H, int N)
{
	if ( H == NULL ) return False;

	H->N = N + 1;	// for not using index 0
	H->count = 0;
	H->keys = (DATA*)malloc(sizeof(DATA) * H->N);
	return H->keys ? True : False;
}


//////////////////////////////////////////
// Insert
// Aim:		insert item x
// Input:	pointer to the heap structure
//          value x
// Output:	index of x in the array
//////////////////////////////////////////
int H_insert(HEAP *H, DATA x)
{
	if ( ( H == NULL ) || ( H->count == H->N - 1 ) )  return -1; 

	H->keys[++(H->count)] = x;
	return sift_up(H, H->count);
}


//////////////////////////////////////////
// Find Max
// Aim:		return maximal value
// Input:	pointer to the heap structure
// Output:	maximal value
//////////////////////////////////////////
DATA H_findMax(HEAP *H)
{
	if ( ( H == NULL ) || ( H->count == 0 ) )  return EMPTY; 
	return H->keys[1];		// the root
}


//////////////////////////////////////////
// Delete Max
// Aim:		delete maximal value
// Input:	pointer to the heap structure
// Output:	maximal value
//////////////////////////////////////////
DATA H_delMax(HEAP *H)
{
	DATA max;
	if ( ( H == NULL ) || ( H->count == 0 ) )  return EMPTY; 

	max = H->keys[1];						// the root
	H->keys[1] = H->keys[(H->count)--];
	sift_down(H, 1);
	return max;
}


/////////////////////////////////////////////////
// Make Heap
// Aim:		build a heap with given values
// Input:	pointer to the heap structure
//          a number of given values
//          an array of given values
// Output:	TRUE if succeeded
/////////////////////////////////////////////////
BOOL H_makeHeap(HEAP *H, int N, DATA* values)
{
	int i;

	if ( ( H == NULL ) || !H_init(H, N) ) return False;

	H->count = N;
	memcpy(H->keys + 1, values, N * sizeof(DATA));

	for ( i = N / 2;  i > 0;  i-- )
		sift_down(H, i);
	return True;
}


//////////////////////////////////////////
// Free
// Aim:		free the heap
// Input:	pointer to the heap structure
//////////////////////////////////////////
void H_free(HEAP *H)
{
	if ( H == NULL ) return;

	free(H->keys);
	H->N = H->count = 0;
	H->keys = NULL;
}

//////////////////////////////////////////
// Print
// Aim:		Print the heap
// Input:	pointer to the heap structure
//////////////////////////////////////////
void H_print(HEAP *H)
{
	float fc = (float)H->count;
	int *ptr = (int*)&fc, leaves = 1 << (((*ptr) >> 23) - 127), i = 1, j, k;

	printf("\n************\n");
	for ( k = 1;  k <= H->count;  k = son(k) + 1 )  {
		for ( ;  i <= k;  i++ )  {
			printf("%5d", H->keys[i]);
			for ( j = 1;  j < leaves;  j++ )
				printf("     ");
		}
		printf("\n");
		leaves /= 2;
	}
	for ( ;  i <= H->count;  i++ ) 
		printf("%5d", H->keys[i]);
	printf("\n*************************\n");
}
/*****************************/
