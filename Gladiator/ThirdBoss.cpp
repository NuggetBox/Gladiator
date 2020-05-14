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
	myTexture.loadFromFile("Textures/Boss/netguy.png");
	//myVisual = Visual(myTexture, myRotation, myScale, myOrigin);
	myVisual = Visual(myTexture, 0, { 5, 5 }, { 0.5f * myTexture.getSize().x, 0.5f * myTexture.getSize().y });
	myHitRadius = 30;
	myIsInvincible = false;
	myState = MoveForThrow;
}

ThirdBoss::~ThirdBoss()
{
	delete(myPlayer);
	myPlayer = NULL;
}

void ThirdBoss::Update(const float& someDelta) 
{
	Vector2 tempMove;

	switch (myState)
	{
	case MoveForThrow:
		tempMove = (myPlayer->GetPosition() - gameInfo::getArenaCenter()) * -1;
		tempMove += gameInfo::getArenaCenter();
		tempMove -= myPosition;

		if (tempMove.Length() > 5)
		{
			tempMove.Normalize();
			tempMove *= (mySpeed * someDelta);
			RequestMove(tempMove);
		}


		break;

	case Throwing:

		break;

	case MoveForAttack:

		break;

	case Attacking:

		break;
	}
}

void ThirdBoss::Draw(sf::RenderWindow& aWindow)
{
	myVisual.Draw(aWindow, myPosition);
}
