#include "ParallelProjectionCamera.hpp"

#include "Visitors/Visitor.hpp"

#include "Creators/Transformations/TransformationSolution.hpp"

void ParallelProjectionCamera::accept(std::shared_ptr<Visitor> visitor) {
    visitor->visit(*this);
}

std::shared_ptr<Transformers::Transformer> ParallelProjectionCamera::get_view_transformer() {

    return transformer;
}

ParallelProjectionCamera::ParallelProjectionCamera(std::shared_ptr<Point> point, std::shared_ptr<Vector> forward) :
        point(point),
        forward(forward) {

    auto scale_transformer_creator = Transformers::TransformationSolution::get("scale");
    auto move_to_camera_center = scale_transformer_creator->create(
            1.0,
            1.0,
            0.0
    );

    transformer = move_to_camera_center;
}
