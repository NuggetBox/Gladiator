#include "GMath.h"

namespace gMath
{
	Vector2 RotateVector(Vector2 aVector, float aRadian)
	{
		float tempSin = (float)sin(aRadian);
		float tempCos = (float)cos(aRadian);

		return
		{
			(tempCos * aVector.x) - (tempSin * aVector.y),
			(tempSin * aVector.x) + (tempCos * aVector.y)
		};
	}
}