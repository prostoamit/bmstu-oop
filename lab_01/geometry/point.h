#ifndef POINT_H
#define POINT_H

#include <stdio.h>

#include "errors.h"

#include "modifications.h"

struct point {
    double x;
    double y;
    double z;
};

using point_t = struct point;

using move_deltas_t = struct move_deltas;
using rotate_angles_t = struct rotate_angles;
using scale_coeffs_t = struct scale_coeffs;

error_e point_file_scan(point_t &point, FILE *file);
error_e point_file_print(const point_t &point, FILE *file);

error_e point_move(point_t &point, const move_deltas_t &deltas);
error_e point_rotate(point_t &point, const point_t &center, const rotate_angles_t &angles);
error_e point_scale(point_t &point, const point_t &center, const scale_coeffs_t &coeffs);


#endif // POINT_H
