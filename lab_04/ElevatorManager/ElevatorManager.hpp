#ifndef ELEVATORMANAGER_HPP
#define ELEVATORMANAGER_HPP

#include <QObject>

#include "Floors.hpp"

#include "Controller.hpp"
#include "Cabin.hpp"

enum class Direction {
    UP, DOWN, IDLE
};

class ElevatorManager : QObject {
Q_OBJECT
public:
    ElevatorManager(QObject* parent = nullptr);

    void internal_pressed(int floor);
    void external_button_pressed(int floor, FloorStates direction_requested);
private:
    Controller controller;
    Cabin cabin;
};


#endif //ELEVATORMANAGER_HPP
