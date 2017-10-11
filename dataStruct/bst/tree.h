#ifndef _TREE_H_
#define _TREE_H_
#endif

#define LEFT 0
#define RIGHT 1

typedef struct _Tree Tree;

struct _Tree
{
    struct _Tree* left;
    void* data;
    struct _Tree* right;
};																			// Basic data structure.

void Fill(Tree* t, int level);												// Fill a binary tree with level 'level'
int PrintTree(Tree* t, void* p);											// Print value of a given node, with parameter p. But the
																			// parameter is not used.
void Visit(Tree* t, int (*Func)(Tree* t, void* p), void* p);				// Visit, not used.
void PreOrder(Tree* t, int (*Func)(Tree* t, void* p), void* p);				// Pre-order visiting, with a function pointer Func, and
																			// parameter p to Func.
void InOrder(Tree* t, int (*Func)(Tree* t, void* p), void* p);				// In-order visiting.
void PostOrder(Tree* t, int (*Func)(Tree* t, void* p), void* p);			// Post-order visiting.
void LevelOrder(Tree* t, int (*Func)(Tree* t, void* p), void* p);			// Level-order visiting.

Tree* InitTreeNode();														// Initialize a tree node.
int AddChild(Tree* parent, void* childData, int loc);						// Add a new node to given node parent, with its location
																			// is indicated by LEFT or RIGHT.
// remove child, return Tree its data.
void* RemoveChild(Tree* parent, int loc);

int Insert(Tree* t, int (*CompareTo)(void* src, void* dst), void* data);	// Insert a node to given node, given a compare function.
Tree* Search(Tree* t, int (*CompareTo)(void* src, void* dst), void* data);	// Search data in a given node, given a compare function,
																			// and returns a pointer to it if the node is found, NULL
																			// if not.
void* Remove(Tree* t, int (*CompareTo)(void* src, void* dst), void* data);	// Remove tree node t, and move data under it to right
																			// place.
