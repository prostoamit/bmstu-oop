#include "ParallelProjectionCameraCreator.hpp"

#include "Objects/Invisible/Cameras/ParallelProjectionCamera/ParallelProjectionCamera.hpp"

std::shared_ptr<Camera> ParallelProjectionCameraCreator::create(
        std::shared_ptr<Point> point,
        std::shared_ptr<Vector> forward
) {
    return std::make_shared<ParallelProjectionCamera>(point, forward);
}
