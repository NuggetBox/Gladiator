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
	float myXOrigin;
	float myYOrigin;
	float myScale;

	Appearance myBodyAppearance;
	Appearance myHeadAppearance;
	Appearance myWeaponAppearance;

	sf::Texture myNoArmor;
	sf::Texture myNoHelmet;
	sf::Texture myBasicSword;
	sf::Texture myNoArmorSwing;
	sf::Texture myNoHelmetSwing;
	sf::Texture myBasicSwordSwing;
};

#endif