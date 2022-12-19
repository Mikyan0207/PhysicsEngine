#include "Tests.h"

#include <PhysicsEngine/Math/Mat4x4.h>

TEST_SUITE("Mat4x4Tests")
{
    TEST_CASE("Mat4x4MultiplyMat4x4")
    {
		Mat4x4 const m1(
			Vector4(1, 2, 3, 4),
			Vector4(5, 6, 7, 8),
			Vector4(9, 10, 11, 12),
			Vector4(13, 14, 15, 16)
		);

		Mat4x4 const m2(
			Vector4(17, 18, 19, 20),
			Vector4(21, 22, 23, 24),
			Vector4(25, 26, 27, 28),
			Vector4(29, 30, 31, 32)
		);

		auto r = m1 * m2;

		CHECK_FLOAT_EQUAL(r(0, 0), 538);
    }

	TEST_CASE("Mat4x4SimpleCofactor")
    {
		Mat4x4 const m1(
			Vector4(1, 2, 3, 4),
			Vector4(5, 6, 7, 8),
			Vector4(9, 10, 11, 12),
			Vector4(13, 14, 15, 16)
		);

		auto r = m1.Cofactor();

		CHECK_FLOAT_EQUAL(r(0, 0), 0.0f);
    }
}
