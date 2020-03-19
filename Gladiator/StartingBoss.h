#pragma once

#include "Boss.h"

class StartingBoss : public Boss
{
public:

	StartingBoss();
	~StartingBoss();

	void Update(const float& someDelta) override;
	void Draw(sf::RenderWindow& aWindow) override;

	void Attack(bool aNear) override;
	void Idle() override;
	void Ultimate() override;

private:
	Vector2 myMove;
	float mySpeed;
};

