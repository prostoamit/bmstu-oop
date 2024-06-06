#ifndef CAMERACREATOR_HPP
#define CAMERACREATOR_HPP

#include <memory>

#include "Objects/Invisible/Cameras/Camera.hpp"

class CameraCreator {
public:
    virtual std::shared_ptr<Camera> create(std::shared_ptr<Point> point, std::shared_ptr<Vector> forward) = 0;
};


#endif //CAMERACREATOR_HPP
