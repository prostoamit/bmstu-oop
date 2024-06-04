#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>

#include "ObjectComposite.hpp"
#include "Visitor.hpp"

class Scene {
public:
    std::shared_ptr<Object> get_object(size_t id);
    void add_object(std::shared_ptr<Object> object);
    void remove_object(size_t id);

    std::shared_ptr<ObjectComposite> get_composite();

private:
    std::shared_ptr<ObjectComposite> composite;
};


#endif //SCENE_HPP
