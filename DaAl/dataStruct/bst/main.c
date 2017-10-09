#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "tree.h"

int CompareInt(void* src, void* dst)
{
    if(*((int*)src) == *((int*)dst))
    {
        return 0;
    }
    else if(*((int*)src) > *((int*)dst))
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int* FillBlocks(Tree* t, int count)
{
    int* data = (int*)malloc(sizeof(int) * count);

    srand(time(NULL));
    printf("init data\n");
    for(int a = 0; a < count; a++)
    {
        data[a] = rand() % 99;
        printf("%d\t", data[a]);
        Insert(t, CompareInt, data + a);
    }
    printf("\ninit finished\n");

    return data;
}

int BaseTest(int level)
{
    Tree* t = InitTreeNode();
    Fill(t, level);
    printf("\n");

    srand(time(NULL));

    PreOrder(t, PrintTree, NULL);
    printf("\n");
    LevelOrder(t, PrintTree, NULL);
    printf("\n");

    return 0;
}

int BSTTest(int count)
{
    int* data = (int*)malloc(sizeof(int) * count);
    Tree* t = InitTreeNode();

    FillBlocks(t, count);

    PreOrder(t, PrintTree, NULL);
    printf("\n");
    InOrder(t, PrintTree, NULL);
    printf("\n");
    PostOrder(t, PrintTree, NULL);
    printf("\n");
    LevelOrder(t, PrintTree, NULL);
    printf("\n");
    
    return 0;
}

int DeleteTest(int count)
{
    Tree* t = InitTreeNode();
    int* data = FillBlocks(t, count);

    printf("pre:\n");
    LevelOrder(t, PrintTree, NULL);
    printf("\n");
    printf("remove 1 / 2: %d\n", *(data + count / 2));
    printf("\n");
    int* removed = Remove(t, CompareInt, data + count / 2);

    LevelOrder(t, PrintTree, NULL);
    printf("\n");
    
}

int main(int argc, char** argv)
{
    if(strcmp(argv[1], "base") == 0)
    {
        if(argc >= 2)
        {
            return BaseTest(atoi(argv[2]));
        }
    }
    if(strcmp(argv[1], "bst") == 0)
    {
        if(argc >= 2)
        {
            return BSTTest(atoi(argv[2]));
        }
    }
    if(strcmp(argv[1], "del") == 0)
    {
        if(argc >= 2)
        {
            return DeleteTest(atoi(argv[2]));
        }
    }
}
