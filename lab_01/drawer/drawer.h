#ifndef DRAWER_H
#define DRAWER_H

#include <QMainWindow>


#include <QtWidgets/QGraphicsView>

#include "errors.h"
#include "figure.h"

error_e figure_draw(QGraphicsScene *scene, figure_t &figure);

#endif // DRAWER_H
