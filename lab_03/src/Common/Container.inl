#include "Container.hpp"

template<typename T>
Container<T>::Container(const std::vector<T> &other) {
    for (auto& i : other)
        data.push_back(i);
}

template<typename T>
void Container<T>::add(const T &element) {
    data.push_back(element);
}

template<typename T>
T &Container<T>::operator[](size_t position) {
    return data[position];
}

template<typename T>
void Container<T>::clear() {
    data.clear();
}

template<typename T>
Container<T>::iterator Container<T>::begin() {
    return data.begin();
}

template<typename T>
Container<T>::iterator Container<T>::end() {
    return data.end();
}

template<typename T>
Container<T>::const_iterator Container<T>::begin() const {
    return data.begin();
}

template<typename T>
Container<T>::const_iterator Container<T>::end() const {
    return data.end();
}

template<typename T>
Container<T>::const_iterator Container<T>::cbegin() const {
    return data.cbegin();
}

template<typename T>
Container<T>::const_iterator Container<T>::cend() const {
    return data.cend();
}


template<typename T>
size_t Container<T>::size() {
    return data.size();
}