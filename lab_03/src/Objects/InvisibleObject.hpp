#ifndef INVISIBLEOBJECT_HPP
#define INVISIBLEOBJECT_HPP

#include "Object.hpp"

class InvisibleObject : public Object {
    virtual bool is_visible() const override;
    virtual bool is_composite() const override;
};


#endif //INVISIBLEOBJECT_HPP
