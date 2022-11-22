#include <PhysicsEngine/Math/Vector2.h>

PE_NAMESPACE_BEGIN

#define M(c, r) m_Cols[c].m_Value32[r]

Mat2x2::Mat2x2(Vector2 c1, Vector2 c2)
{
	m_Cols[0] = c1;
	m_Cols[1] = c2;
}

Mat2x2::Mat2x2(Type c1, Type c2)
{
	m_Cols[0] = Vector2(c1);
	m_Cols[1] = Vector2(c2);
}

Mat2x2 Mat2x2::Identity()
{
	return Mat2x2(
		Vector2(1, 0),
		Vector2(0, 1)
	);
}

Mat2x2 Mat2x2::operator*(Mat2x2 rhs) const
{
	Mat2x2 result = {};

	for (int i = 0; i < 2; ++i)
	{
		result.m_Cols[i] = m_Cols[0] * rhs.m_Cols[i].m_Value32[0]
			+ m_Cols[1] * rhs.m_Cols[i].m_Value32[1];
	}

	return result;
}

Mat2x2 Mat2x2::operator*(float s) const
{
	Vector2 multiplier = Vector2::Fill(s);
	Mat2x2 result = {};

	for (int i = 0; i < 2; i++)
		result.m_Cols[i] = m_Cols[i] * multiplier;

	return result;
}

Mat2x2 Mat2x2::Transposed() const
{
	Mat2x2 result = {};

	for (int c = 0; c < 2; c++)
		for (int r = 0; r < 2; r++)
			result.m_Cols[r].m_Value32[c] = m_Cols[c].m_Value32[r];

	return result;
}

float Mat2x2::Determinant() const
{
	return m_Cols[0].m_Value32[0] * m_Cols[1].m_Value32[1]
		- m_Cols[0].m_Value32[1] * m_Cols[1].m_Value32[0];
}

Mat2x2 Mat2x2::Cofactor() const
{
	return Mat2x2(
		Vector2(M(1, 1), -M(0, 1)),
		Vector2(-M(1, 0), M(0, 0))
	);
}

PE_NAMESPACE_END
