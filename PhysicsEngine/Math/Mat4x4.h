#pragma once

#include <PhysicsEngine/Math/Types.h>

PE_NAMESPACE_BEGIN

class [[nodiscard]] alignas(PE_VECTOR_ALIGNMENT) Mat4x4
{
public:
	using Type = Vector4::Type;

	Mat4x4() = default;
	Mat4x4(const Mat4x4& rhs) = default;
	PE_INLINE Mat4x4(Vector4 c1, Vector4 c2, Vector4 c3, Vector4 c4);
	PE_INLINE Mat4x4(Type c1, Type c2, Type c3, Type c4);
};

PE_NAMESPACE_END
