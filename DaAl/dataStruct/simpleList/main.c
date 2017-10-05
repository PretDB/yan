#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "linearTable.h"

int LoopTest()
{
	int a = 666;
	int b = 999;
	int c = 10;
	Node* head = InitLoopNode();
	Node* tail = InitNode();

	head->data = &a;
	tail->data = &b;
	AppendNode(head, tail);

	while(head != NULL && c != 0)
	{
		Print(head->data);
		head = head->next;
		c--;
	}

	printf("\n");

	return 0;
}

int StackTest()
{
	Node* head = InitNode();
	Node* p = head;

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
	printf("\n");

	return 0;
}

int QueueTest()
{	
	Node* head = InitNode();
	Node* p = head;

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

	printf("\n");

	return 0;
}

int BaseTest()
{
	Node* head = InitNode();
	Node* p = head;

	srand((unsigned)time(NULL));
	
	for(int a = 0; a < 10; a++)
	{
		int *d = (int*)malloc(sizeof(int));
		*d  = rand() % 10;
		ListInsert(p, Length(p, NULL) - 1, d);
		printf("No. %d: %d\n", a, *d);
	}

	p = head->next;

	PrintList(p, NULL, Print);
	printf("length = %d\n", Length(p, NULL));
	printf("remove [0]: %d\n", *((int*)ListDelete(p, 0)));
	PrintList(p, NULL, Print);
	
	return 0;
}


int main(int argc, char** argv)
{
	if(strcmp(argv[1], "loop") == 0)
	{
		LoopTest();
	}
	if(strcmp(argv[1], "stack") == 0)
	{
		StackTest();
	}
	if(strcmp(argv[1], "queue") == 0)
	{
		QueueTest();
	}
	if(strcmp(argv[1], "base") == 0)
	{
		BaseTest();
	}

	return 0;
}