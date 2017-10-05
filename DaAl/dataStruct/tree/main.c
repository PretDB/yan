#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tree.h"

int Fill(Tree* t)
{
    int* i = (int*)malloc(sizeof(int));
    *i = rand() % 10;
    t->data = i;
    return 0;
}

int Print(Tree* t, void* p)
{
    if(t != NULL && t->data != NULL)
    {
        printf("%d\t", *(int*)(t->data));
    }
    return 0;
}

int LevelFill(Tree* t, void* counter)
{
    if(*((int*)(counter)) >= 0 && t != NULL)
    {
        Fill(t); 
        t->left = InitTreeNode();
        t->right = InitTreeNode();
        printf("%d:%d\n", *((int*)counter), *((int*)(t->data)));
        (*(int*)(counter))--;
    }
    return 0;
}



int main(int argc, char** argv)
{
    int*  limit = NULL;
    Tree* t = NULL;

    t = InitTreeNode();
    limit = (int*)malloc(sizeof(int));
    srand(time(NULL));
    *limit = 10;

    PreOrder(t, LevelFill, (void*)limit);
    *limit = 10;
	InOrder(t, LevelFill, (void*)limit);
    InOrder(t, Print, NULL);
	printf("\n");
	PreOrder(t, Print, NULL);
}
