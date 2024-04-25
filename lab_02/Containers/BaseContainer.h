#ifndef BASECONTAINER_H
#define BASECONTAINER_H

class BaseContainer {
public:
    size_t _size;
public:
    virtual ~BaseContainer() = default;
    virtual size_t size() { return _size; }
};

#endif //BASECONTAINER_H
