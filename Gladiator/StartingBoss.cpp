#include "StartingBoss.h"

StartingBoss::StartingBoss()
{
	myPlayer = gameInfo::getPlayer();
	mySpeed = 100;
	myPosition = Vector2(800,500);
	myScale = Vector2(5,5);
	myLayer = 11;
	myTexture.loadFromFile("Textures/Boss/bull.png");
	myOrigin = Vector2(0.5f * myTexture.getSize().x, 0.5f * myTexture.getSize().y);
	myRotation = 0;
	myVisual = Visual(myTexture, myRotation, myScale, myOrigin);
	myHitRadius = 10;
	myAttackBool = false;
}

void StartingBoss::Update(const float& someDelta)
{
	myMove = Vector2(myPlayer->GetPosition().x - myPosition.x, myPlayer->GetPosition().y - myPosition.y);

	Vector2 tempDir = myPlayer->GetPosition() - myPosition;
	myRotation = 90 + atan2(tempDir.y, tempDir.x) * 180 / M_PI;

	myVisual.SetRotation(myRotation);

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
	myVisual.Draw(aWindow, myPosition);
}

StartingBoss::~StartingBoss()
{
	delete(myPlayer);
}