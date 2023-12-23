#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// new types
typedef int DATA;					// a type for data (easy to change)
typedef enum {False, True} BOOL;	// a boolean type

/************ Function Prototypes ******************/
void swap(DATA a[], int i, int j);
void merge(DATA A[], DATA B[], DATA C[], int NA, int NB);
int partition(DATA a[], int n, DATA pivot);
void sift_down(DATA a[], int n, int i);
void BubbleSortSimple(DATA a[], int n);
void BubbleSortSmart(DATA a[], int n);
void SelectSort(DATA a[], int n);
void InsertSort(DATA a[], int n);
void MergeSortR(DATA a[], int n);
void MergeSortNR(DATA a[], int n);
void QuickSort(DATA a[], int n);
void HeapSort(DATA a[], int n);
void printArray(const int Arr[]  , int n);
//+--------------------------------------------------------------------+
void main()
{
	int A[] = {4 , 2 , -3 , 1};
	int n = sizeof(A)/sizeof(A[0]);
	puts("\nYour array before the sort:");
	printArray(A , n);
	SelectSort(A , n);
	puts("\nYour array after the sort:");
	printArray(A , n);
	puts("\n");
}

/* Implementation of all the sorting algorithms studied in the course */
// swaps two elements of an array
//		a - the array
//		i, j - the elements' indices
void swap(DATA a[], int i, int j)
{
	DATA tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}


// merges two sorted arrays A and B to the resulting array C
//		NA - a size of A
//		NB - a size of B
//		a size of C is assumed to be at least NA + NB
void merge(DATA A[], DATA B[], DATA C[], int NA, int NB)
{
	int	i, j, k;

	// merging while neither of the arrays gets to the end
	for ( i = j = k = 0;  i < NA && j < NB;  k++ )
		if ( A[i] < B[j] )  
			C[k] = A[i++];
		else  
			C[k] = B[j++];

	// copying the rest
	for ( ; i < NA;  i++, k++ )  
		C[k] = A[i];
	for ( ; j < NB;  j++, k++ )  
		C[k] = B[j];
}


// partitions the array according to the pivot
// returns the index of the start of the second part (greater values)
int partition(DATA a[], int n, DATA pivot)
{
	int i = 0, j = n-1;

	while ( 1 )  {
		for ( ;  ( a[i] <= pivot ) && ( i < j );  i++ )  ;
		for ( ;  ( a[j] >= pivot ) && ( i < j );  j-- )  ;
		if ( i == j )
			return i;
		swap(a, i, j);
	}
}


// moves a[i] down according to heap order
void sift_down(DATA a[], int n, int i)
{
	int j, k;			// j is left son index, k is right son index

	for ( j = i * 2 + 1;  j < n;  j = i * 2 + 1 )  {
		if ( ( (k = j + 1) < n ) && ( a[j] < a[k] ) )		// the right son is greater
			j = k;											// now j is the greatest son
		if ( a[i] >= a[j] )  return;
		swap(a, i, j);
		i = j;
	}
}




// Bubble sort without early exit
void BubbleSortSimple(DATA a[], int n)
{
	int		i;

	for ( ;  n > 1;  n-- )
		for ( i = 1;  i < n;  i++ )
			if ( a[i-1] > a[i] )
				swap(a, i, i-1);
}



// Bubble sort with early exit option
void BubbleSortSmart(DATA a[], int n)
{
	int		i;
	BOOL	flag = True;	// for early exit

	for ( ;  ( n > 1 ) && flag;  n-- )  {
		flag = False;
		for ( i = 1;  i < n;  i++ )
			if ( a[i-1] > a[i] )  {
				swap(a, i, i-1);
				flag = True;
			}
	}
}



// Selection sort
void SelectSort(DATA a[], int n)
{
	int	i, IndMax;	// IndMax is for the index of the maximum
	for ( ;  n > 1;  n-- )  {
		for ( IndMax = 0, i = 1;  i < n;  i++ )
			if ( a[IndMax] < a[i] )
				IndMax = i;
		swap(a, n-1, IndMax);
	}
}



// Insertion sort
void InsertSort(DATA a[], int n)
{
	int		i, j;
	DATA	key;	// for the element to be inserted

	for ( i = 1;  i < n;  i++ )  {
		for ( key = a[i], j = i-1;  ( j >= 0 ) && ( a[j] > key );  j-- )
			a[j+1] = a[j];
		a[j+1] = key;
	}
}



// Merge sort (recursive)
void MergeSortR(DATA a[], int n)
{
	int		m = n / 2;	// the middle of the segment
	int		size = n * sizeof(DATA);	// size of the array in bytes
	DATA	*aux;

	if ( n < 2 )
		return;

	// recursive sorintg
	MergeSortR(a, m);
	MergeSortR(a+m, n-m);

	// merging
	aux = (DATA*)malloc(size);	// auxiliary array allocation
	merge(a, a+m, aux, m, n-m);
	memcpy(a, aux, size);
	free(aux);
}



// Merge sort (non recursive)
void MergeSortNR(DATA a[], int n)
{
	int block, seg, h, m, block2;	// seg is a size of the relevant segment, block is a half of it
	DATA	*aux = (DATA*)malloc(n * sizeof(DATA));	// auxiliary array allocation

	for ( block = 1, seg = 2;  block < n;  block *= 2, seg *= 2 )  {
		block2 = block;
		for ( h = 0, m = block;  m < n;  h += seg,  m += seg )  {
			if ( n - m < block )
				block2 = n - m;
			merge(a+h, a+m, aux, block, block2);
			memcpy(a+h, aux, (block + block2) * sizeof(DATA));
		}
	}
	free(aux);
}



// Quick sort
void QuickSort(DATA a[], int n)
{
	int i = (int)((double)rand() / (RAND_MAX + 1) * n);	// random index for pivot
	if ( n < 2 )
		return;
	swap(a, i, n-1);	// for convenience, move the pivot to the end
	i = partition(a, n, a[n-1]);
	swap(a, i, n-1);	// move the pivot into its real place

	QuickSort(a, i);
	QuickSort(a+i+1, n-i-1);
}



// Heap sort
void HeapSort(DATA a[], int n)
{
	int i;

	// Make heap
	for ( i = (n - 2) / 2;  i >= 0;  i-- )
		sift_down(a, n, i);

	// Sorting
	for ( n--;  n > 0;  n-- )  {
		swap(a, n, 0);
		sift_down(a, n, 0);
	}
}
//Printing array
void printArray(const int Arr[]  , int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d, " , Arr[i]);
	puts("\n");
}