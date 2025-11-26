#pragma once
#include <string>
#define PI 3.14159265358979323846264f
#define DegToRad 1/180.f * PI
#define RadToDeg 180.f / PI

#ifdef MATH_GLM_EXTENSION
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/norm.hpp> 
#include <glm/gtx/euler_angles.hpp> 
#endif

namespace GALAXY::Math
{
	template<typename T>
	inline bool AlmostEqual(T a, T b, float diff = 1e-5f);

	template<typename T>
	class Vec3;
	template<typename T>
	class Vec4;
	class Mat4;
	class Quat;

	template<typename T>
	class Vec2
	{
	public:
		T x = 0, y = 0;

		inline constexpr Vec2() : x(0), y(0) {}

		explicit inline constexpr Vec2(T _xy) : x(_xy), y(_xy) {}

		inline constexpr Vec2(T _x, T _y) : x(_x), y(_y) {}

		template<typename U>
		inline constexpr Vec2(const Vec3<U>& a);

		template<typename U>
		inline constexpr Vec2(const Vec2<U>& a);

		inline constexpr Vec2(const std::string& str);

		template<typename U>
		inline constexpr Vec2 operator=(const Vec2<U>& a);
		template<typename U>
		inline constexpr Vec2 operator=(const Vec3<U>& a);

		template<typename U>
		inline constexpr Vec2 operator+(const Vec2<U>& a) const;
		template<typename U>
		inline constexpr Vec2 operator-(const Vec2<U>& a) const;
		inline constexpr Vec2 operator-(void) const;
		template<typename U>
		inline constexpr Vec2 operator*(U a) const;
		template<typename U>
		inline constexpr Vec2 operator*(const Vec2<U>& a) const;
		template<typename U>
		inline constexpr Vec2 operator/(U a) const;

		template<typename U>
		inline void operator+=(const Vec2<U>& a);
		template<typename U>
		inline void operator-=(const Vec2<U>& a);
		template<typename U>
		inline void operator*=(const Vec2<U>& a);
		constexpr friend Vec2 operator*(T a, const Vec2<T>& b)
		{
			return { static_cast<T>(a * b.x), static_cast<T>(a * b.y) };
		}
		template<typename U>
		inline void operator*=(U a);
		template<typename U>
		inline void operator/=(U a);

		template<typename U>
		inline constexpr bool operator==(const Vec2<U>& b) const;
		template<typename U>
		inline constexpr bool operator==(const Vec3<U>& b) const;
		template<typename U>
		inline constexpr bool operator!=(const Vec2<U>& b) const;
		template<typename U>
		inline constexpr bool operator!=(const Vec3<U>& b) const;

		inline T& operator[](const size_t a);
		inline const T& operator[](const size_t a) const;

		static inline constexpr Vec2 Right() { return { 1, 0 }; }
		static inline constexpr Vec2 Up() { return { 0, 1 }; }

		static inline constexpr Vec2 Left() { return { -1, 0 }; }
		static inline constexpr Vec2 Down() { return { 0, -1 }; }

		static inline constexpr Vec2 Zero() { return { 0, 0 }; }
		static inline constexpr Vec2 One() { return { 1, 1 }; }

		inline T LengthSquared() const;
		static inline T LengthSquared(const Vec2& a);

		inline T Length() const;
		static inline T Length(const Vec2& a) { return a.Length(); }

		inline T Dot(const Vec2& a) const;
		static inline T Dot(const Vec2& a, const Vec2& b);

		inline Vec2 Cross(const Vec2& a) const;
		static inline Vec2 Cross(const Vec2& a, const Vec2& b);

		inline Vec2 Ortho() const;
		static inline Vec2 Ortho(const Vec2& a);

		inline void Normalize();
		static inline Vec2 Normalize(const Vec2& a);

		inline Vec2 GetNormalize() const;

		inline void Print(int precision = 6) const;
		static inline void Print(const Vec2& a, int precision = 6);

		inline std::string ToString(int precision = 6) const;
		static inline std::string ToString(const Vec2& a, int precision = 6);

		inline Vec2<float> ToVec2f() const;
		inline Vec2<int> ToVec2i() const;

