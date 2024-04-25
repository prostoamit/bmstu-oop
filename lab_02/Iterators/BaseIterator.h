#ifndef BASEITERATOR_H
#define BASEITERATOR_H

#include <memory>
#include <cstddef>

template<typename T>
class BaseIterator {
protected:
    std::weak_ptr<T[]> ptr;
public:
    virtual ~BaseIterator() = default;
};


#endif //BASEITERATOR_H
