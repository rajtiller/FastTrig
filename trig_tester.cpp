#include "trig_tester.h"

// Taylor series expansion centered at 0
double Approximations::atan_taylor_0(double x)
{

    double x2 = x * x;
    return x * (1.0 + x2 * (
        -1.0/3.0 + x2 * (
            1.0/5.0 + x2 * (
                -1.0/7.0 + x2 * (
                    1.0/9.0 + x2 * (
                        -1.0/11.0 + x2 * (
                            1.0/13.0 + x2 * (
                                -1.0/15.0 + x2 * (
                                    1.0/17.0 + x2 * (
                                        -1.0/19.0 + x2 * (
                                            1.0/21.0 + x2 * (
                                                -1.0/23.0 + x2 * (
                                                    1.0/25.0 + x2 * (
                                                        -1.0/27.0 + x2 * (
                                                            1.0/29.0
                                                        )
                                                    )
                                                )
                                            )
                                        )
                                    )
                                )
                            )
                        )
                    )
                )
            )
        )
    ));
}
// Taylor series expansion centered at 1 (for x ≈ 1)
double Approximations::atan_taylor_1(double x) {
    double u = (x - 1) / (x + 1);
    double u2 = u * u;
    return pi / 4 +
           u * (1.0 + u2 * (-1.0 / 3.0 +
                            u2 * (1.0 / 5.0 + u2 * (-1.0 / 7.0 +
                                                     u2 * (1.0 / 9.0 + u2 * (-1.0 / 11.0 +
                                                                              u2 * (1.0 / 13.0 + u2 * (-1.0 / 15.0 +
                                                                                                       u2 * (1.0 / 17.0 + u2 * (-1.0 / 19.0 +
                                                                                                                                u2 * (1.0 / 21.0 + u2 * (-1.0 / 23.0))))))))))));
}

double Approximations::atan_taylor_minus_1(double x) {
    double u = (x + 1) / (x - 1); // Transform x to u where -1 ≤ u ≤ 1
    double u2 = u * u;
    return -pi / 4 -
           u * (1.0 + u2 * (-1.0 / 3.0 +
                            u2 * (1.0 / 5.0 + u2 * (-1.0 / 7.0 + u2 * (1.0 / 9.0 + u2 * (-1.0 / 11.0 +
                                                                                             u2 * (1.0 / 13.0 + u2 * (-1.0 / 15.0 +
                                                                                                                      u2 * (1.0 / 17.0 + u2 * (-1.0 / 19.0 +
                                                                                                                                               u2 * (1.0 / 21.0 + u2 * (-1.0 / 23.0))))))))))));
}

// Optimized atan(x) selection logic
// NOTE: This assumes that we will fmod the result to [0, 2pi] later

double Approximations::atan_func(double y, double x, double (Approximations::*atan_taylor)(double)) {
    
    if (x == 0 && y > 0) {
        return pi/2;
    }
    else if (x == 0 && y < 0) {
        return -pi/2;
    }
    else if (x == 0 && y == 0) {
        return 0;
    }
    else if (x > 0.0)
    {
        return (std::abs(y) > std::abs(x)) ? ((y>=0) ? pi/2 - (this->*atan_taylor)(x/y) 
                                                    : -pi/2 - (this->*atan_taylor)(x/y))
                                            :  (this->*atan_taylor)(y/x);
    } 
    else if (x < 0.0) {

        return (std::abs(y) > std::abs(x)) ? ((y >= 0) ? pi / 2 - (this->*atan_taylor)(x / y) //negative
                                                : -pi / 2 - (this->*atan_taylor)(x / y)) //positive
                                           : ((y >= 0) ? pi + (this->*atan_taylor)(y / x)
                                                : -pi + (this->*atan_taylor)(y / x));
    }
   
   
    return -10;

}


double Approximations::atan2(double y, double x)
{

    if (std::abs(y) >= std::abs(x)) {
        if (x/y >= 0.5) {
            return atan_func(y, x, &Approximations::atan_taylor_1);
        } else if (x/y <= -0.5) {
            return atan_func(y, x, &Approximations::atan_taylor_minus_1);
        } else {
            return atan_func(y, x, &Approximations::atan_taylor_0);
        }
    
    } else {
        if (y/x >= 0.5) {
            return atan_func(y, x, &Approximations::atan_taylor_1);
        } else if (y/x <= -0.5) {
            return atan_func(y, x, &Approximations::atan_taylor_minus_1);
        } else {
            return atan_func(y, x, &Approximations::atan_taylor_0);
        }

    }

}

double Approximations::sin_taylor(double x)
{

    return x + std::pow(x, 3) / 6.0;
}

double Approximations::cos_taylor(double x)
{
    return 1 - (x * x) / 4;
}

/*
constexpr inline double sin_taylor_0(double x) {





}
*/