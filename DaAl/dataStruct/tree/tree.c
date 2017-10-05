#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "tree.h"

void Fill(Tree* t, int level)
{
    if(level > 0)
    {
        t->left = InitTreeNode();
        t->right = InitTreeNode();
        Fill(t->left, level - 1);
        Fill(t->right, level - 1);
        
        t->data = malloc(sizeof(int));
        *((int*)(t->data)) = rand() % 10;
        printf("%d\t", *((int*)(t->data)));
        printf("\n");
    }
}

int Print(Tree* t, void* p)
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
    if(t != NULL)
    {
        (*Func)(t->left, p);
        (*Func)(t->right, p);
        LevelOrder(t->left, Func, p);
        LevelOrder(t->right, Func, p);
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

Tree* RemoveChild(Tree* parent, int loc)
{
    if(parent != NULL)
    {
        Tree* t = NULL;
        switch(loc)
        {
            case LEFT:
                t = parent->left;
                break;
            case RIGHT:
                t = parent->right;
                break;
            default:
                return NULL;
                break;
        }
        return t;
    }
    else
    {
        return NULL;
    }
}
