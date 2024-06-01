#ifndef POINT_HPP
#define POINT_HPP


class Point {
public:
    double get_x();
    void set_x(double x);
    
    double get_y();
    void set_y(double y);

    double get_z();
    void set_z(double z);
    
private:
    double _x;
    double _y;
    double _z;
};


#endif //POINT_HPP
