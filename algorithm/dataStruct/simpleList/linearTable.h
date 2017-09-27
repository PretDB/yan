#ifndef _LINEARTABLE_H_
#define _LINEARTABLE_H_
#endif

typedef struct _Node Node;

struct _Node
{
	void* data;
	struct _Node *next;
};

int CompareTo(void* data1, void* data2);

Node* InitNode();
void DestroyNode(Node* node);
void AppendNode(Node* origin, Node* following);
void RemoveFollowing(Node* origin);

int Length(Node* node);
int LocElem(Node* startNode, void* data, int (CompareTo)(void* data1, void* data2));
int ListInsert(Node* startNode, int loc, void* data);
void* ListDelete(Node* startNode, int loc);
void* GetElem(Node* startNode, int loc);
void PrintList(Node* startNode, void (Print)(void* data));

void Push(Node* startNode, void* data);
void* Pop(Node* startNode);

void Enqueue(Node* startNode, void* data);
void* Dequeue(Node* startNod);

Node* Roll(Node* startNode, int t);
void Print(void* data);
