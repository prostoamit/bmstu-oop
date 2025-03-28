#ifndef PARALLELPROJECTIONCAMERACREATOR_HPP
#define PARALLELPROJECTIONCAMERACREATOR_HPP

#include <memory>

#include "Objects/Invisible/Cameras/CameraCreator.hpp"

class ParallelProjectionCameraCreator : public CameraCreator {
public:
    ParallelProjectionCameraCreator(std::shared_ptr<Point> point, std::shared_ptr<Vector> forward);

    std::shared_ptr<Object> create() override;
private:
    std::shared_ptr<Point> point;
    std::shared_ptr<Vector> forward;
};


#endif //PARALLELPROJECTIONCAMERACREATOR_HPP
