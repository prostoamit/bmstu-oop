#ifndef EDGES_H
#define EDGES_H

#include "stddef.h"
#include "stdio.h"

#include "errors.h"
#include "edge.h"

struct edges {
    edge_t *edges;
    size_t size;
};

using edges_t = struct edges;

void edges_init(edges_t &edges);
void edges_free(edges_t &edges);

error_e edges_handle_file_scan(edges_t &edges, FILE *file);

#endif // EDGES_H
