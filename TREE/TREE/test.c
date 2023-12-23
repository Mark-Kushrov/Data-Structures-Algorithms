#include <stdio.h>
#include "BSTree.h"

void main()
{
	TREE T;
	NODE2* tmp;

	T_init(&T);	

	if ( T_delete(&T, 87) )  printf("Deleted\n");
	else  printf("Not deleted\n");

	T_insert(&T, 5);
	if ( T_delete(&T, 5) )  printf("Deleted\n");
	else  printf("Not deleted\n");
	T_insert(&T, 75);
	T_insert(&T, 345);
	T_insert(&T, 56);
	T_insert(&T, 1);
	T_insert(&T, 87);
	T_insert(&T, 324);
	T_insert(&T, 0);
	T_insert(&T, -6);
	T_insert(&T, 6);
	T_insert(&T, 5);
	T_insert(&T, 2);
	T_insert(&T, 11);
	T_insert(&T, 879);
	T_insert(&T, 4);
	T_insert(&T, -1);
	T_insert(&T, 6);

	preorderPC(T.head.left); 
	putchar('\n');
	inorderPC(T.head.left);
	putchar('\n');
	postorderPC(T.head.left);
	putchar('\n');

	tmp = T_find(&T, 5);
	tmp = T_find(&T, 56);
	tmp = T_find(&T, 15);
	tmp = T_find(&T, -6);
	tmp = T_find(&T, -1);
	tmp = T_find(&T, 879);

	if ( T_delete(&T, 87) )  printf("Deleted\n");
	else  printf("Not deleted\n");
	if ( T_delete(&T, 8) )  printf("Deleted\n");
	else  printf("Not deleted\n");
	if ( T_delete(&T, -1) )  printf("Deleted\n");
	else  printf("Not deleted\n");
	if ( T_delete(&T, 75) )  printf("Deleted\n");
	else  printf("Not deleted\n");

	T_free(&T);
}