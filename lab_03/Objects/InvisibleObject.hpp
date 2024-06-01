#ifndef INVISIBLEOBJECT_HPP
#define INVISIBLEOBJECT_HPP

#include "Object.hpp"

class InvisibleObject : Object {
    virtual bool is_visible() override;
    virtual bool is_composite() override;
};


#endif //INVISIBLEOBJECT_HPP
