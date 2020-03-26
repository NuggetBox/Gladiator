#include "Character.h"
#include "GameInfo.h"

Character::Character()
{
	myCharacterType = PlayerType;
	myHealth = 0;
	myDamage = 0;
	mySpeed = 0;
	myHitAngle = 0;
	myHitRange = 0;
}

Character::~Character()
{

}

bool Character::RequestMove(Vector2 aMovement)
{
	Vector2 tempDestination = myPosition + aMovement;

	std::vector<GameObject*>* tempGameObjects = gameInfo::getGameObjects();

	if (gameInfo::getOutOfBounds(tempDestination, myHitRadius))
	{
		return true;
	}

	for (GameObject* g : *tempGameObjects)
	{
		if (g->GetHitRadius() != 0 && g != this && !g->GetIsCharacter())
		{
			if (tempDestination.Distance(g->GetPosition()) < myHitRadius + g->GetHitRadius())
			{
				return true;
			}
		}
	}

	myPosition = tempDestination;
	return false;
}

void Character::RequestHit(CharacterType aCharacterType)
{
	std::vector<GameObject*>* tempGameObjects = gameInfo::getGameObjects();

	for (GameObject* g : *tempGameObjects)
	{
		if (g->GetIsCharacter())
		{
			Character* tempCharacter = (Character*)g;

			//if (tempCharacter->GetCharacterType() != aCharacterType)
		}
	}
}

CharacterType Character::GetCharacterType()
{
	return myCharacterType;
}

int Character::GetHealth()
{
	return myHealth;
}

int Character::GetDamage()
{
	return myDamage;
}

int Character::GetSpeed()
{
	return mySpeed;
}

float Character::GetHitAngle()
{
	return myHitAngle;
}

float Character::GetHitRange()
{
	return myHitRange;
}
