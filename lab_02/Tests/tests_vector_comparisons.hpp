#ifndef TESTS_VECTOR_COMPARISONS_HPP
#define TESTS_VECTOR_COMPARISONS_HPP

#include "Vector.h"
#include "exceptions.h"
#include <gtest/gtest.h>

TEST(vector_comparisons, equals_different_sizes_error) {
    Vector<int> vector_1 = {1, 3, 5};
    Vector<int> vector_2 = {1, 3, 5, 6, 1};

    EXPECT_THROW(vector_1 == vector_2, exceptions::DifferentVectorSizeException);
}

TEST(vector_comparisons, not_equals_different_sizes_error) {
    Vector<int> vector_1 = {1, 3, 5};
    Vector<int> vector_2 = {1, 3, 5, 6, 1};

    EXPECT_THROW(vector_1 != vector_2, exceptions::DifferentVectorSizeException);
}

TEST(vector_comparisons, equals_true_int) {
    Vector<int> vector_1 = {1, 3, 5};
    Vector<int> vector_2 = {1, 3, 5};

    EXPECT_TRUE(vector_1 == vector_2);
}

TEST(vector_comparisons, equals_false_int) {
    Vector<int> vector_1 = {1, 3, 5};
    Vector<int> vector_2 = {5, 15, 25};

    EXPECT_FALSE(vector_1 == vector_2);
}

TEST(vector_comparisons, not_equals_true_int) {
    Vector<int> vector_1 = {1, 3, 5};
    Vector<int> vector_2 = {5, 15, 25};

    EXPECT_TRUE(vector_1 != vector_2);
}

TEST(vector_comparisons, not_equals_false_int) {
    Vector<int> vector_1 = {1, 3, 5};
    Vector<int> vector_2 = {1, 3, 5};

    EXPECT_FALSE(vector_1 != vector_2);
}

TEST(vector_comparisons, equals_true_double) {
    Vector<double> vector_1 = {6.15234, -23.12314, 55.0123};
    Vector<double> vector_2 = {6.15234, -23.12314, 55.0123};

    EXPECT_TRUE(vector_1 == vector_2);
}

TEST(vector_comparisons, equals_false_double) {
    Vector<double> vector_1 = {6.15234, -23.12314, 55.0123};
    Vector<double> vector_2 = {6.15234, -23.12312, 55.0123};

    EXPECT_FALSE(vector_1 == vector_2);
}

TEST(vector_comparisons, not_equals_true_double) {
    Vector<double> vector_1 = {6.15234, -23.12314, 55.0123};
    Vector<double> vector_2 = {6.15234, -23.12312, 55.0123};

    EXPECT_TRUE(vector_1 != vector_2);
}

TEST(vector_comparisons, not_equals_false_double) {
    Vector<double> vector_1 = {6.15234, -23.12314, 55.0123};
    Vector<double> vector_2 = {6.15234, -23.12314, 55.0123};

    EXPECT_FALSE(vector_1 != vector_2);
}

TEST(vector_comparisons, less_true) {
    Vector<int> vector_1 = {1, 3, 5};
    Vector<int> vector_2 = {1, 3, 5, 6, 1};

    EXPECT_TRUE(vector_1 < vector_2);
}

TEST(vector_comparisons, less_eq_true) {
    Vector<int> vector_1 = {1, 3, 5};
    Vector<int> vector_2 = {3, 7, 1};

    EXPECT_TRUE(vector_1 <= vector_2);
}

TEST(vector_comparisons, more_true) {
    Vector<int> vector_1 = {1, 3, 5, 65, 12};
    Vector<int> vector_2 = {3, 7, 1};

    EXPECT_TRUE(vector_1 > vector_2);
}

TEST(vector_comparisons, more_eq_true) {
    Vector<int> vector_1 = {1, 3, 5};
    Vector<int> vector_2 = {3, 7, 1};

    EXPECT_TRUE(vector_1 >= vector_2);
}


#endif //TESTS_VECTOR_COMPARISONS_HPP
