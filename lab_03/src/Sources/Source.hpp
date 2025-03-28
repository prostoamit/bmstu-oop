#ifndef SOURCE_HPP
#define SOURCE_HPP

#include <string>

class Source {
public:
    virtual ~Source() = default;

    virtual const std::string read_line(size_t bytes, char separator = '\n') = 0;

    virtual void reset() = 0;
};


#endif //SOURCE_HPP
