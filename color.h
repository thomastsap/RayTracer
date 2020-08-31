#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include "ray_tracer.h"

void writeColor(std::ostream &out, color pixelColor, int samplesPerPixel)
{
	double r = pixelColor.m_x;
	double g = pixelColor.m_y;
	double b = pixelColor.m_z;

	double scale = 1.0 / samplesPerPixel;
	r = sqrt(scale * r);
	g = sqrt(scale * g);
	b = sqrt(scale * b);


	out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
		<< static_cast<int>(255.99 * clamp(g, 0.0, 0.999)) << ' '
		<< static_cast<int>(255.99 * clamp(b, 0.0, 0.999)) << '\n';
}

#endif