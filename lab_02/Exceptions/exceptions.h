#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

namespace exceptions {
    const size_t BUFFER_SIZE = 256;

    class BaseException : public std::exception {
    protected:
        char message[BUFFER_SIZE];
    public:
        BaseException() = default;

        const char* what() const noexcept override;

        virtual ~BaseException() = default;
    };

    class DivisionByZeroException : public BaseException {
    public:
        DivisionByZeroException(const char *filename, int line, const char *error_message = "Division by zero error.");
    };
}


#endif //EXCEPTIONS_H
