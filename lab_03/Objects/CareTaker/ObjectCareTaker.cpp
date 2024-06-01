#include "ObjectCareTaker.hpp"

void ObjectCareTaker::set(std::unique_ptr<ObjectMemento> memento) {
    mementos.push(std::move(memento));
}

std::unique_ptr<ObjectMemento> ObjectCareTaker::get() {
    std::unique_ptr<ObjectMemento> previous = std::move(mementos.top());
    mementos.pop();
    return previous;
}
