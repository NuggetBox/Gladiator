#include "ThirdBoss.h"

ThirdBoss::ThirdBoss()
{
	myCharacterType = CharacterType::BossType;
	myMaxHealth = 100;
	myHealth = myMaxHealth;
	myPlayer = gameInfo::getPlayer();
	mySpeed = 150;
	myPosition = Vector2(800, 500);
	myLayer = 12;
	mySpearTexture.loadFromFile("Textures/Boss/treudd.png");
	myNoSpearTexture.loadFromFile("Textures/Boss/nospear.png");
	myAimingTexture.loadFromFile("Textures/Boss/throwing.png");
	//myVisual = Visual(myTexture, myRotation, myScale, myOrigin);
	myVisual = Visual(mySpearTexture, 0, { 5, 5 }, { 0.5f * mySpearTexture.getSize().x, 0.5f * mySpearTexture.getSize().y });
	myHitRadius = 30;
	myIsInvincible = false;
	myState = Moving;

	myMoveTime = 3.5f;
	myMoveTimer = 0;
	myAimTime = 2;
	myAimTimer = 0;
	myPickupTime = 0.3f;
	myPickupTimer = 0;
}

ThirdBoss::~ThirdBoss()
{
	delete(myPlayer);
	myPlayer = NULL;

	delete(mySpear);
	mySpear = NULL;
}

void ThirdBoss::Update(const float& someDelta) 
{
	Vector2 tempMove;

	switch (myState)
	{
	case Moving:
		tempMove = (myPlayer->GetPosition() - gameInfo::getArenaCenter()) * -1;
		tempMove += gameInfo::getArenaCenter();
		tempMove -= myPosition;
		myIsInvincible = true;

		if (tempMove.Length() > 5)
		{
			tempMove.Normalize();
			tempMove *= (mySpeed * someDelta);
			RequestMove(tempMove);
		}

		myMoveTimer += someDelta;

		if (myMoveTimer >= myMoveTime)
		{
			myMoveTimer = 0;
			myState = Aiming;
			myVisual.SetTexture(myAimingTexture);
		}

		myVisual.SetRotation((myPosition - myPlayer->GetPosition()).Angle());

		break;

	case Aiming:
		tempMove = Vector2(0, 0);
		myIsInvincible = true;
		myAimTimer += someDelta;

		if (myAimTimer >= myAimTime)
		{
			// Throw the spear;
			ThrowSpear();
			myVisual.SetTexture(myNoSpearTexture);
			myAimTimer = 0;
			myState = Pickup;
		}
		else
		{
			myVisual.SetRotation((myPosition - myPlayer->GetPosition()).Angle());
		}

		break;

	case Pickup:
		tempMove = mySpear->GetPosition() - myPosition;
		myIsInvincible = false;
		if (tempMove.Length() > 50)
		{
			tempMove.Normalize();
			tempMove *= (mySpeed * someDelta);
			RequestMove(tempMove);
		}
		else
		{
			myPickupTimer += someDelta;

			if (myPickupTimer >= myPickupTime)
			{
				myPickupTimer = 0;
				myVisual.SetTexture(mySpearTexture);
				mySpear->imFuckingDead = true;
				mySpear = NULL;
				myState = Moving;
			}
		}

		break;
	}
}

void ThirdBoss::Draw(sf::RenderWindow& aWindow)
{
	myVisual.Draw(aWindow, myPosition);
}

void ThirdBoss::ThrowSpear()
{
	Vector2 tempMovement = myPlayer->GetPosition() - myPosition;
	tempMovement.Normalize();
	mySpear = new Spear(myPosition, tempMovement);
	gameInfo::addGameObject(mySpear);
}
