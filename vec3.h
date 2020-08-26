#ifndef VEC3_H
#define VEC3_H

#include <cmath>

template <typename T>
struct vec3
{
	T m_x, m_y, m_z;

	vec3() = default;

	vec3(T x, T y, T z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}

	T& operator[] (int index)
	{
		return ((&m_x)[index]);
	}

	const T& operator[] (int index) const
	{
		return ((&m_x)[index]);
	}

	vec3& operator *= (double s)
	{
		m_x *= s;
		m_y *= s;
		m_z *= s;
		return (*this);
	}

	vec3& operator /= (double s)
	{
		s = 1.0f / s;
		m_x *= s;
		m_y *= s;
		m_z *= s;
		return (*this);
	}

	vec3& operator += (const vec3& v)
	{
		m_x += v.x;
		m_y += v.y;
		m_z += v.z;
		return (*this);
	}

	vec3& operator -= (const vec3& v)
	{
		m_x -= v.x;
		m_y -= v.y;
		m_z -= v.z;
		return (*this);
	}
};

template <typename T>
inline vec3<T> operator* (const vec3<T>& v, double s)
{
	return vec3<T>(v.m_x * s, v.m_y * s, v.m_z * s);
}

template <typename T>
inline vec3<T> operator* (double s, const vec3<T>& v)
{
	return vec3<T>(v.m_x * s, v.m_y * s, v.m_z * s);
}

template <typename T>
inline vec3<T> operator/ (const vec3<T>& v, double s)
{
	s = 1.0f / s;
	return vec3<T>(v.m_x * s, v.m_y * s, v.m_z * s);
}

template <typename T>
inline vec3<T> operator- (const vec3<T>& v)
{
	return vec3<T>(-v.m_x, -v.m_y, -v.m_z);
}

template <typename T>
inline double magnitude(const vec3<T>& v)
{
	return (sqrt(v.m_x * v.m_x + v.m_y * v.m_y + v.m_z * v.m_z));
}

template <typename T>
inline double magnitudeSquared(const vec3<T>& v)
{
	return (v.m_x * v.m_x + v.m_y * v.m_y + v.m_z * v.m_z);
}

template <typename T>
inline vec3<T> normalize(const vec3<T>& v)
{
	return vec3<T>(v / magnitude(v));
}

template <typename T>
inline vec3<T> operator+ (const vec3<T>& v1, const vec3<T>& v2)
{
	return vec3<T>(v1.m_x + v2.m_x, v1.m_y + v2.m_y, v1.m_z + v2.m_z);
}

template <typename T>
inline vec3<T> operator- (const vec3<T>& v1, const vec3<T>& v2)
{
	return vec3<T>(v1.m_x - v2.m_x, v1.m_y - v2.m_y, v1.m_z - v2.m_z);
}

template <typename T>
inline double dot(const vec3<T>& v1, const vec3<T>& v2)
{
	return (v1.m_x * v2.m_x + v1.m_y * v2.m_y + v1.m_z * v2.m_z);
}

template <typename T>
inline vec3<T> cross(const vec3<T>& v1, const vec3<T>& v2)
{
	return vec3<T>(	v1.m_y * v2.m_z - v1.m_z * v2.m_y,
					v1.m_z * v2.m_x - v1.m_x * v2.m_z,
					v1.m_x * v2.m_y - v1.m_y - v2.m_x);
}

using point3 = vec3<double>;
using color = vec3<double>;

#endif
