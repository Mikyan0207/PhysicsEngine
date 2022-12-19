#pragma once
#include <PhysicsEngine/Math/Math.h>
#include <PhysicsEngine/Math/Vector3.h>

PE_NAMESPACE_BEGIN

#define M(c, r) m_Cols[c].m_Value32[r]

Mat3x3::Mat3x3(Vector3 c1, Vector3 c2, Vector3 c3)
{
	m_Cols[0] = c1;
	m_Cols[1] = c2;
	m_Cols[2] = c3;
}

Mat3x3 Mat3x3::Identity()
{
	return Mat3x3(
		Vector3(1, 0, 0),
		Vector3(0, 1, 0),
		Vector3(0, 0, 1)
	);
}

Mat3x3 Mat3x3::operator*(Mat3x3 rhs) const
{
	Mat3x3 result = {};

	for (int i = 0; i < 3; ++i)
	{
	    result.m_Cols[i] = m_Cols[0] * rhs.m_Cols[i].m_Value32[0]
		    + m_Cols[1] * rhs.m_Cols[i].m_Value32[1]
		    + m_Cols[2] * rhs.m_Cols[i].m_Value32[2];
    }

	return result;
}

Mat3x3 Mat3x3::operator+(Mat3x3 rhs) const
{
	Mat3x3 result = {};

	for (int i = 0; i < 3; i++)
		result.m_Cols[i] = m_Cols[i] + rhs.m_Cols[i];

	return result;
}

Mat3x3 Mat3x3::operator-(Mat3x3 rhs) const
{
	Mat3x3 result = {};

	for (int i = 0; i < 3; i++)
		result.m_Cols[i] = m_Cols[i] - rhs.m_Cols[i];

	return result;
}

Mat3x3 Mat3x3::operator*(float s) const
{
	Vector3 multiplier = Vector3::Fill(s);
	Mat3x3 result = {};

	for (int i = 0; i < 3; i++)
		result.m_Cols[i]= m_Cols[i] * multiplier;

	return result;
}

Mat3x3 Mat3x3::operator+(float s) const
{
	Mat3x3 result = {};

	for (int i = 0; i < 3; i++)
		result.m_Cols[i] = m_Cols[i] + s;

	return result;
}

Mat3x3 Mat3x3::operator-(float s) const
{
	Mat3x3 result = {};

	for (int i = 0; i < 3; i++)
		result.m_Cols[i] = m_Cols[i] - s;

	return result;
}

Mat3x3& Mat3x3::operator*=(Mat3x3 rhs)
{
	return *this = *this * rhs;
}

Mat3x3& Mat3x3::operator+=(Mat3x3 rhs)
{
	for (int i = 0; i < 3; i++)
		m_Cols[i] += rhs.m_Cols[i];

	return *this;
}

Mat3x3& Mat3x3::operator-=(Mat3x3 rhs)
{
	for (int i = 0; i < 3; i++)
		m_Cols[i] -= rhs.m_Cols[i];

	return *this;
}

Mat3x3& Mat3x3::operator*=(float s)
{
	Vector3 multiplier = Vector3::Fill(s);

	for (int i = 0; i < 3; i++)
		m_Cols[i] *= multiplier;

	return *this;
}

Mat3x3& Mat3x3::operator+=(float s)
{
	for (int i = 0; i < 3; i++)
		m_Cols[i] += s;

	return *this;
}

Mat3x3& Mat3x3::operator-=(float s)
{
	for (int i = 0; i < 3; i++)
		m_Cols[i] -= s;

	return *this;
}

Mat3x3 Mat3x3::Transposed() const
{
	Mat3x3 result = {};

	for (int c = 0; c < 3; c++)
		for (int r = 0; r < 3; r++)
			result.m_Cols[r].m_Value32[c] = m_Cols[c].m_Value32[r];

	return result;
}

float Mat3x3::Determinant() const
{
	return + M(0, 0) * (M(1, 1) * M(2, 2) - M(2, 1) * M(1, 2))
		- M(1, 0) * (M(0, 1) * M(2, 2) - M(2, 1) * M(0, 2))
		+ M(2, 0) * (M(0, 1) * M(1, 2) - M(1, 1) * M(0, 2));
}

Mat3x3 Mat3x3::Cofactor() const
{
	return Mat3x3(
		Vector3(
			+(M(1, 1) * M(2, 2) - M(1, 2) * M(2, 1)),
			-(M(0, 1) * M(2, 2) - M(0, 2) * M(2, 1)),
			+(M(0, 1) * M(1, 2) - M(0, 2) * M(1, 1))
		),
		Vector3(
			-(M(1, 0) * M(2, 2) - M(1, 2) * M(2, 0)),
			+(M(0, 0) * M(2, 2) - M(0, 2) * M(2, 0)),
			-(M(0, 0) * M(1, 2) - M(0, 2) * M(1, 0))
		),
		Vector3(
			+(M(1, 0) * M(2, 1) - M(1, 1) * M(2, 0)),
			-(M(0, 0) * M(2, 1) - M(0, 1) * M(2, 0)),
			+(M(0, 0) * M(1, 1) - M(0, 1) * M(1, 0))
		)
	);
}

Mat3x3 Mat3x3::Adjointed() const
{
	return Cofactor().Transposed();
}

Mat3x3 Mat3x3::Inversed() const
{
#if defined(PE_USE_SEE)
#else

	float const det = Determinant();

	if (PE_FLOAT_CMP(det, 0.0f))
		return Mat3x3();

	return Adjointed() * (1.0f / det);

#endif
}

PE_NAMESPACE_END
