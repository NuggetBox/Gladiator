#include "Ray.h"

Ray::Ray()
{
	myLength = 1;
	myObjectHit = GameObject();
	myPosition = Vector2();
}

Ray::~Ray()
{

}

/*Ray Ray::Cast(float anAngle, Vector2 anOrigin)
{
	return Calculate(gMath::RotateVector({ 0, 1 }, anAngle), anOrigin, 0);
}

Ray Ray::Cast(Vector2 aDirection, Vector2 anOrigin)
{
	return Calculate(aDirection, anOrigin, 0);
}

Ray Ray::Cast(float anAngle, Vector2 anOrigin, float aMaxLength)
{
	return Calculate(gMath::RotateVector({ 0, 1 }, anAngle), anOrigin, aMaxLength);
}

Ray Ray::Cast(Vector2 aDirection, Vector2 anOrigin, float aMaxLength)
{
	return Calculate(aDirection, anOrigin, aMaxLength);
}

Ray Ray::Calculate(Vector2 aDirection, Vector2 anOrigin, float aMaxLength)
{
	myLength = 1;
	myObjectHit = GameObject();
	myPosition = Vector2();

	return *this;
}*/