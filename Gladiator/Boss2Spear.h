#ifndef BOSS2SPEAR_HEADER
#define BOSS2SPEAR_HEADER

#include "Character.h"

class Boss2Spear :
	public GameObject
{
public:
	Boss2Spear(Vector2 aPosition, Vector2 someMovement);
	~Boss2Spear();

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