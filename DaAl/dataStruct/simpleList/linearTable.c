#include "linearTable.h"

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

Node* InitLoopNode()
{
	Node* node = InitNode();
	node->next = node;
}
Node* InitNode()
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = NULL;
	node->next = NULL;
	return node;
}

void DestroyNode(Node* node)
{
	if(!node)
	{
		free(node);
	}
}

void AppendNode(Node* origin, Node* following)
{
	following->next = origin->next;
	origin->next = following;
}

void* RemoveFollowing(Node* origin)
{
	if(origin->next != NULL)
	{
		void* data = origin->next->data;
		origin->next = origin->next->next;
		return data;
	}
	return NULL;
}
Node* Roll(Node* startNode, int loc)
{
	while(loc > 0)
	{
		loc--;
		startNode = startNode->next;
	}
	return startNode;
}


int Length(Node* node, Node* target)
{
	int l = 0;
	while(node != target)
	{
		l++;
		node = node->next;
	}
	return l;
}

int LocElem(Node* startNode, Node* endNode, void* data, int (CompareTo)(void* data1, void* data2))
{
	int loc = 0;
	
	while(startNode != endNode)
	{
		if(CompareTo(startNode->data, data) == 0)
		{
			return loc;
		}
		loc++;
		startNode = startNode->next;
	}
	return -1;
}

int ListInsert(Node* startNode, int loc, void* data)
{
	if(loc < 0 || loc > Length(startNode, NULL) - 1)
	{
		return -1;
	}

	Node* t = InitNode();
	t->data = data;
	AppendNode(Roll(startNode, loc), t);
	return 0;
}

void* ListDelete(Node* startNode, int loc)
{
	if(loc < 0 || loc > Length(startNode, NULL) - 1)
	{
		return NULL;
	}

	Node* n = Roll(startNode, loc - 1);
	void* data = RemoveFollowing(n);
	return data;
}

void* GetElem(Node* startNode, int loc)
{
	if(loc < 0 || loc > Length(startNode, NULL) - 1)
	{
		return NULL;
	}
	return Roll(startNode, loc)->data;
}

void PrintList(Node* startNode, Node* endNode, void (Print)(void* data))
{
	while(startNode != endNode)
	{
		Print(startNode->data);
		startNode = startNode->next;
	}
	printf("\n");
}

void Push(Node* startNode, void* data)
{
	ListInsert(startNode, Length(startNode, NULL) - 1, data);
}
void* Pop(Node* startNode)
{
	return ListDelete(startNode, Length(startNode, NULL) - 1);
}

void Enqueue(Node* startNode, void* data)
{
	ListInsert(startNode, 0, data);
}

void* Dequeue(Node* startNode)
{
	return Pop(startNode);
}


void Print(void* data)
{
	printf("%d\t", *((int*)data));
}
