#ifndef TESTS_VECTOR_CONSTRUCTORS_HPP
#define TESTS_VECTOR_CONSTRUCTORS_HPP

#include "Vector.h"
#include <gtest/gtest.h>

TEST(vector_constructors, default_empty) {
    Vector<int> test;

    EXPECT_EQ(test.size(), 0);
}

TEST(vector_constructors, size_zero_uint) {
    const size_t reference_size = 0;
    Vector<unsigned int> test(reference_size);

    EXPECT_EQ(test.size(), reference_size);
}

TEST(vector_constructors, size_uint) {
    const size_t reference_size = 50;
    Vector<unsigned int> test(reference_size);

    EXPECT_EQ(test.size(), reference_size);
    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(test[i], 0);
}

TEST(vector_constructors, c_array_char) {
    const size_t reference_size = 5;
    float reference[reference_size] = {65, 127, -128, 0, 55};
    Vector<float> test(reference_size, reference);

    EXPECT_EQ(test.size(), reference_size);
    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(test[i], reference[i]);
}

TEST(vector_constructors, c_array_float) {
    const size_t reference_size = 5;
    char reference[reference_size] = {65, 127, -128, 0, 55};
    Vector<char> test(reference_size, reference);

    EXPECT_EQ(test.size(), reference_size);
    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(test[i], reference[i]);
}

TEST(vector_constructors, int_initializer_list_empty) {
    Vector<int> test = {};

    EXPECT_EQ(test.size(), 0);
}

TEST(vector_constructors, initializer_list_int) {
    const size_t reference_size = 10;
    int reference[reference_size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Vector<int> test({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});

    EXPECT_EQ(test.size(), reference_size);
    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(test[i], reference[i]);
}

TEST(vector_constructors, initializer_list_double) {
    const size_t reference_size = 5;
    double reference[reference_size] = {1e-5, M_PI, M_E, DBL_MAX, DBL_MIN};
    Vector<double> test({1e-5, M_PI, M_E, DBL_MAX, DBL_MIN});

    EXPECT_EQ(test.size(), reference_size);
    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(test[i], reference[i]);
}

TEST(vector_constructors, copy_int) {
    const size_t reference_size = 3;
    int reference[reference_size] = {67, -1000, 23};
    Vector<int> from(reference_size, reference);
    Vector<int> test(from);

    EXPECT_EQ(from.size(), reference_size);
    EXPECT_EQ(from.size(), test.size());

    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(from[i], reference[i]);

    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(test[i], from[i]);
}

TEST(vector_constructors, move_int) {
    const size_t reference_size = 3;
    int reference[reference_size] = {67, -1000, 23};
    Vector<int> from(reference_size, reference);
    Vector<int> test(std::move(from));

    EXPECT_EQ(from.size(), 0);
    EXPECT_EQ(test.size(), reference_size);

    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(test[i], reference[i]);
}

#endif //TESTS_VECTOR_CONSTRUCTORS_HPP
