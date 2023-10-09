#pragma once

#include <PhysicsEngine/Core/Core.hpp>
#include <ostream>

PE_NAMESPACE_BEGIN

class [[nodiscard]] Float3
{
  public:
    Float3() = default;
    Float3(const Float3& rhs) = default;
    Float3(float x, float y, float z) : X(x), Y(y), Z(z)
    {
    }

    float operator[](int index) const
    {
        // TODO(Mikyan): assert index >= 0 && index < 3
        return *(&X + index);
    }

    bool operator==(const Float3& rhs)
    {
        return X == rhs.X && Y == rhs.Y && Z == rhs.Z;
    }

    bool operator!=(const Float3& rhs)
    {
        return X != rhs.X || Y != rhs.Y || Z != rhs.Z;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Float3& v)
    {
        return stream << "Float3<" << v.X << ", " << v.Y << ", " << v.Z << ">";
    }

    float X;
    float Y;
    float Z;
};

static_assert(std::is_trivial<Float3>(), "Float3 must be a trivial type.");

PE_NAMESPACE_END // namespace Physics
