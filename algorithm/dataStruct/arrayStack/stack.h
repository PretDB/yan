#ifndef _STACK_H_
#define _STACK_H_
#endif

//////////////////// DESCRYPTION /////////////////////
// structure:
//		-----------------------------------------------------------------------------
//		|	max size		|	current pointer	|	data0	|	data1	|	(null)	|
//		|	(real size - 2)	|		(offset)	|	(real)	| 	(real)	|	(real)	|
//		-----------------------------------------------------------------------------
//		|			3		|			2		|		3	|		4	|			|
//		-----------------------------------------------------------------------------
//																			^
//////////////////////////////////////////////////////

int*	Init(int size);
int		Push(int* stack, int value);
int		Pop(int* stack);
int*	Destroy(int* stack);
int		Seek(int* stack, int index);
int		CurrentSize(int* stack);
void	Print(int* stack);
void	PrintRaw(int* stack);
