#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <vector>
#include <concepts>

template <typename T>
class Container {
public:
    using iterator = std::vector<T>::iterator;
    using const_iterator = std::vector<T>::const_iterator;

    Container() = default;
    explicit Container(const Container& other) = default;

    explicit Container(const std::vector<T>& other);

    T& operator[](size_t position);
    void add (const T& element);

    void clear();

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;

    size_t size();

protected:
    std::vector<T> data;
};

#include "Container.inl"

#endif //CONTAINER_HPP
