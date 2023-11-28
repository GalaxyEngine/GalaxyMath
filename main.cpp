#include "include/VTest.hpp"

#define MATH_GLM_EXTENSION
#include "Maths.h"
using namespace GALAXY::Math;

#include <assert.h>

#include <glm/gtx/matrix_decompose.hpp>


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
			auto stringValue = value.ToString(4);
			REQUIRE(stringValue == std::string("1.5400, 2.3200, 23.4700, 3.6200"));
		}
	}
#pragma endregion

#pragma region Quaternion Tests
	NAMESPACE(Quaternion)
	{
		TEST(Constructors)
		{
			REQUIRE(Quat() == Quat(0, 0, 0, 1));
			REQUIRE(Quat(1) == Quat(1, 1, 1, 1));
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
			Quat quat1 = Quat(1, 2, 3, 4);
			Quat quat2 = Quat(5, 6, 7, 8);
			REQUIRE(quat1 + quat2 == quat1.ToGlm() + quat2.ToGlm());

			// Subtraction
			REQUIRE(quat1 - quat2 == quat1.ToGlm() - quat2.ToGlm());

			// Multiplication
			REQUIRE(quat1 * quat2 == quat1.ToGlm() * quat2.ToGlm());

			REQUIRE(quat1 * 5 == Quat(5, 10, 15, 20));

			Vec3f vectorValue = Vec3f(2.56f, 453.14f, 573.3f);
			auto result = quat1 * vectorValue;
			auto glmResult = quat1.ToGlm() * vectorValue.ToGlm();
			REQUIRE(quat1 * vectorValue == quat1.ToGlm() * vectorValue.ToGlm());
		}
		TEST(Subscript Operators)
		{
			Quat value(1.f, 3.95f, -50, 2.5f);
			COMPARE(value[0], 1);
			COMPARE(value[1], 3.95f);
			COMPARE(value[2], -50);
			COMPARE(value[3], 2.50f);
			COMPARE(value[4], 1);
		}
		TEST(Assignement Operators)
		{
			Quat quat1 = Quat(1, 2, 3, 4);
			Quat quat2 = Quat(5, 6, 7, 8);
			quat1 *= 5;
			REQUIRE(quat1 == Quat(5, 10, 15, 20));

			auto glmResult = quat1.ToGlm() * quat2.ToGlm();
			quat1 *= quat2;
			REQUIRE(quat1 == glmResult);

			Vec3f vectorValue = Vec3f(2.56f, 453.14f, 573.3f);
			auto glmResult2 = quat1.ToGlm() * vectorValue.ToGlm();

			REQUIRE(quat1 * vectorValue == glmResult2);
		}
		TEST(Methods)
		{
			REQUIRE(Quat::Identity() == Quat(0, 0, 0, 1));

			float angle = 36.32f;
			Vec3f axis(0, 1, 0);

			Quat angleAxis = Quat::AngleAxis(angle, axis);
			glm::quat glmAngleAxis = glm::angleAxis(angle * DegToRad, axis.ToGlm());
			REQUIRE(angleAxis == glmAngleAxis);

			Vec3f euler(32.5f, -63.21f, 17.93f);
			Quat eulerQuat = Quat::FromEuler(euler);
			glm::quat glmEulerQuat = glm::quat(DegToRad * euler.ToGlm());
			REQUIRE(eulerQuat == glmEulerQuat);

			Vec3f forward(0, 0, 1);
			Vec3f up(0, 1, 0);
			REQUIRE(Quat::LookRotation(forward, up) == Quat::Identity());

			Quat quat1 = Quat(1, 2, 3, 4);
			Quat quat2 = Quat(5, 6, 7, 8);
			REQUIRE(Quat::SLerp(quat1, quat2, 0.5f) == glm::mix(quat1.ToGlm(), quat2.ToGlm(), 0.5f));

			REQUIRE(quat1.GetInverse() == glm::inverse(quat1.ToGlm()));
			REQUIRE(quat1.GetNormalize() == glm::normalize(quat1.ToGlm()));
			REQUIRE(quat1.GetConjugate() == glm::conjugate(quat1.ToGlm()));
			COMPARE(quat1.Dot(quat2), glm::dot(quat1.ToGlm(), quat2.ToGlm()));

			Vec3f previousEuler = euler;
			euler = eulerQuat.ToEuler();
			auto glmEuler = glm::eulerAngles(glmEulerQuat) * RadToDeg;
			REQUIRE(euler == glmEuler);
			//REQUIRE(euler == previousEuler);

			REQUIRE(quat1.ToString() == std::string("1.000000, 2.000000, 3.000000, 4.000000"));
		}
	}
