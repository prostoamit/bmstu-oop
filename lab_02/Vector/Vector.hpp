#include "Vector.h"

#include <cmath>
#include <cfloat>
#include <compare>

template<NumberType Type>
void Vector<Type>::allocate(size_t elements_count) {
    std::shared_ptr<Type[]> tmp;
    try {
        tmp = std::make_shared<Type[]>(elements_count);
    } catch (std::exception) {
        throw exceptions::MemoryAllocationException(__FILE__, __LINE__ - 2);
    }

    this->data = tmp;
}

template<NumberType Type>
Vector<Type>::~Vector() {
    this->data.reset();
}

template<NumberType Type>
Vector<Type>::Vector() noexcept{
    this->data.reset();
    this->_size = 0;
}

template<NumberType Type>
Vector<Type>::Vector(size_t elements_count) {
    this->data.reset();
    this->allocate(elements_count);

    this->_size = elements_count;
    for (auto& i : *this)
        i = 0;
}

template<NumberType Type>
Vector<Type>::Vector(size_t elements_count, Type *outer_data) {
    this->data.reset();
    this->allocate(elements_count);

    this->_size = elements_count;

    for (Type& element : *this) {
        element = *outer_data;
        outer_data++;
    }
}

template<NumberType Type>
Vector<Type>::Vector(const std::initializer_list<Type>& outer_data) {
    this->data.reset();
    this->allocate(outer_data.size());

    this->_size = outer_data.size();

    VectorIterator<Type> element = begin();

    for (const Type outer_element : outer_data)  {
        *element = outer_element;
        element++;
    }
}

template<NumberType Type>
Vector<Type>::Vector(Vector<Type>&& tmp_vector) noexcept {
    this->data = tmp_vector.data;
    this->_size = tmp_vector._size;

    tmp_vector.data.reset();
    tmp_vector._size = 0;
}

template<NumberType Type>
Vector<Type>::Vector(const Vector<Type>& other) {
    this->data.reset();
    this->allocate(other._size);

    this->_size = other._size;

    ConstVectorIterator<Type> other_iterator = other.begin();

    for (auto& i : *this) {
        i = *other_iterator;

        other_iterator++;
    }
}

template<NumberType Type>
Vector<Type>& Vector<Type>::operator=(const Vector<Type>& other) {
    this->data.reset();
    this->allocate(other._size);

    this->_size = other._size;
    ConstVectorIterator<Type> other_iterator = other.begin();

    for (auto& i : *this) {
        i = *other_iterator;

        other_iterator++;
    }

    return *this;
}

template<NumberType Type>
Vector<Type>& Vector<Type>::operator=(Vector<Type>&& tmp_vector) noexcept {
    this->data = tmp_vector.data;
    this->_size = tmp_vector._size;

    tmp_vector.data.reset();
    tmp_vector._size = 0;

    return *this;
}

template<NumberType Type>
Vector<Type>& Vector<Type>::operator=(const std::initializer_list<Type>& outer_data) {
    this->data.reset();

    this->allocate(outer_data.size());

    this->_size = outer_data.size();

    VectorIterator<Type> element = begin();
    auto outer_it = outer_data.begin();

    for (auto& i : *this) {
        i = *outer_it;

        outer_it++;
    }

    return *this;
}

template<NumberType Type>
Type& Vector<Type>::at(size_t index) {
    if (index >= this->_size)
        throw exceptions::OutOfRangeException(__FILE__, __LINE__);

    return this->data[index];
}

template<NumberType Type>
const Type& Vector<Type>::at(size_t index) const {
    if (index >= this->_size)
        throw exceptions::OutOfRangeException(__FILE__, __LINE__);

    return this->data[index];
}

template<NumberType Type>
Type& Vector<Type>::operator[](size_t index) {
    if (index >= this->_size)
        throw exceptions::OutOfRangeException(__FILE__, __LINE__);

    return this->data[index];
}

template<NumberType Type>
const Type& Vector<Type>::operator[](size_t index) const {
    if (index >= this->_size)
        throw exceptions::OutOfRangeException(__FILE__, __LINE__);

    return this->data[index];
}

