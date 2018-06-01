#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dualTable.h"


int main(int argc, char** argv)
{
	DualNode* head = InitDualNode();
	DualNode* p = head;

	srand((unsigned)time(NULL));
	
	for(int a = 0; a < 10; a++)
	{
		int *d = (int*)malloc(sizeof(int));
		*d  = rand() % 10;
		ListInsert(p, Length(p, NULL) - 1, d);
		printf("No. %d: %d\n", a, *d);
	}

	p = head->next;

	PrintList(p, Print);
	printf("length = %d\n", Length(p, NULL));
	printf("remove [0]: %d\n", *((int*)ListDelete(p, 0)));
	PrintList(p, Print);

	printf("stack op\n");
	DualNode* stack = InitDualNode();
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
	DualNode* queue = InitDualNode();
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
