#ifndef QTLINEDRAWER_HPP
#define QTLINEDRAWER_HPP

#include <QGraphicsScene>

#include "Drawer/Line/LineDrawer.hpp"
#include "Drawer/Line/LineDrawer.hpp"
#include "Geometry/Point2D.hpp"

namespace Drawer {
    class QtLine : public Line {
    public:
        explicit QtLine(std::shared_ptr<QGraphicsScene> scene);

        virtual void draw(const Point2D& point_1, const Point2D& point_2) override;
    private:
        std::shared_ptr<QGraphicsScene> scene;
    };
}

#endif //QTLINEDRAWER_HPP
