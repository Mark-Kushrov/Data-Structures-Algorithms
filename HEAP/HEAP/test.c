#include <stdio.h>
#include "Heap.h"


void main()
{
	HEAP hp;
	DATA A[] = { -18, 61, 573, 72, 91, 654, 43, 76, 0, -5 };

	H_makeHeap(&hp, 10, A);
	H_print(&hp);
	H_free(&hp);

	H_init(&hp, 20);

	H_print(&hp);
	H_delMax(&hp);
	H_insert(&hp, -1);
	H_print(&hp);
	H_insert(&hp, 86);
	H_print(&hp);
	H_insert(&hp, 157);
	H_print(&hp);
	H_insert(&hp, 37);
	H_print(&hp);
	H_insert(&hp, 29);
	H_print(&hp);
	H_insert(&hp, 165);
	H_print(&hp);
	H_insert(&hp, 44);
	H_print(&hp);
	H_insert(&hp, 37);
	H_print(&hp);
	H_insert(&hp, 60);
	H_print(&hp);


	printf("%d \n", H_findMax(&hp));

	printf("%d \n", H_delMax(&hp));
	printf("%d \n", H_delMax(&hp));
	printf("%d \n", H_delMax(&hp));

	printf("%d \n", H_findMax(&hp));

	H_insert(&hp, 89);
	H_insert(&hp, 215);
	H_insert(&hp, 64);
	H_insert(&hp, 137);
	H_insert(&hp, 260);

	printf("%d \n", H_delMax(&hp));
	printf("%d \n", H_delMax(&hp));

	printf("%d \n", H_findMax(&hp));
	H_print(&hp);

	H_free(&hp);
}