#include "Doors.hpp"

#include <QDebug>

#include "Delays.hpp"

Doors::Doors(QObject* parent) :
        QObject(parent),
        state(State::CLOSED) {
    passengersWaitingTimer.setInterval(Delays::PASSENGER_WAITING_TIME);
    passengersWaitingTimer.setSingleShot(true);

    openTimer.setInterval(Delays::DOORS_ACTIONS_TIME);
    openTimer.setSingleShot(true);

    closeTimer.setInterval(Delays::DOORS_ACTIONS_TIME);
    closeTimer.setSingleShot(true);

    QObject::connect(&openTimer, SIGNAL(timeout()), this, SLOT(opened()));

    QObject::connect(this, SIGNAL(signal_opened()), &passengersWaitingTimer, SLOT(start()));

    QObject::connect(&passengersWaitingTimer, SIGNAL(timeout()), this, SLOT(closing()));

    QObject::connect(&closeTimer, SIGNAL(timeout()), this, SLOT(closed()));
}

void Doors::runWaitTimer() {
    openTimer.start();
}

void Doors::runCloseTimer() {
    closeTimer.start();
}

void Doors::runOpenTimer() {
    closeTimer.start(Delays::DOORS_ACTIONS_TIME);
}

void Doors::opening() {
    if (state != State::CLOSED)
        return;

    this->openTimer.start(Delays::DOORS_ACTIONS_TIME);
    qDebug() << "Двери открываются.";
    state = State::OPENING;

    runOpenTimer();
}

void Doors::closing() {
    if (state != State::OPENED)
        return;

    this->closeTimer.start(Delays::DOORS_ACTIONS_TIME);
    qDebug() << "Двери закрываются.";
    state = State::CLOSING;

    runCloseTimer();
}

void Doors::opened() {
    if (state != State::OPENING)
        return;

    qDebug() << "Двери открыты.\n";
    state = State::OPENED;

    emit signal_opened();
}

void Doors::closed() {
    if (state != State::CLOSING)
        return;

    qDebug() << "Двери закрыты.\n";
    state = State::CLOSED;

    emit signal_closed();
}
