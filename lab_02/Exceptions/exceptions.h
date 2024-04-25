#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

namespace exceptions {
    class BaseException : public std::exception {
    protected:
        std::string message;
    public:
        BaseException() = default;

        const char* what() const noexcept override;

        virtual ~BaseException() = default;
    };

    class DivisionByZeroException : public BaseException {
    public:
        DivisionByZeroException(const std::string &filename, int line, std::string error_message = "Division by zero error.");
    };

    class MemoryAllocationException : public BaseException {
    public:
        MemoryAllocationException(const std::string &filename, int line, std::string error_message = "Memory allocation error.");
    };

    class DeletedObjectException : public BaseException {
    public:
        DeletedObjectException(const std::string &filename, int line, std::string error_message = "Deleted object error.");
    };

    class OutOfRangeException : public BaseException {
    public:
        OutOfRangeException(const std::string &filename, int line, std::string error_message = "Out of range error.");
    };

    class DifferentVectorIteratorCmpException : public BaseException {
    public:
        DifferentVectorIteratorCmpException(const std::string &filename, int line, std::string error_message = "Comparing iterators of different vectors error.");
    };

    class DifferentVectorSizeException : public BaseException {
    public:
        DifferentVectorSizeException(const std::string &filename, int line, std::string error_message = "Vectors have different sizes. Operation is impossible.");
    };

    class UnableVectorMultiplicationException : public BaseException {
    public:
        UnableVectorMultiplicationException(const std::string &filename, int line, std::string error_message = "Vectors have different sizes. Operation is impossible.");
    };
}


#endif //EXCEPTIONS_H
