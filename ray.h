#ifndef RAY_H
#define RAY_H

class ray
{
public:
	point3 m_origin;
	vec3<double> m_direction;

	ray() {}
	ray(const point3& origin, const vec3<double>& direction)
		: m_origin{ origin }, m_direction{ direction } {}

	point3 at(double t) const
	{
		return m_origin + t * m_direction;
	}
};

#endif 

