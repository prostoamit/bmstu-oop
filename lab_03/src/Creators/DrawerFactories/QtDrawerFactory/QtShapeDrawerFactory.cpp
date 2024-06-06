#include "QtShapeDrawerFactory.hpp"

#include "Drawer/Line/QtLineDrawer/QtLineDrawer.hpp"
#include "Drawer/ScreenCleaner/QtScreenCleaner/QtScreenCleaner.hpp"

using namespace Drawer;

QtShapeDrawerFactory::QtShapeDrawerFactory(std::shared_ptr<QGraphicsScene> graphics_scene) :
        graphics_scene(graphics_scene) {}

std::shared_ptr<Line> QtShapeDrawerFactory::create_line_drawer() {
    return std::make_shared<QtLine>(graphics_scene);
}

std::shared_ptr<ScreenCleaner> QtShapeDrawerFactory::create_screen_cleaner() {
    return std::make_shared<QtScreenCleaner>(graphics_scene);
}
