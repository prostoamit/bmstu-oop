#ifndef TESTS_VECTOR_MATHS_HPP
#define TESTS_VECTOR_MATHS_HPP

#include "Vector.h"
#include <gtest/gtest.h>

#include <cmath>

TEST(vector_maths, length) {
    const size_t reference_size = 5;
    int reference[reference_size] = {67, -1000, 23, 45, 12};
    Vector<int> test(reference_size, reference);

    double reference_length = 0.0;
    for (auto i : reference)
        reference_length += i * i;

    reference_length = sqrt(reference_length);

    EXPECT_DOUBLE_EQ(test.length(), reference_length);
}

TEST(vector_maths, is_unit_true) {
    Vector<double> test = {1.0, 0., 0.0};

    EXPECT_TRUE(test.is_unit());
}

TEST(vector_maths, is_unit_false) {
    Vector<double> test = {55.0, -23.0, 0.0};

    EXPECT_FALSE(test.is_unit());
}

TEST(vector_maths, angle_different_sizes_error) {
    Vector<double> vector_1 = {1.0, 0.0, 0.0};
    Vector<double> vector_2 = {0.0, 1.0, 0.0, 12.0, 3.0};

    EXPECT_THROW(vector_1.angle(vector_2), exceptions::DifferentVectorSizeException);
}

TEST(vector_maths, angle) {
    Vector<double> vector_1 = {1.0, 0.0, 0.0};
    Vector<double> vector_2 = {0.0, 1.0, 0.0};

    double angle_1_2 = vector_1.angle(vector_2);
    double angle_2_1 = vector_2.angle(vector_1);

    EXPECT_EQ(angle_1_2, angle_2_1);

    EXPECT_DOUBLE_EQ(angle_1_2, M_PI / 2);
}

TEST(vector_maths, is_collinear_different_sizes_error) {
    Vector<double> vector_1 = {1.0, 0.0, 0.0};
    Vector<double> vector_2 = {0.0, 1.0, 0.0, 12.0, 3.0};

    EXPECT_THROW(vector_1.is_collinear(vector_2), exceptions::DifferentVectorSizeException);
}

TEST(vector_maths, is_collinear_true) {
    Vector<double> vector_1 = {1.0, 0.0, 0.0};
    Vector<double> vector_2 = {571.0, 0.0, 0.0};

    EXPECT_TRUE(vector_1.is_collinear(vector_1));
    EXPECT_TRUE(vector_2.is_collinear(vector_2));
    EXPECT_TRUE(vector_1.is_collinear(vector_2));
    EXPECT_TRUE(vector_2.is_collinear(vector_1));
}

TEST(vector_maths, is_collinear_false) {
    Vector<double> vector_1 = {1.0, 0.0, 0.0};
    Vector<double> vector_2 = {1.0, 1.0, 0.0};

    EXPECT_FALSE(vector_1.is_collinear(vector_2));
    EXPECT_FALSE(vector_2.is_collinear(vector_1));
}

TEST(vector_maths, is_othogonal_different_sizes_error) {
    Vector<double> vector_1 = {1.0, 0.0, 0.0};
    Vector<double> vector_2 = {0.0, 1.0, 0.0, 12.0, 3.0};

    EXPECT_THROW(vector_1.is_orthogonal(vector_2), exceptions::DifferentVectorSizeException);
}

TEST(vector_maths, is_orthogonal_true) {
    Vector<double> vector_1 = {1.0, 0.0, 0.0};
    Vector<double> vector_2 = {0.0, 1100.0, 0.0};

    EXPECT_TRUE(vector_1.is_orthogonal(vector_2));
    EXPECT_TRUE(vector_2.is_orthogonal(vector_1));
}

TEST(vector_maths, is_orthogonal_false) {
    Vector<double> vector_1 = {1.0, 0.0, 0.0};
    Vector<double> vector_2 = {0.0001, 10000.1, 0.0};

    EXPECT_FALSE(vector_1.is_orthogonal(vector_2));
    EXPECT_FALSE(vector_2.is_orthogonal(vector_1));
}

TEST(vector_maths, negative) {
    const size_t reference_size = 5;
    int reference[reference_size] = {65, 127, -128, 0, 55};
    Vector<int> test(reference_size, reference);

    Vector<int> neg_test = -test;

    EXPECT_EQ(neg_test.size(), test.size());
    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(neg_test[i], -test[i]);
}

