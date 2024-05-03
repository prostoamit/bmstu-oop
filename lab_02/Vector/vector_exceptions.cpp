#include "vector_exceptions.h"

#include <cstring>

using namespace exceptions;
using namespace vector_exceptions;

VectorBaseException::VectorBaseException(const char *filename, int line, const char *error_message) {
    snprintf(this->message, BUFFER_SIZE, "%s File: %s Line: %d .\n", error_message, filename, line);
}

VectorAllocationException::VectorAllocationException(const char *filename, int line, const char *error_message) {
    snprintf(this->message, BUFFER_SIZE, "%s File: %s Line: %d .\n", error_message, filename, line);
}

VectorDifferentSizeException::VectorDifferentSizeException(const char *filename, int line, const char *error_message) {
    snprintf(this->message, BUFFER_SIZE, "%s File: %s Line: %d .\n", error_message, filename, line);
}

VectorOutOfRangeException::VectorOutOfRangeException(const char *filename, int line, const char *error_message) {
    snprintf(this->message, BUFFER_SIZE, "%s File: %s Line: %d .\n", error_message, filename, line);
}

VectorUnableVectorMultiplicationException::VectorUnableVectorMultiplicationException(const char *filename, int line, const char *error_message) {
    snprintf(this->message, BUFFER_SIZE, "%s File: %s Line: %d .\n", error_message, filename, line);
}