		inline T* Data() const;
		static inline T* Data(const Vec2& a);

#ifdef MATH_GLM_EXTENSION
		inline glm::vec2 ToGlm() const { return glm::vec2(x, y); }

		inline bool operator==(const glm::vec2& b) const { return x == b.x && y == b.y; }
#endif
	};

	typedef Vec2<float> Vec2f;
	typedef Vec2<double> Vec2d;
	typedef Vec2<int> Vec2i;

	template<typename T>
	class Vec3
	{
	public:
		T x = 0, y = 0, z = 0;

		inline constexpr Vec3() : x(0), y(0), z(0) {}

		inline constexpr Vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}

		explicit inline constexpr Vec3(T xyz) : x(xyz), y(xyz), z(xyz) {}

		inline constexpr Vec3(const std::string& str);

		template<typename U>
		inline constexpr Vec3(const Vec2<U>& xy, T _z = 0);

		template<typename U>
		inline constexpr Vec3(const Vec3<U>& a);

		template<typename U>
		inline constexpr Vec3(const Vec4<U>& a);

		inline constexpr Vec3 operator+(const Vec3& b) const;
		inline constexpr Vec3 operator-(const Vec3& b) const;
		inline constexpr Vec3 operator-(void) const;
		template<typename U>
		inline constexpr Vec3 operator*(const Vec3<U>& b) const;
		constexpr friend Vec3 operator*(T a, const Vec3<T>& b)
		{
			return { static_cast<T>(a * b.x), static_cast<T>(a * b.y), static_cast<T>(a * b.z) };
		}
		template<typename U>
		inline constexpr Vec3 operator*(U b) const;
		template<typename U>
		inline constexpr Vec3 operator/(U b) const;

		inline void operator+=(const Vec3& b);
		inline void operator-=(const Vec3& b);
		inline void operator*=(const Vec3& b);
		template<typename U>
		inline void operator*=(U b);
		template<typename U>
		inline void operator/=(U b);

		template<typename U>
		inline constexpr bool operator==(const Vec3<U>& b) const;
		template<typename U>
		inline constexpr bool operator!=(const Vec3<U>& b) const;

		inline constexpr T& operator[](size_t a);
		inline const T& operator[](size_t a) const;

		static inline constexpr Vec3 Right() { return { 1, 0, 0 }; }
		static inline constexpr Vec3 Up() { return { 0, 1, 0 }; }
		static inline constexpr Vec3 Forward() { return { 0, 0, -1 }; }

		static inline constexpr Vec3 Left() { return { -1, 0, 0 }; }
		static inline constexpr Vec3 Down() { return { 0, -1, 0 }; }
		static inline constexpr Vec3 Back() { return { 0, 0, 1 }; }

		static inline constexpr Vec3 Zero() { return { 0, 0, 0 }; }
		static inline constexpr Vec3 One() { return { 1, 1, 1 }; }

		inline T LengthSquared() const;
		static inline T LengthSquared(const Vec3& a);

		inline T Length() const;
		static inline T Length(const Vec3& a);

		inline T Dot(const Vec3& a) const;
		static inline T Dot(const Vec3& a, const Vec3& b);

		inline Vec3 Cross(const Vec3& a) const;
		static inline Vec3 Cross(const Vec3& a, const Vec3& b);

		inline T Distance(const Vec3& a) const;
		static inline T Distance(const Vec3& a, const Vec3& b);

		inline Vec3 Lerp(const Vec3& a, float t) const;
		static inline Vec3 Lerp(const Vec3& a, const Vec3& b, float t) { return a.Lerp(b, t); }

		inline void Normalize();
		static inline Vec3 Normalize(const Vec3& a);

		inline Vec3 GetNormalize() const;

		inline void Print(int precision = 6) const;
		static inline void Print(const Vec3& a, int precision = 6);

		inline std::string ToString(int precision = 6) const;
		static inline std::string ToString(const Vec3& a, int precision = 6);

		inline Quat ToQuaternion() const;
		static inline Quat ToQuaternion(const Vec3& a);

		inline T* Data() const;
		static inline T* Data(const Vec3& a);

#ifdef MATH_GLM_EXTENSION
		inline glm::vec3 ToGlm() const { return glm::vec3(x, y, z); }

