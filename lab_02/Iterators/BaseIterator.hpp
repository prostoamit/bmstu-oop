#ifndef BASEITERATOR_HPP
#define BASEITERATOR_HPP

#include "BaseIterator.h"

template<typename T>
BaseIterator<T>::operator bool() const {
    return this->ptr.expired();
}

#endif //BASEITERATOR_HPP
