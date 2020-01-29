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

	float GetHitRadius();

protected:
	void RequestMove(Vector2 aMovement);

	Visual myVisual;
	Vector2 myPosition;
	int myLayer;
	float myHitRadius;

	bool myIsPlayer;
	bool myIsBoss;
	bool myIsEnemy;
};

#endif