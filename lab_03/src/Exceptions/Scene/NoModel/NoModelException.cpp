#include "NoModelException.hpp"

#include <cstdio>

using namespace Exceptions;

NoModelException::NoModelException(const char* filename, int line, const char* error_message) {
    snprintf(this->message, BUFFER_SIZE, "%s File: %s Line: %d .\n", error_message, filename, line);
}
