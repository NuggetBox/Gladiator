#ifndef SPEAR_H
#define SPEAR_H

#include "Character.h"

class Spear :
	public GameObject
{
public:
	Spear(Vector2 aPosition, Vector2 someMovement);
	~Spear();

	void Update(const float& someDelta) override;
	void Draw(sf::RenderWindow& aWindow) override;

private:
	bool TryMove(Vector2 someMovement);

	sf::Texture myTexture;

	Vector2 myMovement;

	float mySpeed, myDamage;

	bool myIsStuck;
};

#endif