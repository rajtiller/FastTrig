#include "trig_tester.h"

// Taylor series expansion centered at 0
double Approximations::atan_taylor_0(double x)
{
    if (std::abs(x) > 1.0) {
        return (x > 0 ? M_PI_2 : -M_PI_2) - atan_taylor_0(1.0 / x);
    }

    double x2 = x * x;
    return x *
           (1.0 + x2 * (-1.0 / 3.0 + x2 * (1.0 / 5.0 + x2 * (-1.0 / 7.0 + x2 * (1.0 / 9.0 + x2 * (-1.0 / 11.0))))));
}
// Taylor series expansion centered at 1 (for x ≈ 1)
double Approximations::atan_taylor_1(double x)
{
    double u = (x - 1) / (x + 1); // Transform x to u where -1 ≤ u ≤ 1
    double u2 = u * u;
    return pi / 4 +
           u * (1.0 + u2 * (-1.0 / 3.0 +
                            u2 * (1.0 / 5.0 + u2 * (-1.0 / 7.0 + u2 * (1.0 / 9.0 + u2 * (-1.0 / 11.0))))));
}
// Optimized atan(x) selection logic
// NOTE: This assumes that we will fmod the result to [0, 2pi] later
double Approximations::atan2(double y, double x)
{
    
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
        return (std::abs(y) > std::abs(x)) ? ((y>=0) ? pi/2 - atan_taylor_0(x/y) 
                                                    : -pi/2 - atan_taylor_0(x/y))
                                            :  atan_taylor_0(y/x);
        
    } 
    else if (x < 0.0) {

        return (std::abs(y) > std::abs(x)) ? ((y >= 0) ? pi / 2 - atan_taylor_0(x / y) //negative
                                                : -pi / 2 - atan_taylor_0(x / y)) //positive
                                           : ((y >= 0) ? pi + atan_taylor_0(y / x)
                                                : -pi + atan_taylor_0(y / x));
    }
   

    // {
    //     return (y > 0.0) ? pi / 2 : (y < 0.0 ? -pi / 2 : 0.0);
    // }


    // else if (x < 0.0)
    // {
    //     return (std::abs(y) > std::abs(x)) ? ((y > 0) ? pi / 2 - atan_taylor_0(x / y)
    //                                                   : -pi / 2 - atan_taylor_0(x / y))
    //                                        : ((y >= 0) ? pi + atan_taylor_0(y / x)
    //                                                    : -pi + atan_taylor_0(y / x));
    // }
   
    return -10;
    // Normalize the angle using fmod for circular wrap-around
    // return std::fmod(angle + TWO_PI, TWO_PI);
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