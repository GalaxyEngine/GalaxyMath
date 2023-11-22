#include "include/VTest.hpp"

#define MATH_GLM_EXTENSION
#include "Maths.h"
using namespace GALAXY::Math;

VTEST(MATH_TEST)
{
#pragma region Vector 2 Tests
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
			REQUIRE(Vec2i(2, 2) * 4 == Vec2d(8));
			REQUIRE(Vec2i(2, 2) * Vec2f(1, 2) == Vec2d(2, 4));
			REQUIRE(Vec2i(2.5, 3) / 3 == Vec2d(0, 1));
		}
		TEST(Assignement Operators)
		{
			//Copy operator
			Vec2f value = Vec2f(2.5f, 1.33f);
			REQUIRE(value == Vec2f(2.5f, 1.33f));
			value += Vec2f(1.1f, 6.3f);
			REQUIRE(value == Vec2f(3.6f, 7.63f));
			value -= Vec2f(5.3f, 4.7f);
			REQUIRE(value == Vec2f(-1.7f, 2.93f));
			value *= 5.f;
			REQUIRE(value == Vec2f(-8.5f, 14.65f));
			value *= Vec2f(-2, 3);
			REQUIRE(value == Vec2f(17.f, 43.95f));
			value /= 2;
			REQUIRE(value == Vec2f(8.5f, 21.975f));
		}
		TEST(Subscript Operators)
		{
			Vec2i value(1.f, 3.95f);
			COMPARE(value[0], 1);
			COMPARE(value[1], 3.00f);
			COMPARE(value[12], 1);
		}
		TEST(Methods)
		{
			Vec2f value(1.54f, 2.321f);
			COMPARE(value.LengthSquared(), glm::length2(value.ToGlm()));
			COMPARE(value.Length(), glm::length(value.ToGlm()));

			Vec2f value2(98.54f, 12.321f);
			COMPARE(value.Dot(value2), glm::dot(value.ToGlm(), value2.ToGlm()));

			Vec2f manualCrossResult = { value.x * value2.y, value.y * value2.x };
			REQUIRE(value.Cross(value2) == manualCrossResult);

			Vec2f manualOrthoResult(-value.y, value.x);
			REQUIRE(value.Ortho() == manualOrthoResult);

			REQUIRE(value.GetNormalize() == glm::normalize(value.ToGlm()));

			REQUIRE(value.ToString() == std::string("1.540000, 2.321000"));
		}
	}
#pragma endregion

