#include "SecondBoss.h"

SecondBoss::SecondBoss() 
{
	myMove = Vector2(0,0);
	myCharacterType = CharacterType::BossType;
	mySpeed = 300;
	myRotation = 0;
	myMaxHealth = 240;
	myHealth = myOriginalHealth;
	myPosition = Vector2(960, 150);
	myPhase = Phases::Chariot;
}

SecondBoss::~SecondBoss() 
{

}

void SecondBoss::Update(const float& someDelta) 
{
	if (myPhase == Phases::Chariot) 
	{

	}
	else
	{

	}
}

void SecondBoss::Draw(sf::RenderWindow& aWindow) 
{

}

void SecondBoss::Attack(const float& someDelta) 
{

}

void SecondBoss::Idle(const float& someDelta)
{

}