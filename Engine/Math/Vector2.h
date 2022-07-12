#pragma once
#include <cmath>

namespace crae
{
	struct Vector2 //default public
	{
		float x, y;

		Vector2() : x{0}, y{0}{}
		Vector2(float x, float y) : x{x}, y{y}{}
		Vector2(float v) : x{v}, y{v}{}
		Vector2(int x, int y) : x{ (float)x }, y{ (float)y }{}

		void Set(float x, float y) { this->x = x; this->y = y; }
		
		//Vec2 = Vec2 + Vec2
		Vector2 operator + (const Vector2& v) const { return Vector2{ this->x + v.x, this->y + v.y }; } //add 2 vectors together and return a new vector
		Vector2 operator - (const Vector2& v) const { return Vector2{ this->x - v.x, this->y - v.y }; }
		Vector2 operator * (const Vector2& v) const { return Vector2{ this->x * v.x, this->y * v.y }; }
		Vector2 operator / (const Vector2& v) const { return Vector2{ this->x / v.x, this->y / v.y }; }

		//Vector 2 = Vec2 + float
		Vector2 operator + (float s) const { return Vector2{ this->x + s, this->y + s }; }
		Vector2 operator - (float s) const { return Vector2{ this->x - s, this->y - s }; }
		Vector2 operator * (float s) const { return Vector2{ this->x * s, this->y * s }; }
		Vector2 operator / (float s) const { return Vector2{ this->x / s, this->y / s }; }

		//Assignment Operators
		Vector2 operator += (const Vector2& v) { this->x += v.x; this->y += v.y; return *this; }
		Vector2 operator -= (const Vector2& v) { this->x -= v.x; this->y -= v.y; return *this; }
		Vector2 operator *= (const Vector2& v) { this->x *= v.x; this->y *= v.y; return *this; }
		Vector2 operator /= (const Vector2& v) { this->x /= v.x; this->y /= v.y; return *this; }

		//Assignment Operators w/ float
		Vector2 operator += (float s) { this->x += s; this->y += s; return *this; }
		Vector2 operator -= (float s) { this->x -= s; this->y -= s; return *this; }
		Vector2 operator *= (float s) { this->x *= s; this->y *= s; return *this; }
		Vector2 operator /= (float s) { this->x /= s; this->y /= s; return *this; }

		//unary
		//Vector2 = -Vector2
		Vector2 operator - () const { return Vector2{-x, -y}; }

		//Comparison
		//Vector2 == Vector2
		bool operator == (const Vector2& v) const { return (this->x == v.x && this->y == v.y); }
		bool operator != (const Vector2& v) const { return (this->x != v.x || this->y != v.y); }

		//Functions
		float LengthSqr();
		float Length();

		float DistanceSqr(const Vector2& v);
		float Distance(const Vector2& v);

		Vector2 Normalized();
		void Normalize();

		static Vector2 Rotate(const Vector2& v, float angle);
	};

	inline float Vector2::LengthSqr() { return x * x + y * y; }

	inline float Vector2::Length() { return std::sqrt(LengthSqr()); }

	inline float Vector2::DistanceSqr(const Vector2& v) { return ((*this) - v).LengthSqr(); }

	inline float Vector2::Distance(const Vector2& v) { return ((*this) - v).Length(); }
	
	inline Vector2 Vector2::Normalized()
	{
		float length = Length();

		return Vector2{x/ length, y/length};
	}
	inline void Vector2::Normalize()
	{
		(*this) /= Length();
	}
	inline Vector2 Vector2::Rotate(const Vector2& v, float angle)
	{
		float x = v.x * std::cos(angle) - v.y * std::sin(angle);
		float y = v.y * std::sin(angle) - v.y * std::sin(angle);

		return Vector2{x, y};
	}
}