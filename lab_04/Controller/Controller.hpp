#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <QObject>
#include <array>

#include "Cabin.hpp"
#include "Floors.hpp"

class ElevatorManager;

class Controller : public QObject {
Q_OBJECT

public:
    static const size_t FLOORS_COUNT = 8;
    static const int STARTING_FLOOR = 0;

    explicit Controller(QObject* parent = nullptr);
    enum class State {
        WAITING, UPDATING_TARGET, MOVING, REACHED_TARGET
    };


    void add_target(int floor);
    void add_target(int floor, FloorStates state);

    friend ElevatorManager;

signals:
    void signal_wait();
    void signal_start_moving();
    void signal_reached_target();
    void signal_continue_moving();
    void signal_cabin_stop();
    void signal_update_target();
    void signal_cabin_open_doors();


public slots:
    void waiting();
    void updating_target();
    void moving();
    void reached_target();

private:
    enum class Direction {
        DOWN = -1, UP = 1, NONE = 0
    };

    Direction direction, previous_direction;
    State state;

    int current_floor;
    int target;

    std::array<FloorStates, FLOORS_COUNT> floors_states;

    int find_target() const;
    int find_closest_up() const;
    int find_closest_down() const;
    int find_closest_target() const;

    FloorStates decide_direction(int floor);

    Direction find_direction(int target);
};


#endif //CONTROLLER_HPP
