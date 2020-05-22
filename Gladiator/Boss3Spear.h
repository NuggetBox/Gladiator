#ifndef BOSS2SPEAR_HEADER
#define BOSS2SPEAR_HEADER

#include "Character.h"

class Boss3Spear :
	public GameObject
{
public:
	Boss3Spear(Vector2 aPosition, Vector2 someMovement);
	~Boss3Spear();

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