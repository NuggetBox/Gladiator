#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	void Normalize();
	float Length();
	float LengthSquared();

	Vector2 operator-() const;
	Vector2 operator+(const Vector2& b) const;
	Vector2 operator-(const Vector2& b) const;
	Vector2 operator*(const Vector2& b) const;
	Vector2 operator/(const Vector2& b) const;
	Vector2 operator*(const float& b) const;
	Vector2 operator/(const float& b) const;
	Vector2& operator=(const Vector2& b);
	Vector2& operator+=(const Vector2& b);
	Vector2& operator-=(const Vector2& b);
	Vector2& operator*=(const Vector2& b);
	Vector2& operator/=(const Vector2& b);
	Vector2& operator*=(const float& b);
	Vector2& operator/=(const float& b);
										 
	bool operator==(const Vector2& b) const;
	bool operator!=(const Vector2& b) const;

	float x, y;
};

#endif