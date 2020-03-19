#include "Character.h"

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
