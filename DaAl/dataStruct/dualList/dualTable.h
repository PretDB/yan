#ifndef _LINEARTABLE_H_
#define _LINEARTABLE_H_
#endif

typedef struct _DualNode DualNode;

struct _DualNode
{
	void* data;
	struct _DualNode *next;
	struct _DualNode *last;
};

int CompareTo(void* data1, void* data2);

DualNode* InitDualNode();
void DestroyDualNode(DualNode* node);
void AppendDualNode(DualNode* origin, DualNode* following);
void RemoveFollowingDualNode(DualNode* origin);

int Length(DualNode* node, DualNode* target);
int LocElem(DualNode* startNode, void* data, int (CompareTo)(void* data1, void* data2));
int ListInsert(DualNode* startNode, int loc, void* data);
void* ListDelete(DualNode* startNode, int loc);
void* GetElem(DualNode* startNode, int loc);
void PrintList(DualNode* startNode, void (Print)(void* data));

void Push(DualNode* startNode, void* data);
void* Pop(DualNode* startNode);

void Enqueue(DualNode* startNode, void* data);
void* Dequeue(DualNode* startNod);

DualNode* Roll(DualNode* startNode, int t);
void Print(void* data);
