#include "WireframeModel.hpp"

#include "Visitors/Visitor.hpp"
#include <utility>


WireframeModel::WireframeModel::WireframeModel(std::shared_ptr<Implementation> implementation) :
   _implementation(implementation) {

}

void WireframeModel::WireframeModel::accept(std::shared_ptr<Visitor> visitor) {
    visitor->visit(*this);
}