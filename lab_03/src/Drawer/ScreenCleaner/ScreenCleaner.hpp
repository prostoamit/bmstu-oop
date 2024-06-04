#ifndef SCREENCLEANER_HPP
#define SCREENCLEANER_HPP


class ScreenCleaner {
public:
    virtual ~ScreenCleaner() = default;

    virtual void draw() = 0;
};


#endif //SCREENCLEANER_HPP
