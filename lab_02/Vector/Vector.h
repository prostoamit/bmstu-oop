#ifndef VECTOR_H
#define VECTOR_H

#include <iterator>
#include <memory>
#include <cstddef>
#include <iostream>

#include "Containers/BaseContainer.h"
#include "vector_exceptions.h"
#include "VectorIterator.h"
#include "ConstVectorIterator.h"
#include "vector_concepts.h"
#include "container_concept.h"
#include "iterator_concepts.h"

template<NumberType Type>
class Vector : public BaseContainer {
public:
    using value_type = Type;
    using size_type = size_t;
    using iterator = VectorIterator<Type>;
    using const_iterator = ConstVectorIterator<Type>;

    friend class VectorIterator<Type>;
    friend class ConstVectorIterator<Type>;

    virtual ~Vector() override;
    Vector() noexcept;
    explicit Vector(size_t elements_count);
    Vector(size_t elements_count, const Type& filler);

    Vector(size_t elements_count, Type *outer_data);
    Vector(std::initializer_list<Type> outer_data);

    explicit Vector(const Vector<Type>& other);
    Vector(Vector<Type>&& tmp_vector) noexcept;

    template<Container ContainerType>
    requires std::convertible_to<typename ContainerType::value_type, Type>
    explicit Vector(const ContainerType& container);

    template<ForwardIterator IteratorType>
    requires std::convertible_to<typename IteratorType::value_type, Type>
    Vector(const IteratorType& begin, const IteratorType& end);

    Vector<Type>& operator=(const Vector<Type>& other);
    Vector<Type>& operator=(Vector<Type>&& tmp_vector) noexcept;
    Vector<Type>& operator=(std::initializer_list<Type> outer_data);

    template<NumberType OtherType>
    Vector<Type>& operator=(const Vector<OtherType>& other);

    // Обращение к элементу по индексу.
    Type& at(size_t index);
    const Type& at(size_t index) const;
    Type& operator[](size_t index);
    const Type& operator[](size_t index) const;

    template<NumberType ReturnType>
    ReturnType length() const noexcept;

    bool is_unit() const noexcept;
    bool is_zero() const noexcept;

    template<NumberType OtherType> double angle(const Vector<OtherType>& other) const;
    template<NumberType OtherType> bool is_collinear(const Vector<OtherType>& other) const;
    template<NumberType OtherType> bool is_orthogonal(const Vector<OtherType>& other) const;

    // Получение негатива вектора.
    Vector<Type> operator-() const;
    Vector<Type> negative() const;

    // Поэлементное сложение векторов.
    template<NumberType OtherType> decltype(auto) operator+(const Vector<OtherType>& other) const;
    template<NumberType OtherType> decltype(auto) add_vector(const Vector<OtherType>& other) const;
    template<NumberType OtherType> Vector<Type>& operator+=(const Vector<OtherType>& other);
    template<NumberType OtherType> Vector<Type>& add_assign_vector(const Vector<OtherType>& other);

    // Сложение вектора с числом.
    template<NumberType OtherType> decltype(auto) operator+(const OtherType& summand) const;
    template<NumberType OtherType> decltype(auto) add_number(const OtherType& summand) const;
    template<NumberType OtherType> Vector<Type>& operator+=(const OtherType& summand);
    template<NumberType OtherType> Vector<Type>& add_assign_number(const OtherType& summand);

    // Поэлементное вычитание векторов.
    template<NumberType OtherType> decltype(auto) operator-(const Vector<OtherType>& other) const;
    template<NumberType OtherType> decltype(auto) subtract_vector(const Vector<OtherType>& other) const;
    template<NumberType OtherType> Vector<Type>& operator-=(const Vector<OtherType>& other);
    template<NumberType OtherType> Vector<Type>& subtract_assign_vector(const Vector<OtherType>& other);

    // Вычитание числа из вектора.
    template<NumberType OtherType> decltype(auto) operator-(const OtherType& summand) const;
    template<NumberType OtherType> decltype(auto) subtract_number(const OtherType& summand) const;
    template<NumberType OtherType> Vector<Type>& operator-=(const OtherType& summand);
    template<NumberType OtherType> Vector<Type>& subtract_assign_number(const OtherType& summand);

    // Скалярное умножение векторов.
    template<NumberType OtherType> decltype(auto) operator&(const Vector<OtherType>& other) const;
    template<NumberType OtherType> decltype(auto) scalar_multiply(const Vector<OtherType>& other) const;

    // Умножение вектора на число.
    template<NumberType OtherType> decltype(auto) operator*(const OtherType& factor) const;
    template<NumberType OtherType> decltype(auto) multiply_number(const OtherType& factor) const;
    template<NumberType OtherType> Vector<Type>& operator*=(const OtherType& factor);
    template<NumberType OtherType> Vector<Type>& multiply_assign_number(const OtherType& factor);

    // Деление вектора на число.
    template<NumberType OtherType> decltype(auto) operator/(const OtherType& divider) const;
    template<NumberType OtherType> decltype(auto) divide_number(const OtherType& divider) const;
    template<NumberType OtherType> Vector<Type>& operator/=(const OtherType& divider);
    template<NumberType OtherType> Vector<Type>& divide_assign_number(const OtherType& divider);


    // Векторное умножение векторов.
    template<NumberType OtherType> decltype(auto) operator^(const Vector<OtherType>& other) const;
    template<NumberType OtherType> decltype(auto) vector_multiply(const Vector<OtherType>& other) const;
    template<NumberType OtherType> Vector<Type>& operator^=(const Vector<OtherType>& other);
    template<NumberType OtherType> Vector<Type>& vector_multiply_assign(const Vector<OtherType>& other);

    // Поэлементное сравнение векторов.
    template<NumberType OtherType> bool operator==(const Vector<OtherType>& other) const;
    template<NumberType OtherType> bool is_equal(const Vector<OtherType>& other) const;

    template<NumberType OtherType> decltype(auto) operator<=>(const Vector<OtherType>& other) const;

    VectorIterator<Type> begin() noexcept;
    VectorIterator<Type> end() noexcept;
    ConstVectorIterator<Type> begin() const noexcept;
    ConstVectorIterator<Type> end() const noexcept;
    ConstVectorIterator<Type> cbegin() const noexcept;
    ConstVectorIterator<Type> cend() const noexcept;

    template<NumberType OtherType>
    friend std::ostream& operator<<(std::ostream& out_stream, const Vector<OtherType>& vector);

private:
    std::shared_ptr<Type[]> data;

    void allocate(size_t elements_count);

};

#include "Vector.hpp"


#endif //VECTOR_H
