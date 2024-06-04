#ifndef VECTOR_HPP
#define VECTOR_HPP


class Vector {
    double get_x() const;
    void set_x(double x);

    double get_y() const;
    void set_y(double y);

    double get_z() const;
    void set_z(double z);

private:
    double _x;
    double _y;
    double _z;
};


#endif //VECTOR_HPP
