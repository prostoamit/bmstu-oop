#include "TxtFileSource.hpp"

#include <memory>

TxtFileSource::TxtFileSource(const std::string& path) :
        path(path),
        file_stream(std::fstream(path, std::fstream::in)) {}

const std::string TxtFileSource::read_line(size_t bytes, char separator) {
    auto raw_string = std::make_shared<char[]>(bytes);
    file_stream.getline(raw_string.get(), bytes);
    std::string tmp(raw_string.get());
    return tmp;
}

void TxtFileSource::reset() {
    file_stream.clear();
    file_stream.seekg(0, std::fstream ::beg);
}