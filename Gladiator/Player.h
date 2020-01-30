#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#define _USE_MATH_DEFINES

#include "GameObject.h"
#include <cmath>

class Player : public GameObject
{
public:
	Player();
	~Player();

	void Update(const float& someDelta) override;

	void Draw(sf::RenderWindow& aWindow) override;

private:
	float mySpeed;
	float mySwordSwingSpeed;

	float myDodgeTime;
	float myDodgeInvincibilityTime;
	float myDodgeTimer;
	float myDodgeSpeed;
	bool myIsDodging;
	Vector2 myDodgeDirection;
	bool myIsInvincible;
	int myInvincibilityAlpha;

	Visual myBodyVisual;
	Visual myHeadVisual;
	Visual myWeaponVisual;

	sf::Texture
		myNoHelmetIdle, myIronHelmetIdle, myDiamondHelmetIdle,
		myNoArmorIdle, myIronArmorIdle, myDiamonArmorIdle,
		myNoHelmet, myIronHelmet, myDiamondHelmet,
		myNoArmor, myIronArmor, myDiamondArmor,
		myStoneSword, myIronSword, myDiamondSword,
		myNoHelmetSwing, myIronHelmetSwing, myDiamondHelmetSwing,
		myNoArmorSwing, myIronArmorSwing, myDiamondArmorSwing,
		myStoneSwordSwing, myIronSwordSwing, myDiamondSwordSwing,
		myNoHelmetThrow, myIronHelmetThrow, myDiamondHelmetThrow,
		myNoArmorThrow, myIronArmorThrow, myDiamondArmorThrow;
};

#endif