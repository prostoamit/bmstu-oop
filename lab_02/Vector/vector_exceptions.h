#ifndef VECTOR_EXCEPTIONS_H
#define VECTOR_EXCEPTIONS_H

#include "exceptions.h"

using exceptions::BaseException;

namespace vector_exceptions {
    class VectorBaseException : public BaseException {
    protected:
        VectorBaseException() = default;
    public:
        VectorBaseException(const char* filename, int line, const char* error_message = "Vector error.");
    };

    class VectorAllocationException : public VectorBaseException {
    public:
        VectorAllocationException(const char* filename, int line, const char* error_message = "Memory allocation error.");
    };

    class VectorDifferentSizeException : public VectorBaseException {
    public:
        VectorDifferentSizeException(const char* filename, int line, const char* error_message = "Vectors have different sizes. Operation is impossible.");
    };


    class VectorOutOfRangeException : public VectorBaseException {
    public:
        VectorOutOfRangeException(const char* filename, int line, const char* error_message = "Vector out of range error.");
    };

    class VectorUnableVectorMultiplicationException : public VectorBaseException {
    public:
        VectorUnableVectorMultiplicationException(const char *filename, int line, const char *error_message = "Vectors have different sizes. Operation is impossible.");
    };
}


#endif //VECTOR_EXCEPTIONS_H
