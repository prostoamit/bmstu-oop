#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <cstddef>
#include <memory>
#include <map>

#include "ObjectMemento.hpp"

class Visitor;

class Object {
public:
    using container = std::map<size_t, std::shared_ptr<Object>>;
    using iterator = container::iterator;

    Object();
    virtual ~Object() = default;

    virtual size_t get_id() const;

    virtual bool is_visible() const;
    virtual bool is_composite() const;

    virtual void add(std::shared_ptr<Object> object);
    virtual void remove(iterator);

    virtual iterator begin();
    virtual iterator end();

    virtual void accept(std::shared_ptr<Visitor> visitor) = 0;

    virtual std::shared_ptr<ObjectMemento> create_memento() const;
    virtual void restore_memento(std::shared_ptr<ObjectMemento> memento);

    virtual std::shared_ptr<Object> clone() const;

//    friend Visitor;

protected:
    size_t _id;
    static size_t current_objects_count;
};


#endif //OBJECT_HPP