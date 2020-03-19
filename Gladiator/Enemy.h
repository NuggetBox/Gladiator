#ifndef ENEMY_HEADER
#define ENEMY_HEADER

#include "GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();

	virtual void Attack(bool aNear);
	virtual void Idle();

private:
};

#endif