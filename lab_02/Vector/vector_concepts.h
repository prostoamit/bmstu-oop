#ifndef VECTOR_CONCEPTS_H
#define VECTOR_CONCEPTS_H

#include <concepts>

template<typename T>
concept NumberType = std::is_arithmetic<T>::value;

#endif //VECTOR_CONCEPTS_H