		inline bool operator==(const glm::vec3& b) const { return AlmostEqual(x, b.x) && AlmostEqual(y, b.y) && AlmostEqual(z, b.z); }
#endif
	};

	typedef Vec3<float> Vec3f;
	typedef Vec3<int> Vec3i;
	typedef Vec3<double> Vec3d;

#pragma region Vec4
	template<typename T>
	class Vec4 {
	public:
		T x = 0, y = 0, z = 0, w = 0;

		inline constexpr Vec4() : x(0), y(0), z(0), w(0) {}

		inline constexpr Vec4(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}

		explicit inline constexpr Vec4(T xyzw) : x(xyzw), y(xyzw), z(xyzw), w(xyzw) {}

		template<typename U>
		inline constexpr Vec4(const Vec2<U>& xy, T _z = 0, T _w = 0);

		template<typename U>
		inline constexpr Vec4(const Vec3<U>& xyz, T _w = 0);

		template<typename U>
		inline constexpr Vec4(const Vec4<U>& a);

		inline constexpr Vec4(const std::string& str);

		template<typename U>
		inline constexpr Vec4 operator=(const Vec3<U>& b);

		inline constexpr Vec4 operator+(const Vec4& b) const;
		inline constexpr Vec4 operator-(const Vec4& b) const;
		inline constexpr Vec4 operator-(void) const;
		template<typename U>
		inline constexpr Vec4 operator*(const Vec4<U>& b) const;
		constexpr friend Vec4 operator*(T a, const Vec4<T>& b)
		{
			return { static_cast<T>(a * b.x), static_cast<T>(a * b.y), static_cast<T>(a * b.z), static_cast<T>(a * b.w) };
		}
		template<typename U>
		inline constexpr Vec4 operator*(U b) const;
		template<typename U>
		inline constexpr Vec4 operator/(U b) const;

		inline void operator+=(const Vec4& b);
		inline void operator-=(const Vec4& b);
		inline void operator*=(const Vec4& b);
		template<typename U>
		inline void operator*=(U b);
		template<typename U>
		inline void operator/=(U b);

		template<typename U>
		inline bool operator==(const Vec4<U>& b) const;
		template<typename U>
		inline bool operator!=(const Vec4<U>& b) const;

		inline constexpr T& operator[](size_t a);
		inline const T& operator[](size_t a) const;

		friend inline std::ostream& operator<<(std::ostream& os, const Vec4<T>& vec)
		{
			os << vec.x << " " << vec.y << " " << vec.z << " " << vec.w;
			return os;
		}

		static inline constexpr Vec4 Right() { return { 1, 0, 0, 0 }; }
		static inline constexpr Vec4 Up() { return { 0, 1, 0, 0 }; }
		static inline constexpr Vec4 Forward() { return { 0, 0, 1, 0 }; }
		static inline constexpr Vec4 Homogeneous() { return { 0, 0, 0, 1 }; }

		static inline constexpr Vec4 Left() { return { -1, 0, 0, 0 }; }
		static inline constexpr Vec4 Down() { return { 0, -1, 0, 0 }; }
		static inline constexpr Vec4 Back() { return { 0, 0, -1, 0 }; }

		static inline constexpr Vec4 Zero() { return { 0, 0, 0, 0 }; }
		static inline constexpr Vec4 One() { return { 1, 1, 1, 1 }; }

		inline T LengthSquared() const;
		static inline T LengthSquared(const Vec4& a);

		inline T Length() const;
		static inline T Length(const Vec4& a);

		inline T Dot(const Vec4& a) const;
		static inline T Dot(const Vec4& a, const Vec4& b);

		inline T Distance(const Vec4& a) const;
		static inline T Distance(const Vec4& a, const Vec4& b);

		inline void Homogenize();
		static inline Vec4 Homogenize(const Vec4& a);

		inline Vec4 GetHomogenize() const;

		inline void Normalize();
		static inline Vec4 Normalize(const Vec4& a);

		inline Vec4 GetNormalize() const;

		inline void Print(int precision = 6) const;
		static inline void Print(const Vec4& a, int precision = 6);

		inline Vec3<T> ToVector3() const;
		static inline Vec3<T> ToVector3(const Vec4& a);

		inline std::string ToString(int precision = 6) const;
		static inline std::string ToString(const Vec4& a, int precision = 6);

		T* Data() const;
		static inline T* Data(const Vec4& a);

#ifdef MATH_GLM_EXTENSION
		inline glm::vec4 ToGlm() const { return glm::vec4(x, y, z, w); }

		inline bool operator==(const glm::vec4& b) const { return AlmostEqual(x, b.x) && AlmostEqual(y, b.y) && AlmostEqual(z, b.z) && AlmostEqual(w, b.w); }
#endif
	};

	typedef Vec4<float> Vec4f;
	typedef Vec4<int> Vec4i;
	typedef Vec4<double> Vec4d;
