#ifndef HITTABLE_H
#define  HITTABLE_H

#include "ray.h"

struct hitRecord
{
	point3 point;
	vec3<double> normal;
	double t;
	bool frontFace;

	inline void setFaceNormal(const ray& r, const vec3<double>& outwardNormal)
	{
		frontFace = dot(r.m_direction, outwardNormal) < 0;
		normal = frontFace ? outwardNormal : -outwardNormal;
	}
};

class hittable
{
public:
	virtual bool hit(const ray& r, double tMin, double tMax, hitRecord& rec) const = 0;
};

#endif 

