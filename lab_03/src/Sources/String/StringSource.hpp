#ifndef STRINGSOURCE_HPP
#define STRINGSOURCE_HPP

#include <string>
#include <memory>
#include "Source.hpp"

class StringSource : public Source {
public:
    StringSource(std::shared_ptr<std::string> string);

    const std::string read_line(size_t bytes, char separator) override;
    virtual void reset() override;
private:
    std::shared_ptr<std::string> string;
    size_t offset = 0;

    void validate_offset();
};


#endif //STRINGSOURCE_HPP
