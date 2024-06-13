#ifndef DOORS_HPP
#define DOORS_HPP

#include <QObject>
#include <QTimer>

class Doors : public QObject {
Q_OBJECT
public:
    explicit Doors(QObject* parent = nullptr);
    enum class State {
        CLOSED, OPENING, OPENED, CLOSING
    };

signals:
    void signal_opened();
    void signal_closed();

public slots:
    void closed();
    void opening();
    void opened();
    void closing();

private:
    State state;

    QTimer openTimer;
    QTimer closeTimer;
    QTimer passengersWaitingTimer;

    void runOpenTimer();
    void runWaitTimer();
    void runCloseTimer();

    void stopOpenTimer();
    void stopCloseTimer();
    void stopWaitTimer();

};


#endif //DOORS_HPP
