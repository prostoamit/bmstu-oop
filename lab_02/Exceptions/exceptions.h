#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

namespace exceptions {
    const size_t BUFFER_SIZE = 256;

    class BaseException : public std::exception {
    public:

        virtual const char* what() const noexcept override;

        virtual ~BaseException() = default;

    protected:
        char message[BUFFER_SIZE];

        BaseException() = default;
    };

    class DivisionByZeroException : public BaseException {
    public:
        DivisionByZeroException(const char *filename, int line, const char *error_message = "Division by zero error.");
    };
}


#endif //EXCEPTIONS_H
