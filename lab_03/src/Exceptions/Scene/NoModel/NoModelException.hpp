#ifndef NOMODELEXCEPTION_HPP
#define NOMODELEXCEPTION_HPP

#include "Exceptions/Exception.hpp"

namespace Exceptions {
    class NoModelException : public Exception {
    public:
        NoModelException(const char* filename, int line, const char* error_message = "Model was not loaded.");
    };
}

#endif //NOMODELEXCEPTION_HPP
