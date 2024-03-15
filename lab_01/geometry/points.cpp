#include "points.h"

#include <stdlib.h>

void
points_init(points_t &points) {
    points.points = NULL;
    points.size = 0;
}

void
points_free(points_t &points) {
    free(points.points);
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
points_allocate(points_t &points, size_t size) {
    error_e rc = SUCCESS;

    points.points = (point_t *)malloc(size * sizeof(point_t));
    points.size = size;
    if (points.points == NULL) {
        rc = MEMORY_ALLOCATE_ERROR;
        points.size = 0;
    }

    return rc;
}

static error_e
points_file_scan(points_t &points, const size_t size, FILE *file) {
    if (file == NULL)
        return FILE_NULL_ERROR;

    error_e rc = SUCCESS;

    for (size_t i = 0; i < size && rc == SUCCESS; i++)
        rc = point_file_scan(points.points[i], file);

    return rc;
}

error_e
points_handle_file_scan(points_t &points, FILE *file) {
    if (file == NULL)
        return FILE_NULL_ERROR;

    error_e rc = SUCCESS;

    size_t size;

    rc = size_file_scan(size, file);
    if (rc != SUCCESS)
        rc = FILE_POINTS_COUNT_READ_ERROR;

    else {
        rc = points_allocate(points, size);

        if (rc != SUCCESS)
            rc = MEMORY_ALLOCATE_ERROR;
        else {
            rc = points_file_scan(points, size, file);

            if (rc != SUCCESS) {
                points_free(points);
                rc = FILE_POINT_READ_ERROR;
            }
        }
    }

    return rc;
}

error_e
points_move(points_t &points, const move_deltas_t &deltas) {
    error_e rc = SUCCESS;

    for (size_t i = 0; i < points.size && rc == SUCCESS; i++)
        rc = point_move(points.points[i], deltas);

    return rc;
}

error_e
points_rotate(points_t &points, const point_t &center, const rotate_angles_t &angles) {
    error_e rc = SUCCESS;

    for (size_t i = 0; i < points.size && rc == SUCCESS; i++)
        rc = point_rotate(points.points[i], center, angles);

    return rc;
}

error_e
points_scale(points_t &points, const point_t &center, const scale_coeffs_t &coeffs) {
    error_e rc = SUCCESS;

    for (size_t i = 0; i < points.size && rc == SUCCESS; i++)
        rc = point_scale(points.points[i], center, coeffs);

    return rc;
}

