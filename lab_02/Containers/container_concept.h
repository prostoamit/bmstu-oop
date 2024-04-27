#ifndef CONTAINER_CONCEPT_H
#define CONTAINER_CONCEPT_H

#include <concepts>

template <typename Type>
concept Container = requires(Type t)
{
    typename Type::value_type;
    typename Type::size_type;
    typename Type::iterator;
    typename Type::const_iterator;

    { t.size() } noexcept -> std::same_as<typename Type::size_type>;
    { t.end() } noexcept -> std::same_as<typename Type::iterator>;
    { t.begin() } noexcept -> std::same_as<typename Type::iterator>;
};

#endif //CONTAINER_CONCEPT_H
