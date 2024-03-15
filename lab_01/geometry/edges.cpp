#include "edges.h"

#include <stdlib.h>

void
edges_init(edges_t &edges) {
    return;
}

void
edges_free(edges_t &edges) {
    free(edges.edges);
}

static error_e
size_file_scan(size_t &size, FILE *file) {
    if (file == NULL)
        return FILE_NULL_ERROR;

    error_e rc = SUCCESS;

    size_t tmp = 0;
    if (fscanf(file, "%zu", &tmp) != 1)
        rc = FILE_READ_ERROR;
    else
        size = tmp;

    return rc;
}

static error_e
edges_allocate(edges_t &edges, size_t size) {
    error_e rc = SUCCESS;

    edges.edges = (edge_t *)malloc(size * sizeof(edge_t));
    edges.size = size;
    if (edges.edges == NULL) {
        edges.size = 0;
        rc = MEMORY_ALLOCATE_ERROR;
    }

    return rc;
}

static error_e
edges_file_scan(edges_t &edges, const size_t size, FILE *file) {
    if (file == NULL)
        return FILE_NULL_ERROR;

    error_e rc = SUCCESS;

    for (size_t i = 0; i < size && rc == SUCCESS; i++)
        rc = edge_file_scan(edges.edges[i], file);

    return rc;
}

error_e edges_handle_file_scan(edges_t &edges, FILE *file) {
    if (file == NULL)
        return FILE_NULL_ERROR;

    error_e rc = SUCCESS;

    size_t size;

    rc = size_file_scan(size, file);
    if (rc != SUCCESS)
        rc = FILE_POINTS_COUNT_READ_ERROR;

    else {
        rc = edges_allocate(edges, size);

        if (rc != SUCCESS)
            rc = MEMORY_ALLOCATE_ERROR;
        else {
            rc = edges_file_scan(edges, size, file);

            if (rc != SUCCESS) {
                edges_free(edges);
                rc = FILE_POINT_READ_ERROR;
            }
        }
    }

    return rc;
}
