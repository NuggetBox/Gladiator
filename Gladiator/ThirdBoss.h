#ifndef THIRDBOSS_H
#define THIRDBOSS_H

#include "Boss.h"

enum ThirdBossStates
{
	MoveForThrow, Throwing, MoveForAttack, Attacking
};

class ThirdBoss : public Boss
{
public:
	ThirdBoss();
	~ThirdBoss();

	void Update(const float& someDelta) override;
	void Draw(sf::RenderWindow& aWindow) override;

private:
	ThirdBossStates myState;
};

#endif