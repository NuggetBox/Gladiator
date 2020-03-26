#ifndef CHARACTER_HEADER
#define CHARACTER_HEADER

#include "GameObject.h"

enum CharacterType { PlayerType, EnemyType, BossType };

class Character :
	public GameObject
{
public:
	Character();
	~Character();

	CharacterType GetCharacterType();

	int GetHealth();
	int GetDamage();
	int GetSpeed();
	void TakeDamage(int someDamage);

	float GetHitAngle();
	float GetHitRange();

protected:
	CharacterType myCharacterType;

	int myHealth;
	int myDamage;
	int mySpeed;
	
	float myHitAngle;
	float myHitRange;
};

#endif