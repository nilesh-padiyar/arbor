#define _DEFAULT_SOURCE

#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#include "fs.h"

static int compare_entries(const void *a, const void *b)
{
    const struct dirent *left = *(const struct dirent **)a;
    const struct dirent *right = *(const struct dirent **)b;

    int left_is_dir = left->d_type == DT_DIR;
    int right_is_dir = right->d_type == DT_DIR;

    if (left_is_dir != right_is_dir)
    {
        return right_is_dir - left_is_dir;
    }

    return strcmp(left->d_name, right->d_name);
}

int fs_collect_entries(const char *path, struct dirent *entries[])
{
    DIR *dir = opendir(path);

    if (dir == NULL)
    {
        return -1;
    }

    struct dirent *entity;
    int count = 0;

    while ((entity = readdir(dir)) != NULL)
    {
        if (entity->d_name[0] == '.')
        {
            continue;
        }

        entries[count] = malloc(sizeof(struct dirent));

        if (entries[count] == NULL)
        {
            closedir(dir);
            return -1;
        }

        memcpy(entries[count], entity, sizeof(struct dirent));

        count++;
    }

    qsort(entries,
          count,
          sizeof(struct dirent *),
          compare_entries);

    closedir(dir);

    return count;
}

void fs_free_entries(struct dirent *entries[], int count)
{
    for (int i = 0; i < count; i++)
    {
        free(entries[i]);
    }
}