TEST(vector_maths, addition_different_sizes_error) {
    Vector<double> vector_1 = {1.0, 0.0, 0.0};
    Vector<double> vector_2 = {0.0, 1.0, 0.0, 12.0, 3.0};

    EXPECT_THROW(vector_1 + vector_2, exceptions::DifferentVectorSizeException);
}

TEST(vector_maths, addition) {
    const size_t reference_size = 3;

    int term_1_reference[reference_size] = {1, 2, 3};
    int term_2_reference[reference_size] = {5, 6, 7};
    int result_reference[reference_size] = {6, 8, 10};

    Vector<int> term_1(reference_size, term_1_reference);
    Vector<int> term_2(reference_size, term_2_reference);

    Vector<int> sum = term_1 + term_2;

    EXPECT_EQ(sum.size(), reference_size);
    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(sum[i], result_reference[i]);
}

TEST(vector_maths, addition_assign_different_sizes_error) {
    Vector<double> vector_1 = {1.0, 0.0, 0.0};
    Vector<double> vector_2 = {0.0, 1.0, 0.0, 12.0, 3.0};

    EXPECT_THROW(vector_1 += vector_2, exceptions::DifferentVectorSizeException);
}


TEST(vector_maths, addition_assign) {
    const size_t reference_size = 3;

    int term_1_reference[reference_size] = {1, 2, 3};
    int term_2_reference[reference_size] = {5, 6, 7};
    int result_reference[reference_size] = {6, 8, 10};

    Vector<int> term_1(reference_size, term_1_reference);
    Vector<int> term_2(reference_size, term_2_reference);

    term_1 += term_2;

    EXPECT_EQ(term_1.size(), reference_size);
    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(term_1[i], result_reference[i]);
}

TEST(vector_maths, subtraction_different_sizes_error) {
    Vector<double> vector_1 = {1.0, 0.0, 0.0};
    Vector<double> vector_2 = {0.0, 1.0, 0.0, 12.0, 3.0};

    EXPECT_THROW(vector_1 - vector_2, exceptions::DifferentVectorSizeException);
}

TEST(vector_maths, subtraction) {
    const size_t reference_size = 3;

    int term_1_reference[reference_size] = {19, 1, -5};
    int term_2_reference[reference_size] = {5, 12, -7};
    int result_reference[reference_size] = {14, -11, 2};

    Vector<int> term_1(reference_size, term_1_reference);
    Vector<int> term_2(reference_size, term_2_reference);

    Vector<int> sum = term_1 - term_2;

    EXPECT_EQ(sum.size(), reference_size);
    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(sum[i], result_reference[i]);
}

TEST(vector_maths, subtraction_assign_different_sizes_error) {
    Vector<double> vector_1 = {1.0, 0.0, 0.0};
    Vector<double> vector_2 = {0.0, 1.0, 0.0, 12.0, 3.0};

    EXPECT_THROW(vector_1 -= vector_2, exceptions::DifferentVectorSizeException);
}

TEST(vector_maths, subtraction_assign) {
    const size_t reference_size = 3;

    int term_1_reference[reference_size] = {19, 1, -5};
    int term_2_reference[reference_size] = {5, 12, -7};
    int result_reference[reference_size] = {14, -11, 2};

    Vector<int> term_1(reference_size, term_1_reference);
    Vector<int> term_2(reference_size, term_2_reference);

    term_1 -= term_2;

    EXPECT_EQ(term_1.size(), reference_size);
    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(term_1[i], result_reference[i]);
}

TEST(vector_maths, multiplication_element) {
    const size_t reference_size = 3;

    int term_reference[reference_size] = {19, 1, -5};
    int result_reference[reference_size] = {38, 2, -10};

    Vector<int> term(reference_size, term_reference);

    Vector<int> result = term * 2;

    EXPECT_EQ(result.size(), reference_size);
    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(result[i], result_reference[i]);
}

TEST(vector_maths, multiplication_element_assign) {
    const size_t reference_size = 3;

    int term_reference[reference_size] = {19, 1, -5};
    int result_reference[reference_size] = {38, 2, -10};

    Vector<int> term(reference_size, term_reference);

    term *= 2;

    EXPECT_EQ(term.size(), reference_size);
    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(term[i], result_reference[i]);
}

TEST(vector_maths, division_element_int_zero_division_error) {
    Vector<int> vector_1 = {13, 76, -12};

    EXPECT_THROW(vector_1 / 0, exceptions::DivisionByZeroException);
}

