#pragma once

#include <PhysicsEngine/Core/Assert.h>
#include <PhysicsEngine/Math/Float3.h>
#include <PhysicsEngine/Math/Types.h>

#include <cstdint>
#include <type_traits>

PE_NAMESPACE_BEGIN

class [[nodiscard]] alignas(PE_VECTOR4_ALIGNMENT) Vector3
{
  public:
#if defined(PE_USE_SSE)
    using Type = __m128;
#else
    using Type = struct {
		float m_Data[3];
	};
#endif

    Vector3() = default;
    Vector3(const Vector3& rhs) = default;
    explicit PE_INLINE Vector3(Vector4 rhs);
    explicit PE_INLINE Vector3(const Float3& v);
    PE_INLINE Vector3(float x, float y, float z);
    PE_INLINE Vector3(Type rhs) : m_Value(rhs)
    {
    }

    PE_INLINE float operator[](std::uint32_t index) const
    {
		PE_ASSERT(index >= 0 && index < 3);
        return m_Value32[index];
    }

    PE_INLINE bool operator==(Vector3 rhs) const;
    PE_INLINE bool operator!=(Vector3 rhs) const
    {
        return !(*this == rhs);
    }

    PE_INLINE Vector3 operator*(Vector3 rhs) const;
    PE_INLINE Vector3 operator/(Vector3 rhs) const;
    PE_INLINE Vector3 operator+(Vector3 rhs) const;
    PE_INLINE Vector3 operator-(Vector3 rhs) const;

    PE_INLINE Vector3 operator*(float s) const;
    PE_INLINE Vector3 operator/(float s) const;
    PE_INLINE Vector3 operator+(float s) const;
    PE_INLINE Vector3 operator-(float s) const;

    PE_INLINE Vector3& operator*=(Vector3 rhs);
    PE_INLINE Vector3& operator/=(Vector3 rhs);
    PE_INLINE Vector3& operator+=(Vector3 rhs);
    PE_INLINE Vector3& operator-=(Vector3 rhs);

    PE_INLINE Vector3& operator*=(float s);
    PE_INLINE Vector3& operator/=(float s);
    PE_INLINE Vector3& operator+=(float s);
    PE_INLINE Vector3& operator-=(float s);

    PE_INLINE float Dot(Vector3 rhs) const;

	PE_INLINE float Magnitude() const;
	PE_INLINE float SquaredMagnitude() const;

	PE_INLINE float Distance(Vector3 rhs) const;
	PE_INLINE float SquaredDistance(Vector3 rhs) const;

	PE_INLINE void Normalize();
	PE_INLINE Vector3 Normalized() const;

	PE_INLINE Vector3 Cross(Vector3 rhs) const;

	/// <summary>
	/// Returns the angle between this <see cref="Vector3" /> instance and the <see cref="Vector3" /> passed as parameter.
	/// </summary>
	/// <remarks>
	/// The angle is expressed in radians. Use `RadiansToDegrees()` if you need to convert it.
	/// </remarks>
	PE_INLINE float Angle(Vector3 rhs) const;

	PE_INLINE Vector3 Project(Vector3 rhs) const;
	PE_INLINE Vector3 Perpendicular(Vector3 rhs) const;

	PE_INLINE Vector3 Reflection(Vector3 normal) const;

    PE_INLINE float GetX() const
    {
        return m_Value32[0];
    }

    PE_INLINE float GetY() const
    {
        return m_Value32[1];
    }

    PE_INLINE float GetZ() const
    {
        return m_Value32[2];
    }

    PE_INLINE void SetX(float x)
    {
        m_Value32[0] = x;
    }

    PE_INLINE void SetY(float y)
    {
        m_Value32[1] = y;
    }

    PE_INLINE void SetZ(float z)
    {
        m_Value32[2] = z;
    }

    union {
        Type m_Value;
        float m_Value32[3];
    };
};

static_assert(std::is_trivial<Vector3>(), "Vector3 must be a trivial type.");

PE_NAMESPACE_END

#include "Vector3.inl"
