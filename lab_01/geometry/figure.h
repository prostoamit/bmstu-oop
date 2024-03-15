#ifndef FIGURE_H
#define FIGURE_H

#include "stddef.h"
#include "stdio.h"

#include "points.h"
#include "edges.h"

#include "modifications.h"

struct figure {
    points_t points;
    edges_t edges;
};

using figure_t = struct figure;

void figure_init(figure_t &figure);
void figure_free(figure_t &figure);

error_e figure_handle_file_scan(figure_t &figure, const char* filename);

error_e figure_move(figure_t &figure, const move_deltas_t &deltas);
error_e figure_rotate(figure_t &figure, const rotate_angles_t &angles);
error_e figure_scale(figure_t &figure, const scale_coeffs_t &coeffs);

#endif // FIGURE_H
