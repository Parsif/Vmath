#pragma once

#include "vmath.h"

#include <cmath>
#include <iostream>


namespace vmath
{
	template<class T>
	struct Vec2
	{
		T x, y;
		Vec2(T value) : x(value), y(value){}
		Vec2(T value_x, T value_y) : x(value_x), y(value_y) {}

		T length() const
		{
			return std::sqrt(x * x + y * y);
		}

		bool operator ==(const Vec2& other) const
		{
			return x == other.x && y == other.y;
		}
		
		Vec2<T> operator+(const Vec2& other) const
		{
			return Vec2(x + other.x, y + other.y);
		}
		
		Vec2<T> operator-(const Vec2& other) const 
		{
			return Vec2(x - other.x, y - other.y);
		}

		Vec2<T> operator*(const Vec2& other) const
		{
			return Vec2(x * other.x, y * other.y);
		}

		Vec2<T> operator/(T value) const
		{
			ASSERT(value == 0, "Divinsion by 0")
			float inv = float(1) / value;
			return Vec2(x * inv, y * inv);
		}

		Vec2<T>& operator+=(const Vec2& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}


		Vec2<T>& operator-=(const Vec2& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}


		Vec2<T>& operator*=(T value)
		{
			x *= value;
			y *= value;
			return *this;
		}


		Vec2<T>& operator/=(T value)
		{
			ASSERT(value == 0, "Divinsion by 0")
			float inv = float(1) / value;
			x *= inv;
			y *= inv;
			return *this;
		}
	};

	using Vec2i = Vec2<int>;
	using Vec2f = Vec2<float>;

	template <class T>
	T dot(const Vec2<T>& v1, const Vec2<T>& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	template<class T>
	Vec2<T> normalize(const Vec2<T>& v)
	{
		return v / v.length();
	}
	
}
