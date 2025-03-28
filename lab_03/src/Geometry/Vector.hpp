#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector {
public:
    Vector() = default;
    Vector(double x, double y, double z);

    double angle(const Vector& other) const;
    double scalar_multiply(const Vector& other) const;

    double get_x() const;
    void set_x(double x);

    double get_y() const;
    void set_y(double _y);

    double get_z() const;
    void set_z(double z);

    double length() const;
    void normalize();

private:
    double x;
    double y;
    double z;
};


#endif //VECTOR_HPP
