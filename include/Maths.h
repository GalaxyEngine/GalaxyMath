#pragma once
#include <string>
#define PI 3.14159265358979323846264f
#define DegToRad 1/180.f * PI
#define RadToDeg 180.f / PI

#ifdef MATH_GLM_EXTENSION
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
		inline constexpr Vec2 operator*(const U& a) const;
		template<typename U>
		inline constexpr Vec2 operator*(const Vec2<U>& a) const;
		template<typename U>
		inline constexpr Vec2 operator/(const U& a) const;

		template<typename U>
		inline void operator+=(const Vec2<U>& a);
		template<typename U>
		inline void operator-=(const Vec2<U>& a);
		template<typename U>
		inline void operator*=(const Vec2<U>& a);
		template<typename U>
		inline void operator*=(const U& a);
		template<typename U>
		inline void operator/=(const U& a);

		template<typename U>
		inline constexpr bool operator==(const Vec2<U>& b) const;
		template<typename U>
		inline constexpr bool operator==(const Vec3<U>& b) const;
		template<typename U>
		inline constexpr bool operator!=(const Vec2<U>& b) const;
		template<typename U>
		inline constexpr bool operator!=(const Vec3<U>& b) const;

		inline T& operator[](const size_t a);

		inline T LengthSquared() const;

		inline T Length() const;

		inline T Dot(const Vec2& a) const;

		inline Vec2 Cross(const Vec2& a) const;

		inline Vec2 Ortho() const;

		inline void Normalize();

		inline Vec2 GetNormalize() const;

		inline void Print(int precision = 6) const;

		inline std::string ToString(int precision = 6) const;

		inline Vec2<float> ToVec2f() const;

		inline Vec2<int> ToVec2i() const;

		inline T* Data() const;

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
		template<typename U>
		inline constexpr Vec3 operator*(const U& b) const;
		template<typename U>
		inline constexpr Vec3 operator/(const U& b) const;

		inline void operator+=(const Vec3& b);
		inline void operator-=(const Vec3& b);
		inline void operator*=(const Vec3& b);
		template<typename U>
		inline void operator*=(const U& b);
		template<typename U>
		inline void operator/=(const U& b);

		template<typename U>
		inline constexpr bool operator==(const Vec3<U>& b) const;
		template<typename U>
		inline constexpr bool operator!=(const Vec3<U>& b) const;

		inline T& operator[](const size_t a);
		inline const T& operator[](const size_t a) const;

		static inline constexpr Vec3 Right() { return { 1, 0, 0 }; }
		static inline constexpr Vec3 Up() { return { 0, 1, 0 }; }
		static inline constexpr Vec3 Forward() { return { 0, 0, -1 }; }

		static inline constexpr Vec3 Left() { return { -1, 0, 0 }; }
		static inline constexpr Vec3 Down() { return { 0, -1, 0 }; }
		static inline constexpr Vec3 Back() { return { 0, 0, 1 }; }

		static inline constexpr Vec3 Zero() { return { 0, 0, 0 }; }
		static inline constexpr Vec3 One() { return { 1, 1, 1 }; }

		inline T LengthSquared() const;

		inline T Length() const;

		inline T Dot(const Vec3& a) const;

		inline Vec3 Cross(const Vec3& a) const;

		inline T Distance(const Vec3& a) const;

		inline Vec3 Lerp(const Vec3& a, float t) const;

		inline void Normalize();

		inline Vec3 GetNormalize() const;

		inline void Print(int precision = 6) const;

		inline std::string ToString(int precision = 6) const;

		inline Quat ToQuaternion() const;

		inline T* Data() const;

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
		template<typename U>
		inline constexpr Vec4 operator*(const U& b) const;
		template<typename U>
		inline constexpr Vec4 operator/(const U& b) const;

		inline void operator+=(const Vec4& b);
		inline void operator-=(const Vec4& b);
		inline void operator*=(const Vec4& b);
		template<typename U>
		inline void operator*=(const U& b);
		template<typename U>
		inline void operator/=(const U& b);

		template<typename U>
		inline bool operator==(const Vec4<U>& b) const;
		template<typename U>
		inline bool operator!=(const Vec4<U>& b) const;

		inline constexpr T& operator[](const size_t a);
		inline const T& operator[](const size_t a) const;

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

		inline T Length() const;

		inline T Dot(const Vec4& a) const;

		inline T Distance(const Vec4& a) const;

		inline void Homogenize();

		inline Vec4 GetHomogenize() const;

		inline void Normalize();

		inline Vec4 GetNormalize() const;

		inline void Print(int precision = 6) const;

		inline Vec3<T> ToVector3() const;

		inline std::string ToString(int precision = 6) const;

		T* Data() const;

