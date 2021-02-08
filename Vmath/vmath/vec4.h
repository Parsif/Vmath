#pragma once

#include "vmath.h"
#include "mat4.h"

#include <cmath>



namespace vmath
{
	class Mat4;
	
	template<class T>
	struct Vec4
	{
		T x, y, z, w;
		Vec4() : x(0), y(0), z(0), w(0){}
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

		Vec4<T> operator*(Mat4& mat4)
		{
			Vec4<T> vector;
			vector.x = x * mat4[0][0] + y * mat4[0][1] + z * mat4[0][2] + w * mat4[0][3];
			vector.y = x * mat4[1][0] + y * mat4[1][1] + z * mat4[1][2] + w * mat4[1][3];
			vector.z = x * mat4[2][0] + y * mat4[2][1] + z * mat4[2][2] + w * mat4[2][3];
			vector.w = x * mat4[3][0] + y * mat4[3][1] + z * mat4[3][2] + w * mat4[3][3];
			return vector;
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


		Vec4<T>& operator*=(Mat4& mat4)
		{
			x = x * mat4[0][0] + y * mat4[0][1] + z * mat4[0][2] + w * mat4[0][3];
			y = x * mat4[1][0] + y * mat4[1][1] + z * mat4[1][2] + w * mat4[1][3];
			z = x * mat4[2][0] + y * mat4[2][1] + z * mat4[2][2] + w * mat4[2][3];
			w = x * mat4[3][0] + y * mat4[3][1] + z * mat4[3][2] + w * mat4[3][3];
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
