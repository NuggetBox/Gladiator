#include "StartingBoss.h"

StartingBoss::StartingBoss()
{
	myBossStates = States::Idle;
	myIsPlayer = false;
	myMaxHealth = 120;
	myHealth = myMaxHealth;
	myPlayer = playerInfo::getPlayer();
	mySpeed = 100;
	myChargeSpeed = 500;
	myPosition = Vector2(800,500);
	myLayer = 11;
	myTexture.loadFromFile("Textures/Boss/bull.png");
	myRotation = 0;
	//myVisual = Visual(myTexture, myRotation, myScale, myOrigin);
	myVisual = Visual(myTexture, myRotation, { 5, 5 }, { 0.5f * myTexture.getSize().x, 0.5f * myTexture.getSize().y });
	myHitRadius = 100;
	myHits = 0;
	myHasAttacked = false;
	myIsInvincible = true;
}

void StartingBoss::Update(const float& someDelta)
{
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
		myIsInvincible = false;
		myVisual.SetColor(sf::Color(255, 255, 0, 255));
		myStunTimer -= 1 * someDelta;
		if (myHealth <= (myOriginalHealth-(myMaxHealth/3))) 
		{
			myBossStates = States::Idle;
			myIsInvincible = true;
		}
		if (myStunTimer <= 0)
		{
			myBossStates = States::Idle;
			myIsInvincible = true;
		}
		break;
	}
}

void StartingBoss::Attack(const float& someDelta)
{
	myVisual.SetColor(sf::Color(0,255,255,255));

	if (myPosition.Distance(myPlayer->GetPosition()) <= myHitRadius && myHasAttacked == false)
	{
		myPlayer->TakeDamage(10);
		myHasAttacked = true;
	}


	if (gameInfo::getOutOfBounds((myPosition + myMove), myHitRadius))
	{
		if (myHits == 3) 
		{
			myBossStates = States::Stuck;
			myOriginalHealth = myHealth;
			myStunTimer = 10;
			myHits = 0;
		}
		else 
		{
			myHits++;
			myHasAttacked = false;
			myMove = (myPlayer->GetPosition() - myPosition);
			myMove.Normalize();
			myRotation = myMove.Angle();
			myMove *= (myChargeSpeed * someDelta);
		}

	}
	else
	{
		RequestMove(myMove);

	}
}

void StartingBoss::Idle(const float& someDelta)
{
	myVisual.SetColor(sf::Color(255, 0, 255, 255));
	Vector2 tempDir = (myPlayer->GetPosition() - myPosition);
	myRotation = tempDir.Angle();
	if (myPosition.Distance(Vector2(960,540)) > 10) 
	{
		myIdleTimer = 1;
		myMove = Vector2(960 - myPosition.x, 540 - myPosition.y);
		myMove.Normalize();
		myMove *= (someDelta * mySpeed);

		RequestMove(myMove);
	}
	else
	{
		myIdleTimer -= 1 * someDelta;
		if (myIdleTimer <= 0) {
			myBossStates = States::Charging;
			myMove = (myPlayer->GetPosition() - myPosition);
			myMove.Normalize();
			myRotation = myMove.Angle();
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