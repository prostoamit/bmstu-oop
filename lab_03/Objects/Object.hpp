#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <cstddef>
#include <memory>
#include <map>

class Visitor;

class Object {
public:
    using container = std::map<size_t, std::shared_ptr<Object>>;
    using iterator = container::iterator;

    Object();
    virtual ~Object() = default;

    virtual size_t get_id();

    virtual bool is_visible() = 0;
    virtual bool is_composite() = 0;

    virtual void add(std::shared_ptr<Object> object) = 0;
    virtual void remove(iterator) = 0;

    virtual iterator begin() = 0;
    virtual iterator end() = 0;

    virtual void accept(std::shared_ptr<Visitor>) = 0;

    // TODO create_memento()
    // TODO restore_memento()

protected:
    size_t _id;
    static size_t current_objects_count;
};


#endif //OBJECT_HPP