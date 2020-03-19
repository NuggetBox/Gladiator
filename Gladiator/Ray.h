#ifndef RAY_HEADER
#define RAY_HEADER

#include "GameInfo.h"
#include "GMath.h"

class Ray
{
public:
	Ray();
	~Ray();

	Ray Cast(float anAngle, Vector2 anOrigin, std::vector<GameObject*> someValidGameObjects);
	Ray Cast(Vector2 aDirection, Vector2 anOrigin, std::vector<GameObject*> someValidGameObjects);
	Ray Cast(float anAngle, Vector2 anOrigin, float aMaxLength, std::vector<GameObject*> someValidGameObjects);
	Ray Cast(Vector2 aDirection, Vector2 anOrigin, float aMaxLength, std::vector<GameObject*> someValidGameObjects);

	float GetLength();
	Vector2 GetHitPosition();
	GameObject* GetObjectHit();
	bool GetHit();
	std::vector<GameObject*> GetAllObjectsHit();

private:
	Ray Calculate(Vector2 aDirection, Vector2 anOrigin, float aMaxLength, std::vector<GameObject*> someGameObjects);

	float myLength;
	Vector2 myHitPosition;
	GameObject* myObjectHit;
	bool myHit;
	std::vector<GameObject*> myAllObjectsHit;
	
};

#endif