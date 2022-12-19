#pragma once

#include <PhysicsEngine/Math/Types.h>

PE_NAMESPACE_BEGIN

class [[nodiscard]] alignas(PE_VECTOR4_ALIGNMENT) Mat3x3
{
public:
	using Type = Vector3::Type;

	Mat3x3() = default;
	Mat3x3(const Mat3x3& rhs) = default;
	PE_INLINE Mat3x3(Vector3 c1, Vector3 c2, Vector3 c3);

	static PE_INLINE Mat3x3 Identity();

	PE_INLINE float Mat3x3::operator()(std::uint32_t column, std::uint32_t row) const
	{
		PE_ASSERT(row < 3 && column < 3);
		return m_Cols[column].m_Value32[row];
	}

	PE_INLINE float& Mat3x3::operator()(std::uint32_t column, std::uint32_t row)
	{
		PE_ASSERT(row < 3 && column < 3);
		return m_Cols[column].m_Value32[row];
	}

	PE_INLINE Mat3x3 Mat3x3::operator*(Mat3x3 rhs) const;
	PE_INLINE Mat3x3 Mat3x3::operator+(Mat3x3 rhs) const;
	PE_INLINE Mat3x3 Mat3x3::operator-(Mat3x3 rhs) const;

	PE_INLINE Mat3x3 Mat3x3::operator*(float s) const;
	PE_INLINE Mat3x3 Mat3x3::operator+(float s) const;
	PE_INLINE Mat3x3 Mat3x3::operator-(float s) const;

	PE_INLINE Mat3x3& Mat3x3::operator*=(Mat3x3 rhs);
	PE_INLINE Mat3x3& Mat3x3::operator+=(Mat3x3 rhs);
	PE_INLINE Mat3x3& Mat3x3::operator-=(Mat3x3 rhs);

	PE_INLINE Mat3x3& Mat3x3::operator*=(float s);
	PE_INLINE Mat3x3& Mat3x3::operator+=(float s);
	PE_INLINE Mat3x3& Mat3x3::operator-=(float s);

	PE_INLINE Mat3x3 Transposed() const;
	PE_INLINE float Determinant() const;
	PE_INLINE Mat3x3 Cofactor() const;
	PE_INLINE Mat3x3 Adjointed() const;
	PE_INLINE Mat3x3 Inversed() const;

	Vector3 m_Cols[3];
};

static_assert(std::is_trivial<Mat3x3>(), "Mat3x3 must be a trivial type.");

PE_NAMESPACE_END

#include "Mat3x3.inl"
