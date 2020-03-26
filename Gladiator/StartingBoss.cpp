#include "StartingBoss.h"

StartingBoss::StartingBoss()
{
	myBossStates = States::Idle;
	myPlayer = gameInfo::getPlayer();
	mySpeed = 100.0f;
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


	switch (myBossStates)
	{
	case States::Idle:
		Idle(someDelta);
		break;
	case States::Charging:
		Attack(someDelta);
		break;
	case States::Stuck:
		myStunTimer -= 1 * someDelta;
		if (myStunTimer <= 0)
		{
			myBossStates = States::Idle;
		}
		break;
	}
}

void StartingBoss::Attack(const float& someDelta)
{
	mySpeed = 500;
	myMove *= (mySpeed * someDelta);

	if (myPosition.Distance(myPlayer->GetPosition()) < myHitRadius)
	{
		myPlayer->TakeDamage(10);
	}

	RequestMove(myMove);
}

void StartingBoss::Ultimate()
{

}

void StartingBoss::Idle(const float& someDelta)
{
	mySpeed = 100;
	if (myPosition.Distance(Vector2(960,540)) > 100) 
	{
		myIdleTimer = 300;
		myMove = Vector2(960 - myPosition.x, 540 - myPosition.y);

		myMove *= (someDelta * mySpeed);

		RequestMove(myMove);
	}
	else
	{
		myIdleTimer -= 1 * someDelta;
		if (myIdleTimer <= 0) {
			myBossStates = States::Charging;
		}
	}
}

void StartingBoss::Draw(sf::RenderWindow& aWindow)
{
	myVisual.Draw(aWindow, myPosition);
}

StartingBoss::~StartingBoss()
{
	myPlayer = NULL;
	delete(myPlayer);
}