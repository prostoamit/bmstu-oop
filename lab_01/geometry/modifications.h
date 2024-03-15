#ifndef MODIFICATIONS_H
#define MODIFICATIONS_H

struct move_deltas {
    double dx;
    double dy;
    double dz;
};

struct rotate_angles {
    double ox;
    double oy;
    double oz;
};

struct scale_coeffs {
    double kx;
    double ky;
    double kz;
};

#endif // MODIFICATIONS_H
