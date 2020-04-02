#pragma once

#define _USE_MATH_DEFINES

#include "Boss.h"
#include "Ray.h"
#include "GameInfo.h"

enum States
{
	Idle,
	Charging,
	Stuck
};

class StartingBoss : public Boss
{

public:


	StartingBoss();
	~StartingBoss();

	void Update(const float& someDelta) override;
	void Draw(sf::RenderWindow& aWindow) override;

	void Attack(const float& someDelta);
	void Idle(const float& someDelta);
	void Ultimate() override;

private:
	Vector2 myMove;
	float mySpeed, myChargeSpeed, myRotation;
	float myStunTimer, myIdleTimer;
	int myHits;
	Ray myRay;
	std::vector<GameObject*> myGameobjects;
	bool myAttackBool;
	sf::Texture myTexture;
	States myBossStates;
};

