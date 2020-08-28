#ifndef CAMERA_H
#define CAMERA_H

#include "ray_tracer.h"

class camera
{
private:
	point3 m_origin;
	point3 m_lowerLeftCorner;
	vec3<double> m_horizontal;
	vec3<double> m_vertical;

public:
	camera()
	{
		double aspectRatio = 16.0 / 9.0;
		double viewportHeight = 2.0;
		double viewportWidth = aspectRatio * viewportHeight;
		double focalLength = 1.0;

		m_origin = point3(0, 0, 0);
		m_horizontal = vec3<double>(viewportWidth, 0.0, 0.0);
		m_vertical = vec3<double>(0.0, viewportHeight, 0.0);
		m_lowerLeftCorner = m_origin - vec3<double>(0, 0, focalLength) - m_vertical / 2 - m_horizontal / 2;
	}

	ray getRay(double u, double v)
	{
		return ray(m_origin, m_lowerLeftCorner + u * m_horizontal + v * m_vertical - m_origin);
	}
};

#endif 
