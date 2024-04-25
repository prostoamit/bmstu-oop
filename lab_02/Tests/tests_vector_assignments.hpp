#ifndef TESTS_VECTOR_ASSIGNMENTS_HPP
#define TESTS_VECTOR_ASSIGNMENTS_HPP

#include "Vector.h"
#include <gtest/gtest.h>

TEST(vector_assignments, assign_other) {
    const size_t reference_size = 3;
    int reference[reference_size] = {67, -1000, 23};
    Vector<int> from(reference_size, reference);
    Vector<int> test;

    test = from;

    EXPECT_EQ(from.size(), reference_size);
    EXPECT_EQ(test.size(), reference_size);

    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(from[i], reference[i]);

    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(test[i], from[i]);
}

TEST(vector_assignments, assign_move) {
    const size_t reference_size = 3;
    int reference[reference_size] = {67, -1000, 23};
    Vector<int> from(reference_size, reference);
    Vector<int> test;

    test = std::move(from);

    EXPECT_EQ(from.size(), 0);
    EXPECT_EQ(test.size(), reference_size);

    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(test[i], reference[i]);
}

TEST(vector_assignments, assign_initializer_list) {
    const size_t reference_size = 3;
    int reference[reference_size] = {67, -1000, 23};
    Vector<int> test;

    test = {67, -1000, 23};

    EXPECT_EQ(test.size(), reference_size);

    for (size_t i = 0; i < reference_size; i++)
        EXPECT_EQ(test[i], reference[i]);
}

#endif //TESTS_VECTOR_ASSIGNMENTS_HPP
