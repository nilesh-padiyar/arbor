
#define _DEFAULT_SOURCE()

#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(void)
{
    DIR *dir = opendir(".");

    if (dir == NULL)
    {
        printf("Error: No file or directory found!\n");
        return 1;
    }

    struct dirent *entry;

    int directory = DT_DIR;
    int file = DT_REG;

    while ((entry = readdir(dir)) !=  NULL)
    {
        if (entry->d_type == directory)
        {
            printf("[DIR] %s\n", entry->d_name); 
        } else if (entry->d_type == file)
        {
            printf("[FILE] %s\n", entry->d_name);
        }
    }

    closedir(dir);

    return 0;
}
