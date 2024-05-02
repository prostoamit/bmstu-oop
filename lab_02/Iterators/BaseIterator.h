#ifndef BASEITERATOR_H
#define BASEITERATOR_H

#include <memory>
#include <cstddef>
#include "iterator_concept.h"

template<typename T>
class BaseIterator {
protected:
    // TODO: Попробовать поменять [].
    std::weak_ptr<T[]> ptr;
public:
    virtual ~BaseIterator() = default;

    operator bool() const;
};

#include "BaseIterator.hpp"

#endif //BASEITERATOR_H
