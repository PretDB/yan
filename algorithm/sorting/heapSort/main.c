#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

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

void CreateHeap(int* data, int start, int end)
{
	int dad = start;
	int son = start * 2 + 1;

	if(son <= end && data[son] < data[son + 1])
	{
		son++;
	}
	if(data[dad] > data[son])
	{
		return;
	}
	else
	{
		int t = data[dad];
		data[dad] = data[son];
		data[son] = t;
	}
}


void HeapSorting(int* data, int count)
{
	for(int i = count / 2 - 1; i >= 0; i--)
	{
		CreateHeap(data, i, count - 1);
	}
	for(int i = count / 2 - 1; i > 0; i--)
	{
		int t = data[0];
		data[0] = data[i];
		data[i] = t;
		CreateHeap(data, 0, i - 1);
	}
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
