#pragma once

#include "PhysicsEngine/Core/Core.hpp"
#include <PhysicsEngine/Core/Assert.hpp>
#include <PhysicsEngine/Math/Types.hpp>

#include <cstdint>
#include <ostream>
#include <type_traits>

PE_NAMESPACE_BEGIN

class [[nodiscard]] alignas(PE_VECTOR4_ALIGNMENT) Vector4
{
  public:
#if defined(PE_USE_SSE)
    using Type = __m128;
#else
    using Type = struct
    {
        float m_Data[4];
    };
#endif

    Vector4() = default;
    Vector4(const Vector4& rhs) = default;
    explicit PE_INLINE Vector4(Vector3 rhs);
    PE_INLINE Vector4(Vector3 rhs, float w);
    PE_INLINE Vector4(float x, float y, float z, float w);
    PE_INLINE Vector4(Type rhs) : m_Value(rhs)
    {
    }

    static PE_INLINE Vector4 Fill(float v);

    PE_INLINE float operator[](std::uint32_t index) const
    {
        PE_ASSERT(index >= 0 && index < 4);
        return m_Value32[index];
    }

    PE_INLINE bool operator==(Vector4 rhs) const;
    PE_INLINE bool operator!=(Vector4 rhs) const;

    PE_INLINE Vector4 operator*(Vector4 rhs) const;
    PE_INLINE Vector4 operator/(Vector4 rhs) const;
    PE_INLINE Vector4 operator+(Vector4 rhs) const;
    PE_INLINE Vector4 operator-(Vector4 rhs) const;

    PE_INLINE Vector4 operator*(float s) const;
    PE_INLINE Vector4 operator/(float s) const;
    PE_INLINE Vector4 operator+(float s) const;
    PE_INLINE Vector4 operator-(float s) const;

    PE_INLINE Vector4& operator*=(Vector4 rhs);
    PE_INLINE Vector4& operator/=(Vector4 rhs);
    PE_INLINE Vector4& operator+=(Vector4 rhs);
    PE_INLINE Vector4& operator-=(Vector4 rhs);

    PE_INLINE Vector4& operator*=(float s);
    PE_INLINE Vector4& operator/=(float s);
    PE_INLINE Vector4& operator+=(float s);
    PE_INLINE Vector4& operator-=(float s);

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

    PE_INLINE float GetW() const
    {
        return m_Value32[3];
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

    PE_INLINE void SetW(float w)
    {
        m_Value32[3] = w;
    }

    friend std::ostream& operator<<(std::ostream& stream, Vector4 v)
    {
        return stream << "Vector4<" << v.m_Value32[0] << ", " << v.m_Value32[1] << ", " << v.m_Value32[2] << ", "
                      << v.m_Value32[3] << ">";
    }

    union {
        Type m_Value;
        float m_Value32[4];
    };
};

static_assert(std::is_trivial<Vector4>(), "Vector4 must be a trivial type.");

PE_NAMESPACE_END // namespace Physics

#include <PhysicsEngine/Math/Vector4.inl>
