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
}

float Vector2::Length()
{
	return 0.0f;
}

float Vector2::LengthSquared()
{
	return 0.0f;
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