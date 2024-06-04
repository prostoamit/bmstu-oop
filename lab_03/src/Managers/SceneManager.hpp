#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <memory>

#include "Scene.hpp"

class SceneManager {
public:
    std::shared_ptr<Scene> get_scene() const;
    void set_scene(std::shared_ptr<Scene> scene);

    std::shared_ptr<Object> get_object(size_t id) const;
    void add_object(std::shared_ptr<Object> object);
    void remove_object(size_t id);

private:
    std::shared_ptr<Scene> scene;
};


#endif //SCENEMANAGER_HPP
