#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "tree.h"


int BaseTest(int level)
{
    Tree* t = InitTreeNode();
    Fill(t, level);

    srand(time(NULL));

    PreOrder(t, Print, NULL);
    printf("\n");
    LevelOrder(t, Print, NULL);

    return 0;
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
}
