#ifndef VISIBLEOBJECT_HPP
#define VISIBLEOBJECT_HPP

#include "Objects/Object.hpp"

class VisibleObject : public Object {
    virtual bool is_visible() const override;
};

#endif //VISIBLEOBJECT_HPP
