#ifndef POINT_HPP
#define POINT_HPP


class Point {
public:
    Point(double x, double y, double z);

    Point(const Point& other);

    double get_x() const;
    void set_x(double x);
    
    double get_y() const;
    void set_y(double y);

    double get_z() const;
    void set_z(double z);

    Point& operator=(const Point& other) = default;
    bool operator==(const Point& other) const = default;
    
private:
    double _x;
    double _y;
    double _z;
};


#endif //POINT_HPP
