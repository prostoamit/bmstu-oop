#include "VectorIterator.h"

template<NumberType Type>
VectorIterator<Type>::VectorIterator() : vector_size(0), index(0) {
    this->ptr.reset();
}

template<NumberType Type>
void VectorIterator<Type>::deleted_object_check(int line) const {
    if (this->ptr.expired())
        throw vector_iterator_exceptions::VectorIteratorDeletedVectorException(__FILE__, line);
}

template<NumberType Type>
void VectorIterator<Type>::out_of_range_check(int line) const {
    if (index >= vector_size)
        throw vector_iterator_exceptions::VectorIteratorOutOfRangeException(__FILE__, line);
}

template<NumberType Type>
void VectorIterator<Type>::different_vectors_check(int line, const VectorIterator<Type>& other) const {
    if (this->ptr.lock() != other.ptr.lock())
        throw vector_iterator_exceptions::VectorIteratorDifferentVectorCmpException(__FILE__, line);
}

template<NumberType Type>
Type* VectorIterator<Type>::get_ptr() const {
    std::shared_ptr<Type[]> tmp = this->ptr.lock();
    return tmp.get() + index;
}

template<NumberType Type>
VectorIterator<Type>::VectorIterator(const VectorIterator<Type>& other) noexcept {
    this->ptr = other.ptr;
    this->index = other.index;
    this->vector_size = other.vector_size;
}

template<NumberType Type>
VectorIterator<Type>::VectorIterator(VectorIterator<Type> &&other) noexcept {
    this->ptr = other.ptr;
    this->index = other.index;
    this->vector_size = other.vector_size;

    other.ptr.reset();
    other.index = 0;
    other.vector_size = 0;
}

template<NumberType Type>
VectorIterator<Type>::VectorIterator(const Vector<Type>& vector) noexcept {
    this->ptr = vector.data;
    this->index = 0;
    this->vector_size = vector._size;
}

template<NumberType Type>
VectorIterator<Type>& VectorIterator<Type>::operator=(const VectorIterator<Type>& other) noexcept {
    this->ptr = other.ptr;
    this->index = other.index;
    this->vector_size = other.vector_size;
}

template<NumberType Type>
Type& VectorIterator<Type>::operator*() {
    deleted_object_check(__LINE__);
    out_of_range_check(__LINE__);

    return *(this->get_ptr());
}

template<NumberType Type>
const Type &VectorIterator<Type>::operator*() const {
    deleted_object_check(__LINE__);
    out_of_range_check(__LINE__);

    return *(this->get_ptr());
}


template<NumberType Type>
Type* VectorIterator<Type>::operator->() {
    deleted_object_check(__LINE__);
    out_of_range_check(__LINE__);

    return this->get_ptr();
}

template<NumberType Type>
const Type* VectorIterator<Type>::operator->() const {
    deleted_object_check(__LINE__);
    out_of_range_check(__LINE__);

    return this->get_ptr();
}

template<NumberType Type>
Type& VectorIterator<Type>::operator[](size_t n) {
    deleted_object_check(__LINE__);
    if (this->index + n >= this->vector_size)
        throw vector_iterator_exceptions::VectorIteratorOutOfRangeException(__FILE__, __LINE__);

    return (this->get_ptr())[n];
}

template<NumberType Type>
const Type& VectorIterator<Type>::operator[](size_t n) const {
    deleted_object_check(__LINE__);
    if (this->index + n >= this->vector_size)
        throw vector_iterator_exceptions::VectorIteratorOutOfRangeException(__FILE__, __LINE__);

    return (this->get_ptr())[n];
}

template<NumberType Type>
VectorIterator<Type>& 
VectorIterator<Type>::operator++() {
    deleted_object_check(__LINE__);

    ++(this->index);
    return *this;
}

template<NumberType Type>
VectorIterator<Type>
VectorIterator<Type>::operator++(int) {
    deleted_object_check(__LINE__);

    VectorIterator<Type> tmp = *this;

    operator++();
    return tmp;
}

template<NumberType Type>
VectorIterator<Type>
VectorIterator<Type>::operator+(ptrdiff_t offset) const {
    deleted_object_check(__LINE__);

    VectorIterator<Type> tmp(*this);

    tmp += offset;

    return tmp;
}

template<NumberType Type>
VectorIterator<Type>& 
VectorIterator<Type>::operator+=(ptrdiff_t offset) {
    deleted_object_check(__LINE__);
    this->index += offset;
    return *this;
}

template<NumberType Type>
VectorIterator<Type>& 
VectorIterator<Type>::operator--() {
    deleted_object_check(__LINE__);
    if (this->index == 0)
        throw vector_iterator_exceptions::VectorIteratorOutOfRangeException(__FILE__, __LINE__);

    --(this->index);

    return *this;
}

template<NumberType Type>
VectorIterator<Type>
VectorIterator<Type>::operator--(int) {
    deleted_object_check(__LINE__);
    if (this->index == 0)
        throw vector_iterator_exceptions::VectorIteratorOutOfRangeException(__FILE__, __LINE__);

    VectorIterator<Type> tmp = *this;

    operator--();

    return tmp;
}

template<NumberType Type>
VectorIterator<Type>
VectorIterator<Type>::operator-(ptrdiff_t offset) const {
    deleted_object_check(__LINE__);

    VectorIterator<Type> tmp = *this;

    tmp.index -= offset;

    return tmp;
}

template<NumberType Type>
VectorIterator<Type>& 
VectorIterator<Type>::operator-=(ptrdiff_t offset) {
    deleted_object_check(__LINE__);

    this->index -= offset;
    return *this;
}

template<NumberType Type>
ptrdiff_t VectorIterator<Type>::operator-(const VectorIterator<Type>& other) const {
    different_vectors_check(__LINE__, other);

    return this->index - other.index;
}

template<NumberType Type>
bool VectorIterator<Type>::operator==(const VectorIterator<Type>& other) {
    deleted_object_check(__LINE__);
    different_vectors_check(__LINE__, other);

    return this->index == other.index;
}

template<NumberType Type>
bool VectorIterator<Type>::operator!=(const VectorIterator<Type>& other) {
    deleted_object_check(__LINE__);
    different_vectors_check(__LINE__, other);

    return !(*this == other);
}

template<NumberType Type>
decltype(auto) VectorIterator<Type>::operator<=>(const VectorIterator<Type> &other) {
    different_vectors_check(__LINE__, other);

    return this->index <=> other.index;
}