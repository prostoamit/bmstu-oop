#include "figure.h"


void
figure_init(figure_t &figure) {
    points_init(figure.points);
    edges_init(figure.edges);
}

void
figure_free(figure_t &figure) {
    points_free(figure.points);
    edges_free(figure.edges);
}

static point_t
figure_center(figure_t &figure) {
    point_t center = {0.0, 0.0, 0.0};

    for (size_t i = 0; i < figure.points.size; i++)
    {
        center.x += figure.points.points[i].x;
        center.y += figure.points.points[i].y;
        center.z += figure.points.points[i].z;
    }

    center.x /= figure.points.size;
    center.y /= figure.points.size;
    center.z /= figure.points.size;

    return center;
}

static error_e
figure_file_scan(figure_t &figure, FILE *file) {
    error_e rc = SUCCESS;
    if (file == NULL)
        return FILE_NULL_ERROR;
    else {
        rewind(file);
        rc = points_handle_file_scan(figure.points, file);
        if (rc == SUCCESS)
            rc = edges_handle_file_scan(figure.edges, file);
    }

    return rc;
}

error_e figure_handle_file_scan(figure_t &figure, const char* filename) {
    error_e rc = SUCCESS;

    FILE *file = fopen(filename, "r");
    if (file == NULL)
        rc = FILE_OPEN_ERROR;
    else {
        rc = figure_file_scan(figure, file);
        fclose(file);
    }

    return rc;
}

error_e
figure_move(figure_t &figure, const move_deltas_t &deltas) {
    return points_move(figure.points, deltas);
}

error_e
figure_rotate(figure_t &figure, const rotate_angles_t &angles) {
    return points_rotate(figure.points, figure_center(figure), angles);
//    return points_rotate(figure.points, {0, 0, 0}, angles);
}

error_e
figure_scale(figure_t &figure, const scale_coeffs_t &coeffs) {
    return points_scale(figure.points, figure_center(figure), coeffs);
//    return points_scale(figure.points, {0, 0, 0}, coeffs);
}
