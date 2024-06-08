#ifndef TXTFILESOURCE_HPP
#define TXTFILESOURCE_HPP

#include <string>
#include <fstream>

#include "Source.hpp"

class TxtFileSource : public Source {
public:
    explicit TxtFileSource(const std::string& path);

    const std::string read_line(size_t bytes, char separator) override;
    void reset() override;
protected:
    std::fstream file_stream;
    const std::string path;
};


#endif //TXTFILESOURCE_HPP
