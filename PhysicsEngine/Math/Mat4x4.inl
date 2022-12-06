#pragma once
#include <PhysicsEngine/Math/Vector4.h>

PE_NAMESPACE_BEGIN

inline Mat4x4::Mat4x4(Vector4 c1, Vector4 c2, Vector4 c3, Vector4 c4)
{
	m_Cols[0] = c1;
	m_Cols[1] = c2;
	m_Cols[2] = c3;
	m_Cols[3] = c4;
}

Mat4x4 Mat4x4::Identity()
{
	return Mat4x4(
		Vector4(1, 0, 0, 0),
		Vector4(0, 1, 0, 0),
		Vector4(0, 0, 1, 0),
		Vector4(0, 0, 0, 1)
	);
}

Mat4x4 Mat4x4::operator*(Mat4x4 rhs) const
{
	Mat4x4 result = {};

	for (int i = 0; i < 4; ++i)
	{
		result.m_Cols[i] = m_Cols[0] * rhs.m_Cols[i].m_Value32[0]
			+ m_Cols[1] * rhs.m_Cols[i].m_Value32[1]
			+ m_Cols[2] * rhs.m_Cols[i].m_Value32[2]
			+ m_Cols[3] * rhs.m_Cols[i].m_Value32[3];
	}

	return result;
}

Mat4x4 Mat4x4::operator+(Mat4x4 rhs) const
{
	Mat4x4 result = {};

	for (int i = 0; i < 4; i++)
		result.m_Cols[i] = m_Cols[i] + rhs.m_Cols[i];

	return result;
}

Mat4x4 Mat4x4::operator-(Mat4x4 rhs) const
{
	Mat4x4 result = {};

	for (int i = 0; i < 4; i++)
		result.m_Cols[i] = m_Cols[i] - rhs.m_Cols[i];

	return result;
}

Mat4x4 Mat4x4::operator*(float s) const
{
	Vector4 multiplier = Vector4::Fill(s);
	Mat4x4 result = {};

	for (int i = 0; i < 4; i++)
		result.m_Cols[i] = m_Cols[i] * multiplier;

	return result;
}

Mat4x4 Mat4x4::operator+(float s) const
{
	Mat4x4 result = {};

	for (int i = 0; i < 4; i++)
		result.m_Cols[i] = m_Cols[i] + s;

	return result;
}

Mat4x4 Mat4x4::operator-(float s) const
{
	Mat4x4 result = {};

	for (int i = 0; i < 4; i++)
		result.m_Cols[i] = m_Cols[i] - s;

	return result;
}

Mat4x4& Mat4x4::operator*=(Mat4x4 rhs)
{
	return *this = *this * rhs;
}

Mat4x4& Mat4x4::operator+=(Mat4x4 rhs)
{
	for (int i = 0; i < 4; i++)
		m_Cols[i] += rhs.m_Cols[i];

	return *this;
}

Mat4x4& Mat4x4::operator-=(Mat4x4 rhs)
{
	for (int i = 0; i < 4; i++)
		m_Cols[i] -= rhs.m_Cols[i];

	return *this;
}

Mat4x4& Mat4x4::operator*=(float s)
{
	return *this = *this * s;
}

Mat4x4& Mat4x4::operator+=(float s)
{
	for (int i = 0; i < 4; i++)
		m_Cols[i] += s;

	return *this;
}

Mat4x4& Mat4x4::operator-=(float s)
{
	for (int i = 0; i < 4; i++)
		m_Cols[i] -= s;

	return *this;
}

Mat4x4 Mat4x4::Transposed() const
{
	Mat4x4 result = {};

	for (int c = 0; c < 4; c++)
		for (int r = 0; r < 4; r++)
			result.m_Cols[r].m_Value32[c] = m_Cols[c].m_Value32[r];

	return result;
}

PE_NAMESPACE_END
