#include "ElevatorManager.hpp"

#include <string>

#include <QObject>
#include <QDebug>

ElevatorManager::ElevatorManager(QObject* parent) :
        QObject(parent),
        controller(this),
        cabin(this) {

    QObject::connect(&controller, SIGNAL(signal_continue_moving()), &cabin, SLOT(moving()));
    QObject::connect(&controller, SIGNAL(signal_cabin_stop()), &cabin, SLOT(stopped()));
    QObject::connect(&controller, SIGNAL(signal_start_moving()), &cabin, SLOT(moving()));


    QObject::connect(&controller, SIGNAL(signal_update_target()), &controller, SLOT(updating_target()));
    QObject::connect(&controller, SIGNAL(signal_wait()), &controller, SLOT(waiting()));
    QObject::connect(&controller, SIGNAL(signal_reached_target()), &controller, SLOT(reached_target()));


    QObject::connect(&cabin, SIGNAL(signal_locking()), &cabin, SLOT(locked()));
    QObject::connect(&cabin, SIGNAL(signal_passed_floor()), &cabin.floor_passing_timer, SLOT(start()));
    QObject::connect(&cabin.floor_passing_timer, SIGNAL(timeout()), &controller, SLOT(moving()));
    QObject::connect(&cabin, SIGNAL(signal_update_target()), &controller, SLOT(updating_target()));
}

void ElevatorManager::internal_pressed(int floor) {
    qDebug() << "В лифте нажата кнопка " << floor << " этажа.\n";

    controller.add_target(floor - 1);
}

void ElevatorManager::external_button_pressed(int floor, FloorStates direction_requested) {
    std::string direction;
    if (direction_requested == FloorStates::UP)
        direction = "вверх";
    if (direction_requested == FloorStates::DOWN)
        direction = "вниз";

    qDebug() << "Вызван лифт " << QString::fromStdString(direction) << " с " << floor << " этажа.\n";

    controller.add_target(floor - 1, direction_requested);

}
