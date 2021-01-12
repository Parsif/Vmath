#pragma once

#include "vmath.h"

#include <cmath>

namespace vmath
{
	template<class T>
	struct Vec3
	{
		T x, y, z;
		Vec3(T value) : x(value), y(value), z(value) {}
		Vec3(T value_x, T value_y, T value_z) : x(value_x), y(value_y), z(value_z) {}

		T length() const
		{
			return std::sqrt(x * x + y * y + z * z);
		}

		bool operator ==(const Vec3& other) const
		{
			return x == other.x && y == other.y && z == other.z;
		}

		Vec3<T> operator+(const Vec3& other) const
		{
			return Vec3(x + other.x, y + other.y, z + other.z);
		}

		Vec3<T> operator-(const Vec3& other) const
		{
			return Vec3(x - other.x, y - other.y, z - other.z);
		}

		Vec3<T> operator*(const Vec3& other) const
		{
			return Vec3(x * other.x, y * other.y, z * other.z);
		}

		Vec3<T> operator/(T value) const
		{
			ASSERT(value == 0, "Divinsion by 0")
			float inv = float(1) / value;
			return Vec3(x * inv, y * inv, z * inv);
		}

		Vec3<T>& operator+=(const Vec3& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}


		Vec3<T>& operator-=(const Vec3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}


		Vec3<T>& operator*=(T value)
		{
			x *= value;
			y *= value;
			z *= value;
			return *this;
		}


		Vec3<T>& operator/=(T value)
		{
			ASSERT(value == 0, "Divinsion by 0")
			float inv = float(1) / value;
			x *= inv;
			y *= inv;
			z *= inv;
			return *this;
		}
	};

	using Vec3i = Vec3<int>;
	using Vec3f = Vec3<float>;


	template <class T>
	T dot(const Vec3<T>& v1, const Vec3<T>& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	template<class T>
	Vec3<T> cross(const Vec3<T>& v1, const Vec3<T>& v2)
	{
		return Vec3<T>(v1.y * v2.z - v1.z * v2.y,
					   v2.x * v1.z - v1.x * v2.z,
			           v1.x * v2.y - v2.x * v1.y);
	}
	
	template<class T>
	Vec3<T> normalize(const Vec3<T>& v)
	{
		return v / v.length();
	}
}
