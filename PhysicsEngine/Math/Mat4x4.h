#pragma once

#include <PhysicsEngine/Math/Types.h>

#include <ostream>

PE_NAMESPACE_BEGIN

class [[nodiscard]] alignas(PE_VECTOR4_ALIGNMENT) Mat4x4
{
public:
	using Type = Vector4::Type;

	Mat4x4() = default;
	Mat4x4(const Mat4x4& rhs) = default;
	PE_INLINE Mat4x4(Vector4 c1, Vector4 c2, Vector4 c3, Vector4 c4);
	PE_INLINE Mat4x4(Type c1, Type c2, Type c3, Type c4);

	static PE_INLINE Mat4x4 Identity();

	PE_INLINE float operator()(std::uint32_t row, std::uint32_t column) const
	{
		PE_ASSERT(row < 4 && column < 4);
		return m_Cols[column].m_Value32[row];
	}

	PE_INLINE float& operator()(std::uint32_t row, std::uint32_t column)
	{
		PE_ASSERT(row < 4 && column < 4);
		return m_Cols[column].m_Value32[row];
	}

	PE_INLINE Mat4x4 operator*(Mat4x4 rhs) const;
	PE_INLINE Mat4x4 operator+(Mat4x4 rhs) const;
	PE_INLINE Mat4x4 operator-(Mat4x4 rhs) const;

	PE_INLINE Mat4x4 operator*(float s) const;
	PE_INLINE Mat4x4 operator+(float s) const;
	PE_INLINE Mat4x4 operator-(float s) const;

	PE_INLINE Mat4x4& operator*=(Mat4x4 rhs);
	PE_INLINE Mat4x4& operator+=(Mat4x4 rhs);
	PE_INLINE Mat4x4& operator-=(Mat4x4 rhs);

	PE_INLINE Mat4x4& operator*=(float s);
	PE_INLINE Mat4x4& operator+=(float s);
	PE_INLINE Mat4x4& operator-=(float s);

	PE_INLINE Mat4x4 Transposed() const;

	friend std::ostream& operator<<(std::ostream& stream, Mat4x4 m)
	{
		return stream << "Mat4x4[" << m.m_Cols[0] << ", " << m.m_Cols[1] << ", " << m.m_Cols[2] << ", " << m.m_Cols[3] << "]";
	}

private:
	Vector4 m_Cols[4];
};

static_assert(std::is_trivial<Mat4x4>(), "Mat4x4 must be a trivial type.");

PE_NAMESPACE_END

#include "Mat4x4.inl"
