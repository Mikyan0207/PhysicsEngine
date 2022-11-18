#include <PhysicsEngine/Math/Vector3.h>

PE_NAMESPACE_BEGIN

Vector4::Vector4(Vector3 rhs) : m_Value(rhs.m_Value)
{
}

Vector4::Vector4(Vector3 rhs, float w)
{
    for (auto i = 0; i < 3; i++)
        m_Value32[i] = rhs.m_Value32[i];

    m_Value32[3] = w;
}

PE_NAMESPACE_END
