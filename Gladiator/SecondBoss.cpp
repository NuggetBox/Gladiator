#include "SecondBoss.h"

SecondBoss::SecondBoss() 
{
	myMove = Vector2(0,0);
	mySpeed = 300;
	myRotation = 0;
	myMaxHealth = 240;
	myHealth = myOriginalHealth;
	myPosition = Vector2(800, 500);

}

SecondBoss::~SecondBoss() 
{

}

void SecondBoss::Update(const float& someDelta) 
{

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