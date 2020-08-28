#ifndef HITTABLE_LIST
#define HITTABLE_LIST

#include "hittable.h"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable
{
public:
	std::vector<shared_ptr<hittable>> objects;

	hittable_list() {}
	hittable_list(shared_ptr<hittable> object) { add(object); }

	void clear()
	{
		objects.clear();
	}

	void add(shared_ptr<hittable> object)
	{
		objects.push_back(object);
	}

	virtual bool hit(const ray& r, double tMin, double tMax, hitRecord& rec) const override;
};

bool hittable_list::hit(const ray& r, double tMin, double tMax, hitRecord& rec) const
{
	hitRecord tempRec;
	bool hitAnything = false;
	double tClosestSoFar = tMax;

	for (const auto& object : objects)
	{
		if (object->hit(r, tMin, tClosestSoFar, tempRec))
		{
			hitAnything = true;
			tClosestSoFar = tempRec.t;
			rec = tempRec;
		}
	}
	return hitAnything;
}

#endif // !HITTABLE_LIST

