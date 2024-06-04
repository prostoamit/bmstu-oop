#include "QtLineDrawer.hpp"

#include <cmath>

QtLineDrawer::QtLineDrawer(QPainter &painter) :
    painter(painter)
{}

void QtLineDrawer::draw(const Point2D &point_1, const Point2D &point_2) {
    painter.drawLine(
            int(round(point_1.get_x())),
            int(round(point_1.get_y())),
            int(round(point_2.get_x())),
            int(round(point_2.get_y()))
            );
}