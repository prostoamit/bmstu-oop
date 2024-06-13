#include "Controller.hpp"

#include <QDebug>

Controller::Controller(QObject* parent) :
        QObject(parent),
        state(State::WAITING),
        current_floor(STARTING_FLOOR),
        target(-1) {
    floors_states.fill(NONE);
}

void Controller::add_target(int floor) {
    FloorStates direction = decide_direction(floor);
    add_target(floor, direction);
}

FloorStates Controller::decide_direction(int floor) {
    if (current_floor <= floor)
        return UP;
    if (current_floor > floor)
        return DOWN;
}

void Controller::add_target(int floor, FloorStates _state) {
    if ((state == State::REACHED_TARGET || state == State::WAITING) && floor == current_floor) {
        floors_states[floor] = FloorStates::NONE;
        emit signal_cabin_open_doors();
    }

    if (floors_states[floor] == _state)
        return;

    if (floors_states[floor] == FloorStates::NONE)
        floors_states[floor] = _state;
    if (floors_states[floor] == FloorStates::UP && _state == FloorStates::DOWN ||
        floors_states[floor] == FloorStates::DOWN && _state == FloorStates::UP)
        floors_states[floor] = FloorStates::BOTH;

        emit signal_update_target();
}

void Controller::waiting() {
    if (state != State::UPDATING_TARGET)
        return;

    state = State::WAITING;
    qDebug() << "Ожидание цели.\n";
}

void Controller::updating_target() {
    state = State::UPDATING_TARGET;
    qDebug() << "Поиск цели.";

    int new_target = find_target();
    if (new_target == -1) {
        qDebug() << "Цель не найдена.";
        emit signal_wait();
    } else {
        target = new_target;
        direction = find_direction(target);

        qDebug() << "Новая цель: " << target + 1 << "\n";

        emit signal_start_moving();
    }
}

void Controller::moving() {
    if (state != State::MOVING && state != State::UPDATING_TARGET)
        return;

    state = State::MOVING;

    current_floor += int(direction);

    qDebug() << "Лифт сместился на " << current_floor + 1 << " этаж.";

    if (current_floor == target)
        emit signal_reached_target();
    else
        emit signal_continue_moving();
}

void Controller::reached_target() {
    if (state != State::MOVING)
        return;

    state = State::REACHED_TARGET;

    floors_states[current_floor] = FloorStates::NONE;
    target = -1;

    qDebug() << "\nЦель достигнута. Этаж " << current_floor + 1 << "\n";

    emit signal_cabin_stop();
}

int Controller::find_target() const {
    if (direction == Direction::NONE) {
        return find_closest_target();
    } else {
        if (direction == Direction::UP)
            return find_closest_up();

        return find_closest_down();
    }
}

int Controller::find_closest_up() const {
    for (int i = current_floor; i < FLOORS_COUNT; i++) {
        if (floors_states[i] == FloorStates::UP || floors_states[i] == FloorStates::BOTH)
            return i;
    }
    for (int i = current_floor; i >= 0; i--)
        if (floors_states[i] == FloorStates::DOWN || floors_states[i] == FloorStates::BOTH)
            return i;

    return find_closest_target();
}

int Controller::find_closest_down() const {
    for (int i = current_floor; i >= 0; i--) {
        if (floors_states[i] == FloorStates::DOWN || floors_states[i] == FloorStates::BOTH)
            return i;
    }
    for (int i = current_floor; i < FLOORS_COUNT; i++)
        if (floors_states[i] == FloorStates::UP || floors_states[i] == FloorStates::BOTH)
            return i;

    return find_closest_target();
}

int Controller::find_closest_target() const {
    int min_distance = FLOORS_COUNT + 1;
    int result = -1;

    for (int i = 0; i < FLOORS_COUNT; i++) {
        if (floors_states[i] != FloorStates::NONE) {
            int distance = abs(current_floor - i);

            if (distance < min_distance) {
                min_distance = distance;
                result = i;
            }
        }
    }

    return result;
}

Controller::Direction Controller::find_direction(int target) {
    if (current_floor == target)
        return Direction::NONE;
    if (current_floor > target)
        return Direction::DOWN;
    if (current_floor < target)
        return Direction::UP;
}
