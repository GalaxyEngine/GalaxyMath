#include "include/VTest.hpp"
#include "Maths.h"
using namespace GALAXY::Math;

VTEST(TEST)
{
	NAMESPACE(Vector_2)
	{
		TEST(Constructors)
		{
			REQUIRE(Vec2f(1.f) == Vec2d(1, 1));
			REQUIRE(Vec2f(Vec3f(3.5f, 6.6f, 1.2f)) == Vec2d(3.5, 6.6));
			REQUIRE(Vec2f("2.5, 1.33") == Vec2d(2.5, 1.33));
		}
		TEST(Comparison Operators)
		{
			REQUIRE(Vec2i(3, 6) == Vec3f(3.5f, 6.6f, 1.2f));
			REQUIRE(Vec2f(3, 6) != Vec2d(3.5f, 6.6f));
			REQUIRE(Vec2f(3, 6) != Vec3d(3.5f, 6.6f, 1.2f));
		}
		TEST(Arithmetic Operators)
		{
			REQUIRE(Vec2d(2, 2) + Vec2f(1) == Vec2i(3));
			REQUIRE(Vec2i(2, 2) - Vec2f(1) == Vec2d(1));
			REQUIRE(-Vec2i(2, 2) == Vec2d(-2, -2));
			REQUIRE(Vec2i(2, 2) * 1 == Vec2d(2));
			REQUIRE(Vec2i(2, 2) * Vec2f(1, 2) == Vec2d(2, 4));
			REQUIRE(Vec2i(2.5, 3) / 3 == Vec2d(0, 1));
		}
		TEST(Assignement Operators)
		{
			//Copy constructor
			Vec2i value = Vec2f(2.5f, 1.33f);
			REQUIRE(value == Vec2f(2.5f, 1.33f));
			value += Vec2d(1.1f, 6.3f);
			REQUIRE(value == Vec2i(3, 7));
			value -= Vec2f(5.3, 4.7);
			REQUIRE(value == Vec2d(-2, 2));
			value *= 5.f;
			REQUIRE(value == Vec2i(-10, 10));
			value *= Vec2f(-2, 3);
			REQUIRE(value == Vec2d(20, 30));
			value /= 2;
			REQUIRE(value == Vec2i(10, 15));
		}
		TEST(Subscript Operators)
		{
			Vec2i value(1.f, 3.95f);
			COMPARE(value[0], 1);
			COMPARE(value[1], 3.00f);
			COMPARE(value[12], 0);
		}
		TEST(Methods)
		{

		}
	}
}

int main() {
	system("cls");   // used to clear and enable color on Windows
	runTests();
	system("pause"); // used to pause at the end on Windows;
	return 0;
}