#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack.h"


// Descryption see .h
int* Init(int size)
{
	int* loc = (int*)(malloc(sizeof(int) * (size + 2)));
	*(loc) = size;
	*(loc + 1) = 0;
	return loc;
}

int Push(int* stack, int value)
{
	if(*(stack) > *(stack + 1))
	{
		*(stack + *(stack + 1) + 2) = value;
		*(stack + 1) += 1;
	}
}
int Pop(int* stack)
{
	if(*(stack + 1) > 0)
	{
		int a = *(stack + *(stack + 1) + 1);
		*(stack + 1) -= 1;
		return a;
	}
}

int* Destroy(int* stack)
{
	free(stack);
}

int Seek(int* stack, int index)
{
	if(index >= 0 || index < *stack)
	{
		return *(stack + index + 2);
	}
}

int CurrentSize(int* stack)
{
	return *(stack + 2);
}

void PrintRaw(int* stack)
{
	for(int a = 0; a < *(stack) + 2; a++)
	{
		printf("%d\t", *(stack + a));
	}
	printf("\n");
}

void Print(int* stack)
{
	for(int a = 0; a < *(stack + 1); a++)
	{
		printf("No.%d=%d\t", a, *(stack + a));
	}
	printf("\n");
}