#pragma endregion

	class Mat3
	{
	public:
		/* data of the matrix : content[y][x]
		 * Matrix is indexed with:
		 *
		 * Vec3 = 00 | 01 | 02
		 * Vec3 = 10 | 11 | 12
		 * Vec3 = 20 | 21 | 22
		 *
		*/

		Vec3f content[3];

		inline constexpr Mat3() {}

		inline constexpr Mat3(float diagonal);

		inline constexpr Mat3(const Vec3f& m0, const Vec3f& m1, const Vec3f& m2);

		inline constexpr Mat3(const Mat4& m);

		inline constexpr Mat3(const float* data);

		inline constexpr Mat3(const double* data);

		inline constexpr Mat3 operator*(const Mat3& a) const;

		template<typename U>
		inline constexpr Vec3<U> operator*(const Vec3<U>& a) const;

		inline constexpr Mat3 operator+(const Mat3& a) const;

		inline constexpr Vec3f& operator[](size_t i);
		inline constexpr const Vec3f& operator[](size_t i) const;

		inline constexpr bool operator==(const Mat3& b) const;

		static constexpr Mat3 Identity() { return { 1.f }; }

		template<typename U>
		static inline Mat3 CreateRotationMatrix(const Vec3<U>& rotation);
		static inline Mat3 CreateRotationMatrix(const Quat& rotation);

		template<typename U>
		static inline Mat3 CreateScaleMatrix(const Vec3<U>& scale);

		template<typename U>
		static inline Mat3 CreateTransformMatrix(const Vec3<U>& rotation, const Vec3<U>& scale);
		template<typename U>
		static inline Mat3 CreateTransformMatrix(const Quat& rotation, const Vec3<U>& scale);

		inline Quat GetRotation() const;
		static inline Quat GetRotation(const Mat3& a);

		inline Vec3f GetScale() const;
		static inline Vec3f GetScale(const Mat3& a);

		inline Mat3 CreateInverseMatrix() const;
		static inline Mat3 CreateInverseMatrix(const Mat3& a);

		inline Mat3 GetInverseMatrix() const;
		static inline Mat3 GetInverseMatrix(const Mat3& a);

		inline void Inverse();

		inline Mat3 CreateAdjMatrix() const;
		static inline Mat3 CreateAdjMatrix(const Mat3& a);

		inline Mat3 GetCofactor(int p, int q, int n) const;
		static inline Mat3 GetCofactor(const Mat3& a, int p, int q, int n);

		inline float GetDeterminant(float n) const;
		static inline float GetDeterminant(const Mat3& a, float n);
		
		inline void Transpose();
		static inline Mat3 Transpose(const Mat3& a);

		inline Mat3 GetTranspose() const;

		inline void Print() const;
		static inline void Print(const Mat3& a);

		inline std::string ToString() const;
		static inline std::string ToString(const Mat3& a);

		inline Mat3 ToRotationMatrix() const;
		static inline Mat3 ToRotationMatrix(const Mat3& a);

		inline const float* Data() const;

		inline float* Data();
		static inline const float* Data(const Mat3& a);

#ifdef MATH_GLM_EXTENSION
		inline Mat3(const glm::mat3& mat);

		inline glm::mat3 ToGlm() const;

		inline bool operator==(const glm::mat3& b) const;
#endif
	};

	class Mat4
	{
	public:
		/* data of the matrix : content[y][x]
		 * Matrix is indexed with:
		 *
		 * Vec4 = 00 | 01 | 02 | 03
		 * Vec4 = 10 | 11 | 12 | 13
		 * Vec4 = 20 | 21 | 22 | 23
		 * Vec4 = 30 | 31 | 32 | 33
		 *
		*/

		Vec4f content[4];

		inline constexpr Mat4() {}

		inline constexpr Mat4(float diagonal);

		inline constexpr Mat4(const Vec4f& m0, const Vec4f& m1, const Vec4f& m2, const Vec4f& m3);

		inline constexpr Mat4(const Mat3& m);

		inline constexpr Mat4(const float* data);

		inline constexpr Mat4(const double* data);

		inline constexpr Mat4 operator*(const Mat4& a) const;

		template<typename U>
		inline constexpr Vec4<U> operator*(const Vec4<U>& a) const;

		template<typename U>
		inline constexpr Vec3<U> operator*(const Vec3<U>& a) const;

		inline constexpr Mat4 operator+(const Mat4& a) const;

		inline constexpr Vec4f& operator[](size_t i);
		inline constexpr const Vec4f& operator[](size_t i) const;

		inline constexpr bool operator==(const Mat4& b) const;

		static constexpr Mat4 Identity() { return { 1.f }; }

		static inline Mat4 CreateProjectionMatrix(float _fov, float _aspect, float _near, float _far);

		static inline Mat4 CreateOrthographicMatrix(float _left, float _right, float _bottom, float _top, float _near, float _far);
		
		static inline Mat4 CreateViewMatrix(const Vec3f position, const Quat& rotation);
		
		static inline Mat4 LookAtRH(const Vec3f& position, const Vec3f& target, const Vec3f& up);
		static inline Mat4 LookAtLH(const Vec3f& position, const Vec3f& target, const Vec3f& up);

		template<typename U>
		static inline Mat4 CreateTranslationMatrix(const Vec3<U>& translation);

		template<typename U>
		static inline Mat4 CreateRotationMatrix(const Vec3<U>& rotation);
		static inline Mat4 CreateRotationMatrix(const Quat& rotation);

		template<typename U>
		static inline Mat4 CreateScaleMatrix(const Vec3<U>& scale);

		template<typename U>
		static inline Mat4 CreateTransformMatrix(const Vec3<U>& position, const Vec3<U>& rotation, const Vec3<U>& scale);
		template<typename U>
		static inline Mat4 CreateTransformMatrix(const Vec3<U>& position, const Quat& rotation, const Vec3<U>& scale);

		inline void DecomposeTransformMatrix(Vec3f& position, Quat& rotation, Vec3f& scale) const;
		static inline void DecomposeTransformMatrix(const Mat4& a, Vec3f& position, Quat& rotation, Vec3f& scale);

		inline Vec3f GetTranslation() const;
		static inline Vec3f GetTranslation(const Mat4& a);

		inline Quat GetRotation() const;
		static inline Quat GetRotation(const Mat4& a);

		inline Vec3f GetScale() const;
		static inline Vec3f GetScale(const Mat4& a);

		inline Mat4 CreateInverseMatrix() const;
		static inline Mat4 CreateInverseMatrix(const Mat4& a);

		inline Mat4 GetInverseMatrix() const;
		static inline Mat4 GetInverseMatrix(const Mat4& a);

		inline void Inverse();

		inline Mat4 CreateAdjMatrix() const;
		static inline Mat4 CreateAdjMatrix(const Mat4& a);

		inline Mat4 GetCofactor(int p, int q, int n) const;
		static inline Mat4 GetCofactor(const Mat4& a, int p, int q, int n);

		inline float GetDeterminant(float n) const;
		static inline float GetDeterminant(const Mat4& a, float n);

		inline void Transpose();
		static inline Mat4 Transpose(const Mat4& a);

		inline Mat4 GetTranspose() const;

		inline void Print() const;
		static inline void Print(const Mat4& a);

		inline std::string ToString() const;
		static inline std::string ToString(const Mat4& a);

		inline Mat3 ToRotationMatrix() const;
		static inline Mat3 ToRotationMatrix(const Mat4& a);

		// Transforms a position by this matrix, without a perspective divide. (fast)
		template<typename U>
		inline Vec3<U> MultiplyPoint3x4(Vec3<U> point) const;
		template<typename U>
		static inline Vec3<U> MultiplyPoint3x4(const Mat4& a, Vec3<U> point);

		inline const float* Data() const;
		static inline const float* Data(const Mat4& a);

		inline float* Data();

#ifdef MATH_GLM_EXTENSION
		inline Mat4(const glm::mat4& mat);

		inline glm::mat4 ToGlm() const;

		inline bool operator==(const glm::mat4& b) const;
#endif
	};

	class Quat
	{
	public:
		float x;
		float y;
		float z;
		float w;

		inline constexpr Quat() : x(0), y(0), z(0), w(1) {}

		inline constexpr Quat(float a) : x(a), y(a), z(a), w(a) {}

		inline constexpr Quat(float a, float b, float c, float d = 1) : x(a), y(b), z(c), w(d) {}

		inline Quat(const std::string& str);

		template<typename U>
		inline constexpr Quat(const Vec3<U>& a) : x(a.x), y(a.y), z(a.z), w(1.f) {}

		template<typename U>
		inline constexpr Quat(const Vec4<U>& a) : x(a.x), y(a.y), z(a.z), w(a.w) {}

		inline constexpr Quat operator+(const Quat& a) const;

		inline constexpr Quat operator-(const Quat& a) const;

		inline constexpr Quat operator*(const Quat& a) const;

		inline constexpr Quat operator*(float a) const;

		template<typename U>
		inline constexpr Vec3<U> operator*(const Vec3<U>& a) const;

		inline void operator*=(const Quat& a);

		inline void operator*=(float a);

		inline bool operator==(const Quat& a) const;
		inline bool operator!=(const Quat& a) const;

		inline float& operator[](const size_t index);
		inline const float& operator[](const size_t index) const;

		static inline constexpr Quat Identity() { return Quat(0, 0, 0, 1); }

		template<typename U>
		static inline constexpr Quat AngleAxis(float angle, Vec3<U> axis);

		template<typename U>
		static inline constexpr Quat FromEuler(const Vec3<U>& euler);

		template<typename U>
		static inline Quat LookRotation(Vec3<U> forward, Vec3<U> up);

		static inline Quat SLerp(const Quat& a, const Quat& b, float time);

		inline void Inverse();
		static inline Quat Inverse(const Quat& a);

		inline Quat GetInverse() const;

		inline void Normalize();
		static inline Quat Normalize(const Quat& a);

		inline Quat GetNormalize() const;

		inline void Conjugate();
		static inline Quat Conjugate(const Quat& a);

		inline Quat GetConjugate() const;

		inline float Dot(const Quat& a) const;
		static inline float Dot(const Quat& a, const Quat& b);

		template<typename U>
		inline Vec3<U> ToEuler() const;
		template<typename U>
		static inline Vec3<U> ToEuler(const Quat& a);

		inline Vec3f ToEuler() const;
		static inline Vec3f ToEuler(const Quat& a);

		inline Mat3 ToRotationMatrix3() const;
		static inline Mat3 ToRotationMatrix3(const Quat& a);

		inline Mat4 ToRotationMatrix4() const;
		static inline Mat4 ToRotationMatrix4(const Quat& a);

		inline void Print() const;
		static inline void Print(const Quat& a);

		inline std::string ToString(int precision = 6) const;
		static inline std::string ToString(const Quat& a, int precision = 6);

#ifdef MATH_GLM_EXTENSION
		inline glm::quat ToGlm() const { return glm::quat(w, x, y, z); }

		inline bool operator==(const glm::quat& b) const { return AlmostEqual(x, b.x) && AlmostEqual(y, b.y) && AlmostEqual(z, b.z) && AlmostEqual(w, b.w); }
#endif
	};

}

using namespace GALAXY::Math;
#ifdef IMGUI_IMPLEMENTATION
#define IM_VEC2_CLASS_EXTRA                                                     \
        constexpr ImVec2(const Math::Vec2f& f) : x(f.x), y(f.y) {}                   \
        operator Math::Vec2f() const { return Math::Vec2f(x,y); }

#define IM_VEC4_CLASS_EXTRA                                                     \
        constexpr ImVec4(const Math::Vec4f& f) : x(f.x), y(f.y), z(f.z), w(f.w) {}   \
        operator Math::Vec4f() const { return Math::Vec4f(x,y,z,w); }
#endif

#include "Maths.inl"