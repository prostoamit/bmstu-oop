#ifndef POINTS_H
#define POINTS_H

#include "stddef.h"
#include "stdio.h"

#include "errors.h"

#include "point.h"
#include "modifications.h"

struct points {
    point_t *points;
    size_t size;
};

using points_t = struct points;

void points_init(points_t &points);
void points_free(points_t &points);

error_e points_handle_file_scan(points_t &points, FILE *file);

error_e points_move(points_t &points, const move_deltas_t &deltas);
error_e points_rotate(points_t &points, const point_t &center, const rotate_angles_t &angles);
error_e points_scale(points_t &points, const point_t &center, const scale_coeffs_t &coeffs);

#endif // POINTS_H
