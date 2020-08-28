#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable
{
public:
	point3 m_center;
	double m_radius;

	sphere() {}
	sphere(point3 center, double radius)
		: m_center{ center }, m_radius{radius} {}

	virtual bool hit(const ray& r, double tMin, double tMax, hitRecord& rec) const override;
};

bool sphere::hit(const ray& r, double tMin, double tMax, hitRecord& rec) const
{
	vec3<double> CA = r.m_origin - m_center;
	double A = magnitudeSquared(r.m_direction);
	double halfB = dot(r.m_direction, CA);
	double C = magnitudeSquared(CA) - m_radius * m_radius;
	double discriminant = halfB * halfB - A * C;

	if (discriminant > 0)
	{
		double rootOfDiscriminant = sqrt(discriminant);

		double smallestT = (-halfB - rootOfDiscriminant) / A;
		if (smallestT < tMax && smallestT > tMin)
		{
			rec.t = smallestT;
			rec.point = r.at(smallestT);
			vec3<double> outwardNormal = (rec.point - m_center) / m_radius;
			rec.setFaceNormal(r, outwardNormal);
			return true;
		}

		double largestT = (-halfB + rootOfDiscriminant) / A;
		if (largestT < tMax && largestT > tMin)
		{
			rec.t = largestT;
			rec.point = r.at(largestT);
			rec.normal = (rec.point - m_center) / m_radius;
			vec3<double> outwardNormal = (rec.point - m_center) / m_radius;
			rec.setFaceNormal(r, outwardNormal);
			return true;
		}
	}
	return false;
}

#endif 
