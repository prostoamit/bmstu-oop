#ifndef OBJECTMEMENTO_HPP
#define OBJECTMEMENTO_HPP

#include <memory>

#include "Objects/Composite/CompositeObject.hpp"

class ObjectMemento {
public:
    ObjectMemento(std::shared_ptr<CompositeObject> object);
private:
};


#endif //OBJECTMEMENTO_HPP
