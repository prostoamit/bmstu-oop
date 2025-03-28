#ifndef DRAWMANAGER_HPP
#define DRAWMANAGER_HPP

#include <memory>

#include "Creators/DrawerFactories/ShapeDrawerFactory.hpp"

class DrawManager {
public:
    void set_drawer(std::shared_ptr<Drawer::ShapeDrawerFactory> factory);

    void draw_scene();
protected:
    DrawManager() = default;
    DrawManager(const DrawManager& drawer) = default;

    std::shared_ptr<Drawer::Line> line_drawer;
    std::shared_ptr<Drawer::ScreenCleaner> screen_cleaner;
};


#endif //DRAWMANAGER_HPP
