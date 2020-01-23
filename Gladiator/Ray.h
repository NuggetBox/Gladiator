#ifndef RAY_HEADER
#define RAY_HEADER

#include "GameInfo.h"
#include "GMath.h"

class Ray
{
public:
	Ray();
	~Ray();

	/*Ray Cast(float anAngle, Vector2 anOrigin);
	Ray Cast(Vector2 aDirection, Vector2 anOrigin);
	Ray Cast(float anAngle, Vector2 anOrigin, float aMaxLength);
	Ray Cast(Vector2 aDirection, Vector2 anOrigin, float aMaxLength);*/

private:
	//Ray Calculate(Vector2 aDirection, Vector2 anOrigin, float aMaxLength);

	float myLength;
	Vector2 myPosition;
	GameObject myObjectHit;
	
};

#endif