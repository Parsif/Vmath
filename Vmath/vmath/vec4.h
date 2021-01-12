#pragma once

#include "vmath.h"

#include <cmath>

namespace vmath
{

	template<class T>
	struct Vec4
	{
		T x, y, z, w;
		Vec4(T value) : x(value), y(value), z(value), w(value) {}
		Vec4(T value_x, T value_y, T value_z, T value_w) : x(value_x), y(value_y), z(value_z), w(value_w) {}

		T length() const
		{
			return std::sqrt(x * x + y * y + z * z + w * w);
		}

		bool operator ==(const Vec4& other) const
		{
			return x == other.x && y == other.y && z == other.z && w == other.w;
		}

		Vec4<T> operator+(const Vec4& other) const
		{
			return Vec4(x + other.x, y + other.y, z + other.z, w + other.w);
		}

		Vec4<T> operator-(const Vec4& other) const
		{
			return Vec4(x - other.x, y - other.y, z - other.z, w - other.w);
		}

		Vec4<T> operator*(const Vec4& other) const
		{
			return Vec4(x * other.x, y * other.y, z * other.z, w * other.w);
		}

		Vec4<T> operator/(T value) const
		{
			ASSERT(value == 0, "Divinsion by 0")
			float inv = float(1) / value;
			return Vec4(x * inv, y * inv, z * inv, w * inv);
		}

		Vec4<T>& operator+=(const Vec4& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return *this;
		}


		Vec4<T>& operator-=(const Vec4& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;
			return *this;
		}


		Vec4<T>& operator*=(T value)
		{
			x *= value;
			y *= value;
			z *= value;
			w *= value;
			return *this;
		}


		Vec4<T>& operator/=(T value)
		{
			ASSERT(value == 0, "Divinsion by 0")
			float inv = float(1) / value;
			x *= inv;
			y *= inv;
			z *= inv;
			w *= inv;
			return *this;
		}
	};

	using Vec4i = Vec4<int>;
	using Vec4f = Vec4<float>;

	template<class T>
	Vec4<T> normalize(const Vec4<T>& v)
	{
		return v / v.length();
	}
}