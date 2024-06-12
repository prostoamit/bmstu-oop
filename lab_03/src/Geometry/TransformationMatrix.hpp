#ifndef TRANSFORMATIONMATRIX_HPP
#define TRANSFORMATIONMATRIX_HPP

#include <memory>
#include <gsl/gsl_matrix.h>
#include <iostream>

#include "Geometry/Point.hpp"

class TransformationMatrix {
public:
    TransformationMatrix();
    ~TransformationMatrix();

    void apply(std::shared_ptr<Point> point) const;
    std::shared_ptr<Point> apply_get(std::shared_ptr<Point> point) const;
    void apply(Point& point) const;

    void prepare_move(double x_delta, double y_delta, double z_delta);
    void prepare_scale(double x_coefficient, double y_coefficient, double z_coefficient);
    void prepare_rotate(double x_axis_angle, double y_axis_angle, double z_axis_angle);

    TransformationMatrix operator*(const TransformationMatrix& other) const;
    TransformationMatrix& operator*=(const TransformationMatrix& other);

    void set(size_t i, size_t j, double value);

    friend std::ostream& operator <<(std::ostream& out, TransformationMatrix& matrix);
private:

    gsl_matrix *matrix;
};


#endif //TRANSFORMATIONMATRIX_HPP
