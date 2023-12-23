#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "CList.h"


void main()
{
	CLIST clst;
	CL_init(&clst);
	CL_insert(&clst , &clst.head , 30);
	CL_insert(&clst , &clst.head , 20);
	CL_insert(&clst , &clst.head , 10);
	puts("\n\nYour list is:\n");
	CL_print(&clst);
}