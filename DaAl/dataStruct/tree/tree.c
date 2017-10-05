#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

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
        //Visit(t, Func, p);
        PreOrder(t->left, Func, p);
        PreOrder(t->right, Func, p);
    }
}

void InOrder(Tree* t, int (*Func)(Tree* t, void* p), void* p)
{
    if(t != NULL)
    {
        InOrder(t->left, Func, p);
        Visit(t, Func, p);
        InOrder(t->right, Func, p);
    }
}

void PostOrder(Tree* t, int (*Func)(Tree* t, void* p), void* p)
{
    if(t != NULL)
    {
        PostOrder(t->left, Func, p);
        PostOrder(t->right, Func, p);
        Visit(t, Func, p);
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

int AddChild(Tree* parent, Tree* child, int loc)
{
    if(parent != NULL)
    {
        switch(loc)
        {
            case LEFT:
                parent->left = child;
                break;
            case RIGHT:
                parent->right = child;
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
