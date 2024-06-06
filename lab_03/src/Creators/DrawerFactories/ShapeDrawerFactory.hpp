#ifndef SHAPEDRAWERFACTORY_HPP
#define SHAPEDRAWERFACTORY_HPP

#include <memory>

#include "Drawer/ScreenCleaner/ScreenCleaner.hpp"
#include "Drawer/Line/LineDrawer.hpp"

namespace Drawer {
    class ShapeDrawerFactory {
    public:
        virtual ~ShapeDrawerFactory() = default;

        virtual std::shared_ptr<ScreenCleaner> create_screen_cleaner() = 0;
        virtual std::shared_ptr<Line> create_line_drawer() = 0;
    };
}

#endif //SHAPEDRAWERFACTORY_HPP
