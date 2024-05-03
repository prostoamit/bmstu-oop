#ifndef VECTOR_CONCEPTS_H
#define VECTOR_CONCEPTS_H

#include <concepts>

#include <cmath>

//template<typename T>
//concept NumberType = std::is_arithmetic<T>::value;

template<typename From, typename To>
concept Assignable = requires(From a, To b) { a = b; };

template <typename From, typename To>
concept Convertable = std::convertible_to<From, To>;

template<typename T, typename U>
concept Comparable = requires(T a, U b) {
    {a == b} -> std::convertible_to<bool>;
};

template <typename T>
concept Constructable = std::semiregular<T>;

template<typename T>
concept NumberType =
        Comparable<T, int> &&
        Comparable<T, T> &&
        Assignable<T, T> &&
        Constructable<T> &&
        requires(T a, T b) {
            { a + b } -> std::convertible_to<T>;
            { a - b } -> std::convertible_to<T>;
            { a * b } -> std::convertible_to<T>;
            { a / b } -> std::convertible_to<T>;
        };

#endif //VECTOR_CONCEPTS_H
