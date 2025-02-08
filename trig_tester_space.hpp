#ifndef SIMULATOR_APPROXIMATIONS_H
#define SIMULATOR_APPROXIMATIONS_H
#include <cmath>
#include <iostream>
#include <numbers>
namespace Approximations {
	// Taylor series expansion centered at 0
	constexpr inline double atan_taylor_0(double x) {
		double x2 = x * x;
		return x *
			   (1.0 + x2 * (-1.0 / 3.0 + x2 * (1.0 / 5.0 + x2 * (-1.0 / 7.0 + x2 * (1.0 / 9.0 + x2 * (-1.0 / 11.0))))));
	}
	// Taylor series expansion centered at 1 (for x ≈ 1)
	constexpr inline double atan_taylor_1(double x) {
		double u = (x - 1) / (x + 1);  // Transform x to u where -1 ≤ u ≤ 1
		double u2 = u * u;
		return std::numbers::pi / 4 +
			   u * (1.0 + u2 * (-1.0 / 3.0 +
								   u2 * (1.0 / 5.0 + u2 * (-1.0 / 7.0 + u2 * (1.0 / 9.0 + u2 * (-1.0 / 11.0))))));
	}
	// Optimized atan(x) selection logic
	// NOTE: This assumes that we will fmod the result to [0, 2pi] later
	constexpr inline double atan2(double y, double x) {
		double angle;
		if (x > 0.0) {
			angle = (std::abs(y) > std::abs(x)) ? (std::numbers::pi / 2 - atan_taylor_0(x / y)) : atan_taylor_0(y / x);
		} else if (x < 0.0) {
			angle = (std::abs(y) > std::abs(x)) ? ((y > 0) ? std::numbers::pi / 2 - atan_taylor_0(x / y)
														   : -std::numbers::pi / 2 - atan_taylor_0(x / y))
												: ((y >= 0) ? std::numbers::pi + atan_taylor_0(y / x)
															: -std::numbers::pi + atan_taylor_0(y / x));
		} else {
			angle = (y > 0.0) ? std::numbers::pi / 2 : (y < 0.0 ? -std::numbers::pi / 2 : 0.0);
		}
		return angle;
		// Normalize the angle using fmod for circular wrap-around
		// return std::fmod(angle + TWO_PI, TWO_PI);
	}
}  // namespace Approximations
#endif  // SIMULATOR_APPROXIMATIONS_H





7:13