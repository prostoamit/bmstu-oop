#ifndef VECTOR_ITERATOR_EXCEPTIONS_H
#define VECTOR_ITERATOR_EXCEPTIONS_H

#include "exceptions.h"

using exceptions::BaseException;

namespace vector_iterator_exceptions {
    class VectorIteratorBaseException : public BaseException {
    public:
        VectorIteratorBaseException() = default;
        VectorIteratorBaseException(const char* filename, int line, const char* error_message = "Vector error.");
    };

    class VectorIteratorDeletedVectorException : public VectorIteratorBaseException {
    public:
        VectorIteratorDeletedVectorException(const char *filename, int line, const char *error_message = "Pointing to deleted vector error.");
    };

    class VectorIteratorOutOfRangeException : public VectorIteratorBaseException {
    public:
        VectorIteratorOutOfRangeException(const char *filename, int line, const char *error_message = "Out of range error.");
    };

    class VectorIteratorDifferentVectorCmpException : public VectorIteratorBaseException {
    public:
        VectorIteratorDifferentVectorCmpException(const char *filename, int line, const char *error_message = "Comparing iterators of different vectors error.");
    };
}


#endif //VECTOR_ITERATOR_EXCEPTIONS_H
