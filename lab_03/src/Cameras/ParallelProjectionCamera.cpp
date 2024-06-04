#include "ParallelProjectionCamera.hpp"

#include <Visitor.hpp>

void ParallelProjectionCamera::accept(std::shared_ptr<Visitor> visitor) {
    visitor->visit(*this);
}
