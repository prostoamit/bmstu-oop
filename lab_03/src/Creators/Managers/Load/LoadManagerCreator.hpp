#ifndef LOADMANAGERCREATOR_HPP
#define LOADMANAGERCREATOR_HPP

#include <memory>

#include "Managers/LoadManager/LoadManager.hpp"

class LoadManagerCreator {
public:
    static std::shared_ptr<LoadManager> create();
protected:
    static std::shared_ptr<LoadManager> manager;
};


#endif //LOADMANAGERCREATOR_HPP
