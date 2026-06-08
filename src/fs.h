#ifndef FS_H
#define FS_H

#include <dirent.h>

#define MAX_ENTRIES 1024
#define MAX_DEPTH   64

int fs_collect_entries(const char *path, struct dirent *entries[]);
void fs_free_entries(struct dirent *entries[], int count);

#endif
