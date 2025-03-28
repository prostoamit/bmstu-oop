#ifndef SCENEMANAGERCREATOR_HPP
#define SCENEMANAGERCREATOR_HPP

#include <memory>

#include "Managers/SceneManager/SceneManager.hpp"

class SceneManagerCreator {
public:
    static std::shared_ptr<SceneManager> create();
protected:
    static std::shared_ptr<SceneManager> manager;
};


#endif //SCENEMANAGERCREATOR_HPP
