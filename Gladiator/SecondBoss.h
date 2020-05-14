#ifndef SECONDBOSS_HEADER
#define SECONDBOSS_HEADER

#include "Boss.h"

enum Phases 
{
	Chariot,
	Gladiator
};

class SecondBoss : public Boss
{
public:


	SecondBoss();
	~SecondBoss();

	void Update(const float& someDelta) override;
	void Draw(sf::RenderWindow& aWindow) override;

	void Attack(const float& someDelta);
	void Idle(const float& someDelta);

private:
	Vector2 myMove;
	float mySpeed, myRotation, myOriginalHealth;
	float myIdleTimer, myRotateTimer;
	Phases myPhase;
	sf::Texture myTexture;
};

#endif