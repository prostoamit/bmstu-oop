#ifndef OBJECTCREATOR_HPP
#define OBJECTCREATOR_HPP

#include <memory>
#include "Object.hpp"

class ObjectCreator {
public:
    virtual ~ObjectCreator() = default;

    virtual std::shared_ptr<Object> create() = 0;
};


#endif //OBJECTCREATOR_HPP
