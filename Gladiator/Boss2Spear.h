#ifndef BOSS2SPEAR__HEADER
#define BOSS2SPEAR_HEADER

#include "Vector2.h"
#include "GameObject.h"
#include "Character.h"
#include "GameInfo.h"

class Boss2Spear : public GameObject
{
public:

	Spear(CharacterType aCharactertype, Vector2 aDir);
	~Spear();

	Vector2 GetDir();
	void SetDir(Vector2 aDir);

	void Update(const float& someDelta);

	void Draw(sf::RenderWindow& aWindow);

	void RequestMove(Vector2 aMovement);
	void RequestHit(CharacterType anAllyCharacterType);

private:
	Vector2 myDir;
	float mySpeed, myDamage;
	CharacterType myCharactertype;
};

#endif

