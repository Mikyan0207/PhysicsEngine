#pragma once
#include <PhysicsEngine/Math/Math.h>
#include <PhysicsEngine/Math/Vector4.h>

PE_NAMESPACE_BEGIN

#define M(c, r) m_Cols[c].m_Value32[r]

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

float Mat4x4::Determinant() const
{
#if defined(PE_USE_SSE)
#else
	float const subFactor00 = M(2, 2) * M(3, 3) - M(3, 2) * M(2, 3);
	float const subFactor01 = M(2, 1) * M(3, 3) - M(3, 1) * M(2, 3);
	float const subFactor02 = M(2, 1) * M(3, 2) - M(3, 1) * M(2, 2);
	float const subFactor03 = M(2, 0) * M(3, 3) - M(3, 0) * M(2, 3);
	float const subFactor04 = M(2, 0) * M(3, 2) - M(3, 0) * M(2, 2);
	float const subFactor05 = M(2, 0) * M(3, 1) - M(3, 0) * M(2, 1);

	Vector4 const detCof(
		+(M(1, 1) * subFactor00 - M(1, 2) * subFactor01 + M(1, 3) * subFactor02),
		-(M(1, 0) * subFactor00 - M(1, 2) * subFactor03 + M(1, 3) * subFactor04),
		+(M(1, 0) * subFactor01 - M(1, 1) * subFactor03 + M(1, 3) * subFactor05),
		-(M(1, 0) * subFactor02 - M(1, 1) * subFactor04 + M(1, 2) * subFactor05)
	);

	return M(0, 0) * detCof[0] + M(0, 1) * detCof[1]
		+ M(0, 2) * detCof[2] + M(0, 3) * detCof[3];
#endif
}

Mat4x4 Mat4x4::Cofactor() const
{
#if defined(PE_USE_SSE)
#else

	float const m10_21_11_20 = M(1, 0) * M(2, 1) - M(1, 1) * M(2, 0);
	float const m10_22_12_20 = M(1, 0) * M(2, 2) - M(1, 2) * M(2, 0);
	float const m10_23_13_20 = M(1, 0) * M(2, 3) - M(1, 3) * M(2, 0);
	float const m10_31_11_30 = M(1, 0) * M(3, 1) - M(1, 1) * M(3, 0);
	float const m10_32_12_30 = M(1, 0) * M(3, 2) - M(1, 2) * M(3, 0);
	float const m10_33_13_30 = M(1, 0) * M(3, 3) - M(1, 3) * M(3, 0);
	float const m11_22_12_21 = M(1, 1) * M(2, 2) - M(1, 2) * M(2, 1);
	float const m11_23_13_21 = M(1, 1) * M(2, 3) - M(1, 3) * M(2, 1);
	float const m11_32_12_31 = M(1, 1) * M(3, 2) - M(1, 2) * M(3, 1);
	float const m11_33_13_31 = M(1, 1) * M(3, 3) - M(1, 3) * M(3, 1);
	float const m12_23_13_22 = M(1, 2) * M(2, 3) - M(1, 3) * M(2, 2);
	float const m12_33_13_32 = M(1, 2) * M(3, 3) - M(1, 3) * M(3, 2);
	float const m20_31_21_30 = M(2, 0) * M(3, 1) - M(2, 1) * M(3, 0);
	float const m20_32_22_30 = M(2, 0) * M(3, 2) - M(2, 2) * M(3, 0);
	float const m20_33_23_30 = M(2, 0) * M(3, 3) - M(2, 3) * M(3, 0);
	float const m21_32_22_31 = M(2, 1) * M(3, 2) - M(2, 2) * M(3, 1);
	float const m21_33_23_31 = M(2, 1) * M(3, 3) - M(2, 3) * M(3, 1);
	float const m22_33_23_32 = M(2, 2) * M(3, 3) - M(2, 3) * M(3, 2);

	return Mat4x4(
		Vector4(
			+M(1, 1) * m22_33_23_32 - M(1, 2) * m21_33_23_31 + M(1, 3) * m21_32_22_31,
			-M(1, 0) * m22_33_23_32 + M(1, 2) * m20_33_23_30 - M(1, 3) * m20_32_22_30,
			+M(1, 0) * m21_33_23_31 - M(1, 1) * m20_33_23_30 + M(1, 3) * m20_31_21_30,
			-M(1, 0) * m21_32_22_31 + M(1, 1) * m20_32_22_30 - M(1, 2) * m20_31_21_30
		),
		Vector4(
			-M(0, 1) * m22_33_23_32 + M(0, 2) * m21_33_23_31 - M(0, 3) * m21_32_22_31,
			+M(0, 0) * m22_33_23_32 - M(0, 2) * m20_33_23_30 + M(0, 3) * m20_32_22_30,
	        -M(0, 0) * m21_33_23_31 + M(0, 1) * m20_33_23_30 - M(0, 3) * m20_31_21_30,
			+M(0, 0) * m21_32_22_31 - M(0, 1) * m20_32_22_30 + M(0, 2) * m20_31_21_30
		),
		Vector4(
			+M(0, 1) * m12_33_13_32 - M(0, 2) * m11_33_13_31 + M(0, 3) * m11_32_12_31,
			-M(0, 0) * m12_33_13_32 + M(0, 2) * m10_33_13_30 - M(0, 3) * m10_32_12_30,
			+M(0, 0) * m11_33_13_31 - M(0, 1) * m10_33_13_30 + M(0, 3) * m10_31_11_30,
			-M(0, 0) * m11_32_12_31 + M(0, 1) * m10_32_12_30 - M(0, 2) * m10_31_11_30
		),
		Vector4(
			-M(0, 1) * m12_23_13_22 + M(0, 2) * m11_23_13_21 - M(0, 3) * m11_22_12_21,
			+M(0, 0) * m12_23_13_22 - M(0, 2) * m10_23_13_20 + M(0, 3) * m10_22_12_20,
			-M(0, 0) * m11_23_13_21 + M(0, 1) * m10_23_13_20 - M(0, 3) * m10_21_11_20,
			+M(0, 0) * m11_22_12_21 - M(0, 1) * m10_22_12_20 + M(0, 2) * m10_21_11_20
		)
	);

#endif
}

Mat4x4 Mat4x4::Adjointed() const
{
	return Cofactor().Transposed();
}

Mat4x4 Mat4x4::Inversed() const
{
#if defined(PE_USE_SSE)
#else

	float const det = Determinant();

	if (PE_FLOAT_CMP(det, 0.0f))
		return Mat4x4();

	return Adjointed() * (1.0f / det);

#endif
}

PE_NAMESPACE_END
