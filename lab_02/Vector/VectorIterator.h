#ifndef VECTORITERATOR_H
#define VECTORITERATOR_H

#include <memory>
#include <cstddef>

#include "BaseIterator.h"

#include "vector_iterator_exceptions.h"
#include "vector_concepts.h"

template<NumberType Type>
class Vector;

template<NumberType Type>
class ConstVectorIterator;

template<NumberType Type>
class VectorIterator : public BaseIterator<Type> {
public:
    using value_type        = Type;
    using pointer           = Type*;
    using reference         = Type&;
    using difference_type   = ptrdiff_t;
    using iterator_category = std::random_access_iterator_tag;

    VectorIterator();
    VectorIterator(const VectorIterator<Type>& other) noexcept;
    VectorIterator(VectorIterator<Type>&& other) noexcept;
    explicit VectorIterator(const Vector<Type>& vector) noexcept;

    VectorIterator<Type>& operator=(const VectorIterator<Type>& other) noexcept;

    Type& operator*();
    const Type& operator*() const;
    Type* operator->();
    const Type* operator->() const;
    Type& operator[](size_t n);
    const Type& operator[](size_t n) const;

    VectorIterator<Type>& operator++();
    VectorIterator<Type> operator++(int);

    VectorIterator<Type> operator+(ptrdiff_t offset) const;
    VectorIterator<Type>& operator+=(ptrdiff_t offset);

    VectorIterator<Type>& operator--();
    VectorIterator<Type> operator--(int);

    VectorIterator<Type> operator-(ptrdiff_t offset) const;
    VectorIterator<Type>& operator-=(ptrdiff_t offset);

    ptrdiff_t operator-(const VectorIterator<Type>& other) const;

    bool operator==(const VectorIterator<Type>& other);
    bool operator!=(const VectorIterator<Type>& other);

    decltype(auto) operator<=>(const VectorIterator<Type>& other);

    friend class ConstVectorIterator<Type>;
private:
    size_t vector_size;
    size_t index;

protected:
    void deleted_object_check(int line) const;
    void out_of_range_check(int line) const;
    void different_vectors_check(int line, const VectorIterator<Type>& other) const;

    Type* get_ptr() const;
};

#include "VectorIterator.hpp"

#endif //VECTORITERATOR_H
