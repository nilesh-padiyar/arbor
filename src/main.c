#define _DEFAULT_SOURCE

#include <stdio.h>
#include <dirent.h>
#include <string.h>

void arbor_visit(const char *base_path, int depth)
{
    // 1. Open the directory passed into the function
    DIR *dir = opendir(base_path);

    if (dir == NULL)
    {
        // If a directory can't be opened
        return;
    }

    struct dirent *entity;
    int directory = DT_DIR;
    int file = DT_REG;

    // 2. Loop through the contents
    while ((entity = readdir(dir)) != NULL)
    {
        // Skip hidden files/directories
        if (entity->d_name[0] == '.')
        {
            continue;
        }

        // Visual Indentation:
        for (int i = 0; i < depth; i++)
        {
            printf("    ");
        }

        // 3. Check types and handle branching
        if (entity->d_type == directory)
        {
            printf("%s [DIR]\n", entity->d_name); 

            // --- RECURSION ENGINE ---
            // Create a buffer to hold the child's full path
            char next_path[1024];
            
            // Glue the parent path and child name together safely
            snprintf(next_path, sizeof(next_path), "%s/%s", base_path, entity->d_name);
            
            // Dive into the subfolder, increasing the depth counter by 1
            arbor_visit(next_path, depth + 1);
        } 
        else if (entity->d_type == file)
        {
            printf("%s [FILE]\n", entity->d_name);
        }
    }

    // 4. Clean up the directory stream for this specific level
    closedir(dir);
}

int main(void)
{
    // Start the tree exploration at the current directory (".") with a starting depth of 0
    arbor_visit(".", 0);

    return 0;
}
