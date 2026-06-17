#ifndef TREE_H
#define TREE_H

typedef struct
{
    int files;
    int directories;
} tree_stats_t;

void arbor_visit(const char *base_path,
                 int depth,
                 int branches[],
                 tree_stats_t *stats);

#endif
