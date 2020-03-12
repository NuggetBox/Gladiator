#include "StartingBoss.h"

StartingBoss::StartingBoss()
{
	myPlayer = gameInfo::getPlayer();
	mySpeed = 100;
	myVisual = Visual();
}

void StartingBoss::Update(const float& someDelta)
{
	myMove = Vector2(myPlayer->GetPosition().x - myPosition.x, myPlayer->GetPosition().y - myPosition.y);


	if (myPlayer->GetPosition().Distance(myPosition) < 100)
	{
		Attack(true);
	}
	if (myPlayer->GetPosition().Distance(myPosition) > 100)
	{
		Attack(false);
	}

	Idle();
}

void StartingBoss::Attack(bool aNear)
{
	switch (aNear)
	{
	case true:
		myRay.Cast(Vector2(1,1), Vector2(1,1), 10, myGameobjects);

		
		break;
	case false:

		break;
	}
}

void StartingBoss::Ultimate()
{

}

void StartingBoss::Idle()
{
	if (myPlayer->GetPosition().Distance(myPosition) < 100)
	{
		myPosition = myMove * mySpeed;
	}
	if (myPlayer->GetPosition().Distance(myPosition) > 100)
	{

	}
}

void StartingBoss::Draw(sf::RenderWindow& aWindow)
{

}

StartingBoss::~StartingBoss()
{

}