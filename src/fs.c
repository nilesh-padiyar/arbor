#define _DEFAULT_SOURCE

#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#include "fs.h"

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
