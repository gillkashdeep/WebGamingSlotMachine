#include "Vector2.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include "Util.h"

Vector2::Vector2(float x, float y): x(x), y(y)
{
}

Vector2::~Vector2()
{
}

Vector2::Vector2(const Vector2 & vector)
{
	x = vector.x;
	y = vector.y;
}

Vector2 Vector2::operator+(Vector2 const & rhs)
{
	Vector2 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	return result;
}

Vector2 Vector2::operator-(Vector2 const & rhs)
{
	Vector2 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	return result;
}

Vector2 Vector2::operator*(Vector2 const & rhs)
{
	Vector2 result;
	result.x = x * rhs.x;
	result.y = y * rhs.y;
	return result;
}

Vector2 Vector2::operator/(Vector2 const & rhs)
{
	Vector2 result;
	result.x = x / rhs.x;
	result.y = y / rhs.y;
	return result;
}

bool Vector2::operator==(Vector2 const & rhs)
{
	Vector2 vector = Vector2(x, y);
	return double(Vector2::SqrMagnitude(vector - rhs)) < 9.99999943962493E-11;
}

bool Vector2::operator!=(Vector2 const & rhs)
{
	Vector2 vector = Vector2(x, y);
	return double(Vector2::SqrMagnitude(vector - rhs)) >= 9.99999943962493E-11;
}

// public functions
void Vector2::Set(float newX, float newY)
{
	x = newX;
	y = newY;
}

void Vector2::Normalize()
{
	const float magnitude = Magnitude();
	if (double(magnitude) > 9.99999974737875E-06)
	{
		x = x / magnitude;
		y = y / magnitude;
	}	
	else
	{
		x = 0.0f;
		y = 0.0f;
	}
		
}

Vector2 Vector2::Normalized()
{
	Vector2 vector2 = Vector2(x, y);
	vector2.Normalize();
	return vector2;
}

float Vector2::Magnitude()
{
	return sqrt(float((double(x) * double(x)) + (double(y) * double(y))));
}

float Vector2::SqrMagnitude()
{
	return float((double(x) * double(x)) + (double(y) * double(y)));
}

void Vector2::Scale(Vector2 scale)
{
	x *= scale.x;
	y *= scale.y;
}

std::string Vector2::ToString(const int precision) const
{
	std::ostringstream xStream;
	xStream << std::fixed;
	xStream << std::setprecision(precision);
	xStream << x;

	std::ostringstream yStream;
	yStream << std::fixed;
	yStream << std::setprecision(precision);
	yStream << y;

	std::string result = "(" + xStream.str() + ", " + yStream.str() + ")";
	return result;
}

Vector2 Vector2::zero()
{
	return Vector2(0.0f, 0.0f);
}

Vector2 Vector2::one()
{
	return Vector2(1.0f, 1.0f);
}

Vector2 Vector2::up()
{
	return Vector2(0.0f, -1.0f);
}

Vector2 Vector2::down()
{
	return Vector2(0.0f, 1.0f);
}

Vector2 Vector2::left()
{
	return Vector2(-1.0f, 0.0f);
}

Vector2 Vector2::right()
{
	return Vector2(0.0f, 1.0f);
}

Vector2 Vector2::Lerp(Vector2 a, Vector2 b, float t)
{
	t = Util::Clamp01(t);
	return Vector2(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t);
}

Vector2 Vector2::LerpUnclamped(Vector2 a, Vector2 b, float t)
{
	return Vector2(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t);
}

Vector2 Vector2::MoveTowards(Vector2 current, Vector2 target, float maxDistanceDelta)
{
	Vector2 vector2 = target - current;
	float magnitude = vector2.Magnitude();
	if (double(magnitude) <= double(maxDistanceDelta) || double(magnitude) == 0.0)
	{
		return target;
	}
	return current + vector2 / magnitude * maxDistanceDelta;
}

Vector2 Vector2::Scale(Vector2 a, Vector2 b)
{
	return Vector2(a.x * b.x, a.y * b.y);
}

Vector2 Vector2::Reflect(Vector2 inDirection, Vector2 inNormal)
{
	const float reverse = -2.0f * Vector2::Dot(inNormal, inDirection);
	Vector2 result = Vector2::Scale(Vector2(reverse, reverse), inNormal);
	result = result + inDirection;
	return result;
}

float Vector2::Dot(Vector2 lhs, Vector2 rhs)
{
	return float(double(lhs.x) * double(rhs.x) + double(lhs.y) * double(rhs.y));
}

float Vector2::Angle(Vector2 from, Vector2 to)
{
	return acos(Util::Clamp(Vector2::Dot(from.Normalized(), to.Normalized()), -1.0f, 1.0f)) * 57.29578f;
}

float Vector2::Distance(Vector2 a, Vector2 b)
{
	return (a - b).Magnitude();
}

Vector2 Vector2::ClampMagnitude(Vector2 vector, float maxLength)
{
	if (double(vector.SqrMagnitude()) > double(maxLength) * double(maxLength))
	{
		return vector.Normalized() * maxLength;
	}
	return vector;
}

float Vector2::SqrMagnitude(Vector2 a)
{
	return float((double(a.x) * double(a.x)) + (double(a.y) * double(a.y)));
}

Vector2 Vector2::Min(Vector2 lhs, Vector2 rhs)
{
	return Vector2(Util::Min(lhs.x, rhs.x), Util::Min(lhs.y, rhs.y));
}

Vector2 Vector2::Max(Vector2 lhs, Vector2 rhs)
{
	return Vector2(Util::Max(lhs.x, rhs.x), Util::Max(lhs.y, rhs.y));
}
