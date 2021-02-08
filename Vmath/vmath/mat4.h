#pragma once

#include "vec3.h"
#include "vec4.h"

#include <array>

namespace vmath
{
	template<class T>
	struct Vec4;
	
	class Mat4
	{

	private:
		struct MatrixRow
		{
			std::array<float, 4> row;
			auto& operator[](const int index)
			{
				return row[index];
			}

			[[nodiscard]] auto begin()  { return row.begin(); }
			[[nodiscard]] auto end()  { return row.end(); }
			[[nodiscard]] auto begin() const { return row.cbegin(); }
			[[nodiscard]] auto end() const  { return row.cend(); }

			[[nodiscard]] auto size() const { return row.size(); }
		};
		
	public:
		[[nodiscard]] auto begin() { return m_matrix.begin(); }
		[[nodiscard]] auto end() { return m_matrix.end(); }
		[[nodiscard]] auto begin() const { return m_matrix.cbegin(); }
		[[nodiscard]] auto end() const { return m_matrix.cend(); }
	
		
		auto& operator[](const int index)
		{
			return m_matrix[index];
		}
		
		Mat4 operator+(const float value)
		{
			Mat4 matrix;
			for (size_t i = 0; i < m_matrix.size(); ++i)
			{
				for (size_t j = 0; j < m_matrix[0].size(); ++j)
				{
					matrix[i][j] = m_matrix[i][j] + value;
				}
			}
			return matrix;
		}
		
		Mat4 operator+(Mat4& mat4)
		{
			Mat4 matrix;
			for (size_t i = 0; i < m_matrix.size(); ++i)
			{
				for (size_t j = 0; j < m_matrix[0].size(); ++j)
				{
					matrix[i][j] = m_matrix[i][j] + mat4[i][j];
				}
			}
			return matrix;
		}

		Mat4 operator-(const float value)
		{
			Mat4 matrix;
			for (size_t i = 0; i < m_matrix.size(); ++i)
			{
				for (size_t j = 0; j < m_matrix[0].size(); ++j)
				{
					matrix[i][j] = m_matrix[i][j] - value;
				}
			}
			return matrix;
		}

		Mat4 operator*(const float value)
		{
			Mat4 matrix;
			for (size_t i = 0; i < m_matrix.size(); ++i)
			{
				for (size_t j = 0; j < m_matrix[0].size(); ++j)
				{
					matrix[i][j] = m_matrix[i][j] * value;
				}
			}
			return matrix;
		}

