#include "QtScreenCleaner.hpp"

using namespace Drawer;

QtScreenCleaner::QtScreenCleaner(std::shared_ptr<QGraphicsScene> scene) :
    scene(scene)
{}

void QtScreenCleaner::draw() {
    scene->clear();
}