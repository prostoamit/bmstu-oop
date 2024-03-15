#include "edge.h"


error_e edge_file_scan(edge_t &edge, FILE *file) {
    if (file == NULL)
        return FILE_NULL_ERROR;

    error_e rc = SUCCESS;

    if (fscanf(file, "%zu %zu", &edge.point_1, &edge.point_2) != 2)
        rc = FILE_EDGE_READ_ERROR;

    return rc;
}

error_e edge_file_print(FILE *file, edge_t &edge) {
    if (file == NULL)
        return FILE_NULL_ERROR;

    error_e rc = SUCCESS;

    if (fprintf(file, "%zu %zu", edge.point_1, edge.point_2) != 2)
        rc = FILE_EDGE_WRITE_ERROR;

    return rc;
}
