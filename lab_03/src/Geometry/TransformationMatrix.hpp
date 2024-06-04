#ifndef TRANSFORMATIONMATRIX_HPP
#define TRANSFORMATIONMATRIX_HPP

#include <array>

//#include <gsl/

class TransformationMatrix {
private:
    std::array<std::array<double, 4>, 4> data;
};


#endif //TRANSFORMATIONMATRIX_HPP
