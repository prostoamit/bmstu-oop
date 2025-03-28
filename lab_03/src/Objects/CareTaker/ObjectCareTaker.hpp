#ifndef OBJECTCARETAKER_HPP
#define OBJECTCARETAKER_HPP

#include <memory>
#include <vector>

#include "ObjectMemento.hpp"

class ObjectCareTaker {
public:
    ObjectCareTaker() = default;
    void add(std::shared_ptr<ObjectMemento> memento);
    std::shared_ptr<ObjectMemento> undo();
    std::shared_ptr<ObjectMemento> redo();
private:
    std::vector<std::shared_ptr<ObjectMemento>> mementos;
    size_t current_memento;
};


#endif //OBJECTCARETAKER_HPP
