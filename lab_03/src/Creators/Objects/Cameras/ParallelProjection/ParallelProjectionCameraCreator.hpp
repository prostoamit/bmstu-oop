#ifndef PARALLELPROJECTIONCAMERACREATOR_HPP
#define PARALLELPROJECTIONCAMERACREATOR_HPP

#include <memory>

#include "Creators/Objects/Cameras/CameraCreator.hpp"

class ParallelProjectionCameraCreator : public CameraCreator {
public:
    std::shared_ptr<Camera> create(
            std::shared_ptr<Point> point,
            std::shared_ptr<Vector> forward
    ) override;
};


#endif //PARALLELPROJECTIONCAMERACREATOR_HPP
