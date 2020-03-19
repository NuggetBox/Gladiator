#include "Ray.h"

Ray::Ray()
{
	myLength = 0;
	myObjectHit = new GameObject();
	myHitPosition = Vector2();
}

Ray::~Ray()
{
	delete(myObjectHit);
	myObjectHit = NULL;
}

Ray Ray::Cast(float anAngle, Vector2 anOrigin, std::vector<GameObject*> someValidGameObjects)
{
	return Calculate(gMath::RotateVector({ 0, 1 }, anAngle), anOrigin, 0, someValidGameObjects);
}

Ray Ray::Cast(Vector2 aDirection, Vector2 anOrigin, std::vector<GameObject*> someValidGameObjects)
{
	return Calculate(aDirection, anOrigin, 0, someValidGameObjects);
}

Ray Ray::Cast(float anAngle, Vector2 anOrigin, float aMaxLength, std::vector<GameObject*> someValidGameObjects)
{
	return Calculate(gMath::RotateVector({ 0, 1 }, anAngle), anOrigin, aMaxLength, someValidGameObjects);
}

Ray Ray::Cast(Vector2 aDirection, Vector2 anOrigin, float aMaxLength, std::vector<GameObject*> someValidGameObjects)
{
	return Calculate(aDirection, anOrigin, aMaxLength, someValidGameObjects);
}

float Ray::GetLength()
{
	return myLength;
}

Vector2 Ray::GetHitPosition()
{
	return myHitPosition;
}

GameObject* Ray::GetObjectHit()
{
	return myObjectHit;
}

bool Ray::GetHit()
{
	return myHit;
}

std::vector<GameObject*> Ray::GetAllObjectsHit()
{
	return myAllObjectsHit;
}

Ray Ray::Calculate(Vector2 aDirection, Vector2 anOrigin, float aMaxLength, std::vector<GameObject*> someGameObjects)
{
	myLength = 0;
	myHit = false;
	float x = aDirection.x;
	float y = aDirection.y;
	if (x == 0) { x += 0.00001; }
	bool tempGoingRight = x > 0;
	float k = y / x;
	float m = y - k * x;

	for (int i = 0; i < someGameObjects.size(); ++i)
	{
		float tempThisK = someGameObjects[i]->GetPosition().y / someGameObjects[i]->GetPosition().x;
		float tempThisM = someGameObjects[i]->GetPosition().y - tempThisK * someGameObjects[i]->GetPosition().x;

		Vector2 tempIntersection = { (tempThisM - m) / (k - tempThisK), (k * tempThisM - tempThisK * m) / (k - tempThisK) };

		if (((tempIntersection - someGameObjects[i]->GetPosition()).Length() <= someGameObjects[i]->GetHitRadius()) && // The intersection is within hitradius
			(tempGoingRight && anOrigin.x < tempIntersection.x || !tempGoingRight && tempIntersection.x < anOrigin.x) && // The intersection is in the right direction
			(aMaxLength == 0 || (tempIntersection - anOrigin).Length() <= aMaxLength)) // The intersection is within the max length
		{
			myAllObjectsHit.push_back(someGameObjects[i]);

			if (!myHit || (tempIntersection - anOrigin).Length() < myLength) // This is the shortest ray yet
			{
				myHitPosition = tempIntersection;
				myHit = true;
				myLength = (tempIntersection - anOrigin).Length();
				myObjectHit = someGameObjects[i];
			}
		}
	}

	if (!myHit)
	{
		myHitPosition = anOrigin;
		myLength = 0;
		myObjectHit = &GameObject();
		myAllObjectsHit = { myObjectHit };
	}

	return *this;
}