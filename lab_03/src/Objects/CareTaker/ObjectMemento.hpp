#ifndef OBJECTMEMENTO_HPP
#define OBJECTMEMENTO_HPP

#include <memory>

#include "Objects/Composite/ObjectComposite.hpp"

class ObjectMemento {
public:
    ObjectMemento(std::shared_ptr<ObjectComposite> object);
private:
};


#endif //OBJECTMEMENTO_HPP
