#include <PhysicsEngine/Math/Vector4.h>
#include <cmath>

PE_NAMESPACE_BEGIN

// TODO(Mikyan): Initialization using SSE (SIMD).

Vector3::Vector3(Vector4 rhs)
{
    Type value;

    value.m_Data[0] = rhs.m_Value.m_Data[0];
    value.m_Data[1] = rhs.m_Value.m_Data[1];
    value.m_Data[2] = rhs.m_Value.m_Data[2];
    value.m_Data[3] = rhs.m_Value.m_Data[2]; // We don't need Vector4.W

    m_Value = value;
}

Vector3::Vector3(const Float3& v)
{
    m_Value32[0] = v[0];
    m_Value32[1] = v[1];
    m_Value32[2] = v[2];
    m_Value32[3] = v[2];
}

Vector3::Vector3(float x, float y, float z)
{
    m_Value32[0] = x;
    m_Value32[1] = y;
    m_Value32[2] = z;
    m_Value32[3] = z;
}

bool Vector3::operator==(Vector3 rhs) const
{
    return m_Value32[0] == rhs.m_Value32[0]
		&& m_Value32[1] == rhs.m_Value32[1]
		&& m_Value32[2] == rhs.m_Value32[2];
}

Vector3 Vector3::operator*(Vector3 rhs) const
{
    return Vector3(
		m_Value32[0] * rhs.m_Value32[0],
		m_Value32[1] * rhs.m_Value32[1],
		m_Value32[2] * m_Value32[2]
	);
}

Vector3 Vector3::operator/(Vector3 rhs) const
{
    // TODO(Mikyan): check Z and W to avoid division by zero.
    return Vector3(
		m_Value32[0] / rhs.m_Value32[0],
		m_Value32[1] / rhs.m_Value32[1],
		m_Value32[2] / rhs.m_Value32[2]
	);
}

Vector3 Vector3::operator+(Vector3 rhs) const
{
    return Vector3(
		m_Value32[0] + rhs.m_Value32[0],
		m_Value32[1] + rhs.m_Value32[1],
		m_Value32[2] + rhs.m_Value32[2]
	);
}

Vector3 Vector3::operator-(Vector3 rhs) const
{
    return Vector3(
		m_Value32[0] - rhs.m_Value32[0],
		m_Value32[1] - rhs.m_Value32[1],
		m_Value32[2] - rhs.m_Value32[2]
	);
}

Vector3 Vector3::operator*(float s) const
{
    return Vector3(
		m_Value32[0] * s,
		m_Value32[1] * s,
		m_Value32[2] * s
	);
}

Vector3 Vector3::operator/(float s) const
{
    return Vector3(
		m_Value32[0] / s,
		m_Value32[1] / s,
		m_Value32[2] / s
	);
}

Vector3 Vector3::operator+(float s) const
{
    return Vector3(
		m_Value32[0] + s,
		m_Value32[1] + s,
		m_Value32[2] + s
	);
}

Vector3 Vector3::operator-(float s) const
{
    return Vector3(
		m_Value32[0] - s,
		m_Value32[1] - s,
		m_Value32[2] - s
	);
}

Vector3& Vector3::operator*=(Vector3 rhs)
{
    for (int i = 0; i < 3; i++)
        m_Value32[i] *= rhs.m_Value32[i];

    m_Value32[3] = m_Value32[2];

    return *this;
}

Vector3& Vector3::operator/=(Vector3 rhs)
{
    for (int i = 0; i < 3; i++)
        m_Value32[i] /= rhs.m_Value32[i];

    m_Value32[3] = m_Value32[2];

    return *this;
}

Vector3& Vector3::operator+=(Vector3 rhs)
{
    for (int i = 0; i < 3; i++)
        m_Value32[i] += rhs.m_Value32[i];

    m_Value32[3] = m_Value32[2];

    return *this;
}

Vector3& Vector3::operator-=(Vector3 rhs)
{
    for (int i = 0; i < 3; i++)
        m_Value32[i] -= rhs.m_Value32[i];

    m_Value32[3] = m_Value32[2];

    return *this;
}

Vector3& Vector3::operator*=(float s)
{
    for (int i = 0; i < 3; i++)
        m_Value32[i] *= s;

    m_Value32[3] = m_Value32[2];

    return *this;
}

Vector3& Vector3::operator/=(float s)
{
    for (int i = 0; i < 3; i++)
        m_Value32[i] /= s;

    m_Value32[3] = m_Value32[2];

    return *this;
}

Vector3& Vector3::operator+=(float s)
{
    for (int i = 0; i < 3; i++)
        m_Value32[i] += s;

    m_Value32[3] = m_Value32[2];

    return *this;
}

Vector3& Vector3::operator-=(float s)
{
    for (int i = 0; i < 3; i++)
        m_Value32[i] -= s;

    m_Value32[3] = m_Value32[2];

    return *this;
}

float Vector3::Dot(Vector3 rhs) const
{
    return m_Value32[0] * rhs.m_Value32[0]
		+ m_Value32[1] * rhs.m_Value32[1]
		+ m_Value32[2] * rhs.m_Value32[2];
}

float Vector3::Magnitude() const
{
    return std::sqrtf(Dot(*this));
}

float Vector3::SquaredMagnitude() const
{
    return Dot(*this);
}

float Vector3::Distance(Vector3 rhs) const
{
    auto d = *this - rhs;

    return d.Magnitude();
}

float Vector3::SquaredDistance(Vector3 rhs) const
{
    auto d = *this - rhs;

    return d.SquaredMagnitude();
}

void Vector3::Normalize()
{
    *this /= Magnitude();
}

Vector3 Vector3::Normalized() const
{
    return *this / Magnitude();
}

Vector3 Vector3::Cross(Vector3 rhs) const
{
	return Vector3(
		m_Value32[1] * rhs.m_Value32[2] - m_Value32[2] * rhs.m_Value32[1], /// X = lhs.Y * rhs.Z - lhs.Z * rhs.Y
		m_Value32[2] * rhs.m_Value32[0] - m_Value32[0] * rhs.m_Value32[2], /// Y = lhs.Z * rhs.X - lhs.X * rhs.Z
		m_Value32[0] * rhs.m_Value32[1] - m_Value32[1] * rhs.m_Value32[0]  /// Z = lhs.X * rhs.Y - lhs.Y * rhs.X
	);
}

float Vector3::Angle(Vector3 rhs) const
{
	float m = std::sqrtf(SquaredMagnitude() * rhs.SquaredMagnitude());

	return std::acos(Dot(rhs) / m);
}

Vector3 Vector3::Project(Vector3 rhs) const
{
	float dot = Dot(rhs);
	float sqMag = rhs.SquaredMagnitude();

	return rhs * (dot  / sqMag);
}

Vector3 Vector3::Perpendicular(Vector3 rhs) const
{
	return *this - Project(rhs);
}

Vector3 Vector3::Reflection(Vector3 normal) const
{
	float dot = Dot(normal);

	return *this - normal * (dot * 2.0f);
}

PE_NAMESPACE_END
