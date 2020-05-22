#ifndef CHARACTER_HEADER
#define CHARACTER_HEADER

#include "GameObject.h"

class Character : 
	public GameObject
{
public:
	Character();
	~Character();

	void CharacterUpdate(const float& someDelta);

	bool GetIsPlayer();

	float GetHealthRatio();
	int GetHealth();
	int GetDamage();
	int GetSpeed();
	bool TakeDamage(int someDamage);

	float GetHitAngle();
	float GetHitRange();

	bool GetIsInvincible();

protected:
	bool RequestMove(Vector2 aMovement);
	void RequestHit(bool anIsPlayer);

	bool myIsPlayer;

	int myMaxHealth;
	int myHealth;
	int myDamage;
	int mySpeed;
	
	float myHitAngle;
	float myHitRange;
	float myIsTakingDamage;

	bool myIsInvincible;
};

#endif