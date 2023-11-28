#include <iomanip>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <type_traits>

#include "Maths.h"

namespace GALAXY::Math {
#pragma region Math Functions

	template<typename T>
	bool AlmostEqual(T a, T b, float diff /*= 1e-5f*/)
	{
		T absoluteDiff = std::abs(a - b);
		return absoluteDiff <= diff;
	}

#pragma endregion

#pragma region Vec2
	template<typename T>
	template<typename U>
	inline Vec2<T>::Vec2(const Vec2<U>& a)
	{
		x = static_cast<T>(a.x);
		y = static_cast<T>(a.y);
	}

	template<typename T>
	template<typename U>
	inline Vec2<T>::Vec2(const Vec3<U>& a)
	{
		x = static_cast<T>(a.x);
		y = static_cast<T>(a.y);
	}

	template<typename T>
	inline Vec2<T>::Vec2(const std::string& str)
	{
		std::istringstream ss(str);

		char discard;
		ss >> this->x >> discard >> this->y;
	}

	template<typename T>
	template<typename U>
	inline Vec2<T> Vec2<T>::operator=(const Vec2<U>& a)
	{
		x = static_cast<T>(a.x);
		y = static_cast<T>(a.y);
		return *this;
	}

	template<typename T>
	template<typename U>
	inline Vec2<T> Vec2<T>::operator=(const Vec3<U>& a)
	{
		return Vec2(a);
	}

	template<typename T>
	template<typename U>
	inline Vec2<T> Vec2<T>::operator+(const Vec2<U>& a) const
	{
		return { static_cast<T>(x + a.x), static_cast<T>(y + a.y) };
	}

	template<typename T>
	template<typename U>
	inline void Vec2<T>::operator+=(const Vec2<U>& a)
	{
		*this = operator+(a);
	}

	template<typename T>
	template<typename U>
	inline Vec2<T> Vec2<T>::operator-(const Vec2<U>& a) const
	{
		return { static_cast<T>(x - a.x), static_cast<T>(y - a.y) };
	}

	template<typename T>
	template<typename U>
	inline void Vec2<T>::operator-=(const Vec2<U>& a)
	{
		*this = operator-(a);
	}

	template<typename T>
	inline Vec2<T> Vec2<T>::operator-(void) const
	{
		return { -x, -y };
	}

	template<typename T>
	template<typename U>
	inline Vec2<T> Vec2<T>::operator*(const U& a) const
	{
		return { static_cast<T>(x * a), static_cast<T>(y * a) };
	}

	template<typename T>
	template<typename U>
	inline Vec2<T> Vec2<T>::operator*(const Vec2<U>& a) const
	{
		return { static_cast<T>(x * a.x), static_cast<T>(y * a.y) };
	}

	template<typename T>
	template<typename U>
	inline void Vec2<T>::operator*=(const Vec2<U>& a)
	{
		*this = operator*(a);
	}

	template<typename T>
	template<typename U>
	inline void Vec2<T>::operator*=(const U& a)
	{
		*this = operator*(a);
	}

	template<typename T>
	template<typename U>
	inline Vec2<T> Vec2<T>::operator/(const U& a) const
	{
		return { x / a, y / a };
	}

	template<typename T>
	template<typename U>
	inline void Vec2<T>::operator/=(const U& a)
	{
		*this = operator/(a);
	}

	template<typename T>
	template<typename U>
	inline bool Vec2<T>::operator==(const Vec2<U>& a) const
	{
		// "this" vector has the authority for the type comparison
		return AlmostEqual(x, static_cast<T>(a.x)) && AlmostEqual(y, static_cast<T>(a.y));
	}

	template<typename T>
	template<typename U>
	inline bool Vec2<T>::operator==(const Vec3<U>& b) const
	{
		// "this" vector has the authority for the type comparison
		return AlmostEqual(x, static_cast<T>(b.x)) && AlmostEqual(y, static_cast<T>(b.y));
	}

	template<typename T>
	template<typename U>
	bool Vec2<T>::operator!=(const Vec2<U>& a) const
	{
		// "this" vector has the authority for the type comparison
		return !AlmostEqual(x, static_cast<T>(a.x)) || !AlmostEqual(y, static_cast<T>(a.y));
	}

	template<typename T>
	template<typename U>
	inline bool Vec2<T>::operator!=(const Vec3<U>& b) const
	{
		return !AlmostEqual(x, static_cast<T>(b.x)) || !AlmostEqual(y, static_cast<T>(b.y));
	}

	template<typename T>
	inline T& Vec2<T>::operator[](const size_t a)
	{
		if (a >= 2)
			// Return first value of the vector if not valid index
			return this->x;
		return *((&x) + a);
	}

	template<typename T>
	inline T Vec2<T>::LengthSquared() const
	{
		return x * x + y * y;
	}

	template<typename T>
	inline T Vec2<T>::Length() const
	{
		return static_cast<T>(std::sqrt(LengthSquared()));
	}

	template<typename T>
	inline T Vec2<T>::Dot(const Vec2& a) const
	{
		return a.x * x + a.y * y;
	}

	template<typename T>
	inline Vec2<T> Vec2<T>::Cross(const Vec2& a) const
	{
		return { x * a.y, y * a.x };
	}

	template<typename T>
	inline Vec2<T> Vec2<T>::Ortho() const
	{
		return { -y, x };
	}

	template<typename T>
	void Math::Vec2<T>::Normalize()
	{
		*this = GetNormalize();
	}

	template<typename T>
	inline Vec2<T> Math::Vec2<T>::GetNormalize() const
	{
		T len = Length();
		if (len != 0)
			return { x / len, y / len };
		return {};
	}

	template<typename T>
	inline void Vec2<T>::Print(int precision /*= 6*/) const
	{
		std::cout << std::fixed << std::setprecision(precision);
		std::cout << x << ", " << y << std::endl;
	}

	template<typename T>
	inline std::string Vec2<T>::ToString(int precision /*= 6*/) const
	{
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(precision);

		oss << x << ", " << y;

		return oss.str();
	}

	template<typename T>
	inline Vec2<float> Vec2<T>::ToVec2f() const
	{
		return Vec2f{ static_cast<float>(x), static_cast<float>(y) };
	}

	template<typename T>
	inline Vec2<int> Vec2<T>::ToVec2i() const
	{
		return Vec2i{ static_cast<int>(x), static_cast<int>(y) };
	}

	template<typename T>
	inline T* Vec2<T>::Data() const
	{
		return const_cast<T*>(reinterpret_cast<const T*>(this));
	}

#pragma endregion

#pragma region Vec3

