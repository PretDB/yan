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

void QuickSorting(int* data, int count)
{
	if(count > 2)
	{
		int		sent	= *data;
		int		rl		= 0;
		int		ll		= 1;
		int*	bound	= data + count - 1;
		int*	fore	= data + 1;
		int*	rear	= bound;

		while(fore < rear)
		{
			while(*fore < sent && fore < bound)
			{
				fore++;
				ll++;
			}
			while(*rear > sent && rear > data)
			{
				rear--;
				rl++;
			}

			if(fore >= rear)
			{
				break;
			}
			printf("after swap onece:\n");
			SWAP(*fore, *rear);
			Print(data, count);
		}

		printf("swap rear and sent\n");
		SWAP(*rear, *data);
		printf("current turn:\n");
		Print(data, count);
		printf("devide:\tll = %d, rl = %d\n", ll, rl);
		QuickSorting(data, ll);
		QuickSorting(fore, rl);
	}
}


int main(int argc, char** argv)
{
	if(argc > 1)
	{
		int count = atoi(argv[1]);
		int* data = InitArray(count, 99);
		
		Print(data, count);
		QuickSorting(data, count);
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