		Mat4 operator*(Mat4& mat4)
		{
			Mat4 matrix;
			matrix[0][0] = m_matrix[0][0] * mat4[0][0] + m_matrix[0][1] * mat4[1][0] + m_matrix[0][2] * mat4[2][0] + m_matrix[0][3] * mat4[3][0];
			matrix[0][1] = m_matrix[0][0] * mat4[0][1] + m_matrix[0][1] * mat4[1][1] + m_matrix[0][2] * mat4[2][1] + m_matrix[0][3] * mat4[3][1];
			matrix[0][2] = m_matrix[0][0] * mat4[0][2] + m_matrix[0][1] * mat4[1][2] + m_matrix[0][2] * mat4[2][2] + m_matrix[0][3] * mat4[3][2];
			matrix[0][3] = m_matrix[0][0] * mat4[0][3] + m_matrix[0][1] * mat4[1][3] + m_matrix[0][2] * mat4[2][3] + m_matrix[0][3] * mat4[3][3];

			matrix[1][0] = m_matrix[1][0] * mat4[0][0] + m_matrix[1][1] * mat4[1][0] + m_matrix[1][2] * mat4[2][0] + m_matrix[1][3] * mat4[3][0];
			matrix[1][1] = m_matrix[1][0] * mat4[0][1] + m_matrix[1][1] * mat4[1][1] + m_matrix[1][2] * mat4[2][1] + m_matrix[1][3] * mat4[3][1];
			matrix[1][2] = m_matrix[1][0] * mat4[0][2] + m_matrix[1][1] * mat4[1][2] + m_matrix[1][2] * mat4[2][2] + m_matrix[1][3] * mat4[3][2];
			matrix[1][3] = m_matrix[1][0] * mat4[0][3] + m_matrix[1][1] * mat4[1][3] + m_matrix[1][2] * mat4[2][3] + m_matrix[1][3] * mat4[3][3];

			matrix[2][0] = m_matrix[2][0] * mat4[0][0] + m_matrix[2][1] * mat4[1][0] + m_matrix[2][2] * mat4[2][0] + m_matrix[2][3] * mat4[3][0];
			matrix[2][1] = m_matrix[2][0] * mat4[0][1] + m_matrix[2][1] * mat4[1][1] + m_matrix[2][2] * mat4[2][1] + m_matrix[2][3] * mat4[3][1];
			matrix[2][2] = m_matrix[2][0] * mat4[0][2] + m_matrix[2][1] * mat4[1][2] + m_matrix[2][2] * mat4[2][2] + m_matrix[2][3] * mat4[3][2];
			matrix[2][3] = m_matrix[2][0] * mat4[0][3] + m_matrix[2][1] * mat4[1][3] + m_matrix[2][2] * mat4[2][3] + m_matrix[2][3] * mat4[3][3];

			matrix[3][0] = m_matrix[3][0] * mat4[0][0] + m_matrix[3][1] * mat4[1][0] + m_matrix[3][2] * mat4[2][0] + m_matrix[3][3] * mat4[3][0];
			matrix[3][1] = m_matrix[3][0] * mat4[0][1] + m_matrix[3][1] * mat4[1][1] + m_matrix[3][2] * mat4[2][1] + m_matrix[3][3] * mat4[3][1];
			matrix[3][2] = m_matrix[3][0] * mat4[0][2] + m_matrix[3][1] * mat4[1][2] + m_matrix[3][2] * mat4[2][2] + m_matrix[3][3] * mat4[3][2];
			matrix[3][3] = m_matrix[3][0] * mat4[0][3] + m_matrix[3][1] * mat4[1][3] + m_matrix[3][2] * mat4[2][3] + m_matrix[3][3] * mat4[3][3];

			return matrix;
		}
		
		Mat4& operator+=(const float value)
		{
			for (auto&& row : m_matrix)
			{
				for (auto&& elem : row)
				{
					elem += value;
				}
			}
			return *this;
		}

		Mat4& operator+=(Mat4& mat4)
		{
			for (size_t i = 0; i < m_matrix.size(); ++i)
			{
				for (size_t j = 0; j < m_matrix[0].size(); ++j)
				{
					m_matrix[i][j] += mat4[i][j];
				}
			}
			return *this;
		}

		Mat4& operator-=(const float value)
		{
			for (auto&& row : m_matrix)
			{
				for (auto&& elem : row)
				{
					elem -= value;
				}
			}
			return *this;
		}

		Mat4& operator*=(const float value)
		{
			for (auto&& row : m_matrix)
			{
				for (auto&& elem : row)
				{
					elem *= value;
				}
			}
			return *this;
		}
		
