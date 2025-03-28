#include "QtLineDrawer.hpp"

#include <cmath>

using namespace Drawer;

QtLine::QtLine(std::shared_ptr<QGraphicsScene> scene) :
    scene(scene)
{}

void QtLine::draw(const Point2D &point_1, const Point2D &point_2) {
    scene->addLine(
            int(round(point_1.get_x())),
            int(round(point_1.get_y())),
            int(round(point_2.get_x())),
            int(round(point_2.get_y()))
            );
}