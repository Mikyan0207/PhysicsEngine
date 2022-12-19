#include <PhysicsEngine/PhysicsEngine.h>

PE_SUPPRESS_WARNINGS
PE_CLANG_SUPPRESS_WARNING("-Wheader-hygiene")

PE_SUPPRESS_WARNINGS_STD_BEGIN
#include "doctest.h"
PE_SUPPRESS_WARNINGS_STD_END

using namespace Physics;

inline void CHECK_FLOAT_EQUAL(float lhs, float rhs, float epsilon = 1.0e-6f)
{
	CHECK(std::abs(rhs - lhs) <= epsilon);
}
