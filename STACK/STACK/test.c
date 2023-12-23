#include <stdio.h>
#include "stack.h"


void main()
{
	STACK	stk;


	// Initialization
	S_init(&stk);

	//Operations
	S_push(&stk, 0);
	S_push(&stk, 10);
	S_push(&stk, 56);
	S_push(&stk, 210);
	S_push(&stk, 8);
	S_push(&stk, -10);
	S_push(&stk, 11);
	S_push(&stk, 2);

	S_print(&stk);

	printf("%d\n", S_pop(&stk));
	printf("%d\n", S_top(&stk));
	printf("%d\n", S_pop(&stk));

	S_print(&stk);

	// Finish work
	S_free(&stk);
}