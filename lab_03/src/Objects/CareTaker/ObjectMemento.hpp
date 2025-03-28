#ifndef OBJECTMEMENTO_HPP
#define OBJECTMEMENTO_HPP

#include <memory>

class Object;

class ObjectMemento {
public:
    ObjectMemento() = default;
    ObjectMemento(std::shared_ptr<Object> object);

    void set_object(std::shared_ptr<Object> object);
    std::shared_ptr<Object> get_object();
private:
    std::shared_ptr<Object> object;
};


#endif //OBJECTMEMENTO_HPP
