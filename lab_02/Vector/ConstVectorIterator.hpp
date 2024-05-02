#include "ConstVectorIterator.h"

template<NumberType Type>
ConstVectorIterator<Type>::ConstVectorIterator() : vector_size(0), index(0) {
    this->ptr.reset();
}

template<NumberType Type>
void ConstVectorIterator<Type>::deleted_object_check(int line) const {
    if (this->ptr.expired())
        throw vector_iterator_exceptions::VectorIteratorDeletedVectorException(__FILE__, line);
}

template<NumberType Type>
void ConstVectorIterator<Type>::out_of_range_check(int line) const {
    if (index >= vector_size)
        throw vector_iterator_exceptions::VectorIteratorOutOfRangeException(__FILE__, line);
}

template<NumberType Type>
void ConstVectorIterator<Type>::different_vectors_check(int line, const ConstVectorIterator<Type>& other) const {
    if (this->ptr.lock() != other.ptr.lock())
        throw vector_iterator_exceptions::VectorIteratorDifferentVectorCmpException(__FILE__, line);
}

template<NumberType Type>
Type* ConstVectorIterator<Type>::get_ptr() const {
    std::shared_ptr<Type[]> tmp = this->ptr.lock();
    return tmp.get() + index;
}

template<NumberType Type>
ConstVectorIterator<Type>::ConstVectorIterator(const ConstVectorIterator<Type>& other) noexcept {
    this->ptr = other.ptr;
    index = other.index;
    vector_size = other.vector_size;
}

template<NumberType Type>
ConstVectorIterator<Type>::ConstVectorIterator(const Vector<Type>& vector) noexcept {
    this->ptr = vector.data;
    index = 0;
    vector_size = vector._size;
}

template<NumberType Type>
ConstVectorIterator<Type>& ConstVectorIterator<Type>::operator=(const ConstVectorIterator<Type>& other) noexcept {
    this->ptr = other.ptr;
    index = other.index;
    vector_size = other.vector_size;
}

template<NumberType Type>
const Type& ConstVectorIterator<Type>::operator*() const {
    deleted_object_check(__LINE__);
    out_of_range_check(__LINE__);

    return *(this->get_ptr());
}

template<NumberType Type>
std::shared_ptr<const Type[]> ConstVectorIterator<Type>::operator->() const {
    deleted_object_check(__LINE__);
    out_of_range_check(__LINE__);

    return this->get_ptr();
}

template<NumberType Type>
const Type& ConstVectorIterator<Type>::operator[](size_t n) const {
    deleted_object_check(__LINE__);
    if (this->index + n >= this->vector_size)
        throw vector_iterator_exceptions::VectorIteratorOutOfRangeException(__FILE__, __LINE__);

    return (this->get_ptr())[n];
}

template<NumberType Type>
ConstVectorIterator<Type>&
ConstVectorIterator<Type>::operator++() {
    ++index;
    return *this;
}

template<NumberType Type>
ConstVectorIterator<Type>
ConstVectorIterator<Type>::operator++(int) {
    ConstVectorIterator<Type> tmp = *this;

    operator++();
    return tmp;
}

template<NumberType Type>
ConstVectorIterator<Type>
ConstVectorIterator<Type>::operator+(ptrdiff_t offset) const {
    ConstVectorIterator<Type> tmp(*this);

    tmp += offset;

    return tmp;
}

template<NumberType Type>
ConstVectorIterator<Type>&
ConstVectorIterator<Type>::operator+=(ptrdiff_t offset) {
    index += offset;
    return *this;
}

template<NumberType Type>
ConstVectorIterator<Type>&
ConstVectorIterator<Type>::operator--() {
    if (index == 0)
        throw vector_iterator_exceptions::VectorIteratorOutOfRangeException(__FILE__, __LINE__);

    return *this;
}

template<NumberType Type>
ConstVectorIterator<Type>
ConstVectorIterator<Type>::operator--(int) {
    if (index == 0)
        throw vector_iterator_exceptions::VectorIteratorOutOfRangeException(__FILE__, __LINE__);

    ConstVectorIterator<Type> tmp = *this;

    operator--();

    return tmp;
}

template<NumberType Type>
ConstVectorIterator<Type>
ConstVectorIterator<Type>::operator-(ptrdiff_t offset) const {
    ConstVectorIterator<Type> tmp = *this;

    tmp.index -= offset;

    return tmp;
}

template<NumberType Type>
ConstVectorIterator<Type>&
ConstVectorIterator<Type>::operator-=(ptrdiff_t offset) {
    index -= offset;
    return *this;
}

template<NumberType Type>
ptrdiff_t ConstVectorIterator<Type>::operator-(const ConstVectorIterator<Type> &other) const {
    different_vectors_check(__LINE__, other);

    return this->index - other.index;
}

template<NumberType Type>
bool ConstVectorIterator<Type>::operator==(const ConstVectorIterator<Type>& other) {
    different_vectors_check(__LINE__, other);

    return index == other.index;
}

template<NumberType Type>
bool ConstVectorIterator<Type>::operator!=(const ConstVectorIterator<Type>& other) {
    different_vectors_check(__LINE__, other);

    return !(*this == other);
}

template<NumberType Type>
decltype(auto) ConstVectorIterator<Type>::operator<=>(const ConstVectorIterator<Type> &other) {
    different_vectors_check(__LINE__, other);

    return this->index <=> other.index;
}

