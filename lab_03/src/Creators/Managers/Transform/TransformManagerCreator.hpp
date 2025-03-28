#ifndef TRANSFORMMANAGERCREATOR_HPP
#define TRANSFORMMANAGERCREATOR_HPP

#include <memory>

#include "Managers/TransformManager/TransformManager.hpp"

class TransformManagerCreator {
public:
    static std::shared_ptr<TransformManager> create();
protected:
    static std::shared_ptr<TransformManager> manager;
};


#endif //TRANSFORMMANAGERCREATOR_HPP
