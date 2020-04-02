#include "StartingBoss.h"

StartingBoss::StartingBoss()
{
	myBossStates = States::Idle;
	myCharacterType = CharacterType::BossType;
	myPlayer = gameInfo::getPlayer();
	mySpeed = 100.0f;
	myChargeSpeed = 500;
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
	//myMove = Vector2(myPlayer->GetPosition().x - myPosition.x, myPlayer->GetPosition().y - myPosition.y);


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
		myVisual.SetColor(sf::Color(255, 255, 0, 255));
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
	myVisual.SetColor(sf::Color(0,255,255,255));

	if (myPosition.Distance(myPlayer->GetPosition()) < myHitRadius)
	{
		myPlayer->TakeDamage(10);
	}

	RequestMove(myMove);

	if (gameInfo::getOutOfBounds((myPosition + myMove), myHitRadius)) 
	{
		if (myHits == 3) 
		{
			myBossStates = States::Stuck;
			myStunTimer = 20;
			myHits = 0;
		}
		else 
		{
			myHits++;
			myMove = Vector2(myPlayer->GetPosition().x - myPosition.x, myPlayer->GetPosition().y - myPosition.y);
			myMove.Normalize();
			myMove *= (myChargeSpeed * someDelta);
			myRotation = 90 + atan2(myMove.y, myMove.x) * 180 / M_PI;
		}

	}
}

void StartingBoss::Ultimate()
{

}

void StartingBoss::Idle(const float& someDelta)
{
	myVisual.SetColor(sf::Color(255, 0, 255, 255));
	mySpeed = 1;
	if (myPosition.Distance(Vector2(960,540)) > 10) 
	{
		Vector2 tempDir = myPlayer->GetPosition() - myPosition;
		myRotation = 90 + atan2(tempDir.y, tempDir.x) * 180 / M_PI;
		myIdleTimer = 1;
		myMove = Vector2(960 - myPosition.x, 540 - myPosition.y);

		myMove *= (someDelta * mySpeed);

		RequestMove(myMove);
	}
	else
	{
		myIdleTimer -= 1 * someDelta;
		if (myIdleTimer <= 0) {
			myBossStates = States::Charging;
			myMove = Vector2(myPlayer->GetPosition().x - myPosition.x, myPlayer->GetPosition().y - myPosition.y);
			myMove.Normalize();
			myMove *= (myChargeSpeed * someDelta);
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