#include "Cabin.hpp"

#include <QDebug>

#include "Delays.hpp"

Cabin::Cabin(QObject* parent) :
        QObject(parent),
        state(State::UNLOCKED) {

    floor_passing_timer.setSingleShot(true);

    QObject::connect(this, SIGNAL(signal_open_doors()), &doors, SLOT(opening()));
    QObject::connect(&doors, SIGNAL(signal_closed()), this, SLOT(unlocked()));
}

void Cabin::moving() {
    if (state != State::MOVING && state != State::UNLOCKED)
        return;

    state = State::MOVING;

    floor_passing_timer.start(Delays::DOORS_ACTIONS_TIME);
}

void Cabin::stopped() {
    if (state != State::MOVING)
        return;

    state = State::STOPPED;
    qDebug() << "Кабина остановилась.\n";

    emit signal_locking();
}

void Cabin::locked() {
    if (state != State::STOPPED)
        return;

    state = State::LOCKED;
    qDebug() << "Кабина заблокирована.\n";

    emit signal_open_doors();
}

void Cabin::unlocked() {
    if (state != State::LOCKED)
        return;

    state = State::UNLOCKED;
    qDebug() << "Кабина разблокирована.\n";

    emit signal_update_target();
}