	template<typename T>
	inline Vec3<T>::Vec3(const std::string& str)
	{
		std::istringstream ss(str);

		char discard;
		ss >> this->x >> discard >> this->y >> discard >> this->z;
	}

	template<typename T>
	template<typename U>
	inline Vec3<T>::Vec3(const Vec2<U>& xy, T _z)
	{
		x = static_cast<T>(xy.x);
		y = static_cast<T>(xy.y);
		z = _z;
	}

	template<typename T>
	template<typename U>
	inline Vec3<T>::Vec3(const Vec3<U>& a)
	{
		x = static_cast<T>(a.x);
		y = static_cast<T>(a.y);
		z = static_cast<T>(a.z);
	}

	template<typename T>
	template<typename U>
	inline Vec3<T>::Vec3(const Vec4<U>& a)
	{
		x = static_cast<T>(a.x);
		y = static_cast<T>(a.y);
		z = static_cast<T>(a.z);
	}

	template<typename T>
	template<typename U>
	inline Vec3<T> Vec3<T>::operator*(const U& b) const
	{
		return { static_cast<T>(x * b), static_cast<T>(y * b), static_cast<T>(z * b) };
	}

	template<typename T>
	template<typename U>
	inline Vec3<T> Vec3<T>::operator/(const U& b) const
	{
		return { x / b, y / b, z / b };
	}

	template<typename T>
	template<typename U>
	inline void Vec3<T>::operator*=(const U& b)
	{
		*this = operator*(b);
	}

