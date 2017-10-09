#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "tree.h"
#include "../simpleList/linearTable.h"

void Fill(Tree* t, int level)
{
    if(level > 0)
    {
        t->left = InitTreeNode();
        t->right = InitTreeNode();
        Fill(t->left, level - 1);
        Fill(t->right, level - 1);
        
        t->data = malloc(sizeof(int));
        *((int*)(t->data)) = rand() % 99;
        printf("%d\t", *((int*)(t->data)));
    }
}

int PrintTree(Tree* t, void* p)
{
    if(t != NULL && t->data != NULL)
    {
        printf("%d\t", *((int*)(t->data)));
    }
    return 0;
}

void Visit(Tree* t, int (*Func)(Tree* t, void* p), void* p)
{
    if(t != NULL)
    {
        (*Func)(t, p);
    }
    return;
}

void PreOrder(Tree* t, int (*Func)(Tree* t, void* p), void* p)
{
    if(t != NULL)
    {
		(*Func)(t, p);
        PreOrder(t->left, Func, p);
        PreOrder(t->right, Func, p);
    }
}

void InOrder(Tree* t, int (*Func)(Tree* t, void* p), void* p)
{
    if(t != NULL)
    {
        InOrder(t->left, Func, p);
        (*Func)(t, p);
        InOrder(t->right, Func, p);
    }
}

void PostOrder(Tree* t, int (*Func)(Tree* t, void* p), void* p)
{
    if(t != NULL)
    {
        PostOrder(t->left, Func, p);
        PostOrder(t->right, Func, p);
        (*Func)(t, p);
    }
}

void LevelOrder(Tree* t, int (*Func)(Tree* t, void* p), void* p)
{
    Node* queue = InitNode();

    Enqueue(queue, t);

    while(t != NULL)
    {
        t = Dequeue(queue);
        if(t == NULL)
        {
            break;
        }
        Func(t, p);
        if(t->left != NULL)
        {
            Enqueue(queue, t->left);
        }
        if(t->left != NULL)
        {
            Enqueue(queue, t->right);
        }
    }
}


Tree* InitTreeNode()
{
    Tree* t = (Tree*)malloc(sizeof(Tree));
    if(t != NULL)
    {
        memset((void*)t, 0, sizeof(Tree));
    }
    return t;
}

int AddChild(Tree* parent, void* childData, int loc)
{
    if(parent != NULL)
    {
        Tree* t = InitTreeNode();
        t->data = childData;

        switch(loc)
        {
            case LEFT:
                parent->left = t;
                break;
            case RIGHT:
                parent->right = t;
                break;
            defualt:
                return 1;
                break;
        }
        return 0;
    }
    else
    {
        return -1;
    }
}

void* RemoveChild(Tree* parent, int loc)
{
    if(parent != NULL)
    {
        if(loc == LEFT)
        {

        }
        else if(loc == RIGHT)
        {

        }
    }
    return NULL;
}

int Insert(Tree* t, int (*CompareTo)(void* src, void* dst), void* data)
{
    if(t->data != NULL)
    {
        if(CompareTo(t->data, data) < 0)
        {
            Insert(t->left, CompareTo, data);
        }
        else if( CompareTo(t->data, data) == 0)
        {
            return 0;
        }
        else
        {
            Insert(t->right, CompareTo, data);
        }
    }
    else
    {
        t->data = data;
        AddChild(t, NULL, LEFT);
        AddChild(t, NULL, RIGHT);
    }
}

Tree* Search(Tree* t, int (*CompareTo)(void* src, void* dst), void* data)
{
    if(CompareTo(t->data, data) < 0)
    {
        Search(t->left, CompareTo, data);
    }
    else if(CompareTo(t->data, data) > 0)
    {
        Search(t->right, CompareTo, data);
    }
    else if(CompareTo(t->data, data) == 0)
    {
        return t;
    }
    else
    {
        return NULL;
    }
}

Tree* FindMostRightNode(Tree* t)
{
    if(t->right->right != NULL)
    {
        return FindMostRightNode(t->right);
    }
    else
    {
        return t;
    }
}
void* Remove(Tree* t, int (*CompareTo)(void* src, void* dst), void* data)
{
    Tree* node = Search(t, CompareTo, data);
    
    void* ret = node->data;

    if(node != NULL)
    {
        Tree* tmp = NULL;

        if((node->left->left == NULL) ^ (node->right->right == NULL))
        {
            if(node->left->left == NULL)
            {
                tmp = node->right;
            }
            if(node->right->right == NULL)
            {
                tmp = node->left;
            }

            node->data = tmp->data;
            node->left = tmp->left;
            node->right = tmp->right;

            free(tmp);
        }
        else if(node->left->left == NULL && node->right->right == NULL)
        {
            Tree* tmpL = node->left;
            Tree* tmpR = node->right;
            tmp = FindMostRightNode(node);

            free(tmp->right);
            tmp->right = tmpR;
            node->data = tmpL->data;
            node->left = tmpL->left;
            node->right = tmpL->right;
            free(tmpL);
        }
        else
        {
            node->data = NULL;
            free(node->left);
            free(node->right);
            node->left = NULL;
            node->right = NULL;
        }

        return ret;
    }
    return NULL;

    return ret;
}