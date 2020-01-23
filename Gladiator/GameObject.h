#ifndef GAMEOBJECT_HEADER
#define GAMEOBJECT_HEADER

#include "Visual.h"

class GameObject
{
public:
	GameObject(Vector2 aPosition, sf::Texture aTexture, float aRotation, float aScale, int aLayer, float aHitBox);
	GameObject();
	virtual ~GameObject();

	virtual void Update(const float& someDelta);

	virtual void Draw(sf::RenderWindow& aWindow);

	int GetLayer();

	Vector2 GetPosition();

protected:

	Visual myVisual;
	Vector2 myPosition;
	int myLayer;
	float myHitBox;
};

#endif