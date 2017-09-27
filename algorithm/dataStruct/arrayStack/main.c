#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack.h"


int main(int argc, char** argv)
{
	int		stackSize = 10;
	int*	stackLoc = NULL;

	srand(time(NULL));

	stackLoc = Init(stackSize);
	printf("stack location: %p\n", stackLoc);

	for(int a = 0; a < stackSize; a++)
	{
		int tmp = rand() % 10;
		printf("No. %d: Push %d.\n", a, tmp);
		Push(stackLoc, tmp);
		PrintRaw(stackLoc);
		printf("\n");
	}

	for(int a = 0; a < stackSize; a++)
	{
		printf("No. %d: Pop: %d.\n", a, Pop(stackLoc));
		PrintRaw(stackLoc);
		printf("\n");
	}
}
