#ifndef VECTOR_H
#define VECTOR_H

#include <iterator>
#include <memory>
#include <cstddef>
#include <iostream>

#include "Containers/BaseContainer.h"
#include "Exceptions/exceptions.h"
#include "VectorIterator.h"
#include "ConstVectorIterator.h"
#include "vector_concepts.h"

template<NumberType Type>
class Vector : virtual public BaseContainer {
private:
    std::shared_ptr<Type[]> data;

    void allocate(size_t elements_count);

public:
    using value_type = Type;
    using reference = Type&;
    using cons_reference = const Type&;
    using iterator = VectorIterator<Type>;
    using const_iterator = ConstVectorIterator<Type>;
    using difference_type = ptrdiff_t;
    using size_type = size_t;

    friend class VectorIterator<Type>;
    friend class ConstVectorIterator<Type>;

    virtual ~Vector() override;
    Vector() noexcept;
    explicit Vector(size_t elements_count);

    Vector(size_t elements_count, Type *outer_data);
    Vector(const std::initializer_list<Type>& outer_data);

    Vector(const Vector<Type>& other);
    Vector(Vector<Type>&& tmp_vector) noexcept;


    Vector<Type>& operator=(const Vector<Type>& other);
    Vector<Type>& operator=(Vector<Type>&& tmp_vector) noexcept;
    Vector<Type>& operator=(const std::initializer_list<Type>& outer_data);


    // Обращение к элементу по индексу.
    Type& at(size_t index);
    const Type& at(size_t index) const;
    Type& operator[](size_t index);
    const Type& operator[](size_t index) const;

    double length() const noexcept;

    bool is_unit() const noexcept;
    bool is_zero() const noexcept;

    template<NumberType OtherType> double angle(const Vector<OtherType>& other) const;
    template<NumberType OtherType> bool is_collinear(const Vector<OtherType>& other) const;
    template<NumberType OtherType> bool is_orthogonal(const Vector<OtherType>& other) const;

    // Получение негатива вектора.
    Vector<Type> operator-() const;

    // Поэлементное сложение векторов.
    template<NumberType OtherType> decltype(auto) operator+(const Vector<OtherType>& other) const;
    template<NumberType OtherType> Vector<Type>& operator+=(const Vector<OtherType>& other);

    // Поэлементное вычитание векторов.
    template<NumberType OtherType> decltype(auto) operator-(const Vector<OtherType>& other) const;
    template<NumberType OtherType> Vector<Type>& operator-=(const Vector<OtherType>& other);

    // Скалярное умножение векторов.
    template<NumberType OtherType> decltype(auto) operator&(const Vector<OtherType>& other) const;

    // Умножение вектора на число.
    template<NumberType OtherType> decltype(auto) operator*(const OtherType& factor) const;
    template<NumberType OtherType> Vector<Type>& operator*=(const OtherType& factor);

    // Деление вектора на число.
    template<NumberType OtherType> decltype(auto) operator/(const OtherType& divider) const;
    template<NumberType OtherType> Vector<Type>& operator/=(const OtherType& divider);


    // Векторное умножение векторов.
    template<NumberType OtherType> decltype(auto) operator^(const Vector<OtherType>& other) const;
    template<NumberType OtherType> Vector<Type>& operator^=(const Vector<OtherType>& other);

    template<NumberType OtherType> bool operator==(const Vector<OtherType>& other) const;
    template<NumberType OtherType> bool operator!=(const Vector<OtherType>& other) const;
    template<NumberType OtherType> decltype(auto) operator<=>(const Vector<OtherType>& other) const;

    VectorIterator<Type> begin() noexcept;
    VectorIterator<Type> end() noexcept;
    ConstVectorIterator<Type> begin() const noexcept;
    ConstVectorIterator<Type> end() const noexcept;
    ConstVectorIterator<Type> cbegin() const noexcept;
    ConstVectorIterator<Type> cend() const noexcept;


    friend std::ostream& operator<<(std::ostream& out_stream, const Vector<Type>& vector) {
        for (auto i : vector)
            std::cout << i << ' ';

        std::cout << std::endl;

        return out_stream;
    }
};

#include "Vector.hpp"


#endif //VECTOR_H
