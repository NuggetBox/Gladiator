#ifndef BOSS_HEADER
#define BOSS_HEADER

#include "GameInfo.h"
#include "Character.h"

class Boss
	: public Character
{
public:
	Boss();
	~Boss();

	void Update(const float& someDelta) override;

protected:
	Player* myPlayer;
	sf::Texture myTexture;
};

#endif