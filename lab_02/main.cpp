#include <gtest/gtest.h>

#include "tests_vector_constructors.hpp"
#include "tests_vector_assignments.hpp"
#include "tests_vector_elements_access.hpp"
#include "tests_vector_maths.hpp"
#include "tests_vector_comparisons.hpp"

#include "tests_vector_iterators.hpp"

#include "Vector.h"
#include <gtest/gtest.h>

int main() {
    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}