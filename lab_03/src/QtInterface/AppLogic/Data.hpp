#ifndef DATA_HPP
#define DATA_HPP

#include <memory>
#include <map>
#include <string>

class Data {
public:
    void add_object(const std::string& name, size_t id);
    void remove_object(const std::string& name);
    std::pair<std::string, size_t> set_active_object(const std::string& name);
    std::pair<std::string, size_t> get_active_object();

    std::map<std::string, size_t>& get_objects();


    void add_camera(const std::string& name, size_t id);
    void remove_camera(const std::string& name);
    std::pair<std::string, size_t> set_active_camera(const std::string& name);
    std::pair<std::string, size_t> get_active_camera();
    std::map<std::string, size_t>& get_cameras();

private:
    std::map<std::string, size_t> objects;
    std::pair<std::string, size_t> active_object;

    std::map<std::string, size_t> cameras;
    std::pair<std::string, size_t> active_camera;
};


#endif //DATA_HPP
