#include "point.h"

#include "math.h"

error_e
point_file_scan(point_t &point, FILE *file) {
    if (file == NULL)
        return  FILE_NULL_ERROR;

    error_e rc = SUCCESS;

    if (fscanf(file, "%lf %lf %lf", &point.x, &point.y, &point.z) != 3)
        rc = FILE_POINT_READ_ERROR;

    return rc;
}

error_e
point_file_print(const point_t &point, FILE *file) {
    if (file == NULL)
        return FILE_NULL_ERROR;

    error_e rc = SUCCESS;

    if (fprintf(file, "%lf %lf %lf\n", point.x, point.y, point.z) < 0)
        rc = FILE_POINT_WRITE_ERROR;

    return rc;
}

error_e
point_move(point_t &point, const move_deltas_t &deltas) {
    point.x += deltas.dx;
    point.y += deltas.dy;
    point.z += deltas.dz;

    return SUCCESS;
}

#define PI acos(-1.0)

inline double
to_rad(double angle) {
    return angle * (PI / 180.0);
}

static void
point_rotate_x(point_t &point, const point_t &center, const double angle) {
    double r_cos = cos(to_rad(angle));
    double r_sin = sin(to_rad(angle));

    double y = point.y;

    point.y = (point.y - center.y) * r_cos + (point.z - center.z) * r_sin + center.y;
    point.z = -(y - center.y) * r_sin + (point.z - center.z) * r_cos + center.z;
}

static void
point_rotate_y(point_t &point, const point_t &center, double angle) {
    double r_cos = cos(to_rad(angle));
    double r_sin = sin(to_rad(angle));

    double x = point.x;

    point.x = (point.x - center.x) * r_cos + (point.z - center.z) * r_sin + center.x;
    point.z = -(x - center.y) * r_sin + (point.z - center.z) * r_cos + center.z;
}

static void
point_rotate_z(point_t &point, const point_t &center, double angle) {
    double r_cos = cos(to_rad(angle));
    double r_sin = sin(to_rad(angle));

    double x = point.x;

    point.x = (point.x - center.x) * r_cos + (point.y - center.y) * r_sin + center.x;
    point.y = -(x - center.x) * r_sin + (point.y - center.y) * r_cos + center.y;
}

error_e
point_rotate(point_t &point, const point_t &center, const rotate_angles_t &angles) {
    point_rotate_x(point, center, angles.ox);
    point_rotate_y(point, center, angles.oy);
    point_rotate_z(point, center, angles.oz);

    return SUCCESS;
}


error_e
point_scale(point_t &point, const point_t &center, const scale_coeffs_t &coeffs) {
    if (coeffs.kx == 0 || coeffs.ky == 0 || coeffs.kz == 0)
        return ZERO_SCALE_COEF_ERROR;

    point.x = (point.x - center.x) * coeffs.kx + center.x;
    point.y = (point.y - center.y) * coeffs.ky + center.y;
    point.z = (point.z - center.z) * coeffs.kz + center.z;

    return SUCCESS;
}
