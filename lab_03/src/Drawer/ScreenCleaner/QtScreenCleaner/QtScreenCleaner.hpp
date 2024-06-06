#ifndef QTSCREENCLEANER_HPP
#define QTSCREENCLEANER_HPP

#include <QGraphicsScene>

#include "Drawer/ScreenCleaner/ScreenCleaner.hpp"

namespace Drawer {
    class QtScreenCleaner : public ScreenCleaner {
    public:
        QtScreenCleaner(std::shared_ptr<QGraphicsScene> scene);

        virtual void draw() override;
    private:
        std::shared_ptr<QGraphicsScene> scene;
    };
}

#endif //QTSCREENCLEANER_HPP
