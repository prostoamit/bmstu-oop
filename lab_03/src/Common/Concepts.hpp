#ifndef CONCEPTS_HPP
#define CONCEPTS_HPP

#include <concepts>

template <typename Derived, typename Base>
concept DerivedFrom = std::is_abstract_v<Base> && std::is_base_of_v<Base, Derived>;

template <typename Type>
concept NotAbstract = !std::is_abstract_v<Type>;

template <typename Type, typename... Args>
concept Constructable = std::is_constructible_v<Type, Args...>;

template <typename T>
concept NotAbstractClass = std::is_class_v<T> && !std::is_abstract_v<T>;

template <typename T>
concept CopyConstructible = requires(T t) {
    T(t);
};

template <typename T>
concept Assignable = requires(T t1, T t2) {
    t1 = t2;
};

template <typename T>
concept OnlyObject = NotAbstractClass<T> && !CopyConstructible<T> && !Assignable<T>;


#endif //CONCEPTS_HPP
