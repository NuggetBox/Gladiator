#pragma once

#define _USE_MATH_DEFINES

#include "Boss.h"
#include "Ray.h"


class StartingBoss : public Boss
{
public:

	StartingBoss();
	~StartingBoss();

	void Update(const float& someDelta) override;
	void Draw(sf::RenderWindow& aWindow) override;

	void Attack(bool aNear);
	void Idle();
	void Ultimate() override;

private:
	Vector2 myMove, myScale, myOrigin;
	float mySpeed, myRotation;
	Ray myRay;
	std::vector<GameObject*> myGameobjects;
	bool myAttackBool;
	sf::Texture myTexture;
};

