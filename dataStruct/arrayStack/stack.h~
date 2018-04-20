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

int*	Init(int size);						// Initialize a stack with size, returning its pointer.
int		Push(int* stack, int value);		// Push data 'value' to stack 'stack', returns status(normally be 0).
int		Pop(int* stack);					// Pop data in stack 'stack', and returns that value.
int*	Destroy(int* stack);				// Destroy a stack.
int		Seek(int* stack, int index);		// Seek value in stack at 'index', if a wrong index given, -1 will be returned.
int		CurrentSize(int* stack);			// Return current stack size (not initialize size, this indicating how many data in this
											// stack).
void	Print(int* stack);					// Print the whole stack (only data).
void	PrintRaw(int* stack);				// Print the whole stack (max size block and current pointer are included).
