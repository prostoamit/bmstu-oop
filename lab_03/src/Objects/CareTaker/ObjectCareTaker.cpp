#include "ObjectCareTaker.hpp"

#include "NoMementoException.hpp"

void ObjectCareTaker::add(std::shared_ptr<ObjectMemento> memento) {
    if (mementos.size() == 0) {
        mementos.push_back(memento);
        return;
    }

    if (current_memento != mementos.size() - 1)
        mementos.resize(current_memento + 1);

    mementos.push_back(memento);
    current_memento++;
}

std::shared_ptr<ObjectMemento> ObjectCareTaker::undo() {
    if (current_memento == 0)
        throw Exceptions::NoMementoException(__FILE__, __LINE__);
    return mementos[--current_memento];
}

std::shared_ptr<ObjectMemento> ObjectCareTaker::redo() {
    if (current_memento == mementos.size() - 1)
        throw Exceptions::NoMementoException(__FILE__, __LINE__, "This is the latest memento.");

    return mementos[++current_memento];
}
