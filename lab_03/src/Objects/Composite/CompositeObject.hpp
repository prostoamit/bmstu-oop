#ifndef COMPOSITEOBJECT_HPP
#define COMPOSITEOBJECT_HPP

#include "Objects/Object.hpp"

class CompositeObject : public Object {
public:
    CompositeObject();
    CompositeObject(const CompositeObject& other);
    CompositeObject(CompositeObject&& tmp_composite);

    virtual bool is_composite() const override;
    virtual void add(std::shared_ptr<Object> object) override;
    virtual void remove(Object::iterator iterator) override;

    virtual Object::iterator begin() override;
    virtual Object::iterator end() override;

    virtual void accept(std::shared_ptr<Visitor> visitor) override;
protected:
    Object::container container;
};


#endif //COMPOSITEOBJECT_HPP
