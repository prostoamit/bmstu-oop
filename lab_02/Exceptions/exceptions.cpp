#include "exceptions.h"

using namespace exceptions;

const char *BaseException::what() const noexcept {
    return message.c_str();
}

DivisionByZeroException::DivisionByZeroException(const std::string &filename, int line, std::string error_message) {
    message = error_message + " File: " + filename +
              " Line: " + std::to_string(line) + ".\n";
}

MemoryAllocationException::MemoryAllocationException(const std::string &filename, int line, std::string error_message) {
    message = error_message + " File: " + filename +
              " Line: " + std::to_string(line) + ".\n";
}

DeletedObjectException::DeletedObjectException(const std::string &filename, int line, std::string error_message) {
    message = error_message + " File: " + filename +
              " Line: " + std::to_string(line) + ".\n";
}

OutOfRangeException::OutOfRangeException(const std::string &filename, int line, std::string error_message) {
    message = error_message + " File: " + filename +
              " Line: " + std::to_string(line) + ".\n";
}

DifferentVectorIteratorCmpException::DifferentVectorIteratorCmpException(const std::string &filename, int line, std::string error_message) {
    message = error_message + " File: " + filename +
              " Line: " + std::to_string(line) + ".\n";
}

DifferentVectorSizeException::DifferentVectorSizeException(const std::string &filename, int line, std::string error_message) {
    message = error_message + " File: " + filename +
              " Line: " + std::to_string(line) + ".\n";
}

UnableVectorMultiplicationException::UnableVectorMultiplicationException(const std::string &filename, int line, std::string error_message) {
    message = error_message + " File: " + filename +
              " Line: " + std::to_string(line) + ".\n";
}
