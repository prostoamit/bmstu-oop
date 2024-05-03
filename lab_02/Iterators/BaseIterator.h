#ifndef BASEITERATOR_H
#define BASEITERATOR_H

#include <memory>
#include <cstddef>
#include "iterator_concepts.h"

template<typename T>
class BaseIterator {
protected:
    std::weak_ptr<T[]> ptr;
    BaseIterator() = default;
public:
    virtual ~BaseIterator() = default;

    operator bool() const;
};

#include "BaseIterator.hpp"

#endif //BASEITERATOR_H
