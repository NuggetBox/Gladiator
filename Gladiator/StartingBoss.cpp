#include "StartingBoss.h"

StartingBoss::StartingBoss()
{
	myPlayer = gameInfo::getPlayer();
	mySpeed = 100;
	myVisual = Visual();
	myHitRadius = 10;
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

		break;
	case false:
		if (myPosition.Distance(myPlayer->GetPosition()) < (myHitRadius + myPlayer->GetHitRadius()))
		{

		}
		break;
	}
}

void StartingBoss::Ultimate()
{

}

void StartingBoss::Idle()
{
	if (myPosition.Distance(myPlayer->GetPosition()) < 100)
	{
		myPosition = myMove * mySpeed;
	}
	if (myPosition.Distance(myPlayer->GetPosition()) > 100)
	{

	}
}

void StartingBoss::Draw(sf::RenderWindow& aWindow)
{

}

StartingBoss::~StartingBoss()
{
	delete(myPlayer);
}