#ifdef MATH_GLM_EXTENSION
		inline glm::vec4 ToGlm() const { return glm::vec4(x, y, z, w); }

		inline bool operator==(const glm::vec4& b) const { return AlmostEqual(x, b.x) && AlmostEqual(y, b.y) && AlmostEqual(z, b.z) && AlmostEqual(w, b.w); }
#endif
	};


	typedef Vec4<float> Vec4f;
	typedef Vec4<int> Vec4i;
	typedef Vec4<double> Vec4d;
#pragma endregion

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

		inline constexpr Mat4(Vec4f m0, Vec4f m1, Vec4f m2, Vec4f m3);

		inline constexpr Mat4(const float* data);

		inline constexpr Mat4(const double* data);

		inline constexpr Mat4 operator*(const Mat4& a) const;

		template<typename U>
		inline constexpr Vec4<U> operator*(const Vec4<U>& a) const;

		inline constexpr Mat4 operator+(const Mat4& a) const;

		inline constexpr Vec4f& operator[](size_t i);

		inline constexpr bool operator==(const Mat4& b) const;

		static constexpr Mat4 Identity() { return { 1.f }; }

		static inline Mat4 CreateProjectionMatrix(float _fov, float _aspect, float _near, float _far);

		static inline Mat4 CreateOrthographicMatrix(float _left, float _right, float _bottom, float _top, float _near, float _far);
		
		static inline Mat4 CreateViewMatrix(const Vec3f position, const Quat& rotation);

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

		inline Vec3f GetTranslation() const;

		inline Quat GetRotation() const;

		inline Vec3f GetScale() const;

		inline Mat4 CreateInverseMatrix() const;

		inline Mat4 CreateAdjMatrix() const;

		inline Mat4 GetCofactor(int p, int q, int n) const;

		inline float GetDeterminant(float n) const;

		inline Mat4 GetTranspose() const;

		inline void Print() const;

		inline std::string ToString() const;

		inline Mat4 ToRotationMatrix() const;

		// Transforms a position by this matrix, without a perspective divide. (fast)
		template<typename U>
		inline Vec3<U> MultiplyPoint3x4(Vec3<U> point);

		// Transforms a direction by this matrix.
		template<typename U>
		inline Vec3<U> MultiplyVector(Vec3<U> vector);		

		inline float* Data() const;

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

		static inline constexpr Quat Identity() { return Quat(0, 0, 0, 1); }

		template<typename U>
		static inline constexpr Quat AngleAxis(float angle, Vec3<U> axis);

		template<typename U>
		static inline constexpr Quat FromEuler(const Vec3<U>& euler);

		template<typename U>
		static inline Quat LookRotation(Vec3<U> forward, Vec3<U> up);

		static inline Quat SLerp(const Quat& a, const Quat& b, float time);

		inline void Inverse();

		inline Quat GetInverse() const;

		inline void Normalize();

		inline Quat GetNormalize() const;

		inline void Conjugate();

		inline Quat GetConjugate() const;

		inline float Dot(const Quat& a) const;

		template<typename U>
		inline Vec3<U> ToEuler() const;

		inline Vec3f ToEuler() const;

		inline Mat4 ToRotationMatrix() const;

		inline void Print() const;

		inline std::string ToString(int precision = 6) const;

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