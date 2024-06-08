#include "StringSource.hpp"

StringSource::StringSource(std::shared_ptr<std::string> string) :
        string(string) {}

void StringSource::validate_offset() {
    if (offset > string->length())
        offset = string->length();
}
const std::string StringSource::read_line(size_t bytes) {
    std::string res = string->substr(offset, bytes);

    offset += bytes;
    validate_offset();

    return res;
}

void StringSource::reset() {
    offset = 0;
}