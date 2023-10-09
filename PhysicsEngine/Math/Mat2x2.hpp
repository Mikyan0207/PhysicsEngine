#pragma once

#include <PhysicsEngine/Core/Assert.hpp>
#include <PhysicsEngine/Core/Core.hpp>
#include <PhysicsEngine/Math/Vector2.hpp>
#include <cstdint>

PE_NAMESPACE_BEGIN

class [[nodiscard]] alignas(PE_VECTOR2_ALIGNMENT) Mat2x2
{
  public:
    using Type = Vector2::Type;

    Mat2x2() = default;
    Mat2x2(const Mat2x2& rhs) = default;
    PE_INLINE Mat2x2(Vector2 c1, Vector2 c2);
    PE_INLINE Mat2x2(Type c1, Type c2);

    static PE_INLINE Mat2x2 Identity();

    PE_INLINE float operator()(std::uint32_t column, std::uint32_t row) const
    {
        PE_ASSERT(row < 2 && column < 2);
        return m_Cols[column].m_Value32[row];
    }

    PE_INLINE float& operator()(std::uint32_t column, std::uint32_t row)
    {
        PE_ASSERT(row < 2 && column < 2);
        return m_Cols[column].m_Value32[row];
    }

    PE_INLINE Mat2x2 operator*(Mat2x2 rhs) const;
    PE_INLINE Mat2x2 operator+(Mat2x2 rhs) const;
    PE_INLINE Mat2x2 operator-(Mat2x2 rhs) const;

    PE_INLINE Mat2x2 operator*(float s) const;
    PE_INLINE Mat2x2 operator+(float s) const;
    PE_INLINE Mat2x2 operator-(float s) const;

    PE_INLINE Mat2x2& operator*=(Mat2x2 rhs);
    PE_INLINE Mat2x2& operator+=(Mat2x2 rhs);
    PE_INLINE Mat2x2& operator-=(Mat2x2 rhs);

    PE_INLINE Mat2x2& operator*=(float s);
    PE_INLINE Mat2x2& operator+=(float s);
    PE_INLINE Mat2x2& operator-=(float s);

    PE_INLINE Mat2x2 Transposed() const;
    PE_INLINE float Determinant() const;
    PE_INLINE Mat2x2 Cofactor() const;
    PE_INLINE Mat2x2 Adjointed() const;
    PE_INLINE Mat2x2 Inversed() const;

    Vector2 m_Cols[2];
};

static_assert(std::is_trivial<Mat2x2>(), "Mat2x2 must be a trivial type.");

PE_NAMESPACE_END // namespace Physics

#include <PhysicsEngine/Math/Mat2x2.inl>