#pragma region Vector 3 Tests
	NAMESPACE(Vector_3)
	{
		TEST(Constructors)
		{
			REQUIRE(Vec3f(1.f) == Vec3d(1, 1, 1));
			REQUIRE(Vec3f(Vec2d(3.5f, 6.6f), 0.1f) == Vec3d(3.5, 6.6, 0.1));
			REQUIRE(Vec3f("2.5, 1.33, 6.75") == Vec3d(2.5, 1.33, 6.75));
			REQUIRE(Vec3i("2, 1, 6") == Vec3d(2, 1, 6));
			REQUIRE(Vec3i(Vec4d(2.5, 6.9, 1.1, 1.0)) == Vec3d(2, 6, 1));
		}
		TEST(Comparison Operators)
		{
			REQUIRE(Vec3i(3, 6, 1) == Vec3f(3.5f, 6.6f, 1.2f));
			REQUIRE(Vec3d(3, 6, 1) == Vec3i(3.5f, 6.6f, 1.2f));
			REQUIRE(Vec3i(3, 6, 1) != Vec3d(4.5f, 6.6f, 1.2f));
		}
		TEST(Arithmetic Operators)
		{
			REQUIRE(Vec3d(2, 2, 2) + Vec3f(1) == Vec3i(3));
			REQUIRE(Vec3i(2, 2, 2) - Vec3f(1, 1, 1) == Vec3d(1));
			REQUIRE(-Vec3i(2, 2, 2) == Vec3d(-2, -2, -2));
			REQUIRE(Vec3i(2, 2, 2) * 4 == Vec3d(8));
			REQUIRE(Vec3i(2, 2, 2) * Vec3f(1, 2, 5) == Vec3d(2, 4, 10));
			REQUIRE(Vec3i(2.5, 3, 9.0) / 3 == Vec3d(0, 1, 3));
		}
		TEST(Assignement Operators)
		{
			//Copy operator
			Vec3f value = Vec3f(2.5f, 1.33f ,2.5f);
			REQUIRE(value == Vec3f(2.5f, 1.33f, 2.5f));
			value += Vec3d(1.1f, 6.3f, 5.6f);
			REQUIRE(value == Vec3f(3.6f, 7.63f, 8.1f));
			value -= Vec3f(5.3f, 4.7f, 3.6f);
			REQUIRE(value == Vec3f(-1.7f, 2.93f, 4.5f));
			value *= 5.f;
			REQUIRE(value == Vec3f(-8.5f, 14.65f, 22.5f));
			value *= Vec3f(-2, 3, 4);
			REQUIRE(value == Vec3f(17, 43.95f, 90.0));
			value /= 2;
			REQUIRE(value == Vec3f(8.5, 21.975, 45));
		}
		TEST(Subscript Operators)
		{
			Vec3i value(1.f, 3.95f, -50);
			COMPARE(value[0], 1);
			COMPARE(value[1], 3.00f);
			COMPARE(value[2], -50);
			COMPARE(value[3], 1);
		}
		TEST(Methods)
		{
			Vec3f value(1.54f, 2.321f, 23.478f);
			COMPARE(value.LengthSquared(), glm::length2(value.ToGlm()));
			COMPARE(value.Length(), glm::length(value.ToGlm()));

			Vec3f value2(98.54f, 12.321f, 37.89f);
			COMPARE(value.Dot(value2), glm::dot(value.ToGlm(), value2.ToGlm()));

			REQUIRE(value.Cross(value2) == glm::cross(value.ToGlm(), value2.ToGlm()));

			REQUIRE(value.GetNormalize() == glm::normalize(value.ToGlm()));

			REQUIRE(value.Distance(value2) == glm::distance(value.ToGlm(), value2.ToGlm()));

			Vec3 expected(
				glm::mix(value.x, value2.x, glm::clamp(0.5f, 0.0f, 1.0f)),
				glm::mix(value.y, value2.y, glm::clamp(0.5f, 0.0f, 1.0f)),
				glm::mix(value.z, value2.z, glm::clamp(0.5f, 0.0f, 1.0f))
			);
			REQUIRE(value.Lerp(value2, 0.5f) == expected);
			
			Vec3f angle(147.5, 34.25f, 144.0f);
			Vec3f radAngle = angle * DegToRad;

			Quat quat = angle.ToQuaternion();
			glm::quat glmQuat = glm::quat(radAngle.ToGlm());
			REQUIRE(quat == glmQuat);

			REQUIRE(value.ToString(5) == std::string("1.54000, 2.32100, 23.47800"));
		}
	}
#pragma endregion

