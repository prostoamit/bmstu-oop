#include "vector_iterator_exceptions.h"

using namespace exceptions;
using namespace vector_iterator_exceptions;

VectorIteratorBaseException::VectorIteratorBaseException(const char *filename, int line, const char *error_message) {
    snprintf(this->message, BUFFER_SIZE, "%s File: %s Line: %d .\n", error_message, filename, line);
}

VectorIteratorDeletedVectorException::VectorIteratorDeletedVectorException(const char *filename, int line, const char *error_message) {
    snprintf(this->message, BUFFER_SIZE, "%s File: %s Line: %d .\n", error_message, filename, line);
}

VectorIteratorOutOfRangeException::VectorIteratorOutOfRangeException(const char *filename, int line, const char *error_message) {
    snprintf(this->message, BUFFER_SIZE, "%s File: %s Line: %d .\n", error_message, filename, line);
}

VectorIteratorDifferentVectorCmpException::VectorIteratorDifferentVectorCmpException(const char *filename, int line, const char *error_message) {
    snprintf(this->message, BUFFER_SIZE, "%s File: %s Line: %d .\n", error_message, filename, line);
}