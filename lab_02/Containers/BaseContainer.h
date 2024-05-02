#ifndef BASECONTAINER_H
#define BASECONTAINER_H

class BaseContainer {
protected:
    size_t _size;
    BaseContainer() = default;
public:
    virtual ~BaseContainer() = default;
    virtual size_t size() const noexcept { return _size; }
};

#endif //BASECONTAINER_H