template<NumberType Type>
double Vector<Type>::length() const noexcept {
    double square_sum = 0;
    for (auto& value : *this)
        square_sum += value * value;

    return sqrt(square_sum);
}

template<NumberType Type>
bool Vector<Type>::is_unit() const noexcept {
    return length() == 1;
}

template<>
bool Vector<float>::is_unit() const noexcept {
    return (fabsf(length() - 1.0F) < FLT_EPSILON);
}

template<>
bool Vector<double>::is_unit() const noexcept {
    return (fabs(length() - 1.0) < DBL_EPSILON);
}

template<>
bool Vector<long double>::is_unit() const noexcept {
    return (fabsl(length() - 1.0L) < LDBL_EPSILON);
}

template<NumberType Type>
bool Vector<Type>::is_zero() const noexcept {
    bool zero_vector = true;
    for (auto value : *this)
        if (value != 0)
            zero_vector = false;

    return zero_vector;
}

template<>
bool Vector<float>::is_zero() const noexcept {
    bool zero_vector = true;
    for (float value : *this)
        if (fabsf(value) > FLT_EPSILON)
            zero_vector = false;

    return zero_vector;
}

template<>
bool Vector<double>::is_zero() const noexcept {
    bool zero_vector = true;
    for (double value : *this)
        if (fabs(value) > DBL_EPSILON)
            zero_vector = false;

    return zero_vector;
}

template<>
bool Vector<long double>::is_zero() const noexcept {
    bool zero_vector = true;
    for (long double value : *this)
        if (fabsl(value) > LDBL_EPSILON)
            zero_vector = false;

    return zero_vector;
}

template<NumberType Type>
template<NumberType OtherType>
double Vector<Type>::angle(const Vector<OtherType>& other) const {
    if (this->_size != other._size)
        throw exceptions::DifferentVectorSizeException(__FILE__, __LINE__, "Different vector sizes. Addition is impossible.");

    double scalar_product = double(*this & other);
    double length_1 = this->length();
    double length_2 = other.length();

    double angle_cos = scalar_product / (length_1 * length_2);

    return acos(angle_cos);
}

template<NumberType Type>
template<NumberType OtherType>
bool Vector<Type>::is_collinear(const Vector<OtherType>& other) const {
    if (this->_size != other._size)
        throw exceptions::DifferentVectorSizeException(__FILE__, __LINE__, "Different vector sizes. Addition is impossible.");

    return (*this ^ other).is_zero();
}

template<NumberType Type>
template<NumberType OtherType>
bool Vector<Type>::is_orthogonal(const Vector<OtherType>& other) const {
    if (this->_size != other._size)
        throw exceptions::DifferentVectorSizeException(__FILE__, __LINE__, "Different vector sizes. Addition is impossible.");

    return (*this & other) == 0;
}

template<>
template<NumberType OtherType>
bool Vector<float>::is_orthogonal(const Vector<OtherType>& other) const {
    if (this->_size != other._size)
        throw exceptions::DifferentVectorSizeException(__FILE__, __LINE__, "Different vector sizes. Addition is impossible.");

    return fabsf(*this & other) < FLT_EPSILON;
}

template<>
template<NumberType OtherType>
bool Vector<double>::is_orthogonal(const Vector<OtherType>& other) const {
    if (this->_size != other._size)
        throw exceptions::DifferentVectorSizeException(__FILE__, __LINE__, "Different vector sizes. Addition is impossible.");

    return fabs(*this & other) < DBL_EPSILON;
}

template<>
template<NumberType OtherType>
bool Vector<long double>::is_orthogonal(const Vector<OtherType>& other) const {
    if (this->_size != other._size)
        throw exceptions::DifferentVectorSizeException(__FILE__, __LINE__, "Different vector sizes. Addition is impossible.");

    return fabsl(*this & other) < LDBL_EPSILON;
}

template<NumberType Type>
Vector<Type> Vector<Type>::operator-() const {
    Vector<Type> negative_copy = *this;

    for (auto& element : negative_copy)
        element = -element;

    return negative_copy;
}

