#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <cmath>

class Player : public GameObject
{
public:
	Player();
	~Player();

	void Update(const float& someDelta) override;

private:
	float mySpeed;

	float mySwordSwingSpeed;

	sf::Texture myNoArmorNoHelmetNoSword;
	sf::Texture myNoArmorNoHelmetBasicSword;

	Animation mySwingNoArmorNoHelmetBasicSword;
};

#endif