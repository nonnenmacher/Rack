#pragma once

#include <cmath>


namespace rack {


inline float sinc(float x) {
	if (x == 0.f)
		return 1.f;
	x *= M_PI;
	return sinf(x) / x;
}

inline float quadraticBipolar(float x) {
	float x2 = x*x;
	return (x >= 0.f) ? x2 : -x2;
}

inline float cubic(float x) {
	return x*x*x;
}

inline float quarticBipolar(float x) {
	float y = x*x*x*x;
	return (x >= 0.f) ? y : -y;
}

inline float quintic(float x) {
	// optimal with --fast-math
	return x*x*x*x*x;
}

inline float sqrtBipolar(float x) {
	return (x >= 0.f) ? sqrtf(x) : -sqrtf(-x);
}

/** This is pretty much a scaled sinh */
inline float exponentialBipolar(float b, float x) {
	const float a = b - 1.f / b;
	return (powf(b, x) - powf(b, -x)) / a;
}


} // namespace rack
