#include <iostream>
#include "color.h"
#include "sphere.h"
#include "hittable_list.h"
#include "ray_tracer.h"
#include "camera.h"

#define ASPECT_RATIO (16.0 / 9.0)
#define IMAGE_WIDTH 400
#define IMAGE_HEIGHT (static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO))

color rayColor(const ray& r, const hittable& world)
{
	
	hitRecord rec;
	if (world.hit(r, 0, infinity, rec))
	{
		return 0.5 * color(rec.normal.m_x + 1, rec.normal.m_y + 1, rec.normal.m_z + 1);
	}

	// Background
	vec3<double> unitDirection = normalize(r.m_direction);
	// m_y increases untill center, then decreases. It can get negative values
	double t = 0.5 * (unitDirection.m_y + 1.0);
	return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main()
{
	hittable_list world;
	world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
	world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));


	camera cam;
	const int samplesPerPixel = 100;

	std::cout << "P3\n" << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << "\n255\n";
	
	for (int j = IMAGE_HEIGHT - 1; j >= 0; --j)
	{
		std::cerr << "\r Scanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < IMAGE_WIDTH; ++i)
		{
			color accPixelColor{ 0, 0, 0 };
			for (int s = 0; s < samplesPerPixel; s++)
			{
				double u = (i + randomDouble()) / (IMAGE_WIDTH - 1);
				double v = (j + randomDouble()) / (IMAGE_HEIGHT - 1);
				ray r = cam.getRay(u, v);
				accPixelColor += rayColor(r, world);
			}			
			writeColor(std::cout, accPixelColor, samplesPerPixel);
		}
	}
	std::cerr << "\nDone. \n";
}