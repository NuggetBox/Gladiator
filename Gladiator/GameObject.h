#ifndef GAMEOBJECT_HEADER
#define GAMEOBJECT_HEADER

#include "Appearance.h"

class GameObject
{
public:
	GameObject(Vector2 aPosition, sf::Texture aTexture, float aRotation, float aScale, int aLayer);
	GameObject();
	virtual ~GameObject();

	virtual void Update(const float& someDelta);

	virtual void Draw(sf::RenderWindow& aWindow);

	int GetLayer();

protected:

	Appearance myAppearance;
	int myLayer;
	Vector2 myPosition;
};

#endif