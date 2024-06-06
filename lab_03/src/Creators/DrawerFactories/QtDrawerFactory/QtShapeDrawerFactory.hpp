#ifndef QTSHAPEDRAWERFACTORY_HPP
#define QTSHAPEDRAWERFACTORY_HPP

#include <QGraphicsScene>

#include "Creators/DrawerFactories/ShapeDrawerFactory.hpp"

namespace Drawer {
    class QtShapeDrawerFactory : public ShapeDrawerFactory {
    public:
        explicit QtShapeDrawerFactory(std::shared_ptr<QGraphicsScene> graphics_scene);

        std::shared_ptr<Line> create_line_drawer() override;
        std::shared_ptr<ScreenCleaner> create_screen_cleaner() override;
    protected:
        std::shared_ptr<QGraphicsScene> graphics_scene;
    };
}

#endif //QTSHAPEDRAWERFACTORY_HPP
