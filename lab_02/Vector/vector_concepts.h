#ifndef VECTOR_CONCEPTS_H
#define VECTOR_CONCEPTS_H

#include <concepts>

#include <cmath>

//template<typename T>
//concept NumberType = std::is_arithmetic<T>::value;

// TODO: Посмотреть примеры. Конкретно - обработку литералов.
template<typename T>
concept NumberType = requires(T a, T b) {
    a + b; a - b; a * b; a / b;
    sqrt(a);
    a + 0; a - 0; a * 0; a / 1;
    a + 0.0; a - 0.0; a * 0.0; a / 1.0;
    a = 0;
    a = 0.0;
    a <=> b;
    a == 0;
    a == 0.0;
};

#endif //VECTOR_CONCEPTS_H
