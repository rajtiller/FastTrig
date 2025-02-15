#include <cmath>
#include <iostream>
#include <numbers>

const double pi = 3.1415926535897932384626433832795028841971693993;

class Approximations
{
public:
    // Taylor series expansion centered at 0
    double atan_taylor_0(double x);
    // Taylor series expansion centered at 1 (for x ≈ 1)
    double atan_taylor_1(double x);
    // Taylor series expansion centered at -1 (for x = -1)
    double atan_taylor_minus_1(double x);

    // Optimized atan(x) selection logic
    // NOTE: This assumes that we will fmod the result to [0, 2pi] later
    double atan2(double y, double x);

    //atan algo
    double atan_func(double y, double x, double (Approximations::*atan_taylor)(double));

    double sin_taylor(double x);

    double cos_taylor(double x);
}; // namespace Approximations

/*
constexpr inline double sin_taylor_0(double x) {





}
*/