TEST(vector_maths, division_element_double_zero_division_error) {
    Vector<double> vector_1 = {1.0, 0.0, 0.0};

    EXPECT_THROW(vector_1 / DBL_MIN, exceptions::DivisionByZeroException);
}

TEST(vector_maths, division_element) {
    const size_t reference_size = 3;

    int term_reference[reference_size] = {27, 333, 3};
    int result_reference[reference_size] = {9, 111, 1};

    Vector<int> term(reference_size, term_reference);

    Vector<int> result = term / 3;

    EXPECT_EQ(result.size(), reference_size);
    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(result[i], result_reference[i]);
}

TEST(vector_maths, division_element_assign_int_zero_division_error) {
    Vector<int> vector_1 = {13, 76, -12};

    EXPECT_THROW(vector_1 /= 0, exceptions::DivisionByZeroException);
}

TEST(vector_maths, division_element_assign_double_zero_division_error) {
    Vector<double> vector_1 = {1.0, 0.0, 0.0};

    EXPECT_THROW(vector_1 /= 0.0, exceptions::DivisionByZeroException);
}

TEST(vector_maths, division_element_assign) {
    const size_t reference_size = 3;

    int term_reference[reference_size] = {27, 333, 3};
    int result_reference[reference_size] = {9, 111, 1};

    Vector<int> term(reference_size, term_reference);

    term /= 3;

    EXPECT_EQ(term.size(), reference_size);
    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(term[i], result_reference[i]);
}

TEST(vector_maths, scalar_multiplication_different_sizes_error) {
    Vector<double> vector_1 = {1.0, 0.0, 0.0};
    Vector<double> vector_2 = {0.0, 1.0, 0.0, 12.0, 3.0};

    EXPECT_THROW(vector_1 & vector_2, exceptions::DifferentVectorSizeException);
}

TEST(vector_maths, scalar_multiplication) {
    const size_t reference_size = 3;

    int term_1_reference[reference_size] = {12, -3, 2};
    int term_2_reference[reference_size] = {54, 12, -1};
    double result_reference = 610.0;

    Vector<int> term_1(reference_size, term_1_reference);
    Vector<int> term_2(reference_size, term_2_reference);

    double result = term_1 & term_2;

    EXPECT_DOUBLE_EQ(result, result_reference);
}

TEST(vector_maths, vector_multiplication_not_3_dimentional) {
    Vector<double> vector_1 = {1.0, 0.0, 0.0};
    Vector<double> vector_2 = {0.0, 1.0, 0.0, 12.0, 3.0};

    EXPECT_THROW(vector_1 ^ vector_2, exceptions::UnableVectorMultiplicationException);
}

TEST(vector_maths, vector_multiplication) {
    const size_t reference_size = 3;

    double term_1_reference[reference_size] = {12, -3, 2};
    double term_2_reference[reference_size] = {54, 12, -1};
    double result_reference[reference_size] = {-21, 120, 306};

    Vector<double> term_1(reference_size, term_1_reference);
    Vector<double> term_2(reference_size, term_2_reference);

    Vector<double> result = term_1 ^ term_2;

    EXPECT_EQ(result.size(), reference_size);
    for (size_t i = 0; i < reference_size; i++)
        EXPECT_DOUBLE_EQ(result[i], result_reference[i]);
}

TEST(vector_maths, vector_multiplication_assign_not_3_dimentional) {
    Vector<double> vector_1 = {1.0, 0.0, 0.0};
    Vector<double> vector_2 = {0.0, 1.0, 0.0, 12.0, 3.0};

    EXPECT_THROW(vector_1 ^ vector_2, exceptions::UnableVectorMultiplicationException);
}

TEST(vector_maths, vector_multiplication_assign) {
    const size_t reference_size = 3;

    double term_1_reference[reference_size] = {12, -3, 2};
    double term_2_reference[reference_size] = {54, 12, -1};
    double result_reference[reference_size] = {-21, 120, 306};

    Vector<double> term_1(reference_size, term_1_reference);
    Vector<double> term_2(reference_size, term_2_reference);

    term_1 ^= term_2;

    EXPECT_EQ(term_1.size(), reference_size);
    for (size_t i = 0; i < reference_size; i++)
        EXPECT_DOUBLE_EQ(term_1[i], result_reference[i]);
}

#endif //TESTS_VECTOR_MATHS_HPP
