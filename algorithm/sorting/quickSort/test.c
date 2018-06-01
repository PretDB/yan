#include <stdio.h>
#include <stdlib.h>

#define SWAP(A,B) {int _tmp = 0; _tmp = A; A = B; B = _tmp;}

int main(int argc, char** argv)
{
	int a = 15, b = 20;

	SWAP(a,b);

	printf("a = %d, b = %d\n", a, b);

}
