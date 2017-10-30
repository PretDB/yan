#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define SWAP(A, B) { int _tmp = 0; _tmp = A; A = B; B = _tmp; }

void Print(int* data, int count)
{
	for(int a = 0; a < count; a++)
	{
		printf("%d\t", *(data + a));
	}
	printf("\n");
}

int* InitArray(int count, int max)
{
	if(count > 0)
	{
		int* data = (int*)malloc(sizeof(int) * count);
		srand(time(NULL));

		for(int a = 0; a < count; a++)
		{
			data[a] = rand() % max;
		}

		return data;
	}
	else
	{
		return NULL;
	}
}

void HeapSorting(int* data, int count)
{
	return;
}


int main(int argc, char** argv)
{
	if(argc > 1)
	{
		int count = atoi(argv[1]);
		int* data = InitArray(count, 99);
		
		Print(data, count);
		HeapSorting(data, count);
		Print(data, count);
	}
	else
	{
		printf("======= Usage ======\n");
		printf("$ main <count>\n");
		printf("====================\n");
		return 1;
	}


	return 0;
}
