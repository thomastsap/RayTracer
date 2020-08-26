#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include "vec3.h"

void writeColor(std::ostream &out, color pixelColor)
{
	out << static_cast<int>(255.99 * pixelColor.m_x) << ' '
		<< static_cast<int>(255.99 * pixelColor.m_y) << ' '
		<< static_cast<int>(255.99 * pixelColor.m_z) << '\n';
}

#endif