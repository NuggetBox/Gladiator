#ifndef RAY_HEADER
#define RAY_HEADER

#include "GameInfo.h"

class Ray
{
public:
	Ray();
	virtual ~Ray();

	Ray Cast(float anAngle, Vector2 anOrigin);
	Ray Cast(Vector2 aDirection, Vector2 anOrigin);
	Ray Cast(float anAngle, Vector2 anOrigin, float aMaxLength);
	Ray Cast(Vector2 aDirection, Vector2 anOrigin, float aMexLength);

private:

	
};

#endif