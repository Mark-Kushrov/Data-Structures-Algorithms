#include <stdio.h>
#include "queue.h"
#include "stack.h"
void Q_reverse(QUEUE * q);


void main()
{
	QUEUE	que;
	// Initialization
	Q_init(&que);

	//Operations
	Q_enque(&que, 10);
	Q_enque(&que, 20);
	Q_enque(&que, 30);
	Q_enque(&que, 40);
	Q_enque(&que, 50);
	puts("\nYour Q BEFORE is:\n\n");
	Q_print(&que);
	puts("\nYour Q AFTER is:\n\n");
	Q_reverse(&que);
	Q_print(&que);
	// Finish work
	Q_free(&que);
}
void Q_reverse(QUEUE * q)
{
	STACK tmp;
	S_init(&tmp);
	while( ! Q_isEmpty(q))
		S_push(&tmp , Q_deque(q));
	while( !S_isEmpty(&tmp))
		Q_enque(q , S_pop(&tmp));
	S_free(&tmp);
}