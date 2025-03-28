#include "Exceptions/Exception.hpp"

using namespace Exceptions;

const char *Exception::what() const noexcept {
    return message;
}
