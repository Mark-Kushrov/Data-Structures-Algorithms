#include <stdio.h>
#include "queue.h"


void main()
{
	QUEUE	que;


	// Initialization
	Q_init(&que);

	//Operations
	Q_enque(&que, 0);
	Q_enque(&que, 10);
	Q_enque(&que, 56);
	Q_enque(&que, 210);
	Q_enque(&que, 8);
	Q_enque(&que, -10);
	Q_enque(&que, 11);
	Q_enque(&que, 2);

	Q_print(&que);

	printf("%d\n", Q_deque(&que));
	printf("%d\n", Q_head(&que));
	printf("%d\n", Q_deque(&que));

	Q_print(&que);

	// Finish work
	Q_free(&que);
}