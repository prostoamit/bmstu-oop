#include "ParallelProjectionCameraCreator.hpp"

#include "Objects/Invisible/Cameras/ParallelProjectionCamera/ParallelProjectionCamera.hpp"

ParallelProjectionCameraCreator::ParallelProjectionCameraCreator(
        std::shared_ptr<Point> point,
        std::shared_ptr<Vector> forward
) :
        point(point),
        forward(forward) {
}

std::shared_ptr<Object> ParallelProjectionCameraCreator::create() {
    return std::make_shared<ParallelProjectionCamera>(point, forward);
}