#pragma region Vector 4 Tests
	NAMESPACE(Vector_4)
	{
		TEST(Constructors)
		{
			REQUIRE(Vec4f(1.f) == Vec4d(1, 1, 1, 1));
			REQUIRE(Vec4f(Vec3d(3.5f, 6.6f, 7.5), 0.1f) == Vec4d(3.5, 6.6, 7.5, 0.1f));
			REQUIRE(Vec4f("2.5, 1.33, 6.75, 2.32") == Vec4d(2.5, 1.33, 6.75, 2.32));
			REQUIRE(Vec4i("2, 1, 6, 5") == Vec4d(2, 1, 6, 5));
			REQUIRE(Vec4i(Vec2d(2.5, 6.9), 1.f, 0.5f) == Vec4d(2, 6, 1, 0));
			REQUIRE(Vec4i(Vec3d(2.5, 6.9, 4.5f), 0.5f) == Vec4d(2, 6, 4, 0));
			REQUIRE(Vec4i(Vec3d(2.5, 6.9, 7.7)) == Vec4d(2, 6, 7, 0));
		}
		TEST(Comparison Operators)
		{
			REQUIRE(Vec4i(3, 6, 1, 5) == Vec4f(3.5f, 6.6f, 1.2f, 5.6f));
			REQUIRE(Vec4d(3, 6, 1, 5) == Vec4i(3.5f, 6.6f, 1.2f, 5.6f));
			REQUIRE(Vec4i(3, 6, 1, 5) != Vec4d(4.5f, 6.6f, 1.2f, 5.6f));
		}
		TEST(Arithmetic Operators)
		{
			REQUIRE(Vec4d(2, 2, 2, 2) + Vec4f(1) == Vec4i(3));
			REQUIRE(Vec4i(2, 2, 2, 2) - Vec4f(1, 1, 1, 1) == Vec4d(1));
			REQUIRE(-Vec4i(2, 2, 2, 2) == Vec4d(-2, -2, -2, -2));
			REQUIRE(Vec4i(2, 2, 2, 2) * 4 == Vec4d(8));
			REQUIRE(Vec4i(2, 2, 2, 2) * Vec4f(1, 2, 5, 3) == Vec4d(2, 4, 10, 6));
			REQUIRE(Vec4i(2.5, 3, 9.0, 6.6) / 3 == Vec4d(0, 1, 3, 2));
		}
		TEST(Assignement Operators)
		{
			//Copy operator
			Vec4f value = Vec4f(2.5f, 1.33f, 2.5f, 1.33f);
			REQUIRE(value == Vec4f(2.5f, 1.33f, 2.5f, 1.33f));
			value += Vec4d(1.1f, 6.3f, 5.6f, 9.2f);
			REQUIRE(value == Vec4f(3.6f, 7.63f, 8.1f, 10.53f));
			value -= Vec4f(5.3f, 4.7f, 3.6f, 1.1f);
			REQUIRE(value == Vec4f(-1.7f, 2.93f, 4.5f, 9.43f));
			value *= 5.f;
			REQUIRE(value == Vec4f(-8.5f, 14.65f, 22.5f, 47.15f));
			value *= Vec4f(-2, 3, 4, 0.2f);
			REQUIRE(value == Vec4f(17, 43.95f, 90.0, 9.43f));
			value /= 2;
			REQUIRE(value == Vec4f(8.5, 21.975, 45, 4.715));
		}
		TEST(Subscript Operators)
		{
			Vec4i value(1.f, 3.95f, -50, 2.5f);
			COMPARE(value[0], 1);
			COMPARE(value[1], 3.00f);
			COMPARE(value[2], -50);
			COMPARE(value[3], 2.00f);
			COMPARE(value[4], 1);
		}
		TEST(Methods)
		{
			Vec4f value(1.54f, 2.32f, 23.47f, 3.62f);
			COMPARE(value.LengthSquared(), glm::length2(value.ToGlm()));
			COMPARE(value.Length(), glm::length(value.ToGlm()));
			Vec4f value2(98.54f, 12.32f, 37.89f, 3.57f);
			COMPARE(value.Dot(value2), glm::dot(value.ToGlm(), value2.ToGlm()));
			REQUIRE(AlmostEqual(value.Distance(value2), glm::distance(value.ToGlm(), value2.ToGlm())));
			REQUIRE(value.GetHomogenize() == Vec4f(Vec3f(value) / value.w));
			REQUIRE(value.GetNormalize() == glm::normalize(value.ToGlm()));
			REQUIRE(value.ToVector3() == Vec3f(value));
		}
	}
}

int main() {
	system("cls");   // used to clear and enable color on Windows
	runTests();
	system("pause"); // used to pause at the end on Windows;
	return 0;
}