#ifndef POINT2D_HPP
#define POINT2D_HPP


class Point2D {
public:
    Point2D();
    Point2D(double x, double y);

    double get_x() const;
    void set_x(double x);

    double get_y() const ;
    void set_y(double y);
private:
    double _x;
    double _y;
};


#endif //POINT2D_HPP
