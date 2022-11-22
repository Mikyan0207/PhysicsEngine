#include <cmath>

PE_NAMESPACE_BEGIN

Vector2::Vector2(Float2 rhs)
{
	m_Value32[0] = rhs.X;
	m_Value32[1] = rhs.Y;
}

Vector2::Vector2(Vector3 rhs)
{
	m_Value32[0] = rhs.m_Value32[0];
	m_Value32[1] = rhs.m_Value32[1];
}

Vector2::Vector2(float x, float y)
{
	m_Value32[0] = x;
	m_Value32[1] = y;
}

Vector2 Vector2::Fill(float v)
{
	return Vector2(v, v);
}

Vector2 Vector2::operator*(Vector2 rhs) const
{
	return Vector2(
		m_Value32[0] * rhs.m_Value32[0],
		m_Value32[1] * rhs.m_Value32[1]
	);
}

Vector2 Vector2::operator/(Vector2 rhs) const
{
	return Vector2(
		m_Value32[0] / rhs.m_Value32[0],
		m_Value32[1] / rhs.m_Value32[1]
	);
}

Vector2 Vector2::operator+(Vector2 rhs) const
{
	return Vector2(
		m_Value32[0] + rhs.m_Value32[0],
		m_Value32[1] + rhs.m_Value32[1]
	);
}

Vector2 Vector2::operator-(Vector2 rhs) const
{
	return Vector2(
		m_Value32[0] - rhs.m_Value32[0],
		m_Value32[0] - rhs.m_Value32[1]
	);
}

Vector2 Vector2::operator*(float s) const
{
	return Vector2(
		m_Value32[0] * s,
		m_Value32[1] * s
	);
}

Vector2 Vector2::operator/(float s) const
{
	return Vector2(
		m_Value32[0] / s,
		m_Value32[1] / s
	);
}

Vector2 Vector2::operator+(float s) const
{
	return Vector2(
		m_Value32[0] + s,
		m_Value32[1] + s
	);
}

Vector2 Vector2::operator-(float s) const
{
	return Vector2(
		m_Value32[0] - s,
		m_Value32[1] - s
	);
}

Vector2& Vector2::operator*=(Vector2 rhs)
{
	for (int i = 0; i < 2; i++)
		m_Value32[i] *= rhs.m_Value32[i];

	return *this;
}

Vector2& Vector2::operator/=(Vector2 rhs)
{
	for (int i = 0; i < 2; i++)
		m_Value32[i] /= rhs.m_Value32[i];

	return *this;
}

Vector2& Vector2::operator+=(Vector2 rhs)
{
	for (int i = 0; i < 2; i++)
		m_Value32[i] += rhs.m_Value32[i];

	return *this;
}

Vector2& Vector2::operator-=(Vector2 rhs)
{
	for (int i = 0; i < 2; i++)
		m_Value32[i] -= rhs.m_Value32[i];

	return *this;
}

Vector2& Vector2::operator*=(float s)
{
	for (int i = 0; i < 2; i++)
		m_Value32[i] *= s;

	return *this;
}

Vector2& Vector2::operator/=(float s)
{
	for (int i = 0; i < 2; i++)
		m_Value32[i] /= s;

	return *this;
}

Vector2& Vector2::operator+=(float s)
{
	for (int i = 0; i < 2; i++)
		m_Value32[i] += s;

	return *this;
}

Vector2& Vector2::operator-=(float s)
{
	for (int i = 0; i < 2; i++)
		m_Value32[i] -= s;

	return *this;
}

float Vector2::Dot(Vector2 rhs) const
{
	return m_Value32[0] * rhs.m_Value32[0]
		+ m_Value32[1] * rhs.m_Value32[1];
}

float Vector2::Length() const
{
	return std::sqrtf(Dot(*this));
}

float Vector2::LengthSquared() const
{
	return Dot(*this);
}

float Vector2::Distance(Vector2 rhs) const
{
	auto d = *this - rhs;

	return d.Length();
}

float Vector2::DistanceSquared(Vector2 rhs) const
{
	auto d = *this - rhs;

	return d.LengthSquared();
}

Vector2 Vector2::Normalized() const
{
	return *this / Length();
}

void Vector2::Normalize()
{
	*this /= Length();
}

float Vector2::Angle(Vector2 rhs) const
{
	float l = std::sqrtf(LengthSquared() * rhs.LengthSquared());

	return std::acos(Dot(rhs) / l);
}

Vector2 Vector2::Project(Vector2 rhs) const
{
	float dot = Dot(rhs);
	float lengthSq = rhs.LengthSquared();

	return rhs * (dot / lengthSq);
}

Vector2 Vector2::Perpendicular(Vector2 rhs) const
{
	return *this - Project(rhs);
}

Vector2 Vector2::Reflection(Vector2 normal) const
{
	float dot = Dot(normal);

	return *this - normal * (dot * 2.0f);
}

PE_NAMESPACE_END

