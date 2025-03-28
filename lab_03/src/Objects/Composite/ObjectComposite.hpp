#ifndef OBJECTCOMPOSITE_HPP
#define OBJECTCOMPOSITE_HPP

#include "Objects/Object.hpp"

class ObjectComposite : public Object {
public:
    ObjectComposite() = default;
    ObjectComposite(const ObjectComposite& other);
    ObjectComposite(ObjectComposite&& tmp_composite) = default;

    virtual bool is_composite() const override;
    virtual void add(std::shared_ptr<Object> object) override;
    virtual void remove(Object::iterator iterator) override;

    virtual Object::iterator begin() override;
    virtual Object::iterator end() override;

    virtual void accept(std::shared_ptr<Visitor> visitor) override;

//    virtual std::shared_ptr<ObjectMemento> create_memento() const override;

    virtual std::shared_ptr<Object> clone() const override;
protected:
    Object::container container;
};


#endif //OBJECTCOMPOSITE_HPP
