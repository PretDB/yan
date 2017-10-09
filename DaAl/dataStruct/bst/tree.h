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
};

void Fill(Tree* t, int level);
int PrintTree(Tree* t, void* p);
void Visit(Tree* t, int (*Func)(Tree* t, void* p), void* p);
void PreOrder(Tree* t, int (*Func)(Tree* t, void* p), void* p);
void InOrder(Tree* t, int (*Func)(Tree* t, void* p), void* p);
void PostOrder(Tree* t, int (*Func)(Tree* t, void* p), void* p);
void LevelOrder(Tree* t, int (*Func)(Tree* t, void* p), void* p);

Tree* InitTreeNode();
int AddChild(Tree* parent, void* childData, int loc);
// remove child, return Tree node.
void* RemoveChild(Tree* parent, int loc);

int Insert(Tree* t, int (*CompareTo)(void* src, void* dst), void* data);
Tree* Search(Tree* t, int (*CompareTo)(void* src, void* dst), void* data);
void* Remove(Tree* t, int (*CompareTo)(void* src, void* dst), void* data);