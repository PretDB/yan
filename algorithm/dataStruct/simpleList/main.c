#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "linearTable.h"


int main(int argc, char** argv)
{
	Node* head = InitNode();
	Node* p = head;

	srand((unsigned)time(NULL));
	
	for(int a = 0; a < 10; a++)
	{
		int *d = (int*)malloc(sizeof(int));
		*d  = rand() % 10;
		ListInsert(p, Length(p) - 1, d);
		printf("No. %d: %d\n", a, *d);
	}

	p = head->next;

	PrintList(p, Print);
	printf("length = %d\n", Length(p));
	printf("remove [0]: %d\n", *((int*)ListDelete(p, 0)));
	PrintList(p, Print);

	printf("stack op\n");
	Node* stack = InitNode();
	for(int a = 0; a < 10; a++)
	{
		int *d = (int*)malloc(sizeof(int));
		*d = rand() % 10;
		Push(stack, (void*)d);
		printf("pu %d\t", *d);
	}
	printf("\n");
	for(int a = 0; a < 10; a++)
	{
		printf("po %d\t", *(int*)Pop(stack));
	}

	printf("\nqueue op\n");
	Node* queue = InitNode();
	for(int a = 0; a < 10; a++)
	{
		int *d = (int*)malloc(sizeof(int));
		*d = rand() % 10;
		Enqueue(queue, (void*)d);
		printf("en %d\t", *d);
	}
	printf("\n");
	for(int a = 0; a < 10; a++)
	{
		printf("de %d\t", *(int*)Dequeue(queue));
	}
	return 0;
}