template<NumberType Type>
template<NumberType OtherType>
decltype(auto) Vector<Type>::operator+(const Vector<OtherType>& other) const {
    if (this->_size != other._size)
        throw exceptions::DifferentVectorSizeException(__FILE__, __LINE__, "Different vector sizes. Addition is impossible.");

    Vector<decltype((*this)[0] + other[0])> sum(this->_size);

    ConstVectorIterator<Type> this_iterator = this->begin();
    ConstVectorIterator<OtherType> other_iterator = other.begin();

    for (auto& i : sum) {
        i = *this_iterator + *other_iterator;

        this_iterator++;
        other_iterator++;
    }

    return sum;
}

template<NumberType Type>
template<NumberType OtherType>
Vector<Type>& Vector<Type>::operator+=(const Vector<OtherType>& other) {
    if (this->_size != other._size)
        throw exceptions::DifferentVectorSizeException(__FILE__, __LINE__, "Different vector sizes. Addition is impossible.");

    ConstVectorIterator<OtherType> other_iterator = other.begin();

    for (Type& i : *this) {
        i += *other_iterator;

        other_iterator++;
    }
    return *this;
}

template<NumberType Type>
template<NumberType OtherType>
decltype(auto) Vector<Type>::operator-(const Vector<OtherType>& other) const {
    if (this->_size != other._size)
        throw exceptions::DifferentVectorSizeException(__FILE__, __LINE__, "Different vector sizes. Addition is impossible.");

    Vector<decltype((*this)[0] - other[0])> difference(this->_size);

    ConstVectorIterator<Type> this_iterator = this->begin();
    ConstVectorIterator<OtherType> other_iterator = other.begin();

    for (auto& i : difference) {
        i = *this_iterator - *other_iterator;

        this_iterator++;
        other_iterator++;
    }

    return difference;
}

template<NumberType Type>
template<NumberType OtherType>
Vector<Type>& Vector<Type>::operator-=(const Vector<OtherType>& other) {
    if (this->_size != other._size)
        throw exceptions::DifferentVectorSizeException(__FILE__, __LINE__, "Different vector sizes. Addition is impossible.");

    ConstVectorIterator<OtherType> other_iterator = other.begin();

    for (auto& i : *this) {
        i -= *other_iterator;

        other_iterator++;
    }

    return *this;
}

template<NumberType Type>
template<NumberType OtherType>
decltype(auto) Vector<Type>::operator*(const OtherType& factor) const {

    Vector<decltype(this->at(0) * factor)> product(this->_size);

    ConstVectorIterator<Type> this_iterator = this->begin();

    for (auto& i : product) {
        i = *this_iterator * factor;

        this_iterator++;
    }

    return product;
}

template<NumberType Type>
template<NumberType OtherType>
Vector<Type>& Vector<Type>::operator*=(const OtherType& factor) {
    for (auto& i : *this)
        i *= factor;

    return *this;
}

template<NumberType Type>
bool _is_zero(const Type& value);

template<NumberType Type>
bool _is_zero(const Type& value) {
    return value == 0;
}

template<>
bool _is_zero(const float& value) {
    return fabsf(value) < FLT_EPSILON;
}

template<>
bool _is_zero(const double& value) {
    return fabs(value) < DBL_EPSILON;
}

template<>
bool _is_zero(const long double& value) {
    return fabsl(value) < LDBL_EPSILON;
}

template<NumberType Type>
template<NumberType OtherType>
decltype(auto) Vector<Type>::operator/(const OtherType& divider) const {
    if (_is_zero(divider))
        throw exceptions::DivisionByZeroException(__FILE__, __LINE__, "Dividing vector by zero error.");

    Vector<decltype(this->at(0) * divider)> quotient(this->_size);

    ConstVectorIterator<Type> this_iterator = this->begin();

    for (auto& i : quotient) {
        i = *this_iterator / divider;

        this_iterator++;
    }

    return quotient;
}

template<NumberType Type>
template<NumberType OtherType>
Vector<Type>& Vector<Type>::operator/=(const OtherType& divider) {
    if (_is_zero(divider))
        throw exceptions::DivisionByZeroException(__FILE__, __LINE__, "Dividing vector by zero error.");

    for (auto& i : *this)
        i /= divider;

    return *this;
}

