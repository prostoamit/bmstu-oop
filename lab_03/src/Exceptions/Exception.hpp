#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>

namespace Exceptions {
    const size_t BUFFER_SIZE = 256;

    class Exception : public std::exception {
    public:
        virtual const char* what() const noexcept override;

        virtual ~Exception() = default;

    protected:
        char message[BUFFER_SIZE]{};

        Exception() = default;
    };
}


#endif //EXCEPTION_HPP
