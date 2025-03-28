#ifndef LINEDRAWER_HPP
#define LINEDRAWER_HPP

#include "Geometry/Point2D.hpp"

namespace Drawer {
    class Line {
    public:
        virtual ~Line() = default;

        virtual void draw(const Point2D& point_1, const Point2D& point_2) = 0;
    };
}

#endif //LINEDRAWER_HPP
