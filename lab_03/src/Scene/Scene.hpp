#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>
#include <map>
#include <string>

#include "ObjectComposite.hpp"

class Scene {
public:
    Scene();

    std::shared_ptr<Object> get_active_object();
    std::string& get_active_object_name();
    void set_active_object(std::shared_ptr<Object> object);
    std::shared_ptr<Object> get_object(const std::string& name);
    void add_object(std::shared_ptr<Object> object, const std::string& name);
    void remove_object(const std::string& name);

    std::map<std::string, std::shared_ptr<Object>>::iterator begin();
    std::map<std::string, std::shared_ptr<Object>>::iterator end();

    std::map<std::string, std::shared_ptr<Object>>& get_objects();

private:
    std::map<std::string, std::shared_ptr<Object>> objects;
    std::shared_ptr<Object> active_object;
    std::string active_object_name;
};


#endif //SCENE_HPP
