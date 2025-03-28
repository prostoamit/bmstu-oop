#ifndef NOMEMENTOEXCEPTION_HPP
#define NOMEMENTOEXCEPTION_HPP

#include "Exception.hpp"

namespace Exceptions {
    class NoMementoException : public Exception {
    public:
        NoMementoException(const char* filename, int line, const char* error_message = "There are no mementos in caretaker.");
    };
}

#endif //NOMEMENTOEXCEPTION_HPP
