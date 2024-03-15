#ifndef EDGE_H
#define EDGE_H

#include "stddef.h"
#include "stdio.h"

#include "errors.h"

struct edge {
    size_t point_1;
    size_t point_2;
};

using edge_t = struct edge;

error_e edge_file_scan(edge_t &edge, FILE *file);
error_e edge_file_print(FILE *file, edge_t &edge);

#endif // EDGE_H
