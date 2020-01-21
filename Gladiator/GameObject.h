#ifndef GAMEOBJECT_HEADER
#define GAMEOBJECT_HEADER

#include "Appearance.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update(const float& someDelta);

	virtual void Draw(sf::RenderWindow& aWindow);

protected:

	Appearance myAppearance;
	Vector2 myPosition;
};

#endif