#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "list.h"


void main()
{
	LIST	lst;
	NODE	*ptr1, *ptr2;


	// Initialization
	L_init(&lst);

	//Operations on list
	L_insert(&(lst.head), 0);
	L_insert(&(lst.head), 2);
	ptr1 = L_insert(&(lst.head), 10);
	ptr2 = L_insert(ptr1, -5);
	L_insert(ptr2, 100);

	L_delete(lst.head.next);
	L_delete(ptr1);

	// Print
	L_print(&lst);

	// Finish work
	L_free(&lst);
}
