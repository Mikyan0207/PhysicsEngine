#include "Tests.h"

#include <PhysicsEngine/Math/Mat2x2.h>

TEST_SUITE("Mat2x2Tests")
{
	TEST_CASE("Mat2x2Constructor")
	{
		Mat2x2 m(Vector2(2, 3), Vector2(4, 5));

		CHECK(m(1, 0) == 4);
		CHECK(m(0, 1) == 3);
	}
}
