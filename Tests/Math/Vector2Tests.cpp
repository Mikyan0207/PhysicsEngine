#include "Tests.h"

#include <PhysicsEngine/Math/Vector2.h>

TEST_SUITE("Vector2Tests")
{
	TEST_CASE("Vector2Constructor")
	{
		Vector2 v(2, 5);

		CHECK(v.GetX() == 2);
		CHECK(v.GetY() == 5);

		CHECK(v[0] == 2);
		CHECK(v[1] == 5);
	}

	TEST_CASE("Vector2Additions")
	{
		Vector2 v1(2, 5);
		Vector2 v2(3, 9);

		Vector2 r1 = v1 + v2;

		CHECK(r1.GetX() == 5);
		CHECK(r1.GetY() == 14);

		v1 += v2;

		CHECK(v1.GetX() == 5);
		CHECK(v1.GetY() == 14);

		v2 += 3;

		CHECK(v2.GetX() == 6);
		CHECK(v2.GetY() == 12);
	}

	TEST_CASE("Vector2Multiplications")
	{
		Vector2 v1(2, 5);
		Vector2 v2(3, 9);

		Vector2 r1 = v1 * v2;

		CHECK(r1.GetX() == 6);
		CHECK(r1.GetY() == 45);
	}

	TEST_CASE("Vector2DotProduct")
	{
		Vector2 v1(2, 5);
		Vector2 v2(3, 9);

		float dot = v1.Dot(v2);

		CHECK(dot == 51);
	}

	TEST_CASE("Vector2Length")
	{
		Vector2 v1(3, 5);

		float length = v1.Length();

		CHECK_FLOAT_EQUAL(length, 5.830951f);
	}

	TEST_CASE("Vector2LengthSquared")
	{
		Vector2 v1(3, 5);

		float length = v1.LengthSquared();

		CHECK_FLOAT_EQUAL(length, 34.0f);
	}
}
