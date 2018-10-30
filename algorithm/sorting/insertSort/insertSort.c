#include <stdio.h>

void insertSort(int* buf, int l)
{
	int temp;

	for( int a = 1; a < l; a++)
	{
		int b;
		temp = buf[a];

		for( b = a - 1; b >= 0 && temp < buf[b]; b-- )
		{
			buf[b + 1] = buf[b];
		}
		buf[b + 1] = temp;
	}

}

int main(int argc, char** argv)
{
	int test[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	insertSort( test, 10 );

	for( int a = 0; a < 10; a ++ )
	{
		printf( "%d\t", test[a] );
	}
	printf("\n");

	return 0;
}
