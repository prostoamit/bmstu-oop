#ifndef DRAWMANAGERCREATOR_HPP
#define DRAWMANAGERCREATOR_HPP

#include <memory>

#include "Managers/DrawManager/DrawManager.hpp"

class DrawManagerCreator {
public:
    static std::shared_ptr<DrawManager> create();
protected:
    static std::shared_ptr<DrawManager> manager;
};


#endif //DRAWMANAGERCREATOR_HPP
