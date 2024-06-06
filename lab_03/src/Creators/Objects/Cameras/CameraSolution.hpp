#ifndef CAMERASOLUTION_HPP
#define CAMERASOLUTION_HPP

#include <memory>
#include <string>
#include <map>

#include "Creators/Objects/Cameras/CameraCreator.hpp"

class CameraSolution {
public:
    static std::shared_ptr<CameraCreator> get(const std::string& type);

    static void register_creator(const std::string& type, std::shared_ptr<CameraCreator> creator);
protected:
    static std::map<std::string, std::shared_ptr<CameraCreator>> creators_map;
};


#endif //CAMERASOLUTION_HPP