template<NumberType Type>
template<NumberType OtherType>
decltype(auto) Vector<Type>::operator&(const Vector<OtherType>& other) const {
    if (this->_size != other._size)
        throw exceptions::DifferentVectorSizeException(__FILE__, __LINE__, "Different vector sizes. Scalar multiplication is impossible.");

    decltype(this->at(0) * other.at(0) + this->at(0) * other.at(0)) result = 0;

    ConstVectorIterator<OtherType> other_iterator = other.begin();

    for(auto i : *this) {
        result += i * *other_iterator;

        other_iterator++;
    }

    return result;
}

template<NumberType Type>
template<NumberType OtherType>
decltype(auto) Vector<Type>::operator^(const Vector<OtherType> &other) const {
    if (this->_size != 3 || other._size != 3)
        throw exceptions::UnableVectorMultiplicationException(__FILE__, __LINE__);

    Vector<decltype(this->at(0) * other.at(0))> result = {
            this->at(1) * other.at(2) - this->at(2) * other.at(1),  // AyBz - AzBy
            this->at(2) * other.at(0) - this->at(0) * other.at(2),  // AzBx - AxBz
            this->at(0) * other.at(1) - this->at(1) * other.at(0)   // AxBy - AyBx
    };

    return result;
}

template<NumberType Type>
template<NumberType OtherType>
Vector<Type>& Vector<Type>::operator^=(const Vector<OtherType> &other) {
    if (this->_size != 3 || other._size != 3)
        throw exceptions::UnableVectorMultiplicationException(__FILE__, __LINE__);

    *this = {
            this->at(1) * other.at(2) - this->at(2) * other.at(1),  // AyBz - AzBy
            this->at(2) * other.at(0) - this->at(0) * other.at(2),  // AzBx - AxBz
            this->at(0) * other.at(1) - this->at(1) * other.at(0)   // AxBy - AyBx
    };

    return *this;
}

template<NumberType Type>
template<NumberType OtherType>
bool Vector<Type>::operator==(const Vector<OtherType> &other) const {
    if (this->_size != other._size)
        throw exceptions::DifferentVectorSizeException(__FILE__, __LINE__, "Different vector sizes. Addition is impossible.");

    bool is_equal = true;

    ConstVectorIterator<OtherType> other_iterator = other.begin();

    for (Type i : *this) {
        auto difference = i - *other_iterator;
        if (!_is_zero<decltype(difference)>(difference))
            is_equal = false;

        other_iterator++;
    }

    return  is_equal;
}

template<NumberType Type>
template<NumberType OtherType>
bool Vector<Type>::operator!=(const Vector<OtherType> &other) const {
    if (this->_size != other._size)
        throw exceptions::DifferentVectorSizeException(__FILE__, __LINE__, "Different vector sizes. Addition is impossible.");

    return !this->operator==(other);
}

template<NumberType Type>
template<NumberType OtherType>
decltype(auto) Vector<Type>::operator<=>(const Vector<OtherType> &other) const {
    return this->_size <=> other._size;
}


template<NumberType Type>
VectorIterator<Type> Vector<Type>::begin() noexcept {
    return VectorIterator<Type>(*this);
}

template<NumberType Type>
VectorIterator<Type> Vector<Type>::end() noexcept {
    VectorIterator<Type> iterator(*this);
    iterator += this->_size;
    return iterator;
}

template<NumberType Type>
ConstVectorIterator<Type> Vector<Type>::begin() const noexcept {
    ConstVectorIterator<Type> const_iterator(*this);
    return const_iterator;
}

template<NumberType Type>
ConstVectorIterator<Type> Vector<Type>::end() const noexcept {
    ConstVectorIterator<Type> const_iterator(*this);
    return const_iterator + this->_size;
}

template<NumberType Type>
ConstVectorIterator<Type> Vector<Type>::cbegin() const noexcept {
    ConstVectorIterator<Type> const_iterator(*this);
    return const_iterator;
}

template<NumberType Type>
ConstVectorIterator<Type> Vector<Type>::cend() const noexcept {
    ConstVectorIterator<Type> const_iterator(*this);
    return const_iterator + this->_size;
}