	template<typename T>
	template<typename U>
	inline void Vec3<T>::operator/=(const U& b)
	{
		*this = operator/(b);
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::operator+(const Vec3& b) const
	{
		return { x + b.x, y + b.y, z + b.z };
	}

	template<typename T>
	inline void Vec3<T>::operator+=(const Vec3& b)
	{
		*this = operator+(b);
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::operator-(const Vec3& b) const
	{
		return { x - b.x, y - b.y, z - b.z };
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::operator-(void) const
	{
		return { -x, -y, -z };
	}

	template<typename T>
	inline void Vec3<T>::operator-=(const Vec3& b)
	{
		*this = operator-(b);
	}

	template<typename T>
	template<typename U>
	inline Vec3<T> Vec3<T>::operator*(const Vec3<U>& b) const
	{
		return { static_cast<T>(x * b.x), static_cast<T>(y * b.y), static_cast<T>(z * b.z) };
	}

	template<typename T>
	inline void Vec3<T>::operator*=(const Vec3& b)
	{
		*this = operator*(b);
	}

	template<typename T>
	template<typename U>
	inline bool Vec3<T>::operator==(const Vec3<U>& a) const
	{
		return AlmostEqual(x, static_cast<T>(a.x)) && AlmostEqual(y, static_cast<T>(a.y)) && AlmostEqual(z, static_cast<T>(a.z));
	}

	template<typename T>
	template<typename U>
	inline bool Vec3<T>::operator!=(const Vec3<U>& a) const
	{
		return !AlmostEqual(x, static_cast<T>(a.x)) || !AlmostEqual(y, static_cast<T>(a.y)) || !AlmostEqual(z, static_cast<T>(a.z));
	}

	template<typename T>
	inline T& Vec3<T>::operator[](const size_t a)
	{
		if (a >= 3)
			return x;
		return *((&x) + a);
	}

	template<typename T>
	inline const T& Vec3<T>::operator[](const size_t a) const
	{
		return *((&x) + a);
	}

	template<typename T>
	inline T Vec3<T>::LengthSquared() const
	{
		return x * x + y * y + z * z;
	}

	template<typename T>
	inline T Vec3<T>::Length() const
	{
		return std::sqrt(LengthSquared());
	}

	template<typename T>
	inline T Vec3<T>::Dot(const Vec3& a) const
	{
		return x * a.x + y * a.y + z * a.z;
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::Cross(const Vec3& a) const
	{
		return { (y * a.z) - (z * a.y), (z * a.x) - (x * a.z), (x * a.y) - (y * a.x) };
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::GetNormalize() const
	{
		T len = Length();
		if (len != 0)
			return { x / len, y / len, z / len };
		return {};
	}

	template<typename T>
	inline void Vec3<T>::Normalize()
	{
		*this = GetNormalize();
	}

	template<typename T>
	inline T Vec3<T>::Distance(const Vec3& a) const
	{
		T i = a.x - x;
		T j = a.y - y;
		T h = a.z - z;
		return std::sqrt(i * i + j * j + h * h);
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::Lerp(const Vec3& b, float t) const
	{
		if (t < 0)
			return *this;
		else if (t >= 1)
			return b;
		return (*this) * (1 - t) + b * t;
	}

	template<typename T>
	inline void Vec3<T>::Print(int precision /*= 6*/) const
	{
		std::cout << std::fixed << std::setprecision(precision);
		std::cout << x << ", " << y << ", " << z << std::endl;
	}

	template<typename T>
	inline std::string Vec3<T>::ToString(int precision /*= 6*/) const
	{
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(precision);
		oss << x << ", " << y << ", " << z;
		return oss.str();
	}

	template<typename T>
	inline Quat Vec3<T>::ToQuaternion() const
	{
		Quat result;
		Vec3<T> eulerAngle = *this * DegToRad;

		Vec3<T> c;
		c.x = std::cos(eulerAngle.x * T(0.5));
		c.y = std::cos(eulerAngle.y * T(0.5));
		c.z = std::cos(eulerAngle.z * T(0.5));

		Vec3<T> s;
		s.x = std::sin(eulerAngle.x * T(0.5));
		s.y = std::sin(eulerAngle.y * T(0.5));
		s.z = std::sin(eulerAngle.z * T(0.5));

		result.w = c.x * c.y * c.z + s.x * s.y * s.z;
		result.x = s.x * c.y * c.z - c.x * s.y * s.z;
		result.y = c.x * s.y * c.z + s.x * c.y * s.z;
		result.z = c.x * c.y * s.z - s.x * s.y * c.z;
		return result;
	}


	template<typename T>
	inline T* Vec3<T>::Data() const
	{
		return const_cast<T*>(reinterpret_cast<const T*>(this));
	}

#pragma endregion

#pragma region Vec4
	template<typename T>
	inline Vec4<T>::Vec4(const std::string& str)
	{
		std::istringstream ss(str);

		char discard;
		ss >> this->x >> discard >> this->y >> discard >> this->z >> discard >> this->w;
	}

	template<typename T>
	template<typename U>
	inline Vec4<T>::Vec4(const Vec2<U>& xy, T _z /*= 0*/, T _w /*= 0*/)
	{
		x = static_cast<T>(xy.x);
		y = static_cast<T>(xy.y);
		z = _z;
		w = _w;
	}

	template<typename T>
	template<typename U>
	inline Vec4<T>::Vec4(const Vec3<U>& xyz, T _w /*= 0*/)
	{
		x = static_cast<T>(xyz.x);
		y = static_cast<T>(xyz.y);
		z = static_cast<T>(xyz.z);
		w = _w;
	}

	template<typename T>
	template<typename U>
	inline Vec4<T>::Vec4(const Vec4<U>& a)
	{
		x = static_cast<T>(a.x);
		y = static_cast<T>(a.y);
		z = static_cast<T>(a.z);
		w = static_cast<T>(a.w);
	}

	template<typename T>
	template<typename U>
	inline Vec4<T> Vec4<T>::operator=(const Vec3<U>& b)
	{
		this->x = static_cast<T>(b.x);
		this->y = static_cast<T>(b.y);
		this->z = static_cast<T>(b.z);
		return *this;
	}

	template<typename T>
	inline Vec4<T> Vec4<T>::operator+(const Vec4& b) const {
		return { x + b.x, y + b.y, z + b.z, w + b.w };
	}

	template<typename T>
	inline Vec4<T> Vec4<T>::operator-(const Vec4& b) const {
		return { x - b.x, y - b.y, z - b.z, w - b.w };
	}

	template<typename T>
	inline Vec4<T> Vec4<T>::operator-(void) const {
		return { -x, -y, -z, -w };
	}

	template<typename T>
	template<typename U>
	inline Vec4<T> Vec4<T>::operator*(const Vec4<U>& b) const {
		return Vec4(x * b.x, y * b.y, z * b.z, w * b.w);
	}

	template<typename T>
	template<typename U>
	inline Vec4<T> Vec4<T>::operator*(const U& b) const {
		return { x * b, y * b, z * b, w * b };
	}

	template<typename T>
	template<typename U>
	inline Vec4<T> Vec4<T>::operator/(const U& b) const {
		return { x / b, y / b, z / b, w / b };
	}

	template<typename T>
	inline void Vec4<T>::operator+=(const Vec4& b) {
		*this = operator+(b);
	}

	template<typename T>
	inline void Vec4<T>::operator-=(const Vec4& b) {
		*this = operator-(b);
	}

	template<typename T>
	inline void Vec4<T>::operator*=(const Vec4& b) {
		*this = operator*(b);
	}

	template<typename T>
	template<typename U>
	inline void Vec4<T>::operator*=(const U& b) {
		*this = operator*(b);
	}

	template<typename T>
	template<typename U>
	inline void Vec4<T>::operator/=(const U& b) {
		*this = operator/(b);
	}

	template<typename T>
	template<typename U>
	inline bool Vec4<T>::operator==(const Vec4<U>& b) const {
		return AlmostEqual(x, static_cast<T>(b.x)) && AlmostEqual(y, static_cast<T>(b.y))
			&& AlmostEqual(z, static_cast<T>(b.z)) && AlmostEqual(w, static_cast<T>(b.w));
	}

	template<typename T>
	template<typename U>
	inline bool Vec4<T>::operator!=(const Vec4<U>& b) const {
		return !AlmostEqual(x, static_cast<T>(b.x)) || !AlmostEqual(y, static_cast<T>(b.y))
			|| !AlmostEqual(z, static_cast<T>(b.z)) || !AlmostEqual(w, static_cast<T>(b.w));
	}

	template<typename T>
	inline T& Vec4<T>::operator[](const size_t a) {
		if (a >= 4)
			return x;
		return *((&x) + a);
	}

	template<typename T>
	inline const T& Vec4<T>::operator[](const size_t a) const {
		if (a >= 4)
			return x;
		return *((&x) + a);
	}

	template<typename T>
	inline T Vec4<T>::LengthSquared() const {
		return (x * x + y * y + z * z + w * w);
	}

	template<typename T>
	inline T Vec4<T>::Length() const {
		return std::sqrt(LengthSquared());
	}

	template<typename T>
	inline T Vec4<T>::Dot(const Vec4& a) const {
		return (x * a.x + y * a.y + z * a.z + w * a.w);
	}

	template<typename T>
	inline T Vec4<T>::Distance(const Vec4& a) const {
		return (a - *this).Length();
	}

	template<typename T>
	Vec4<T> Vec4<T>::GetHomogenize() const
	{
		return { ToVector3() / w };
	}

	template<typename T>
	void Vec4<T>::Homogenize()
	{
		*this = GetHomogenize();
	}

	template<typename T>
	inline void Vec4<T>::Normalize()
	{
		*this = GetNormalize();
	}

	template<typename T>
	inline Vec4<T> Vec4<T>::GetNormalize() const {
		T len = Length();
		if (len != 0)
			return operator/(len);
		return {};
	}

	template<typename T>
	void Vec4<T>::Print(int precision /*= 6*/) const
	{
		std::cout << std::fixed << std::setprecision(precision);
		std::cout << x << ", " << y << ", " << z << ", " << w << std::endl;
	}

	template<typename T>
	Vec3<T> Vec4<T>::ToVector3() const
	{
		return { x, y, z };
	}

	template<typename T>
	std::string Vec4<T>::ToString(int precision /*= 6*/) const
	{
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(precision);
		oss << x << ", " << y << ", " << z << ", " << w;
		return oss.str();
	}

	template<typename T>
	T* Vec4<T>::Data() const
	{
		return const_cast<T*>(reinterpret_cast<const T*>(this));
	}

#pragma endregion

#pragma  region Mat4
	inline Mat4::Mat4(float diagonal)
	{
		content[0][0] = 1;
		content[1][1] = 1;
		content[2][2] = 1;
		content[3][3] = 1;
	}

	inline Mat4::Mat4(Vec4f m0, Vec4f m1, Vec4f m2, Vec4f m3)
	{
		content[0] = m0;
		content[1] = m1;
		content[2] = m2;
		content[3] = m3;
	}


	inline Mat4::Mat4(const float* data)
	{
		for (size_t i = 0; i < 4; ++i) {
			for (size_t j = 0; j < 4; ++j) {
				content[i][j] = data[i * 4 + j];
			}
		}
	}

	inline Mat4::Mat4(const double* data)
	{
		for (size_t i = 0; i < 4; ++i) {
			for (size_t j = 0; j < 4; ++j) {
				content[i][j] = static_cast<float>(data[i * 4 + j]);
			}
		}
	}

	inline Mat4 Mat4::operator*(const Mat4& a) const
	{
		Vec4f SrcA0 = this->content[0];
		Vec4f SrcA1 = this->content[1];
		Vec4f SrcA2 = this->content[2];
		Vec4f SrcA3 = this->content[3];

		Vec4f SrcB0 = a.content[0];
		Vec4f SrcB1 = a.content[1];
		Vec4f SrcB2 = a.content[2];
		Vec4f SrcB3 = a.content[3];

		Mat4 Result;
		Result[0] = SrcA0 * SrcB0[0] + SrcA1 * SrcB0[1] + SrcA2 * SrcB0[2] + SrcA3 * SrcB0[3];
		Result[1] = SrcA0 * SrcB1[0] + SrcA1 * SrcB1[1] + SrcA2 * SrcB1[2] + SrcA3 * SrcB1[3];
		Result[2] = SrcA0 * SrcB2[0] + SrcA1 * SrcB2[1] + SrcA2 * SrcB2[2] + SrcA3 * SrcB2[3];
		Result[3] = SrcA0 * SrcB3[0] + SrcA1 * SrcB3[1] + SrcA2 * SrcB3[2] + SrcA3 * SrcB3[3];
		return Result;
	}

	template<typename U>
	inline Vec4<U> Mat4::operator*(const Vec4<U>& a) const
	{
		Vec4f Mov0(a[0]);
		Vec4f Mov1(a[1]);
		Vec4f Mul0 = content[0] * Mov0;
		Vec4f Mul1 = content[1] * Mov1;
		Vec4f Add0 = Mul0 + Mul1;
		Vec4f Mov2(a[2]);
		Vec4f Mov3(a[3]);
		Vec4f Mul2 = content[2] * Mov2;
		Vec4f Mul3 = content[3] * Mov3;
		Vec4f Add1 = Mul2 + Mul3;
		Vec4f Add2 = Add0 + Add1;
		return Add2;
	}

	inline Mat4 Mat4::operator+(const Mat4& a) const
	{
		Mat4 tmp;
		for (size_t j = 0; j < 4; j++)
		{
			tmp.content[j] = content[j] + a.content[j];
		}
		return tmp;
	}

	inline Vec4f& Mat4::operator[](const size_t i)
	{
		return content[i];
	}

	inline bool Mat4::operator==(const Mat4& b) const
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (!AlmostEqual(b.content[i][j], content[i][j]))
					return false;
			}
		}
		return true;
	}

	inline Mat4 Mat4::CreateProjectionMatrix(float _fov, float _aspect, float _near, float _far)
	{
		float tanHalfFov = std::tan(_fov * DegToRad * 0.5f);

		Mat4 projectionMatrix = Mat4();
		projectionMatrix[0][0] = 1.0f / (_aspect * tanHalfFov);
		projectionMatrix[1][1] = 1.0f / tanHalfFov;
		projectionMatrix[2][2] = -(_far + _near) / (_far - _near);
		projectionMatrix[2][3] = -1.0f;
		projectionMatrix[3][2] = -(2.0f * _far * _near) / (_far - _near);
		projectionMatrix[3][3] = 0.0f;

		return projectionMatrix;
	}

	inline Mat4 Mat4::CreateViewMatrix(const Vec3f position, const Quat& rotation)
	{
		Mat4 out = Mat4::CreateTransformMatrix(position, rotation, Vec3f(1, 1, -1));
		out = out.CreateInverseMatrix();
		return out;
	}

	template<typename U>
	inline Mat4 Mat4::CreateTranslationMatrix(const Vec3<U>& translation)
	{
		Mat4 out(1);
		out[3] = translation;
		return out;
	}

	inline Mat4 Mat4::CreateRotationMatrix(const Quat& rotation)
	{
		return rotation.ToRotationMatrix();
	}

	template<typename U>
	inline Mat4 Mat4::CreateRotationMatrix(const Vec3<U>& rotation)
	{
		float t1 = rotation.x * DegToRad;
		float t2 = rotation.y * DegToRad;
		float t3 = rotation.z * DegToRad;
		float c1 = std::cos(-t1);
		float c2 = std::cos(-t2);
		float c3 = std::cos(-t3);
		float s1 = std::sin(-t1);
		float s2 = std::sin(-t2);
		float s3 = std::sin(-t3);

		Mat4 Result;
		Result[0][0] = c2 * c3;
		Result[0][1] = -c1 * s3 + s1 * s2 * c3;
		Result[0][2] = s1 * s3 + c1 * s2 * c3;
		Result[0][3] = 0.f;
		Result[1][0] = c2 * s3;
		Result[1][1] = c1 * c3 + s1 * s2 * s3;
		Result[1][2] = -s1 * c3 + c1 * s2 * s3;
		Result[1][3] = 0.f;
		Result[2][0] = -s2;
		Result[2][1] = s1 * c2;
		Result[2][2] = c1 * c2;
		Result[2][3] = 0.f;
		Result[3][0] = 0.f;
		Result[3][1] = 0.f;
		Result[3][2] = 0.f;
		Result[3][3] = 1.f;
		return Result;
	}

	template<typename U>
	inline Mat4 Mat4::CreateScaleMatrix(const Vec3<U>& scale)
	{
		Mat4 out(1);
		for (size_t i = 0; i < 3; i++)
			out[i][i] = scale[i];
		return out;
	}

	template<typename U>
	inline Mat4 Mat4::CreateTransformMatrix(const Vec3<U>& position, const Vec3<U>& rotation, const Vec3<U>& scale)
	{
		return CreateTranslationMatrix(position) * CreateRotationMatrix(rotation) * CreateScaleMatrix(scale);
	}

	template<typename U>
	inline Mat4 Mat4::CreateTransformMatrix(const Vec3<U>& position, const Quat& rotation, const Vec3<U>& scale)
	{
		return CreateTranslationMatrix(position) * rotation.ToRotationMatrix() * CreateScaleMatrix(scale);
	}
	/*

	inline Quat Mat4::ToQuaternion()
	{
		float w = sqrtf(1 + at(0, 0) + at(1, 1) + at(2, 2)) / 2;
		return Quat((at(2, 1) - at(1, 2)) / (4 * w), (at(0, 2) - at(2, 0)) / (4 * w), (at(1, 0) - at(0, 1)) / (4 * w), w);
	}
	*/

	inline void Mat4::DecomposeTransformMatrix(Vec3f& translation, Quat& rotation, Vec3f& scale) const
	{
		Mat4 LocalMatrix(*this);

		for (size_t i = 0; i < 4; ++i)
			for (size_t j = 0; j < 4; ++j)
				LocalMatrix[i][j] /= LocalMatrix[3][3];

		// perspectiveMatrix is used to solve for perspective, but it also provides
		// an easy way to test for singularity of the upper 3x3 component.
		Mat4 PerspectiveMatrix(LocalMatrix);

		for (size_t i = 0; i < 3; i++)
			PerspectiveMatrix[i][3] = 0.f;
		PerspectiveMatrix[3][3] = 1.f;

		auto epsilonNotEqual = [](float a, float b) -> bool
			{
				return std::abs(a - b) >= std::numeric_limits<float>::epsilon();
			};

		// First, isolate perspective.  This is the messiest.
		if (
			epsilonNotEqual(LocalMatrix[0][3], 0.f) ||
			epsilonNotEqual(LocalMatrix[1][3], 0.f) ||
			epsilonNotEqual(LocalMatrix[2][3], 0.f)
			)
		{
			// rightHandSide is the right hand side of the equation.
			Vec4f RightHandSide;
			RightHandSide[0] = LocalMatrix[0][3];
			RightHandSide[1] = LocalMatrix[1][3];
			RightHandSide[2] = LocalMatrix[2][3];
			RightHandSide[3] = LocalMatrix[3][3];

			// Solve the equation by inverting PerspectiveMatrix and multiplying
			// rightHandSide by the inverse.  (This is the easiest way, not
			// necessarily the best.)
			Mat4 InversePerspectiveMatrix = PerspectiveMatrix.CreateInverseMatrix();//   inverse(PerspectiveMatrix, inversePerspectiveMatrix);
			Mat4 TransposedInversePerspectiveMatrix = InversePerspectiveMatrix.GetTranspose();//   transposeMatrix4(inversePerspectiveMatrix, transposedInversePerspectiveMatrix);

			Vec4f Perspective = TransposedInversePerspectiveMatrix * RightHandSide;
			//  v4MulPointByMatrix(rightHandSide, transposedInversePerspectiveMatrix, perspectivePoint);

			// Clear the perspective partition
			LocalMatrix[0][3] = LocalMatrix[1][3] = LocalMatrix[2][3] = 0.f;
			LocalMatrix[3][3] = 1.f;
		}
		else
		{
			// No perspective.
			Vec4f Perspective = Vec4f(0, 0, 0, 1);
		}

		// Next take care of translation (easy).
		translation = Vec3f(LocalMatrix[3]);
		LocalMatrix[3] = Vec4f(0, 0, 0, LocalMatrix[3].w);

		Vec3f Row[3], Pdum3, Skew;

		// Now get scale and shear.
		for (size_t i = 0; i < 3; ++i)
			for (size_t j = 0; j < 3; ++j)
				Row[i][j] = LocalMatrix[i][j];

		auto scaleVector = [](Vec3f v, float s)->Vec3f
			{
				return v * s / v.Length();
			};

		auto combine = [](Vec3f a, Vec3f b, float ascl, float bscl)->Vec3f
			{
				return a * ascl + b * bscl;
			};

		// Compute X scale factor and normalize first row.
		scale.x = Row[0].Length();// v3Length(Row[0]);

		// Scale vector
		Row[0] = scaleVector(Row[0], 1.f);

		// Compute XY shear factor and make 2nd row orthogonal to 1st.
		Skew.z = Row[0].Dot(Row[1]);

		/// Make a linear combination of two vectors and return the result.
		Row[1] = combine(Row[1], Row[0], 1.f, -Skew.z);

		// Now, compute Y scale and normalize 2nd row.
		scale.y = Row[1].Length();

		// Scale vector
		Row[1] = scaleVector(Row[1], 1.f);
		Skew.z /= scale.y;

		// Compute XZ and YZ shears, orthogonalize 3rd row.
		Skew.y = Row[0].Dot(Row[2]);
		Row[2] = combine(Row[2], Row[0], 1.f, -Skew.y);
		Skew.x = Row[1].Dot(Row[2]);
		Row[2] = combine(Row[2], Row[1], 1.f, -Skew.x);

		// Next, get Z scale and normalize 3rd row.
		scale.z = Row[2].Length();
		Row[2] = scaleVector(Row[2], 1.f);
		Skew.y /= scale.z;
		Skew.x /= scale.z;

		// At this point, the matrix (in rows[]) is orthonormal.
		// Check for a coordinate system flip.  If the determinant
		// is -1, then negate the matrix and the scaling factors.
		Pdum3 = Row[1].Cross(Row[2]); // v3Cross(row[1], row[2], Pdum3);
		if (Row[0].Dot(Pdum3) < 0)
		{
			for (size_t i = 0; i < 3; i++)
			{
				scale[i] *= -1.f;
				Row[i] *= -1.f;
			}
		}

		// Now, get the rotations out, as described in the gem.

		// FIXME - Add the ability to return either quaternions (which are
		// easier to recompose with) or Euler angles (rx, ry, rz), which
		// are easier for authors to deal with. The latter will only be useful
		// when we fix https://bugs.webkit.org/show_bug.cgi?id=23799, so I
		// will leave the Euler angle code here for now.

		// ret.rotateY = asin(-Row[0][2]);
		// if (cos(ret.rotateY) != 0) {
		//     ret.rotateX = atan2(Row[1][2], Row[2][2]);
		//     ret.rotateZ = atan2(Row[0][1], Row[0][0]);
		// } else {
		//     ret.rotateX = atan2(-Row[2][0], Row[1][1]);
		//     ret.rotateZ = 0;
		// }

		int i, j, k = 0;
		float root, trace = Row[0].x + Row[1].y + Row[2].z;
		if (trace > 0.f)
		{
			root = std::sqrt(trace + 1.f);
			rotation.w = 0.5f * root;
			root = 0.5f / root;
			rotation.x = root * (Row[1].z - Row[2].y);
			rotation.y = root * (Row[2].x - Row[0].z);
			rotation.z = root * (Row[0].y - Row[1].x);
		} // End if > 0
		else
		{
			static int Next[3] = { 1, 2, 0 };
			i = 0;
			if (Row[1].y > Row[0].x) i = 1;
			if (Row[2].z > Row[i][i]) i = 2;
			j = Next[i];
			k = Next[j];

			root = std::sqrt(Row[i][i] - Row[j][j] - Row[k][k] + 1.0f);

			rotation[i] = 0.5f * root;
			root = 0.5f / root;
			rotation[j] = root * (Row[i][j] + Row[j][i]);
			rotation[k] = root * (Row[i][k] + Row[k][i]);
			rotation.w = root * (Row[j][k] - Row[k][j]);
		} // End if <= 0

		rotation.Conjugate();
	}

	inline Vec3f Mat4::GetTranslation() const
	{
		return content[3];
	}

	inline Vec3f Mat4::GetScale() const
	{
		// World Scale equal length of columns of the model matrix.
		float x = Vec3f(content[0][0], content[0][1], content[0][2]).Length();
		float y = Vec3f(content[1][0], content[1][1], content[1][2]).Length();
		float z = Vec3f(content[2][0], content[2][1], content[2][2]).Length();
		return { x, y, z };
	}

	inline Quat Mat4::GetRotation() const
	{
		// !! Work only with rotation matrix
		Mat4 temp = ToRotationMatrix();

		// Extracting the rotation from the matrix
		float trace = temp.content[0][0] + temp.content[1][1] + temp.content[2][2];

		if (trace > 0)
		{
			float s = 0.5f / std::sqrt(trace + 1.0f);
			float w = 0.25f / s;
			float x = (temp.content[1][2] - temp.content[2][1]) * s;
			float y = (temp.content[2][0] - temp.content[0][2]) * s;
			float z = (temp.content[0][1] - temp.content[1][0]) * s;
			return Quat(x, y, z, w).GetInverse();
		}
		else if (temp.content[0][0] > temp.content[1][1] && temp.content[0][0] > temp.content[2][2])
		{
			float s = 2.0f * std::sqrt(1.0f + temp.content[0][0] - temp.content[1][1] - temp.content[2][2]);
			float x = 0.25f * s;
			float w = (temp.content[1][2] - temp.content[2][1]) / s;
			float y = (temp.content[1][0] + temp.content[0][1]) / s;
			float z = (temp.content[2][0] + temp.content[0][2]) / s;
			return Quat(x, y, z, w).GetInverse();
		}
		else if (temp.content[1][1] > temp.content[2][2])
		{
			float s = 2.0f * std::sqrt(1.0f + temp.content[1][1] - temp.content[0][0] - temp.content[2][2]);
			float y = 0.25f * s;
			float w = (temp.content[2][0] - temp.content[0][2]) / s;
			float x = (temp.content[1][0] + temp.content[0][1]) / s;
			float z = (temp.content[2][1] + temp.content[1][2]) / s;
			return Quat(x, y, z, w).GetInverse();
		}
		else
		{
			float s = 2.0f * std::sqrt(1.0f + temp.content[2][2] - temp.content[0][0] - temp.content[1][1]);
			float w = (temp.content[0][1] - temp.content[1][0]) / s;
			float x = (temp.content[2][0] + temp.content[0][2]) / s;
			float y = (temp.content[2][1] + temp.content[1][2]) / s;
			float z = 0.25f * s;
			return Quat(x, y, z, w).GetInverse();
		}
	}

	inline Mat4 Mat4::CreateInverseMatrix() const
	{
		// Find determinant of matrix
		Mat4 inverse;
		float det = GetDeterminant(4);
		if (det == 0)
		{
			std::cout << "ERROR with Inverse Matrix" << std::endl;
			return Mat4::Identity();
		}

		// Find adjoint
		Mat4 adj = CreateAdjMatrix();

		// Find Inverse using formula "inverse(A) = adj(A)/det(A)"
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				inverse.content[i][j] = adj.content[i][j] / float(det);

		return inverse;
	}

	inline Mat4 Mat4::CreateAdjMatrix() const
	{
		// temp is used to store cofactors of matrix
		Mat4 temp;
		Mat4 adj;
		int sign = 1;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				// Get cofactor of matrix[i][j]
				temp = GetCofactor(i, j, 4);

				// sign of adj positive if sum of row
				// and column indexes is even.
				sign = ((i + j) % 2 == 0) ? 1 : -1;

				// Interchanging rows and columns to get the
				// transpose of the cofactor matrix
				adj.content[j][i] = (float)((sign) * (temp.GetDeterminant(3)));
			}
		}
		return adj;
	}

	inline Mat4 Mat4::GetCofactor(int p, int q, int n) const
	{
		Mat4 mat;
		int i = 0, j = 0;
		// Looping for each element of the matrix
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				//  Copying into temporary matrix only those element
				//  which are not in given row and column
				if (row != p && col != q)
				{
					mat.content[i][j++] = content[row][col];

					// Row is filled, so increase row index and
					// reset col index
					if (j == n - 1)
					{
						j = 0;
						i++;
					}
				}
			}
		}
		return mat;
	}

	inline float Mat4::GetDeterminant(float n) const
	{
		if (n == 2)
		{
			float result = content[0][0] * content[1][1] - content[1][0] * content[0][1];
			return result;
		}
		else if (n == 3)
		{
			float result = content[0][0] * content[1][1] * content[2][2]
				- content[0][0] * content[2][1] * content[1][2]
				+ content[1][0] * content[2][1] * content[0][2]
				- content[1][0] * content[0][1] * content[2][2]
				+ content[2][0] * content[0][1] * content[1][2]
				- content[2][0] * content[1][1] * content[0][2];
			return result;
		}
		else if (n == 4)
		{
			float result = content[0][0] * (content[1][1] * content[2][2] * content[3][3] // a(fkp
				- content[1][1] * content[3][2] * content[2][3] //flo
				- content[2][1] * content[1][2] * content[3][3] //gjp
				+ content[2][1] * content[3][2] * content[1][3] //gln
				+ content[3][1] * content[1][2] * content[2][3] //hjo
				- content[3][1] * content[2][2] * content[1][3]) // hkn

				- content[1][0] * (content[0][1] * content[2][2] * content[3][3] //b(ekp
					- content[0][1] * content[3][2] * content[2][3] // elo
					- content[2][1] * content[0][2] * content[3][3] //gip
					+ content[2][1] * content[3][2] * content[0][3] //glm
					+ content[3][1] * content[0][2] * content[2][3] //hio
					- content[3][1] * content[2][2] * content[0][3]) //hkm

				+ content[2][0] * (content[0][1] * content[1][2] * content[3][3] // c(ejp
					- content[0][1] * content[3][2] * content[1][3] //eln
					- content[1][1] * content[0][2] * content[3][3] //fip
					+ content[1][1] * content[3][2] * content[0][3] //flm
					+ content[3][1] * content[0][2] * content[1][3] //hin
					- content[3][1] * content[1][2] * content[0][3]) //hjm

				- content[3][0] * (content[0][1] * content[1][2] * content[2][3] // d(ejo
					- content[0][1] * content[2][2] * content[1][3] //ekn
					- content[1][1] * content[0][2] * content[2][3] //fio
					+ content[1][1] * content[2][2] * content[0][3] //fkm
					+ content[2][1] * content[0][2] * content[1][3] //gin
					- content[2][1] * content[1][2] * content[0][3]); //gjm
			return result;
		}
		else return 0.0f;
	}

	inline Mat4 Mat4::GetTranspose() const
	{
		Mat4 transpose = *this;
		float temp;

		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				temp = transpose[i][j];
				transpose[i][j] = transpose[j][i];
				transpose[j][i] = temp;
			}
		}
		return transpose;
	}

	template<typename U>
	inline Vec3<U> Mat4::MultiplyPoint3x4(Vec3<U> point)
	{
		Vec3<U> res;
		res.x = content[0][0] * point.x + content[0][1] * point.y + content[0][2] * point.z + content[0][3];
		res.y = content[1][0] * point.x + content[1][1] * point.y + content[1][2] * point.z + content[1][3];
		res.z = content[2][0] * point.x + content[2][1] * point.y + content[2][2] * point.z + content[2][3];
		return res;
	}

	template<typename U>
	inline Vec3<U> Mat4::MultiplyVector(Vec3<U> vector)
	{
		Vec3<U> res;
		res.x = content[0][0] * vector.x + content[0][1] * vector.y + content[0][2] * vector.z;
		res.y = content[1][0] * vector.x + content[1][1] * vector.y + content[1][2] * vector.z;
		res.z = content[2][0] * vector.x + content[2][1] * vector.y + content[2][2] * vector.z;
		return res;
	}

	inline float* Mat4::Data() const
	{
		return const_cast<float*>(reinterpret_cast<const float*>(this));
	}

	inline void Mat4::Print() const
	{
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				if (content[j][i] >= 0.0f) printf(" ");
				printf("%.6f", content[j][i]);
			}
			printf("\n");
		}
		printf("\n");
	}

	inline std::string Math::Mat4::ToString() const
	{
		std::string print;
		for (int j = 0; j < 4; j++)
		{
			print += "{";
			for (int i = 0; i < 4; i++)
			{
				print += " ";
				print += std::to_string(content[j][i]);
			}
			print += "}";
		}
		return print;
	}

	inline Mat4 Mat4::ToRotationMatrix() const
	{		
		// Convert to rotation Matrix
		Vec3f scale = GetScale();
		return Mat4(
			Vec4f(Vec3f(content[0]) / scale[0], 0),
			Vec4f(Vec3f(content[1]) / scale[1], 0),
			Vec4f(Vec3f(content[2]) / scale[2], 0),
			Vec4f(0));
	}

