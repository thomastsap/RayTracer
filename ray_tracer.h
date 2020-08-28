#ifndef RAY_TRACER_H
#define RAY_TRACER_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include "vec3.h"
#include "ray.h"
#include "random"

inline double randomDouble()
{
	static std::uniform_real_distribution<double> distribution(0.0, 1.0);
	static std::mt19937 generator;
	return distribution(generator);
}

inline double clamp(double x, double min, double max)
{
	if (x < min) return min;
	if (x > max) return max;
	return x;
}

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degreesToRadians(double degrees)
{
	return degrees * pi / 180.0;
}



#endif 

