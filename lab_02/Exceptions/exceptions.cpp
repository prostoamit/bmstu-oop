#include "exceptions.h"

using namespace exceptions;

const char *BaseException::what() const noexcept {
    return message;
}

DivisionByZeroException::DivisionByZeroException(const char *filename, int line, const char *error_message) {
    snprintf(this->message, BUFFER_SIZE, "%s File: %s Line: %d .\n", error_message, filename, line);
}
