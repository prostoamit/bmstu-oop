#ifndef PARALLELPROJECTIONCAMERA_HPP
#define PARALLELPROJECTIONCAMERA_HPP

#include <memory>

#include "Objects/Invisible/Cameras/Camera.hpp"

#include "Geometry/Point.hpp"
#include "Geometry/Vector.hpp"

class TransformVisitor;

class ParallelProjectionCamera : public Camera {
public:
    ParallelProjectionCamera(std::shared_ptr<Point> point, std::shared_ptr<Vector> forward);

    void accept(std::shared_ptr<Visitor> visitor) override;

    friend TransformVisitor;
protected:
    std::shared_ptr<Point> point;

    std::shared_ptr<Vector> forward;
    std::shared_ptr<Vector> up;

    std::shared_ptr<Transformers::Transformer> get_view_transformer() override;
    std::shared_ptr<Transformers::Transformer> transformer;
};


#endif //PARALLELPROJECTIONCAMERA_HPP
