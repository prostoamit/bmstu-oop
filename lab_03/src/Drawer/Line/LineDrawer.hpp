#ifndef LINEDRAWER_HPP
#define LINEDRAWER_HPP

#include "Point2D.hpp"

class LineDrawer {
public:
    virtual ~LineDrawer() = default;

    virtual void draw(const Point2D& point_1, const Point2D& point_2) = 0;
};


#endif //LINEDRAWER_HPP
