#pragma once
#ifndef __VECTOR2__
#define __VECTOR2__
#include <string>

class Vector2
{
public:
	float x;
	float y;
	
	Vector2(float x = 0.0f, float y = 0.0f);
	~Vector2();

	// Copy constructor 
	Vector2(const Vector2 &vector);

	Vector2 operator + (Vector2 const &rhs);
	Vector2 operator - (Vector2 const &rhs);
	Vector2 operator * (Vector2 const &rhs);
	Vector2 operator / (Vector2 const &rhs);
	bool operator == (Vector2 const &rhs);
	bool operator != (Vector2 const &rhs);
	
	// public functions
	void Set(float newX, float newY);
	void Normalize();
	Vector2 Normalized();
	float Magnitude();
	float SqrMagnitude();
	void Scale(Vector2 scale);
	std::string ToString(int precision = 0) const;

	// public static functions
	static Vector2 zero();
	static Vector2 one();
	static Vector2 up();
	static Vector2 down();
	static Vector2 left();
	static Vector2 right();
	static Vector2 Lerp(Vector2 a, Vector2 b, float t);
	static Vector2 LerpUnclamped(Vector2 a, Vector2 b, float t);
	static Vector2 MoveTowards(Vector2 current, Vector2 target, float maxDistanceDelta);
	static Vector2 Scale(Vector2 a, Vector2 b);
	static Vector2 Reflect(Vector2 inDirection, Vector2 inNormal);
	static float Dot(Vector2 lhs, Vector2 rhs);
	static float Angle(Vector2 from, Vector2 to);
	static float Distance(Vector2 a, Vector2 b);
	static Vector2 ClampMagnitude(Vector2 vector, float maxLength);
	static float SqrMagnitude(Vector2 a);
	static Vector2 Min(Vector2 lhs, Vector2 rhs);
	static Vector2 Max(Vector2 lhs, Vector2 rhs);
	
private:
	float m_magnitude;
	
};
#endif /* defined (__VECTOR2__) */