		Mat4& operator*=(Mat4& mat4)
		{
			m_matrix[0][0] = m_matrix[0][0] * mat4[0][0] + m_matrix[0][1] * mat4[1][0] + m_matrix[0][2] * mat4[2][0] + m_matrix[0][3] * mat4[3][0];
			m_matrix[0][1] = m_matrix[0][0] * mat4[0][1] + m_matrix[0][1] * mat4[1][1] + m_matrix[0][2] * mat4[2][1] + m_matrix[0][3] * mat4[3][1];
			m_matrix[0][2] = m_matrix[0][0] * mat4[0][2] + m_matrix[0][1] * mat4[1][2] + m_matrix[0][2] * mat4[2][2] + m_matrix[0][3] * mat4[3][2];
			m_matrix[0][3] = m_matrix[0][0] * mat4[0][3] + m_matrix[0][1] * mat4[1][3] + m_matrix[0][2] * mat4[2][3] + m_matrix[0][3] * mat4[3][3];

			m_matrix[1][0] = m_matrix[1][0] * mat4[0][0] + m_matrix[1][1] * mat4[1][0] + m_matrix[1][2] * mat4[2][0] + m_matrix[1][3] * mat4[3][0];
			m_matrix[1][1] = m_matrix[1][0] * mat4[0][1] + m_matrix[1][1] * mat4[1][1] + m_matrix[1][2] * mat4[2][1] + m_matrix[1][3] * mat4[3][1];
			m_matrix[1][2] = m_matrix[1][0] * mat4[0][2] + m_matrix[1][1] * mat4[1][2] + m_matrix[1][2] * mat4[2][2] + m_matrix[1][3] * mat4[3][2];
			m_matrix[1][3] = m_matrix[1][0] * mat4[0][3] + m_matrix[1][1] * mat4[1][3] + m_matrix[1][2] * mat4[2][3] + m_matrix[1][3] * mat4[3][3];

			m_matrix[2][0] = m_matrix[2][0] * mat4[0][0] + m_matrix[2][1] * mat4[1][0] + m_matrix[2][2] * mat4[2][0] + m_matrix[2][3] * mat4[3][0];
			m_matrix[2][1] = m_matrix[2][0] * mat4[0][1] + m_matrix[2][1] * mat4[1][1] + m_matrix[2][2] * mat4[2][1] + m_matrix[2][3] * mat4[3][1];
			m_matrix[2][2] = m_matrix[2][0] * mat4[0][2] + m_matrix[2][1] * mat4[1][2] + m_matrix[2][2] * mat4[2][2] + m_matrix[2][3] * mat4[3][2];
			m_matrix[2][3] = m_matrix[2][0] * mat4[0][3] + m_matrix[2][1] * mat4[1][3] + m_matrix[2][2] * mat4[2][3] + m_matrix[2][3] * mat4[3][3];

			m_matrix[3][0] = m_matrix[3][0] * mat4[0][0] + m_matrix[3][1] * mat4[1][0] + m_matrix[3][2] * mat4[2][0] + m_matrix[3][3] * mat4[3][0];
			m_matrix[3][1] = m_matrix[3][0] * mat4[0][1] + m_matrix[3][1] * mat4[1][1] + m_matrix[3][2] * mat4[2][1] + m_matrix[3][3] * mat4[3][1];
			m_matrix[3][2] = m_matrix[3][0] * mat4[0][2] + m_matrix[3][1] * mat4[1][2] + m_matrix[3][2] * mat4[2][2] + m_matrix[3][3] * mat4[3][2];
			m_matrix[3][3] = m_matrix[3][0] * mat4[0][3] + m_matrix[3][1] * mat4[1][3] + m_matrix[3][2] * mat4[2][3] + m_matrix[3][3] * mat4[3][3];

			return *this;
		}



		void inverse()
		{

		}

	
		
		[[nodiscard]] static auto identity()
		{
			Mat4 mat4;
			for (size_t i = 0; i < mat4[0].size(); ++i)
			{
				mat4[i][i] = 1;
			}
			return mat4;
		}

		[[nodiscard]] static auto perspective(float aspect_ration, float fov, float near_z, float far_z)
		{
			Mat4 mat4;
			
			mat4[3][2] = -1;
			
			return mat4;
		}

		[[nodiscard]] static auto ortho(float width, float height, float z_near_plane, float z_far_plane)
		{

		}

		template<class T>
		[[nodiscard]] static auto look_at(const Vec3<T>& eye, const Vec3<T>& up, const Vec3<T>& center)
		{
			Vec3f x, y, z;
			z = normalize(eye - center);
			y = up;
			x = cross(y, z);
			y = cross(x, z);

			Mat4 look_at_matrix;
			look_at_matrix[0][0] = x.x;
			look_at_matrix[0][1] = x.y;
			look_at_matrix[0][2] = x.z;

			look_at_matrix[1][0] = y.x;
			look_at_matrix[1][1] = y.y;
			look_at_matrix[1][2] = y.z;

			look_at_matrix[2][0] = z.x;
			look_at_matrix[2][1] = z.y;
			look_at_matrix[2][2] = z.z;

			look_at_matrix[3][3] = 1;
			return look_at_matrix;
		}
		
	private:
		std::array<MatrixRow, 4> m_matrix;
	};

	template<class T>
	void translate(Mat4& mat4, Vec3<T>& vec3)
	{
		mat4[0][3] += vec3.x;
		mat4[1][3] += vec3.y;
		mat4[2][3] += vec3.z;
	}

	template<class T>
	void scale(Mat4& mat4, Vec3<T>& vec3)
	{
		mat4[0][0] += vec3.x;
		mat4[1][1] += vec3.y;
		mat4[2][2] += vec3.z;
	}

	void rotate()
	{

	}
}
