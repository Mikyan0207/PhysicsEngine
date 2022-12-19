#include <PhysicsEngine/Math/Vector3.h>

PE_NAMESPACE_BEGIN

Vector4::Vector4(Vector3 rhs) : Vector4(rhs, 0)
{
}

Vector4::Vector4(Vector3 rhs, float w)
{
    for (auto i = 0; i < 3; i++)
        m_Value32[i] = rhs.m_Value32[i];

    m_Value32[3] = w;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	m_Value32[0] = x;
	m_Value32[1] = y;
	m_Value32[2] = z;
	m_Value32[3] = w;
}

Vector4 Vector4::Fill(float v)
{
	return Vector4(v, v, v, v);
}

bool Vector4::operator==(Vector4 rhs) const
{
	return m_Value32[0] == rhs.m_Value32[0]
	    && m_Value32[1] == rhs.m_Value32[1]
		&& m_Value32[2] == rhs.m_Value32[2]
		&& m_Value32[3] == rhs.m_Value32[3];
}

Vector4 Vector4::operator*(Vector4 rhs) const
{
	return Vector4(
		m_Value32[0] * rhs.m_Value32[0],
		m_Value32[1] * rhs.m_Value32[1],
		m_Value32[2] * rhs.m_Value32[2],
		m_Value32[3] * rhs.m_Value32[3]
	);
}

Vector4 Vector4::operator/(Vector4 rhs) const
{
	return Vector4(
		m_Value32[0] / rhs.m_Value32[0],
		m_Value32[1] / rhs.m_Value32[1],
		m_Value32[2] / rhs.m_Value32[2],
		m_Value32[3] / rhs.m_Value32[3]
	);
}

Vector4 Vector4::operator+(Vector4 rhs) const
{
	return Vector4(
		m_Value32[0] + rhs.m_Value32[0],
		m_Value32[1] + rhs.m_Value32[1],
		m_Value32[2] + rhs.m_Value32[2],
		m_Value32[3] + rhs.m_Value32[3]
	);
}

Vector4 Vector4::operator-(Vector4 rhs) const
{
	return Vector4(
		m_Value32[0] - rhs.m_Value32[0],
		m_Value32[1] - rhs.m_Value32[1],
		m_Value32[2] - rhs.m_Value32[2],
		m_Value32[3] - rhs.m_Value32[3]
	);
}

Vector4 Vector4::operator*(float s) const
{
	return Vector4(
		m_Value32[0] * s,
		m_Value32[1] * s,
		m_Value32[2] * s,
		m_Value32[3] * s
	);
}

Vector4 Vector4::operator/(float s) const
{
	return Vector4(
		m_Value32[0] / s,
		m_Value32[1] / s,
		m_Value32[2] / s,
		m_Value32[3] / s
	);
}

Vector4 Vector4::operator+(float s) const
{
	return Vector4(
		m_Value32[0] + s,
		m_Value32[1] + s,
		m_Value32[2] + s,
		m_Value32[3] + s
	);
}

Vector4 Vector4::operator-(float s) const
{
	return Vector4(
		m_Value32[0] - s,
		m_Value32[1] - s,
		m_Value32[2] - s,
		m_Value32[3] - s
	);
}

Vector4& Vector4::operator*=(Vector4 rhs)
{
	for (int i = 0; i < 4; i++)
		m_Value32[i] *= rhs.m_Value32[i];

	return *this;
}

Vector4& Vector4::operator/=(Vector4 rhs)
{
	for (int i = 0; i < 4; i++)
		m_Value32[i] /= rhs.m_Value32[i];

	return *this;
}

Vector4& Vector4::operator+=(Vector4 rhs)
{
	for (int i = 0; i < 4; i++)
	  m_Value32[i] += rhs.m_Value32[i];

	return *this;
}

Vector4& Vector4::operator-=(Vector4 rhs)
{
	for (int i = 0; i < 4; i++)
		m_Value32[i] -= rhs.m_Value32[i];

	return *this;
}

Vector4& Vector4::operator*=(float s)
{
	for (int i = 0; i < 4; i++)
		m_Value32[i] *= s;

	return *this;
}

Vector4& Vector4::operator/=(float s)
{
	for (int i = 0; i < 4; i++)
		m_Value32[i] /= s;

	return *this;
}

Vector4& Vector4::operator+=(float s)
{
	for (int i = 0; i < 4; i++)
		m_Value32[i] += s;

	return *this;
}

Vector4& Vector4::operator-=(float s)
{
	for (int i = 0; i < 4; i++)
		m_Value32[i] -= s;

	return *this;
}

PE_NAMESPACE_END
