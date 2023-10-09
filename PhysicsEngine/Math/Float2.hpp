#pragma once

#include <PhysicsEngine/Core/Core.hpp>
#include <ostream>

PE_NAMESPACE_BEGIN

class [[nodiscard]] Float2
{
  public:
    Float2() = default;
    Float2(const Float2& rhs) = default;
    Float2(float x, float y) : X(x), Y(y)
    {
    }

    bool operator==(const Float2& rhs) const
    {
        return X == rhs.X && Y == rhs.Y;
    }

    bool operator!=(const Float2& rhs) const
    {
        return X != rhs.X || Y != rhs.Y;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Float2& v)
    {
        return stream << "Float2<" << v.X << ", " << v.Y << ">";
    }

    float X;
    float Y;
};

static_assert(std::is_trivial<Float2>(), "Float2 must be a trivial type.");

PE_NAMESPACE_END // namespace Physics
