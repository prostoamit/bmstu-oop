#ifndef CABIN_HPP
#define CABIN_HPP

#include <QObject>
#include <QTimer>


#include "Doors.hpp"

class ElevatorManager;

class Cabin : public QObject {
Q_OBJECT
public:
    explicit Cabin(QObject* parent = nullptr);
    enum class State {
        STOPPED, LOCKED, UNLOCKED, MOVING
    };

    friend ElevatorManager;

signals:
    void signal_update_target();
    void signal_passed_floor();
    void signal_open_doors();
    void signal_locking();


public slots:
    void stopped();
    void locked();
    void unlocked();
    void moving();

private:
    State state;
    Doors doors;
    QTimer floor_passing_timer;
};


#endif //CABIN_HPP
