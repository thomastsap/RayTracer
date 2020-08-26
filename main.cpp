#include <iostream>
#include "vec3.h"
#include "color.h"
#include "ray.h"

#define ASPECT_RATIO (16.0 / 9.0)
#define IMAGE_WIDTH 400
#define IMAGE_HEIGHT (static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO))

bool hit_sphere(const point3& center, double radius, const ray& r)
{
	vec3<double> CA = r.m_origin - center;
	double A = dot(r.m_direction, r.m_direction);
	double B = 2 * dot(r.m_direction, CA);
	double C = dot(CA, CA) - radius * radius;
	double discriminant = B * B - 4 * A * C;
	return (discriminant > 0);
}

color rayColor(const ray& r)
{
	if (hit_sphere(point3(0, 0, -1), -0.5, r))
		return color(0.5, 0, 0);
	vec3<double> unitDirection = normalize(r.m_direction);
	// m_y increases untill center, then decreases. It can get negative values
	double t = 0.5 * (unitDirection.m_y + 1.0);
	return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main()
{
	double viewportHeight = 2.0;
	double viewportWidth = viewportHeight * ASPECT_RATIO;
	double focalLength = 1.0; 

	point3 origin{ 0, 0, 0 };
	vec3<double> horizontal{ viewportWidth, 0, 0 };
	vec3<double> vertical{ 0, viewportHeight, 0 };
	point3 lowerLeftCorner = origin - vec3<double>(0, 0, focalLength) - vertical / 2 - horizontal / 2;


	std::cout << "P3\n" << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << "\n255\n";

	
	for (int j = IMAGE_HEIGHT - 1; j >= 0; --j)
	{
		std::cerr << "\r Scanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < IMAGE_WIDTH; ++i)
		{
			double u = (double(i) + 0.5) / IMAGE_WIDTH;
			double v = (double(j) + 0.5) / IMAGE_HEIGHT;
			ray r{ origin, lowerLeftCorner + u * horizontal + v * vertical - origin };
			color pixelColor = rayColor(r);
			writeColor(std::cout, pixelColor);
		}
	}
	std::cerr << "\nDone. \n";
}