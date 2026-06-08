#include <stdio.h>

#include "tree.h"
#include "fs.h"

int main(void)
{
    int branches[MAX_DEPTH] = {0};

    printf(".\n");

    arbor_visit(".", 0, branches);

    return 0;
}
