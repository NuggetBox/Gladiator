#include "Character.h"
#include "GameInfo.h"

Character::Character()
{
	myIsPlayer = false;
	myIsCharacter = true;
	myMaxHealth = 0;
	myHealth = 0;
	myDamage = 0;
	mySpeed = 0;
	myHitAngle = 45;
	myHitRange = 150;
	myIsTakingDamage = 0;
	myIsInvincible = false;
}

Character::~Character()
{

}

void Character::CharacterUpdate(const float& someDelta)
{
	if (myIsTakingDamage > 0)
	{
		myVisual.SetColor(sf::Color(255, 100, 100, 255));
		myIsTakingDamage -= someDelta;
	}
	else
	{
		myVisual.SetColor(sf::Color(255, 255, 255, 255));
		myIsTakingDamage = 0;
	}
}

bool Character::RequestMove(Vector2 aMovement)
{
	Vector2 tempDestination = myPosition + aMovement;

	std::vector<GameObject*>* tempGameObjects = gameInfo::getGameObjects();

	if (gameInfo::getOutOfBounds(tempDestination, myHitRadius))
	{
		return true;
	}

	/*for (GameObject* g : *tempGameObjects)
	{
		if (g->GetHitRadius() != 0 && g != this && !g->GetIsCharacter())
		{
			if (tempDestination.Distance(g->GetPosition()) < myHitRadius + g->GetHitRadius())
			{
				return true;
			}
		}
	}*/

	myPosition = tempDestination;
	return false;
}

void Character::RequestHit(bool anIsPlayer)
{
	std::vector<GameObject*>* tempGameObjects = gameInfo::getGameObjects();

	for (GameObject* g : *tempGameObjects)
	{
		if (g->GetIsCharacter())
		{
			Character* tempCharacter = (Character*)g;
				
			if (!tempCharacter->GetIsInvincible())
			{
				if (anIsPlayer && !tempCharacter->GetIsPlayer() || !anIsPlayer && tempCharacter->GetIsPlayer())
				{
					Vector2 dir = tempCharacter->GetPosition() - myPosition;

					if (dir.Length() < myHitRange)
					{
						float diff = myVisual.GetRotation() - dir.Angle();

						if (abs(diff) < myHitAngle || abs(diff) + myHitAngle > 360)
						{
							tempCharacter->TakeDamage(myDamage);
							// It's a hit
						}
					}
				}
			}
		}
	}
}

bool Character::GetIsPlayer()
{
	return myIsPlayer;
}

float Character::GetHealthRatio()
{
	return myHealth / myMaxHealth;
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

bool Character::TakeDamage(int someDamage)
{
	myHealth -= someDamage;
	myIsTakingDamage = 0.5f;

	if (myHealth <= 0)
	{
		myHealth = 0;

		if (!myIsPlayer && !imFuckingDead)
		{
			*conditionsInfo::accessBossIsDead() = true;
		}
		else if (myIsPlayer && !imFuckingDead)
		{
			*conditionsInfo::accessPlayerIsDead() = true;
		}

		imFuckingDead = true;

		return true;
	}

	return false;
}

float Character::GetHitAngle()
{
	return myHitAngle;
}

float Character::GetHitRange()
{
	return myHitRange;
}

bool Character::GetIsInvincible()
{
	return myIsInvincible;
}
