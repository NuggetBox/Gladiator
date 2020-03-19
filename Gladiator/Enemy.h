#ifndef ENEMY_HEADER
#define ENEMY_HEADER

#include "Character.h"

class Enemy : public Character
{
public:
	Enemy();
	~Enemy();

	virtual void Attack(bool aNear);
	virtual void Idle();

private:
};

#endif