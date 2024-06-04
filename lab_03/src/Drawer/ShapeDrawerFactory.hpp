#ifndef SHAPEDRAWERFACTORY_HPP
#define SHAPEDRAWERFACTORY_HPP

#include <memory>

#include "ScreenCleaner/ScreenCleaner.hpp"
#include "Line/LineDrawer.hpp"

class ShapeDrawerFactory {
public:
    virtual ~ShapeDrawerFactory() = 0;

    virtual std::shared_ptr<ScreenCleaner> create_screen_cleaner() = 0;
    virtual std::shared_ptr<LineDrawer> create_line_drawer() = 0;
};


#endif //SHAPEDRAWERFACTORY_HPP
