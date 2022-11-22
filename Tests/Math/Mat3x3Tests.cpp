#include "Tests.h"
#include <PhysicsEngine/Math/Mat3x3.h>

TEST_SUITE("Mat3x3Tests")
{
	TEST_CASE("Mat3x3Constructor")
	{

	}

	TEST_CASE("Mat3x3Determinant")
	{
		Mat3x3 m3(
			Vector3(1, 2, 3),
			Vector3(4, 5, 6),
			Vector3(7, 15, 9)
		);

		float det = m3.Determinant();

		CHECK(det == 42);
	}

	TEST_CASE("Mat3x3Cofactor")
	{
		Mat3x3 m3(
			Vector3(1, 2, 3),
			Vector3(4, 5, 6),
			Vector3(7, 8, 9)
		);

		Mat3x3 cofactor = m3.Cofactor();

		CHECK_FLOAT_EQUAL(cofactor(0, 0), -3);
		CHECK_FLOAT_EQUAL(cofactor(0, 1), 6);
		CHECK_FLOAT_EQUAL(cofactor(0, 2), -3);
		CHECK_FLOAT_EQUAL(cofactor(1, 0), 6);
		CHECK_FLOAT_EQUAL(cofactor(1, 1), -12);
		CHECK_FLOAT_EQUAL(cofactor(1, 2), 6);
		CHECK_FLOAT_EQUAL(cofactor(2, 0), -3);
		CHECK_FLOAT_EQUAL(cofactor(2, 1), 6);
		CHECK_FLOAT_EQUAL(cofactor(2, 2), -3);
	}
}
