#ifndef VISIBLEOBJECT_HPP
#define VISIBLEOBJECT_HPP

#include "Object.hpp"

class VisibleObject : Object {
    virtual bool is_visible() override;
    virtual bool is_composite() override;
};

#endif //VISIBLEOBJECT_HPP
