#ifndef THIRDBOSS_H
#define THIRDBOSS_H

#include "Boss.h"

class ThirdBoss : public Boss
{
public:
	ThirdBoss();
	~ThirdBoss();

	void Update(const float& someDelta) override;
	void Draw(sf::RenderWindow& aWindow) override;
};

#endif