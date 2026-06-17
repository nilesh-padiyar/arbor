#include <stdio.h>
#include <unistd.h>
#include <libgen.h>

#include "tree.h"
#include "fs.h"

int main(void)
{
    int branches[MAX_DEPTH] = {0};

    tree_stats_t stats = {0};

    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s\n", basename(cwd));
    }
    else
    {
        printf(".\n");
    }

    arbor_visit(".",
                0,
                branches,
                &stats);

    printf("\n");
    printf("%d director%s, %d file%s\n",
           stats.directories,
           stats.directories == 1 ? "y" : "ies",
           stats.files,
           stats.files == 1 ? "" : "s");

    return 0;
}
