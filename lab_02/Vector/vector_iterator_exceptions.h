#ifndef VECTOR_ITERATOR_EXCEPTIONS_H
#define VECTOR_ITERATOR_EXCEPTIONS_H


#include "exceptions.h"

using exceptions::BaseException;

namespace exceptions {
    class VectorIteratorDeletedVectorException : public BaseException {
    public:
        VectorIteratorDeletedVectorException(const char *filename, int line, const char *error_message = "Pointing to deleted vector error.");
    };

    class VectorIteratorOutOfRangeException : public BaseException {
    public:
        VectorIteratorOutOfRangeException(const char *filename, int line, const char *error_message = "Out of range error.");
    };

    class VectorIteratorDifferentVectorCmpException : public BaseException {
    public:
        VectorIteratorDifferentVectorCmpException(const char *filename, int line, const char *error_message = "Comparing iterators of different vectors error.");
    };
}


#endif //VECTOR_ITERATOR_EXCEPTIONS_H
