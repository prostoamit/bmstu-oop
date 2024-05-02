#ifndef TESTS_VECTOR_ELEMENTS_ACCESS_HPP
#define TESTS_VECTOR_ELEMENTS_ACCESS_HPP

#include "Vector.h"
#include "vector_exceptions.h"
#include <gtest/gtest.h>

TEST(vector_elements_access, at_correct) {
    const size_t reference_size = 5;
    int reference[reference_size] = {67, -1000, 23, 45, 12};
    Vector<int> test(reference_size, reference);

    const size_t index = 3;
    int element = test.at(index);

    EXPECT_EQ(element, reference[index]);
}

TEST(vector_elements_access, at_error) {
    const size_t reference_size = 5;
    int reference[reference_size] = {67, -1000, 23, 45, 12};
    Vector<int> test(reference_size, reference);

    EXPECT_THROW(test.at(reference_size + 1), exceptions::VectorOutOfRangeException);
}

TEST(vector_elements_access, subscript_operator_correct) {
    const size_t reference_size = 5;
    int reference[reference_size] = {67, -1000, 23, 45, 12};
    Vector<int> test(reference_size, reference);

    const size_t index = 3;
    int element = test[index];

    EXPECT_EQ(element, reference[index]);
}

TEST(vector_elements_access, subscript_operator_error) {
    const size_t reference_size = 5;
    int reference[reference_size] = {67, -1000, 23, 45, 12};
    Vector<int> test(reference_size, reference);

    EXPECT_THROW(test[reference_size + 1], exceptions::OutOfRangeException);
}

#endif //TESTS_VECTOR_ELEMENTS_ACCESS_HPP
