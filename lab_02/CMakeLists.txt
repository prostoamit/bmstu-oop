cmake_minimum_required(VERSION 3.28)
project(lab_02)

set(CMAKE_CXX_STANDARD 20)


include_directories(
        .
        Iterators
        Containers
        Exceptions
        Vector
        AVLTree
        Tests
)

add_executable(lab_02 main.cpp
        Vector/Vector.hpp
        Vector/Vector.h
        Exceptions/exceptions.cpp
        Exceptions/exceptions.h
        Vector/VectorIterator.hpp
        Vector/VectorIterator.h
        Vector/vector_concepts.h
        Vector/ConstVectorIterator.hpp
        Vector/ConstVectorIterator.h
        Iterators/BaseIterator.h
        AVLTree/AvlTree.hpp
        AVLTree/AVLTree.h
        AVLTree/AVLTree_concepts.h
        AVLTree/AvlTreeIterator.hpp
        AVLTree/AvlTreeIterator.h
        AVLTree/ConstAvlTreeIterator.hpp
        AVLTree/ConstAvlTreeIterator.h
        Tests/tests_vector_constructors.hpp
        Tests/tests_vector_assignments.hpp
        Tests/tests_vector_elements_access.hpp
        Tests/tests_vector_maths.hpp
        Tests/tests_vector_comparisons.hpp
        Tests/tests_vector_iterators.hpp
)

target_link_libraries(lab_02 gtest gmock pthread)

add_link_options(-lgtest -lgmock -pthread)