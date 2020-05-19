#include "ThirdBoss.h"

ThirdBoss::ThirdBoss()
{
	myCharacterType = CharacterType::BossType;
	myMaxHealth = 100;
	myHealth = myMaxHealth;
	myPlayer = gameInfo::getPlayer();
	myRegularSpeed = 150;
	myPickupSpeed = 300;
	mySpeed = myRegularSpeed;
	myPosition = Vector2(800, 500);
	myLayer = 12;
	mySpearTexture.loadFromFile("Textures/Boss/treudd.png");
	myNoSpearTexture.loadFromFile("Textures/Boss/nospear.png");
	myAimingTexture.loadFromFile("Textures/Boss/throwing.png");
	myStabTexture.loadFromFile("Textures/Boss/stabanimation.png");
	//myVisual = Visual(myTexture, myRotation, myScale, myOrigin);
	myVisual = Visual(mySpearTexture, 0, { 5, 5 }, { 0.5f * mySpearTexture.getSize().x, 0.5f * mySpearTexture.getSize().y });
	myHitRadius = 30;
	myIsInvincible = false;
	myState = Moving;
	myDamage = 10;

	myMoveTime = 3.5f;
	myMoveTimer = 0;
	myAimTime = 2;
	myAimTimer = 0;
	myPickupTime = 0.75f;
	myPickupTimer = 0;
	myDealtDamage = false;
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

		myMoveTimer += someDelta;

		if ((myPlayer->GetPosition() - myPosition).Length() < 200)
		{
			if (!myVisual.GetAnimationOn())
			{
				myVisual.PlayAnimationOnce(Animation(myStabTexture, 2, 1));
				myDealtDamage = false;
			}
			else
			{
				if (myVisual.GetAnimation().GetAnimationCompletion() >= 0.5f && !myDealtDamage)
				{
					myDealtDamage = true;
					myPlayer->TakeDamage(myDamage);
				}
			}
		}
		else
		{
			if (tempMove.Length() > 5)
			{
				myVisual.StopAnimation();
				tempMove.Normalize();
				tempMove *= (mySpeed * someDelta);
				RequestMove(tempMove);
			}

			myVisual.StopAnimation();

			if (myMoveTimer >= myMoveTime)
			{
				myMoveTimer = 0;
				myState = Aiming;
				myVisual.SetTexture(myAimingTexture);
			}
		}

		myVisual.SetRotation((myPosition - myPlayer->GetPosition()).Angle());

		break;

	case Aiming:
		tempMove = Vector2(0, 0);
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
		mySpeed = myPickupSpeed;
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
				mySpeed = myRegularSpeed;
				myState = Moving;
			}
		}

		break;
	}

	myVisual.Update(someDelta);
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
