#include "include/VTest.hpp"
#ifdef __APPLE__
#define PCOMPARE(a, b) COMPARE_WITH_PRECISION(a, b, 1e-4f)
#else
#define PCOMPARE(a, b) COMPARE_WITH_PRECISION(a, b, 1e-5f)
#endif

#define MATH_GLM_EXTENSION
#include "Maths.h"
using namespace GALAXY::Math;

#include <cassert>
#include <glm/gtx/matrix_decompose.hpp>


VTEST(MATH_TEST)
{
#pragma region Vector 2 Tests
	NAMESPACE(Vector_2)
	{
		TEST(Constructors)
		{
			constexpr Vec2f v1 = Vec2f(1.f);
			REQUIRE(Vec2f() == Vec2f(0, 0));
			REQUIRE(v1 == Vec2d(1, 1));
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
			REQUIRE(Vec2f(2.5, 3) * 3.1415 == 3.1415 * Vec2f(2.5, 3));
		}
		TEST(Assignement Operators)
		{
			//Copy operator
			Vec2f value = Vec2f(2.5f, 1.33f);
			REQUIRE(value == Vec2f(2.5f, 1.33f));
			value += Vec2f(1.1f, 6.3f);
			REQUIRE(value == Vec2f(3.6f, 7.63f));
			value -= Vec2d(5.3f, 4.7f);
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
			constexpr Vec2i value(1.f, 3.95f);
			Vec2i value2 = value; 
			
			COMPARE(value[0], 1);
			COMPARE(value[1], 3.0f);
			COMPARE(value[12], 1);

			value2[1] = 5;
			COMPARE(value2[1], 5);
		}
		TEST(Methods)
		{
			constexpr Vec2f value(1.54f, 2.321f);
			constexpr Vec2f value2(98.54f, 12.321f);
			constexpr Vec2f manualCrossResult = { value.x * value2.y, value.y * value2.x };
			constexpr Vec2f manualOrthoResult(-value.y, value.x);
			const float* data = value.Data();

			COMPARE(value.LengthSquared(), glm::length2(value.ToGlm()));
			COMPARE(value.Length(), glm::length(value.ToGlm()));
			COMPARE(value.Dot(value2), glm::dot(value.ToGlm(), value2.ToGlm()));
			REQUIRE(value.Cross(value2) == manualCrossResult);
			REQUIRE(value.Ortho() == manualOrthoResult);
			REQUIRE(value.GetNormalize() == glm::normalize(value.ToGlm()));
			REQUIRE(value.ToString(2) == std::string("1.54, 2.32"));
			REQUIRE(value.ToVec2i() == Vec2i(1, 2));
			REQUIRE(Vec2i(1, 2).ToVec2f() == Vec2f(1.f, 2.f));
			COMPARE(data[0], 1.54f);
			COMPARE(data[1], 2.321f);
		}
	}
#pragma endregion

#pragma region Vector 3 Tests
	NAMESPACE(Vector_3)
	{
		TEST(Constructors)
		{
			constexpr Vec3f v1 = Vec3f(1.f);
			REQUIRE(v1 == Vec3d(1, 1, 1));
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
			REQUIRE(Vec3f(2.5, 3, 9.0) * 3.1415 == 3.1415 * Vec3f(2.5, 3, 9.0));
		}
		TEST(Assignement Operators)
		{
			//Copy operator
			Vec3f value = Vec3f(2.5f, 1.33f, 2.5f);
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
			constexpr Vec3i value(1.f, 3.95f, -50);
			Vec3i value2 = value; 
			COMPARE(value[0], 1);
			COMPARE(value[1], 3.00f);
			COMPARE(value[2], -50);
			COMPARE(value[3], 1);

			value2[1] = 5;
			COMPARE(value2[1], 5);			
		}
		TEST(Methods)
		{
			constexpr Vec3f value(1.54f, 2.321f, 23.478f);
			constexpr Vec3f value2(98.54f, 12.321f, 37.89f);
			const Vec3 lerpGLM(
				glm::mix(value.x, value2.x, glm::clamp(0.5f, 0.0f, 1.0f)),
				glm::mix(value.y, value2.y, glm::clamp(0.5f, 0.0f, 1.0f)),
				glm::mix(value.z, value2.z, glm::clamp(0.5f, 0.0f, 1.0f))
				);
			constexpr Vec3f angle(147.5, 34.25f, 144.0f);
			constexpr Vec3f radAngle = angle * DegToRad;
			
			COMPARE(value.LengthSquared(), glm::length2(value.ToGlm()));
			COMPARE(value.Length(), glm::length(value.ToGlm()));
			COMPARE(value.Dot(value2), glm::dot(value.ToGlm(), value2.ToGlm()));
			REQUIRE(value.Cross(value2) == glm::cross(value.ToGlm(), value2.ToGlm()));
			REQUIRE(Vec3f::Cross(value, value2) == glm::cross(value.ToGlm(), value2.ToGlm()));
			REQUIRE(value.GetNormalize() == glm::normalize(value.ToGlm()));
			COMPARE(value.Distance(value2), glm::distance(value.ToGlm(), value2.ToGlm()));
			REQUIRE(value.Lerp(value2, 0.5f) == lerpGLM);
			REQUIRE(angle.ToQuaternion() == glm::quat(radAngle.ToGlm()));
			REQUIRE(value.ToString(5) == std::string("1.54000, 2.32100, 23.47800"));
		}
	}
#pragma endregion

#pragma region Vector 4 Tests
	NAMESPACE(Vector_4)
	{
		TEST(Constructors)
		{
			constexpr Vec4f v1 = Vec4f(1.f);
			REQUIRE(v1 == Vec4d(1, 1, 1, 1));
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
			REQUIRE(Vec4f(2.5, 3, 9.0, 11.2) * 3.1415 == 3.1415 * Vec4f(2.5, 3, 9.0, 11.2));
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
			constexpr Vec4i value(1.f, 3.95f, -50, 2.5f);
			Vec4i value2 = value;
			COMPARE(value[0], 1);
			COMPARE(value[1], 3.00f);
			COMPARE(value[2], -50);
			COMPARE(value[3], 2.00f);
			COMPARE(value[4], 1);

			value2[0] = 2;
			COMPARE(value2[0], 2);
		}
		TEST(Methods)
		{
			constexpr Vec4f value(1.54f, 2.32f, 23.47f, 3.62f);
			constexpr Vec4f value2(98.54f, 12.32f, 37.89f, 3.57f);
			const std::string stringValue = value.ToString(4);
			COMPARE(value.LengthSquared(), glm::length2(value.ToGlm()));
			COMPARE(value.Length(), glm::length(value.ToGlm()));
			COMPARE(value.Dot(value2), glm::dot(value.ToGlm(), value2.ToGlm()));
			PCOMPARE(value.Distance(value2), glm::distance(value.ToGlm(), value2.ToGlm()));
			REQUIRE(value.GetHomogenize() == Vec4f(Vec3f(value) / value.w));
			REQUIRE(value.GetNormalize() == glm::normalize(value.ToGlm()));
			REQUIRE(value.ToVector3() == Vec3f(value));
			REQUIRE(stringValue == std::string("1.5400, 2.3200, 23.4700, 3.6200"));
		}
	}
#pragma endregion

#pragma region Quaternion Tests
	NAMESPACE(Quaternion)
	{
		TEST(Constructors)
		{
			constexpr Quat quat = Quat(1);
			REQUIRE(Quat() == Quat(0, 0, 0, 1));
			REQUIRE(quat == Quat(1, 1, 1, 1));
			REQUIRE(Quat(1, 2, 3) == Quat(1, 2, 3, 1));
			REQUIRE(Quat("1, 2, 3, 1") == Quat(1, 2, 3, 1));
			REQUIRE(Quat(Vec3f(1, 2, 3)) == Quat(1, 2, 3, 1));
			REQUIRE(Quat(Vec4f(1, 2, 3, 1)) == Quat(1, 2, 3, 1));
		}
		TEST(Comparison Operators)
		{
			REQUIRE(Quat(0) != Quat(0, 0, 0, 1));
		}
		TEST(Arithmetic Operators)
		{
			// Addition
			constexpr Quat quat1 = Quat(1, 2, 3, 4);
			constexpr Quat quat2 = Quat(5, 6, 7, 8);
			constexpr Vec3f vectorValue = Vec3f(2.56f, 453.14f, 573.3f);
			
			REQUIRE(quat1 + quat2 == quat1.ToGlm() + quat2.ToGlm());

			// Subtraction
			REQUIRE(quat1 - quat2 == quat1.ToGlm() - quat2.ToGlm());

			// Multiplication
			REQUIRE(quat1 * quat2 == quat1.ToGlm() * quat2.ToGlm());
			REQUIRE(quat1 * 5 == Quat(5, 10, 15, 20));
			REQUIRE(quat1 * vectorValue == quat1.ToGlm() * vectorValue.ToGlm());
		}
		TEST(Subscript Operators)
		{
			constexpr Quat value(1.f, 3.95f, -50, 2.5f);
			Quat value2 = value;
			COMPARE(value[0], 1);
			COMPARE(value[1], 3.95f);
			COMPARE(value[2], -50);
			COMPARE(value[3], 2.50f);
			COMPARE(value[4], 1);

			value2[0] = 2;
			COMPARE(value2[0], 2);
		}
		TEST(Assignement Operators)
		{
			Quat quat1 = Quat(1, 2, 3, 4);
			Quat quat2 = Quat(5, 6, 7, 8);
			const glm::quat glmQuat = quat1.ToGlm() * 5.f * quat2.ToGlm();
			constexpr Vec3f vectorValue = Vec3f(2.56f, 453.14f, 573.3f);
			
			quat1 *= 5;
			REQUIRE(quat1 == Quat(5, 10, 15, 20));

			quat1 *= quat2;
			REQUIRE(quat1 == glmQuat);
			REQUIRE(quat1 * vectorValue == quat1.ToGlm() * vectorValue.ToGlm());
		}
		TEST(Methods)
		{
			constexpr float angle = 36.32f;
			constexpr Vec3f axis(0, 1, 0);
			constexpr Vec3f euler(32.5f, -63.21f, 17.93f);
			const Quat eulerQuat = Quat::FromEuler(euler);
			constexpr Quat quat1 = Quat(1, 2, 3, 4);
			constexpr Quat quat2 = Quat(5, 6, 7, 8);
			const glm::quat glmEulerQuat = glm::quat(DegToRad * euler.ToGlm());
			
			REQUIRE(Quat::Identity() == Quat(0, 0, 0, 1));
			REQUIRE(Quat::AngleAxis(angle, axis) == glm::angleAxis(angle * DegToRad, axis.ToGlm()));

			REQUIRE(eulerQuat == glmEulerQuat);
			REQUIRE(eulerQuat.ToRotationMatrix4() == glm::mat4_cast(glmEulerQuat));
			REQUIRE(eulerQuat.ToRotationMatrix3() == glm::mat3_cast(glmEulerQuat));
			REQUIRE(Quat::LookRotation(-Vec3f::Forward(), Vec3f::Up()) == Quat::Identity());
			REQUIRE(Quat::SLerp(quat1, quat2, 0.5f) == glm::mix(quat1.ToGlm(), quat2.ToGlm(), 0.5f));
			REQUIRE(quat1.GetInverse() == glm::inverse(quat1.ToGlm()));
			REQUIRE(quat1.GetNormalize() == glm::normalize(quat1.ToGlm()));
			REQUIRE(quat1.GetConjugate() == glm::conjugate(quat1.ToGlm()));
			COMPARE(quat1.Dot(quat2), glm::dot(quat1.ToGlm(), quat2.ToGlm()));
			// REQUIRE(eulerQuat.ToEuler() == glm::eulerAngles(glmEulerQuat) * RadToDeg);
			PCOMPARE(eulerQuat.ToEuler().x, glm::eulerAngles(glmEulerQuat).x * RadToDeg);
			PCOMPARE(eulerQuat.ToEuler().y, glm::eulerAngles(glmEulerQuat).y * RadToDeg);
			PCOMPARE(eulerQuat.ToEuler().z, glm::eulerAngles(glmEulerQuat).z * RadToDeg);
			
			REQUIRE(quat1.ToString() == std::string("1.000000, 2.000000, 3.000000, 4.000000"));
		}
	}
#pragma endregion

#pragma region Matrix 4 Tests

	NAMESPACE(Matrix_4)
	{
		// Initialize test matrices using raw values and vector constructors
		float values[16] = {
			2.5f,   10.35f, 147.3f, 10.35f,
			5.6f,   72.36f, 69.69f, 5.75f,
			78.f,   14.f,   3.25f, 10.5f,
			7.8f,   32.6f,  71.f,   6.78f
		};
		Mat4 matrix = Mat4(values);

		constexpr Mat4 matrix2 = Mat4(
			Vec4f(1.2f, 5.8f, 3.4f, 9.1f),
			Vec4f(6.3f, 2.7f, 8.9f, 4.5f),
			Vec4f(7.2f, 3.1f, 5.6f, 2.8f),
			Vec4f(9.4f, 4.7f, 1.8f, 6.2f)
		);

		TEST(Constructors)
		{
			// Verify identity matrix construction
			REQUIRE(Mat4(1) == Mat4::Identity());
			REQUIRE(Mat4::Identity() == glm::mat4(1));
		}

		TEST(ComparisonOperators)
		{
			// Create an equivalent glm matrix for comparison
			auto glmMatrix = glm::mat4(
				values[0],  values[1],  values[2],  values[3],
				values[4],  values[5],  values[6],  values[7],
				values[8],  values[9],  values[10], values[11],
				values[12], values[13], values[14], values[15]
			);

			// Verify equality and inequality operators
			REQUIRE(matrix != matrix2);
			REQUIRE(matrix == Mat4(values));
			REQUIRE(matrix.ToGlm() == glmMatrix);
			REQUIRE(matrix == matrix.ToGlm());
		}

		TEST(ArithmeticOperators)
		{
			// Matrix multiplication test
			Mat4 multiply = matrix * matrix2;
			glm::mat4 glmMultiply = matrix.ToGlm() * matrix2.ToGlm();
			REQUIRE(multiply == glmMultiply);

			// Vector multiplication test (Vec4)
			Vec4f vec4Value(5, 6, 3.2f, 14.f);
			REQUIRE(matrix * vec4Value == matrix.ToGlm() * vec4Value.ToGlm());

			// Vector multiplication test (Vec3 with w set to 0)
			vec4Value.w = 0;
			REQUIRE(Vec3f(matrix * vec4Value) == matrix * Vec3f(vec4Value));

			// Matrix addition test
			REQUIRE(matrix + matrix2 == matrix.ToGlm() + matrix2.ToGlm());
		}

		TEST(TransformationMethods)
		{
			// Translation
			Vec3f translation(1, 2, 3);
			Mat4 translationMatrix = Mat4::CreateTranslationMatrix(translation);
			glm::mat4 glmTranslationMatrix = glm::translate(glm::mat4(1), translation.ToGlm());
			REQUIRE(translationMatrix == glmTranslationMatrix);

			// Rotation using Euler angles
			Vec3f euler(32.5f, -63.21f, 17.93f);
			Mat4 rotationMatrix = Mat4::CreateRotationMatrix(euler);
			glm::mat4 glmRotationMatrix = glm::eulerAngleXYZ(DegToRad * euler.x, DegToRad * euler.y, DegToRad * euler.z);
			REQUIRE(rotationMatrix == glmRotationMatrix);

			// Rotation using Quaternion
			Quat eulerQuat = euler.ToQuaternion();
			Mat4 quatRotationMatrix = Mat4::CreateRotationMatrix(eulerQuat);
			glm::mat4 glmQuatRotationMatrix = glm::mat4(eulerQuat.ToGlm());
			REQUIRE(quatRotationMatrix == glmQuatRotationMatrix);

			// Scale
			Vec3f scale(1, 2, 3);
			Mat4 scaleMatrix = Mat4::CreateScaleMatrix(scale);
			glm::mat4 glmScaleMatrix = glm::scale(glm::mat4(1), scale.ToGlm());
			REQUIRE(scaleMatrix == glmScaleMatrix);

			// Combined transformation with Euler angles
			Mat4 transformMatrix = Mat4::CreateTransformMatrix(translation, euler, scale);
			glm::mat4 glmTransformMatrix = glmTranslationMatrix * glmRotationMatrix * glmScaleMatrix;
			REQUIRE(transformMatrix == glmTransformMatrix);

			// Combined transformation with Quaternion
			Mat4 transformQuatMatrix = Mat4::CreateTransformMatrix(translation, eulerQuat, scale);
			glm::mat4 glmTransformQuatMatrix = glmTranslationMatrix * glmQuatRotationMatrix * glmScaleMatrix;
			REQUIRE(transformQuatMatrix == glmTransformQuatMatrix);

			// Decomposition test
			glm::vec3 glmGetTranslation, glmGetScale, glmSkew;
			glm::quat glmGetRotation;
			glm::vec4 glmPerspective;
			Vec3f getTranslation;
			Quat getRotation;
			Vec3f getScale;

			transformMatrix.DecomposeTransformMatrix(getTranslation, getRotation, getScale);

			bool decomposeSuccess = glm::decompose(
				glmTransformMatrix, glmGetScale, glmGetRotation, glmGetTranslation, glmSkew, glmPerspective
			);
			assert(decomposeSuccess);
			glmGetRotation = glm::conjugate(glmGetRotation);

			REQUIRE(getTranslation == glmGetTranslation);
			REQUIRE(getRotation == glmGetRotation);
			REQUIRE(getScale == glmGetScale);

			// Retrieve individual components

			// Translation component
			getTranslation = transformMatrix.GetTranslation();
			REQUIRE(getTranslation == glmGetTranslation);

			// Rotation component: recalculate rotation from the transform matrix
			for (int i = 0; i < 3; i++)
				scale[i] = glm::length(glm::vec3(glmTransformMatrix[i]));
			const glm::mat3 rotMtx(
				glm::vec3(glmTransformMatrix[0]) / scale[0],
				glm::vec3(glmTransformMatrix[1]) / scale[1],
				glm::vec3(glmTransformMatrix[2]) / scale[2]
			);
			glm::quat glmGetRotation2 = glm::quat_cast(rotMtx);
			glmGetRotation2 = glm::conjugate(glmGetRotation2);
			glm::vec3 eulerGetRotation2 = glm::eulerAngles(glmGetRotation2) * RadToDeg;
			glm::vec3 eulerGetRotation = glm::eulerAngles(glmGetRotation) * RadToDeg;
			// REQUIRE(eulerGetRotation == eulerGetRotation2);
			PCOMPARE(eulerGetRotation.x, eulerGetRotation2.x);
			PCOMPARE(eulerGetRotation.y, eulerGetRotation2.y);
			PCOMPARE(eulerGetRotation.z, eulerGetRotation2.z);

			getRotation = transformMatrix.GetRotation();
			REQUIRE(getRotation == glmGetRotation);

			// Scale component
			getScale = transformMatrix.GetScale();
			REQUIRE(getScale == glmGetScale);

			// Projection matrix test
			Mat4 projectionMatrix = Mat4::CreateProjectionMatrix(90.f, 4.f / 3.f, 0.01f, 1000.f);
			glm::mat4 glmProjectMatrix = glm::perspective(DegToRad * 90.f, 4.f / 3.f, 0.01f, 1000.f);
			REQUIRE(projectionMatrix == glmProjectMatrix);

			// View matrix test
			Mat4 viewMatrix = Mat4::CreateViewMatrix(translation, euler.ToQuaternion());
			glm::mat4 glmViewMatrix = glm::translate(glm::mat4(1), translation.ToGlm()) *
									   glm::mat4_cast(euler.ToQuaternion().ToGlm()) *
									   glm::scale(Vec3f(1, 1, -1).ToGlm());
			glmViewMatrix = glm::inverse(glmViewMatrix);
			REQUIRE(viewMatrix == glmViewMatrix);
			
			{
				Vec3f target = Vec3f::Zero();
				Vec3f pos(2, 2, 2);
				Vec3f up(0, 1, 0);
				REQUIRE(Mat4::LookAtRH(pos, target, up) == glm::lookAtRH(pos.ToGlm(), target.ToGlm(), up.ToGlm()));
				REQUIRE(Mat4::LookAtLH(pos, target, up) == glm::lookAtLH(pos.ToGlm(), target.ToGlm(), up.ToGlm()));
			}

			// Orthographic matrix test
			glm::mat4 glmOrtho = glm::ortho(-10.f, 10.f, -10.f, 10.f, 0.01f, 1000.f);
			Mat4 ortho = Mat4::CreateOrthographicMatrix(-10.f, 10.f, -10.f, 10.f, 0.01f, 1000.f);
			REQUIRE(ortho == glmOrtho);

			// Inverse matrix test
			Mat4 inverse = transformMatrix.CreateInverseMatrix();
			glm::mat4 glmInverse = glm::inverse(glmTransformMatrix);
			REQUIRE(inverse == glmInverse);

			// Transpose matrix test
			Mat4 transpose = transformMatrix.GetTranspose();
			glm::mat4 glmTranspose = glm::transpose(glmTransformMatrix);
			REQUIRE(transpose == glmTranspose);

			// Determinant test
			float determinant = transformMatrix.GetDeterminant(4);
			float glmDeterminant = glm::determinant(glmTransformMatrix);
			PCOMPARE(determinant, glmDeterminant);

			Vec3f point(1, 2, 3);
			Vec3f result = matrix.MultiplyPoint3x4(point);
			glm::vec3 glmResult = glm::vec3(matrix.ToGlm() * glm::vec4(point.ToGlm(), 1.0f));
			REQUIRE(result == glmResult);
		}

		TEST(SubscriptOperators)
		{
			// Verify subscript access for matrix2
			COMPARE(matrix2[0][1], 5.8f);
			COMPARE(matrix2[1][0], 6.3f);
			REQUIRE(matrix2[0] == Vec4f(1.2f, 5.8f, 3.4f, 9.1f));
			REQUIRE(matrix2[1] == Vec4f(6.3f, 2.7f, 8.9f, 4.5f));
			REQUIRE(matrix2[2] == Vec4f(7.2f, 3.1f, 5.6f, 2.8f));
			REQUIRE(matrix2[3] == Vec4f(9.4f, 4.7f, 1.8f, 6.2f));

			matrix[1] = Vec4f(1, 2, 3, 4);
			REQUIRE(matrix[1] == Vec4f(1, 2, 3, 4));
		}
	}
#pragma endregion
#pragma region Matrix 3 Tests

	NAMESPACE(Matrix_3)
	{
		// Initialize test matrices using raw values and vector constructors
		float values[9] = {
			10.35f, 147.3f, 10.35f,
			5.6f,   69.69f, 3.25f,
			10.5f,  7.8f,  71.f
		};
		Mat3 matrix = Mat3(values);

		constexpr Mat3 matrix2 = Mat3(
			Vec3f(5.8f, 3.4f, 9.1f),
			Vec3f(6.3f, 8.9f, 4.5f),
			Vec3f(9.4f, 4.7f, 1.8f)
		);

		TEST(Constructors)
		{
			// Verify identity matrix construction
			REQUIRE(Mat3(1) == Mat3::Identity());
			REQUIRE(Mat3::Identity() == glm::mat3(1));

			// Implicit conversion from Mat4 to Mat3 should preserve matrix values
			Mat4 tmp = matrix;
			Mat3 tmp2 = tmp;
			REQUIRE(matrix == tmp2);
		}

		TEST(ComparisonOperators)
		{
			// Create an equivalent glm matrix for comparison
			auto glmMatrix = glm::mat3(
				values[0], values[1], values[2],
				values[3], values[4], values[5],
				values[6], values[7], values[8]
			);

			// Verify equality and inequality operators
			REQUIRE(matrix != matrix2);
			REQUIRE(matrix == Mat3(values));
			REQUIRE(matrix.ToGlm() == glmMatrix);
			REQUIRE(matrix == matrix.ToGlm());
		}

		TEST(ArithmeticOperators)
		{
			// Matrix multiplication test
			Mat3 multiply = matrix * matrix2;
			glm::mat3 glmMultiply = matrix.ToGlm() * matrix2.ToGlm();
			REQUIRE(multiply == glmMultiply);

			// Vector multiplication test
			Vec3f vec3Value(5, 6, 14.f);
			REQUIRE(matrix * vec3Value == matrix.ToGlm() * vec3Value.ToGlm());

			// Matrix addition test
			REQUIRE(matrix + matrix2 == matrix.ToGlm() + matrix2.ToGlm());
		}

		TEST(TransformationMethods)
		{
			// Rotation using Euler angles
			Vec3f euler(32.5f, -63.21f, 17.93f);
			Mat3 rotationMatrix = Mat3::CreateRotationMatrix(euler);
			glm::mat3 glmRotationMatrix = glm::eulerAngleXYZ(
				DegToRad * euler.x, DegToRad * euler.y, DegToRad * euler.z
			);
			REQUIRE(rotationMatrix == glmRotationMatrix);

			// Rotation using Quaternion
			Quat eulerQuat = euler.ToQuaternion();
			Mat3 quatRotationMatrix = Mat3::CreateRotationMatrix(eulerQuat);
			glm::mat3 glmQuatRotationMatrix = glm::mat3(eulerQuat.ToGlm());
			REQUIRE(quatRotationMatrix == glmQuatRotationMatrix);

			// Scale transformation
			Vec3f scale(1, 2, 3);
			Mat3 scaleMatrix = Mat3::CreateScaleMatrix(scale);
			glm::mat3 glmIdentity = glm::mat3(1);
			glm::mat3 glmScaleMatrix;
			glmScaleMatrix[0] = glmIdentity[0] * scale[0];
			glmScaleMatrix[1] = glmIdentity[1] * scale[1];
			glmScaleMatrix[2] = glmIdentity[2] * scale[2];
			REQUIRE(scaleMatrix == glmScaleMatrix);

			// Combined transformation using Euler angles (rotation and scale)
			Mat3 transformMatrix = Mat3::CreateTransformMatrix(euler, scale);
			glm::mat3 glmTransformMatrix = glmRotationMatrix * glmScaleMatrix;
			REQUIRE(transformMatrix == glmTransformMatrix);

			// Combined transformation using Quaternion
			Mat3 transformQuatMatrix = Mat3::CreateTransformMatrix(eulerQuat, scale);
			glm::mat3 glmTransformQuatMatrix = glmQuatRotationMatrix * glmScaleMatrix;
			REQUIRE(transformQuatMatrix == glmTransformQuatMatrix);

			// Extract and compare rotation component
			glm::quat glmGetRotation = glm::quat(glm::transpose(glmRotationMatrix));
			Quat getRotation = transformMatrix.ToRotationMatrix().GetRotation();
			REQUIRE(getRotation == glmGetRotation);
			
			// Extract and compare scale component
			Vec3f getScale = transformMatrix.GetScale();
			glm::vec3 glmGetScale = glm::vec3(
				glm::length(glmTransformMatrix[0]),
				glm::length(glmTransformMatrix[1]),
				glm::length(glmTransformMatrix[2])
			);
			REQUIRE(getScale == glmGetScale);

			// Inverse matrix test
			Mat3 inverse = transformMatrix.CreateInverseMatrix();
			glm::mat3 glmInverse = glm::inverse(glmTransformMatrix);
			REQUIRE(inverse == glmInverse);

			// Transpose matrix test
			Mat3 transpose = transformMatrix.GetTranspose();
			glm::mat3 glmTranspose = glm::transpose(glmTransformMatrix);
			REQUIRE(transpose == glmTranspose);

			// Determinant test
			float determinant = transformMatrix.GetDeterminant(3);
			float glmDeterminant = glm::determinant(glmTransformMatrix);
			PCOMPARE(determinant, glmDeterminant);

		}

		TEST(SubscriptOperators)
		{
			// Verify subscript access for matrix2
			COMPARE(matrix2[0][1], 3.4f);
			COMPARE(matrix2[1][0], 6.3f);
			REQUIRE(matrix2[0] == Vec3f(5.8f, 3.4f, 9.1f));
			REQUIRE(matrix2[1] == Vec3f(6.3f, 8.9f, 4.5f));
			REQUIRE(matrix2[2] == Vec3f(9.4f, 4.7f, 1.8f));

			matrix[1] = Vec3f(1, 2, 3);
			REQUIRE(matrix[1] == Vec3f(1, 2, 3));
		}
	}
#pragma endregion
}

int main() {
	system("cls");   // used to clear and enable color on Windows
	runTests();
	return failed != 0;
}