#pragma endregion

#pragma region Matrix 4 Tests
	NAMESPACE(Matrix_4)
	{
		float values[16] = { 2.5f,	10.35f, 147.3f, 10.35f,
							5.6f,	72.36f, 69.69f, 5.75f,
							78.f,	14.f,	3.25f,	10.5f,
							7.8f,	32.6f,	71,		6.78 };
		Mat4 matrix = Mat4(values);

		Mat4 matrix2 = Mat4(Vec4f(1.2f, 5.8f, 3.4f, 9.1f),
			Vec4f(6.3f, 2.7f, 8.9f, 4.5f),
			Vec4f(7.2f, 3.1f, 5.6f, 2.8f),
			Vec4f(9.4f, 4.7f, 1.8f, 6.2f));

		TEST(Constructors)
		{
			REQUIRE(Mat4(1) == Mat4::Identity());
			REQUIRE(Mat4::Identity() == glm::mat4(1));
		}
		TEST(Comparison Operators)
		{

			auto glmMatrix = glm::mat4(
				values[0], values[1], values[2], values[3],
				values[4], values[5], values[6], values[7],
				values[8], values[9], values[10], values[11],
				values[12], values[13], values[14], values[15]);

			REQUIRE(matrix != matrix2);
			REQUIRE(matrix == Mat4(values));
			REQUIRE(matrix.ToGlm() == glmMatrix);
			REQUIRE(matrix == matrix.ToGlm());
		}
		TEST(Arithmetic Operators)
		{
			Mat4 multiply = matrix * matrix2;
			glm::mat4 glmMultiply = matrix.ToGlm() * matrix2.ToGlm();
			REQUIRE(multiply == glmMultiply);

			Vec4f vec4Value = Vec4f(5, 6, 3.2f, 14.f);
			REQUIRE(matrix * vec4Value == matrix.ToGlm() * vec4Value.ToGlm());

			REQUIRE(matrix + matrix2 == matrix.ToGlm() + matrix2.ToGlm());
		}
		TEST(Methods)
		{
			// Translation
			Vec3f translation = Vec3f(1, 2, 3);
			Mat4 translationMatrix = Mat4::CreateTranslationMatrix(translation);
			glm::mat4 glmTranslationMatrix = glm::translate(glm::mat4(1), translation.ToGlm());
			REQUIRE(translationMatrix == glmTranslationMatrix);

			// Rotation
			Vec3f euler(32.5f, -63.21f, 17.93f);
			Mat4 rotationMatrix = Mat4::CreateRotationMatrix(euler);
			glm::mat4 glmRotationMatrix = glm::eulerAngleXYZ(DegToRad * euler.x, DegToRad * euler.y, DegToRad * euler.z);
			REQUIRE(rotationMatrix == glmRotationMatrix);

			// Quaternion
			Quat eulerQuat = euler.ToQuaternion();
			Mat4 quatRotationMatrix = Mat4::CreateRotationMatrix(eulerQuat);
			glm::mat4 glmQuatRotationMatrix = glm::mat4(eulerQuat.ToGlm());
			REQUIRE(quatRotationMatrix == glmQuatRotationMatrix);

			// Scale
			Vec3f scale = Vec3f(1, 2, 3);
			Mat4 scaleMatrix = Mat4::CreateScaleMatrix(scale);
			glm::mat4 glmScaleMatrix = glm::scale(glm::mat4(1), scale.ToGlm());
			REQUIRE(scaleMatrix == glmScaleMatrix);

			// Transform with euler
			Mat4 transformMatrix = Mat4::CreateTransformMatrix(translation, euler, scale);
			glm::mat4 glmTransformMatrix = glmTranslationMatrix * glmRotationMatrix * glmScaleMatrix;
			REQUIRE(transformMatrix == glmTransformMatrix);

			// Transform with quaternion
			Mat4 transformQuatMatrix = Mat4::CreateTransformMatrix(translation, eulerQuat, scale);
			glm::mat4 glmTransformQuatMatrix = glmTranslationMatrix * glmQuatRotationMatrix * glmScaleMatrix;
			REQUIRE(transformQuatMatrix == glmTransformQuatMatrix);

			// Decompose
			glm::vec3 glmGetTranslation;
			glm::quat glmGetRotation;
			glm::vec3 glmGetScale;
			glm::vec3 glmSkew;
			glm::vec4 glmPerspective;

			Vec3f getTranslation;
			Quat getRotation;
			Vec3f getScale;

			transformMatrix.DecomposeTransformMatrix(getTranslation, getRotation, getScale);

			assert(glm::decompose(glmTransformMatrix, glmGetScale, glmGetRotation, glmGetTranslation, glmSkew, glmPerspective));
			glmGetRotation = glm::conjugate(glmGetRotation);

			REQUIRE(getTranslation == glmGetTranslation);
			REQUIRE(getRotation == glmGetRotation);
			REQUIRE(getScale == glmGetScale);

			// Get Individuals components
			// Get Translation
			getTranslation = transformMatrix.GetTranslation();
			REQUIRE(getTranslation == glmGetTranslation);

			// Get Rotation
			for (int i = 0; i < 3; i++)
				scale[i] = glm::length(glm::vec3(glmTransformMatrix[i]));
			const glm::mat3 rotMtx(
				glm::vec3(glmTransformMatrix[0]) / scale[0],
				glm::vec3(glmTransformMatrix[1]) / scale[1],
				glm::vec3(glmTransformMatrix[2]) / scale[2]);

			glm::quat glmGetRotation2 = glm::quat_cast(rotMtx);
			glmGetRotation2 = glm::conjugate(glmGetRotation2);
			glm::vec3 eulerGetRotation2 = glm::eulerAngles(glmGetRotation2) * RadToDeg;
			glm::vec3 eulerGetRotation = glm::eulerAngles(glmGetRotation) * RadToDeg;

			getRotation = transformMatrix.GetRotation();
			REQUIRE(getRotation == glmGetRotation);

			// Get Scale
			getScale = transformMatrix.GetScale();
			REQUIRE(getScale == glmGetScale);

			// Create Projection Matrix
			auto projectionMatrix = Mat4::CreateProjectionMatrix(90.f, 4.f / 3.f, 0.01f, 1000.f);
			auto glmProjectMatrix = glm::perspective(DegToRad * 90.f, 4.f / 3.f, 0.01f, 1000.f);
			REQUIRE(projectionMatrix == glmProjectMatrix);

			auto viewMatrix = Mat4::CreateViewMatrix(translation, euler.ToQuaternion());
			glm::vec3 forward = euler.ToQuaternion().ToGlm() * Vec3f(0, 0, 1).ToGlm();
			auto glmViewMatrix = glm::lookAt(translation.ToGlm(), translation.ToGlm() + forward, glm::vec3(0, 1, 0));
			
			Mat4(glmViewMatrix).Print();
			viewMatrix.Print();
			
			REQUIRE(viewMatrix == glmViewMatrix);

			// Create Inverse matrix
			Mat4 inverse = transformMatrix.CreateInverseMatrix();
			glm::mat4 glmInverse = glm::inverse(glmTransformMatrix);
			REQUIRE(inverse == glmInverse);

			// Create Transpose matrix
			Mat4 transpose = transformMatrix.GetTranspose();
			glm::mat4 glmTranspose = glm::transpose(glmTransformMatrix);
			REQUIRE(transpose == glmTranspose);

			// Get Determinant
			float determinant = transformMatrix.GetDeterminant(4);
			float glmDeterminant = glm::determinant(glmTransformMatrix);
			REQUIRE(AlmostEqual(determinant, glmDeterminant));
		}
		TEST(Subscript Operators)
		{
			COMPARE(matrix2[0][1], 5.8f);
			COMPARE(matrix2[1][0], 6.3f);
			REQUIRE(matrix2[0] == Vec4f(1.2f, 5.8f, 3.4f, 9.1f));
			REQUIRE(matrix2[1] == Vec4f(6.3f, 2.7f, 8.9f, 4.5f));
			REQUIRE(matrix2[2] == Vec4f(7.2f, 3.1f, 5.6f, 2.8f));
			REQUIRE(matrix2[3] == Vec4f(9.4f, 4.7f, 1.8f, 6.2f));
		}
	}
}

int main() {
	system("cls");   // used to clear and enable color on Windows
	runTests();
	system("pause"); // used to pause at the end on Windows;
	return 0;
}