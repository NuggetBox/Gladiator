#ifndef SPEAR__HEADER
#define SPEAR_HEADER

#include "Vector2.h"
#include "GameObject.h"
#include "Character.h"
#include "GameInfo.h"

class Spear : public GameObject
{
public:

	Spear(bool anIsPlayer, Vector2 aDir);
	~Spear();

	Vector2 GetDir();
	void SetDir(Vector2 aDir);

	void Update(const float& someDelta);

	void Draw(sf::RenderWindow& aWindow);

	void RequestMove(Vector2 aMovement);
	void RequestHit(bool anIsPlayer);

private:
	Vector2 myDir;
	float mySpeed, myDamage;
	bool myIsPlayer;
};

#endif
