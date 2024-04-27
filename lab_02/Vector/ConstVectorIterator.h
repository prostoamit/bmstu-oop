#ifndef CONSTVECTORITERATOR_H
#define CONSTVECTORITERATOR_H

#include <memory>
#include <cstddef>

#include "BaseIterator.h"

#include "Exceptions/exceptions.h"
#include "vector_concepts.h"

template<NumberType Type>
class Vector;

template<NumberType Type>
class ConstVectorIterator : public BaseIterator<Type> {
public:
    using value_type        = Type;
    using pointer           = std::shared_ptr<const Type[]>;
    using reference         = const Type&;
    using difference_type   = ptrdiff_t;
    using iterator_category = std::random_access_iterator_tag;

    ConstVectorIterator();
    ConstVectorIterator(const ConstVectorIterator<Type>& other) noexcept;
    explicit ConstVectorIterator(const Vector<Type>& vector) noexcept;
    // TODO: Добавить конструктор из обычного итератора.

    ConstVectorIterator<Type>& operator=(const ConstVectorIterator<Type>& other) noexcept;

    const Type& operator*() const;
    std::shared_ptr<const Type[]> operator->() const;
    const Type& operator[](size_t n) const;

    ConstVectorIterator<Type>& operator++();
    ConstVectorIterator<Type> operator++(int);

    ConstVectorIterator<Type> operator+(ptrdiff_t offset) const;
    ConstVectorIterator<Type>& operator+=(ptrdiff_t offset);

    ConstVectorIterator<Type>& operator--();
    ConstVectorIterator<Type> operator--(int);

    ConstVectorIterator<Type> operator-(ptrdiff_t offset) const;
    ConstVectorIterator<Type>& operator-=(ptrdiff_t offset);

    bool operator==(const ConstVectorIterator<Type>& other);
    bool operator!=(const ConstVectorIterator<Type>& other);

    decltype(auto) operator<=>(const ConstVectorIterator<Type>& other);

private:

    size_t vector_size;
    size_t index;
protected:
    void deleted_object_check(int line) const;
    void out_of_range_check(int line) const;
    void different_vectors_check(int line, const ConstVectorIterator<Type>& other) const;

    Type* get_ptr() const;
};

#include "ConstVectorIterator.hpp"

#endif //CONSTVECTORITERATOR_H
