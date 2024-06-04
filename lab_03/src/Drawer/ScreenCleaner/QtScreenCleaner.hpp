#ifndef QTSCREENCLEANER_HPP
#define QTSCREENCLEANER_HPP

#include <QPainter>

#include "ScreenCleaner.hpp"

class QtScreenCleaner : ScreenCleaner {
public:
    QtScreenCleaner(QPainter& painter);

    virtual void draw() override;
private:
    QPainter& painter;
};


#endif //QTSCREENCLEANER_HPP
