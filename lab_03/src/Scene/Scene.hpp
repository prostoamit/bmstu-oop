#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>

#include "Objects/Composite/ObjectComposite.hpp"

class Scene {
public:
    Scene();

    std::shared_ptr<Object> get_active_object();
    void set_active_object(std::shared_ptr<Object> object);
    std::shared_ptr<Object> get_object(size_t id);
    void add_object(std::shared_ptr<Object> object);
    void remove_object(size_t id);

    ObjectComposite::iterator begin();
    ObjectComposite::iterator end();

    std::shared_ptr<ObjectComposite> get_objects();

private:
    std::shared_ptr<ObjectComposite> objects;
    std::shared_ptr<Object> active_object;
};


#endif //SCENE_HPP
