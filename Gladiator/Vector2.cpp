#include "Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y) : x(x), y(y)
{

}

Vector2::~Vector2()
{

}

void Vector2::Normalize()
{
	if (Length() != 0)
	{
		x /= Length();
		y /= Length();
	}
}

float Vector2::Length()
{
	return sqrtf(x * x + y * y);
}

float Vector2::LengthSquared()
{
	return x * x + y * y;
}

float Vector2::Angle()
{
	return atan2f(y, x);
}

float Vector2::Distance(Vector2 b)
{
	return (*this - b).Length();
}

// Operators
Vector2 Vector2::operator-() const
{
	return Vector2(-x, -y);
}

Vector2 Vector2::operator+(const Vector2& b) const
{
	return Vector2(x + b.x, y + b.y);
}

Vector2 Vector2::operator-(const Vector2& b) const
{
	return Vector2(x - b.x, y - b.y);
}

Vector2 Vector2::operator*(const Vector2& b) const
{
	return Vector2(x * b.x, y * b.y);
}

Vector2 Vector2::operator/(const Vector2& b) const
{
	return Vector2(x / b.x, y / b.y);
}

Vector2 Vector2::operator*(const float& b) const
{
	return Vector2(x * b, y * b);
}

Vector2 Vector2::operator/(const float& b) const
{
	return Vector2(x / b, y / b);
}

Vector2& Vector2::operator=(const Vector2& b)
{
	x = b.x;
	y = b.y;

	return *this;
}

Vector2& Vector2::operator+=(const Vector2& b)
{
	x += b.x;
	y += b.y;

	return *this;
}

Vector2& Vector2::operator-=(const Vector2& b)
{
	x -= b.x;
	y -= b.y;

	return *this;
}

Vector2& Vector2::operator*=(const Vector2& b)
{
	x *= b.x;
	y *= b.y;

	return *this;
}

Vector2& Vector2::operator/=(const Vector2& b)
{
	x /= b.x;
	y /= b.y;

	return *this;
}

Vector2& Vector2::operator*=(const float& b)
{
	x *= b;
	y *= b;

	return *this;
}

Vector2& Vector2::operator/=(const float& b)
{
	x /= b;
	y /= b;

	return *this;
}

bool Vector2::operator==(const Vector2& b) const
{
	return x == b.x && y == b.y;
}

bool Vector2::operator!=(const Vector2& b) const
{
	return x != b.x || y != b.y;
} 