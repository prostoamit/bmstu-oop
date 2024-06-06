#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <memory>

#include "Scene/Scene.hpp"

class SceneManager {
public:
    std::shared_ptr<Scene> get_scene() const;
    void set_scene(std::shared_ptr<Scene> scene);

    std::shared_ptr<Object> get_active_object();
    void set_active_object(std::shared_ptr<Object> object);
    std::shared_ptr<Object> get_object(size_t id) const;
    void add_object(std::shared_ptr<Object> object);
    void remove_object(size_t id);

protected:
    SceneManager();
    SceneManager(const SceneManager& other) = default;

private:
    std::shared_ptr<Scene> scene;
};


#endif //SCENEMANAGER_HPP
