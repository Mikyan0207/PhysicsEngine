#pragma once

#include <PhysicsEngine/Core/Core.h>
#include <PhysicsEngine/Math/Types.h>

#include <ostream>

PE_NAMESPACE_BEGIN

class [[nodiscard]] alignas(PE_VECTOR2_ALIGNMENT) Vector2
{
  public:
#if defined(PE_USE_SSE)
	using Type = __m64;
#else
	using Type = struct
	{
		float m_Data[2];
	};
#endif

	Vector2() = default;
	Vector2(const Vector2& v) = default;
	PE_INLINE Vector2(float x, float y);
	PE_INLINE Vector2(Type rhs) : m_Value(rhs)
	{
	}

	PE_INLINE float operator[](std::uint32_t index) const
	{
		PE_ASSERT(index < 2);
		return m_Value32[index];
	}

	PE_INLINE Vector2 operator*(Vector2 rhs) const;
	PE_INLINE Vector2 operator/(Vector2 rhs) const;
	PE_INLINE Vector2 operator+(Vector2 rhs) const;
	PE_INLINE Vector2 operator-(Vector2 rhs) const;

	PE_INLINE Vector2 operator*(float s) const;
	PE_INLINE Vector2 operator/(float s) const;
	PE_INLINE Vector2 operator+(float s) const;
	PE_INLINE Vector2 operator-(float s) const;

	PE_INLINE Vector2& operator*=(Vector2 rhs);
	PE_INLINE Vector2& operator/=(Vector2 rhs);
	PE_INLINE Vector2& operator+=(Vector2 rhs);
	PE_INLINE Vector2& operator-=(Vector2 rhs);

	PE_INLINE Vector2& operator*=(float s);
	PE_INLINE Vector2& operator/=(float s);
	PE_INLINE Vector2& operator+=(float s);
	PE_INLINE Vector2& operator-=(float s);

	PE_INLINE float Dot(Vector2 rhs) const;

	PE_INLINE float Length() const;
	PE_INLINE float LengthSquared() const;

	PE_INLINE float Distance(Vector2 rhs) const;
	PE_INLINE float DistanceSquared(Vector2 rhs) const;

	PE_INLINE Vector2 Normalized() const;
	PE_INLINE void Normalize();

	PE_INLINE Vector2 Cross(Vector2 rhs) const;

	PE_INLINE float Angle(Vector2 rhs) const;

	PE_INLINE Vector2 Project(Vector2 rhs) const;
	PE_INLINE Vector2 Perpendicular(Vector2 rhs) const;
	PE_INLINE Vector2 Reflection(Vector2 normal) const;

	PE_INLINE float GetX() const
	{
		return m_Value32[0];
	}

	PE_INLINE float GetY() const
	{
		return m_Value32[1];
	}

	PE_INLINE void SetX(float x)
	{
		m_Value32[0] = x;
	}

	PE_INLINE void SetY(float y)
	{
		m_Value32[1] = y;
	}

	friend std::ostream& operator<<(std::ostream& stream, Vector2 v)
	{
		return stream << "Vector2<" << v.m_Value32[0] << ", " << v.m_Value32[1] << ">";
	}

	union
	{
		Type m_Value;
		float m_Value32[2];
	};
};

static_assert(std::is_trivial<Vector2>(), "Vector2 must be a trivial type.");

PE_NAMESPACE_END

#include "Vector2.inl"
