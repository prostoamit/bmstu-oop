#ifndef QTLINEDRAWER_HPP
#define QTLINEDRAWER_HPP

#include <QPainter>

#include "LineDrawer.hpp"
#include "Point2D.hpp"

class QtLineDrawer : public LineDrawer {
public:
    explicit QtLineDrawer(QPainter& painter);

    virtual void draw(const Point2D &point_1, const Point2D &point_2) override;
private:
    QPainter& painter;
};


#endif //QTLINEDRAWER_HPP
