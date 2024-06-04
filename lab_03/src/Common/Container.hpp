#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <vector>
#include <concepts>

template <typename T>
class Container {
public:
    using iterator = std::vector<T>::iterator;

    Container() = default;
    explicit Container(const Container& other) = default;
    Container(Container&& other) = default;

    explicit Container(const std::vector<T>& other);

    T& operator[](size_t position);
    void add (const T& element);

    void clear();

    iterator begin();
    iterator end();

    size_t size();

protected:
    std::vector<T> data;
};

#include "Container.inl"

#endif //CONTAINER_HPP
