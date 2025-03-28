#include "TransformationMatrix.hpp"

#include <gsl/gsl_vector.h>
#include <gsl/gsl_blas.h>

#include <cmath>
#include <iomanip>

TransformationMatrix::TransformationMatrix() {
    matrix = gsl_matrix_calloc(4, 4);

    gsl_matrix_set(matrix, 3, 3, 1.0);
}

TransformationMatrix::~TransformationMatrix() {
    gsl_matrix_free(matrix);
}

void TransformationMatrix::apply(std::shared_ptr<Point> point) const {
    apply(*point);
}

std::shared_ptr<Point> TransformationMatrix::apply_get(std::shared_ptr<Point> point) const {
    auto new_point = std::make_shared<Point>(*point);
    apply(*new_point);
    return new_point;
}

void TransformationMatrix::apply(Point& point) const {
    gsl_matrix* column_point = gsl_matrix_calloc(4, 1);
    gsl_matrix* result = gsl_matrix_calloc(4, 1);

    gsl_matrix_set(column_point, 0, 0, point.get_x());
    gsl_matrix_set(column_point, 1, 0, point.get_y());
    gsl_matrix_set(column_point, 2, 0, point.get_z());
    gsl_matrix_set(column_point, 3, 0, 1.0);

    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, matrix, column_point, 0.0, result);

    point.set_x(gsl_matrix_get(result, 0, 0));
    point.set_y(gsl_matrix_get(result, 1, 0));
    point.set_z(gsl_matrix_get(result, 2, 0));

    gsl_matrix_free(column_point);
    gsl_matrix_free(result);
}

void TransformationMatrix::prepare_move(double x_delta, double y_delta, double z_delta) {
    gsl_matrix_set_all(matrix, 0.0);

    gsl_matrix_set(matrix, 0, 3, x_delta);
    gsl_matrix_set(matrix, 1, 3, y_delta);
    gsl_matrix_set(matrix, 2, 3, z_delta);

    gsl_matrix_set(matrix, 0, 0, 1.0);
    gsl_matrix_set(matrix, 1, 1, 1.0);
    gsl_matrix_set(matrix, 2, 2, 1.0);
    gsl_matrix_set(matrix, 3, 3, 1.0);
}

void TransformationMatrix::prepare_scale(double x_coefficient, double y_coefficient, double z_coefficient) {
    gsl_matrix_set_all(matrix, 0.0);

    gsl_matrix_set(matrix, 0, 0, x_coefficient);
    gsl_matrix_set(matrix, 1, 1, y_coefficient);
    gsl_matrix_set(matrix, 2, 2, z_coefficient);

    gsl_matrix_set(matrix, 3, 3, 1.0);
}

void TransformationMatrix::prepare_rotate(double x_axis_angle, double y_axis_angle, double z_axis_angle) {
    double cos_a = cos(x_axis_angle);
    double sin_a = sin(x_axis_angle);
    double cos_b = cos(y_axis_angle);
    double sin_b = sin(y_axis_angle);
    double cos_t = cos(z_axis_angle);
    double sin_t = sin(z_axis_angle);

    gsl_matrix_set(matrix, 0, 0, cos_t * cos_b);
    gsl_matrix_set(matrix, 0, 1, cos_t * sin_b * sin_a - sin_t * cos_a);
    gsl_matrix_set(matrix, 0, 2, cos_t * sin_b * cos_a + sin_t * sin_a);
    gsl_matrix_set(matrix, 0, 3, 0.0);

    gsl_matrix_set(matrix, 1, 0, sin_t * cos_b);
    gsl_matrix_set(matrix, 1, 1, sin_t * sin_b * sin_a + cos_t * cos_a);
    gsl_matrix_set(matrix, 1, 2, sin_t * sin_b * cos_a - cos_t * sin_a);
    gsl_matrix_set(matrix, 1, 3, 0.0);

    gsl_matrix_set(matrix, 2, 0, -sin_b);
    gsl_matrix_set(matrix, 2, 1, cos_b * sin_a);
    gsl_matrix_set(matrix, 2, 2, cos_b * cos_a);
    gsl_matrix_set(matrix, 2, 3, 0.0);

    gsl_matrix_set(matrix, 3, 0, 0.0);
    gsl_matrix_set(matrix, 3, 1, 0.0);
    gsl_matrix_set(matrix, 3, 2, 0.0);
    gsl_matrix_set(matrix, 3, 3, 1.0);
}

TransformationMatrix TransformationMatrix::operator*(const TransformationMatrix& other) const {
    TransformationMatrix result;

    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, other.matrix, matrix, 0.0, result.matrix);

    return result;
}

TransformationMatrix& TransformationMatrix::operator*=(const TransformationMatrix& other) {
    gsl_matrix* result = gsl_matrix_alloc(4, 4);
    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, other.matrix, matrix, 0.0, result);

    gsl_matrix_memcpy(matrix, result);

    return *this;
}

void TransformationMatrix::set(size_t i, size_t j, double value) {
    gsl_matrix_set(matrix, i, j, value);
}

std::ostream& operator<<(std::ostream& out, TransformationMatrix& matrix) {
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            out << std::setprecision(3) << std::setw(10) << gsl_matrix_get(matrix.matrix, i, j) << ' ';
        }
        std::cout << std::endl;
    }

    return out;
}
