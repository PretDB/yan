#include "dualTable.h"

#include <stdlib.h>
#include <stdio.h>

int CompareTo(void* data1, void* data2)
{
	if(*((int*)data1) == *((int*)data2))
	{
		return 0;
	}
	else if(*((int*)data1) >*(int*)data2)
	{
		return 1;
	}
	else
	{
		return -1;
	}	
}

DualNode* InitDualNode()
{
	DualNode* node = (DualNode*)malloc(sizeof(DualNode));

	node->data = NULL;
	node->next = NULL;
	node->last = NULL;

	return node;
}

void DestroyDualNode(DualNode* node)
{
	if(!node)
	{
		free(node);
	}
}

void AppendDualNode(DualNode* origin, DualNode* following)
{
	following->next = origin->next;
	if(following->next != NULL)
	{
		following->next->last = following;
	}
	origin->next = following;
	following->last = origin;
}

void RemoveFollowingDualNode(DualNode* origin)
{
	if(origin->next != NULL)
	{
		DualNode* n = origin->next;
		origin->next = n->next;
		if(n->next != NULL)
		{
			n->next->last = origin;
		}
		DestroyDualNode(n);
	}
}

// from startNode, roll forward if loc > 0,
// backward if loc < 0;
DualNode* Roll(DualNode* startNode, int loc)
{
	int l = 0;
	char factor = 0;
	factor = loc > 0 ? 1 : -1;

	while(l !=  loc)
	{
		l += factor;
		startNode = factor > 0 ? startNode->next : startNode->last;
	}
	return startNode;
}

// Length from node to target, target not included.
// for example, n1 -> n2 -> n3 -> n4, node = n1, target = 
// n4, length = 3.
int Length(DualNode* node, DualNode* target)
{
	int l = 0;
	while(node != target)
	{
		l++;
		node = node->next;
	}
	return l;
}

int LocElem(DualNode* startNode, void* data, int (CompareTo)(void* data1, void* data2))
{
	int loc = 0;
	DualNode* n = startNode;
	
	while(n != NULL)
	{
		if(CompareTo(n->data, data) == 0)
		{
			return loc;
		}
		loc++;
	}
	return -1;
}

int ListInsert(DualNode* startNode, int loc, void* data)
{
	if(loc < 0 || loc > Length(startNode, NULL) - 1)
	{
		return -1;
	}

	int l = 0;
	DualNode* t = InitDualNode();
	t->data = data;
	AppendDualNode(Roll(startNode, loc), t);
	return 0;
}

void* ListDelete(DualNode* startNode, int loc)
{
	if(loc < 0 || loc > Length(startNode, NULL) - 1)
	{
		return NULL;
	}

	startNode = Roll(startNode, loc - 1);
	void* data = startNode->next->data;
	if (loc != 0)
	{
		RemoveFollowingDualNode(startNode);;
	}
	return data;
}

void* GetElem(DualNode* startNode, int loc)
{
	if(loc < 0 || loc > Length(startNode, NULL) - 1)
	{
		return NULL;
	}
	return Roll(startNode, loc)->data;
}

void PrintList(DualNode* startNode, void (Print)(void* data))
{
	while(startNode != NULL)
	{
		Print(startNode->data);
		startNode = startNode->next;
	}
	printf("\n");
}

void Push(DualNode* startNode, void* data)
{
	ListInsert(startNode, Length(startNode, NULL) - 1, data);
}
void* Pop(DualNode* startNode)
{
	return ListDelete(startNode, Length(startNode, NULL) - 1);
}

void Enqueue(DualNode* startNode, void* data)
{
	ListInsert(startNode, 0, data);
}

void* Dequeue(DualNode* startNode)
{
	return Pop(startNode);
}


void Print(void* data)
{
	printf("%d\t", *((int*)data));
}
