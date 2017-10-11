#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int BubbleSorting(int* data, int count)
{
	int tmp = 0;
	for(int a = 0; a < count - 1; a++)
	{
		for(int b = 0; b < count - 1; b++)
		{
			if(data[b] > data[b + 1])
			{
				tmp = data[b];
				data[b] = data[b + 1];
				data[b + 1] = tmp;
			}
		}
	}

	return 0;
}

void Print(int* data, int count)
{
	for(int a = 0; a < count; a++)
	{
		printf("%d\t", data[a]);
	}
	printf("\n");
}

int main(int argc, char** argv)
{
	int count = 10;

	srand(time(NULL));

	for(int a = 0; a < count; a++)
	{
		printf("rount: %d\n", a);
		int* dataset = (int*)malloc(sizeof(int) * count);

		for(int a = 0; a < count; a++)
		{
			dataset[a] = rand() % 99;
		}
		Print(dataset, count);

		BubbleSorting(dataset, count);

		Print(dataset, count);

		free(dataset);
		printf("\n");
	}

	return 0;
}
