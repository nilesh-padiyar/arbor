#define _DEFAULT_SOURCE

#include <stdio.h>
#include <dirent.h>

#include "tree.h"
#include "fs.h"

void arbor_visit(const char *base_path,
                 int depth,
                 int branches[],
                 tree_stats_t *stats)
{
    stats->directories++;

    struct dirent *entries[MAX_ENTRIES];

    int count = fs_collect_entries(base_path, entries);

    if (count < 0)
    {
        return;
    }

    for (int i = 0; i < count; i++)
    {
        struct dirent *entity = entries[i];

        int is_last = (i == count - 1);

        for (int j = 0; j < depth; j++)
        {
            if (branches[j])
            {
                printf("│   ");
            }
            else
            {
                printf("    ");
            }
        }

        printf("%s── ", is_last ? "└" : "├");

        if (entity->d_type == DT_DIR)
        {
            printf("%s/\n", entity->d_name);

            char next_path[1024];

            snprintf(next_path,
                     sizeof(next_path),
                     "%s/%s",
                     base_path,
                     entity->d_name);

            branches[depth] = !is_last;

            arbor_visit(next_path,
                        depth + 1,
                        branches,
                        stats);
        }
        else
        {
            stats->files++;

            printf("%s\n", entity->d_name);
        }
    }

    fs_free_entries(entries, count);
}