#ifdef MATH_GLM_EXTENSION

	Mat4::Mat4(const glm::mat4& mat)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				content[i][j] = mat[i][j];
			}
		}
	}

	glm::mat4 Mat4::ToGlm() const
	{
		auto mat = glm::mat4();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mat[i][j] = content[i][j];
			}
		}
		return mat;
	}

	inline bool Mat4::operator==(const glm::mat4& b) const
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (!AlmostEqual(b[i][j], content[i][j]))
					return false;
			}
		}
		return true;
	}
#endif
#pragma  endregion

#pragma region Quaternion

	inline Quat::Quat(const std::string& str)
	{
		std::istringstream ss(str);

		char discard;
		ss >> this->x >> discard >> this->y >> discard >> this->z >> discard >> this->w;
	}

	inline Quat Quat::operator+(const Quat& a) const
	{
		return Quat(x + a.x, y + a.y, z + a.z, w + a.w);
	}

	inline Quat Quat::operator-(const Quat& a) const
	{
		return Quat(x - a.x, y - a.y, z - a.z, w - a.w);
	}

	inline Quat Quat::operator*(const Quat& a) const
	{
		return Quat(
			w * a.x + x * a.w + y * a.z - z * a.y,
			w * a.y + y * a.w + z * a.x - x * a.z,
			w * a.z + z * a.w + x * a.y - y * a.x,
			w * a.w - x * a.x - y * a.y - z * a.z);
	}

	inline Quat Quat::operator*(float a) const
	{
		return Quat(this->x * a, this->y * a, this->z * a, this->w * a);
	}
	template<typename U>
	inline Vec3<U> Quat::operator*(const Vec3<U>& v) const
	{
#if 0
		Vec3<U> vector;
		float ax = x * 2.f;
		float ay = y * 2.f;
		float az = z * 2.f;
		float xx = x * ax;
		float yy = y * ay;
		float zz = z * az;
		float xy = x * ay;
		float xz = x * az;
		float yz = y * az;
		float wx = w * ax;
		float wy = w * ay;
		float wz = w * az;
		return { (1.f - (yy + zz)) * a.x + (xy - wz) * a.y + (xz + wy) * a.z ,
				(xy + wz) * a.x + (1.f - (xx + zz)) * a.y + (yz - wx) * a.z ,
				(xz - wy) * a.x + (yz + wx) * a.y + (1.f - (xx + yy)) * a.z
};
#else
		Quat q = *this;
		Vec3f const QuatVector(q.x, q.y, q.z);
		Vec3f const uv(QuatVector.Cross(v));
		Vec3f const uuv(QuatVector.Cross(uv));
		return v + ((uv * q.w) + uuv) * static_cast<U>(2);
#endif

	}

	inline void Quat::operator*=(const Quat& a)
	{
		*this = operator*(a);
	}

	inline void Quat::operator*=(float a)
	{
		*this = operator*(a);
	}

	inline bool Quat::operator==(const Quat& a) const
	{
		return AlmostEqual(x, a.x) && AlmostEqual(y, a.y)
			&& AlmostEqual(z, a.z) && AlmostEqual(w, a.w);
	}

	inline bool Quat::operator!=(const Quat& a) const
	{
		return	!AlmostEqual(x, a.x) || !AlmostEqual(y, a.y)
			|| !AlmostEqual(z, a.z) || !AlmostEqual(w, a.w);
	}

	inline float& Quat::operator[](const size_t index)
	{
		if (index >= 4)
			return x;
		return *((&x) + index);
	}

	template<typename U>
	inline Quat Quat::AngleAxis(float angle, Vec3<U> axis)
	{
		float rad = angle * DegToRad;
		axis.Normalize();
		Quat q;
		q.w = std::cos(rad / 2);
		q.x = std::sin(rad / 2) * axis.x;
		q.y = std::sin(rad / 2) * axis.y;
		q.z = std::sin(rad / 2) * axis.z;
		return q;
	}

	template<typename U>
	Quat Quat::FromEuler(const Vec3<U>& euler)
	{
		return euler.ToQuaternion();
	}

	template<typename U>
	Quat Quat::LookRotation(Vec3<U> forward, Vec3<U> up)
	{
		forward.Normalize();
		Vec3<U>  vector = forward.GetNormalize();
		Vec3<U>  vector2 = up.Cross(vector).GetNormalize();
		Vec3<U>  vector3 = vector.Cross(vector2);
		float m00 = vector2.x;
		float m01 = vector2.y;
		float m02 = vector2.z;
		float m10 = vector3.x;
		float m11 = vector3.y;
		float m12 = vector3.z;
		float m20 = vector.x;
		float m21 = vector.y;
		float m22 = vector.z;

		float num8 = (m00 + m11) + m22;
		Quat quaternion;
		if (num8 > 0.f)
		{
			float num = std::sqrt(num8 + 1.f);
			quaternion.w = num * 0.5f;
			num = 0.5f / num;
			quaternion.x = (m12 - m21) * num;
			quaternion.y = (m20 - m02) * num;
			quaternion.z = (m01 - m10) * num;
			return quaternion;
		}
		if ((m00 >= m11) && (m00 >= m22))
		{
			float num7 = std::sqrt(((1.f + m00) - m11) - m22);
			float num4 = 0.5f / num7;
			quaternion.x = 0.5f * num7;
			quaternion.y = (m01 + m10) * num4;
			quaternion.z = (m02 + m20) * num4;
			quaternion.w = (m12 - m21) * num4;
			return quaternion;
		}
		if (m11 > m22)
		{
			float num6 = std::sqrt(((1.f + m11) - m00) - m22);
			float num3 = 0.5f / num6;
			quaternion.x = (m10 + m01) * num3;
			quaternion.y = 0.5f * num6;
			quaternion.z = (m21 + m12) * num3;
			quaternion.w = (m20 - m02) * num3;
			return quaternion;
		}
		float num5 = (float)sqrtf(((1.f + m22) - m00) - m11);
		float num2 = 0.5f / num5;
		return { (m20 + m02) * num2 , (m21 + m12) * num2, 0.5f * num5,(m01 - m10) * num2 };
	}


	inline Quat Quat::SLerp(const Quat& a, const Quat& b, float time)
	{
		if (time < 0.0f)
			return a;
		else if (time >= 1.0f)
			return b;
		float d = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
		float s0, s1;
		float sd = (float)((d > 0.0f) - (d < 0.0f));

		d = fabs(d);

		if (d < 0.9995f)
		{
			float s = std::sqrt(1.0f - d * d);
			float a = std::atan2(s, d);
			float c = std::cos(time * a);


			s1 = std::sqrt(1.0f - c * c) / s;
			s0 = c - d * s1;
		}
		else
		{
			s0 = 1.0f - time;
			s1 = time;
		}

		return a * s0 + b * sd * s1;
	}

	inline void Quat::Inverse()
	{
		*this = GetInverse();
	}
	inline Quat Quat::GetInverse() const
	{
		float d = w * w + x * x + y * y + z * z;
		if (x == 0 && y == 0 && z == 0 && w == 0)
			return *this;
		else
			return Quat(-x / d, -y / d, -z / d, w / d);
	}
	inline void Quat::Normalize()
	{
		*this = GetNormalize();
	}
	inline Quat Quat::GetNormalize() const
	{
		float mag = std::sqrt(Dot(*this));

		if (mag < FLT_MIN)
			return Quat::Identity();
		else
			return Quat(x / mag, y / mag, z / mag, w / mag);
	}

	inline void Quat::Conjugate()
	{
		*this = GetConjugate();
	}

	inline Quat Quat::GetConjugate() const
	{
		return Quat(-x, -y, -z, w);
	}

	inline float Quat::Dot(const Quat& a) const
	{
		return x * a.x + y * a.y + z * a.z + w * a.w;
	}

	static float NormalizeAngle(float angle)
	{
		float modAngle = std::fmod(angle, 360.0f);

		if (modAngle < 0.0f)
			return modAngle + 360.0f;
		else
			return modAngle;
	}

	template<typename U>
	static Vec3<U> NormalizeAngles(Vec3<U>  angles)
	{
		angles.x = NormalizeAngle(angles.x);
		angles.y = NormalizeAngle(angles.y);
		angles.z = NormalizeAngle(angles.z);
		return angles;
	}

	inline Vec3f Quat::ToEuler() const
	{
		return ToEuler<float>();
	}

	template<typename U>
	inline Vec3<U> Quat::ToEuler() const
	{
		U pitch;
		Quat q = *this;
		U y = static_cast<U>(2) * (q.y * q.z + q.w * q.x);
		U x = q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z;

		U epsilon = std::numeric_limits<U>::epsilon();
		if (std::abs(x) < epsilon && std::abs(y) < epsilon) {
			// Avoid atan2(0,0) - handle singularity
			pitch = static_cast<U>(2) * std::atan2(q.x, q.w);
		}
		else
		{
			pitch = std::atan2(y, x);
		}


		U yaw = std::asin(std::clamp(static_cast<U>(-2) * (q.x * q.z - q.w * q.y), static_cast<U>(-1), static_cast<U>(1)));

		U roll = static_cast<U>(std::atan2(static_cast<U>(2) * (q.x * q.y + q.w * q.z), q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z));

		return Vec3<U>(pitch, yaw, roll) * RadToDeg;
	}

	inline Mat4 Quat::ToRotationMatrix() const
	{
		// Precalculate coordinate products
		float _x = x * 2.0F;
		float _y = y * 2.0F;
		float _z = z * 2.0F;
		float xx = x * _x;
		float yy = y * _y;
		float zz = z * _z;
		float xy = x * _y;
		float xz = x * _z;
		float yz = y * _z;
		float wx = w * _x;
		float wy = w * _y;
		float wz = w * _z;

		// Calculate 3x3 matrix from orthonormal basis
		Mat4 m;
		m[0][0] = 1.0f - (yy + zz);
		m[0][1] = xy + wz;
		m[0][2] = xz - wy;
		m[0][3] = 0.0F;

		m[1][0] = xy - wz;
		m[1][1] = 1.0f - (xx + zz);
		m[1][2] = yz + wx;
		m[1][3] = 0.0F;

		m[2][0] = xz + wy;
		m[2][1] = yz - wx;
		m[2][2] = 1.0f - (xx + yy);
		m[2][3] = 0.0F;

		m[3][0] = 0.0F;
		m[3][1] = 0.0F;
		m[3][2] = 0.0F;
		m[3][3] = 1.0F;

		return m;
	}

	inline void Quat::Print() const
	{
		printf("Quaternion { %f, %f, %f, %f}\n", x, y, z, w);
	}
	inline std::string Quat::ToString(int precision) const
	{
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(precision);
		oss << x << ", " << y << ", " << z << ", " << w;
		return oss.str();
	}
#pragma endregion
}
