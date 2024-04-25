#ifndef TESTS_VECTOR_ITERATORS_HPP
#define TESTS_VECTOR_ITERATORS_HPP

#include "Vector.h"
#include "exceptions.h"
#include <gtest/gtest.h>

TEST(vector_iterators, out_of_range_error) {
    const size_t reference_size = 5;
    int reference[reference_size] = {0, 1, 2, 3, 4};
    Vector<int> test_vector(reference_size, reference);

    VectorIterator<int> test = test_vector.end();

    EXPECT_THROW(*test, exceptions::OutOfRangeException);
}

TEST(vector_iterators, hanging_object_error) {
    const size_t reference_size = 5;
    int reference[reference_size] = {0, 1, 2, 3, 4};
    auto *test_vector = new Vector<int>(reference_size, reference);

    VectorIterator<int> test = test_vector->begin();

    delete test_vector;

    EXPECT_THROW(*test, exceptions::DeletedObjectException);
}

TEST(vector_iterators, bool_true) {
    const size_t reference_size = 5;
    int reference[reference_size] = {0, 1, 2, 3, 4};
    auto *test_vector = new Vector<int>(reference_size, reference);

    VectorIterator<int> test = test_vector->begin();

    delete test_vector;

    EXPECT_TRUE(test);
}

TEST(vector_iterators, subsript_operator) {
    const size_t reference_size = 5;
    int reference[reference_size] = {0, 1, 2, 3, 4};
    Vector<int> test_vector(reference_size, reference);

    VectorIterator<int> test = test_vector.begin();

    EXPECT_EQ(test[3], reference[3]);
}

TEST(vector_iterators, begin_iterator) {
    const size_t reference_size = 5;
    int reference[reference_size] = {0, 1, 2, 3, 4};
    Vector<int> test_vector(reference_size, reference);

    VectorIterator<int> test = test_vector.begin();

    EXPECT_EQ(*test, reference[0]);
}

TEST(vector_iterators, end_iterator) {
    const size_t reference_size = 5;
    int reference[reference_size] = {0, 1, 2, 3, 4};
    Vector<int> test_vector(reference_size, reference);

    VectorIterator<int> test = test_vector.end();
    test--;

    EXPECT_EQ(*test, reference[reference_size - 1]);
}

TEST(vector_iterators, increment) {
    const size_t reference_size = 5;
    int reference[reference_size] = {0, 1, 2, 3, 4};
    Vector<int> test_vector(reference_size, reference);

    VectorIterator<int> test = test_vector.begin();
    test++;

    EXPECT_EQ(*test, reference[1]);
}

TEST(vector_iterators, decrement) {
    const size_t reference_size = 5;
    int reference[reference_size] = {0, 1, 2, 3, 4};
    Vector<int> test_vector(reference_size, reference);

    VectorIterator<int> test = test_vector.begin();
    test++;
    test--;

    EXPECT_EQ(*test, reference[0]);
}

TEST(vector_iterators, add) {
    const size_t reference_size = 5;
    int reference[reference_size] = {0, 1, 2, 3, 4};
    Vector<int> test_vector(reference_size, reference);

    VectorIterator<int> test = test_vector.begin();
    VectorIterator<int> test_added = test + 3;

    EXPECT_EQ(*test_added, reference[3]);
}

TEST(vector_iterators, add_assign) {
    const size_t reference_size = 5;
    int reference[reference_size] = {0, 1, 2, 3, 4};
    Vector<int> test_vector(reference_size, reference);

    VectorIterator<int> test = test_vector.begin();
    test += 3;

    EXPECT_EQ(*test, reference[3]);
}

TEST(vector_iterators, subtract) {
    const size_t reference_size = 5;
    int reference[reference_size] = {0, 1, 2, 3, 4};
    Vector<int> test_vector(reference_size, reference);

    VectorIterator<int> test = test_vector.end();
    VectorIterator<int> test_subtracted = test - 3;

    EXPECT_EQ(*test_subtracted, reference[reference_size - 3]);
}

TEST(vector_iterators, subtract_assign) {
    const size_t reference_size = 5;
    int reference[reference_size] = {0, 1, 2, 3, 4};
    Vector<int> test_vector(reference_size, reference);

    VectorIterator<int> test = test_vector.end();
    test -= 3;

    EXPECT_EQ(*test, reference[reference_size - 3]);
}

TEST(vector_iterator, compare_equal_error) {
    const size_t reference_size = 3;
    int reference_1[reference_size] = {0, 1, 2};
    int reference_2[reference_size] = {0, 1, 2};

    Vector<int> test_vector_1(reference_size, reference_1);
    Vector<int> test_vector_2(reference_size, reference_2);

    VectorIterator<int> test_iterator_1 = test_vector_1.begin();
    VectorIterator<int> test_iterator_2 = test_vector_2.begin();

    EXPECT_THROW(test_iterator_1 == test_iterator_2, exceptions::DifferentVectorIteratorCmpException);
}

TEST(vector_iterator, compare_equal_true) {
    const size_t reference_size = 3;
    int reference[reference_size] = {0, 1, 2};

    Vector<int> test_vector(reference_size, reference);

    VectorIterator<int> test_iterator_1(test_vector);
    VectorIterator<int> test_iterator_2(test_vector);

    EXPECT_TRUE(test_iterator_1 == test_iterator_1);

    test_iterator_1 += 2;
    test_iterator_2 += 2;

    EXPECT_TRUE(test_iterator_1 == test_iterator_2);
}

TEST(vector_iterator, compare_equal_false) {
    const size_t reference_size = 3;
    int reference[reference_size] = {0, 1, 2};

    Vector<int> test_vector(reference_size, reference);

    VectorIterator<int> test_iterator_1(test_vector);
    VectorIterator<int> test_iterator_2(test_vector);

    test_iterator_2 += 2;

    EXPECT_FALSE(test_iterator_1 == test_iterator_2);
}

TEST(vector_iterator, compare_not_equal_true) {
    const size_t reference_size = 3;
    int reference[reference_size] = {0, 1, 2};

    Vector<int> test_vector(reference_size, reference);

    VectorIterator<int> test_iterator_1(test_vector);
    VectorIterator<int> test_iterator_2(test_vector);

    test_iterator_2 += 2;

    EXPECT_TRUE(test_iterator_1 != test_iterator_2);
}

TEST(vector_iterator, compare_not_equal_false) {
    const size_t reference_size = 3;
    int reference[reference_size] = {0, 1, 2};

    Vector<int> test_vector(reference_size, reference);

    VectorIterator<int> test_iterator_1(test_vector);
    VectorIterator<int> test_iterator_2(test_vector);

    EXPECT_FALSE(test_iterator_1 != test_iterator_2);

    test_iterator_1 += 2;
    test_iterator_2 += 2;

    EXPECT_FALSE(test_iterator_1 != test_iterator_2);
}

#endif //TESTS_VECTOR_ITERATORS_HPP
