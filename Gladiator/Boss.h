#ifndef BOSS_HEADER
#define BOSS_HEADER

#include "GameInfo.h"
#include "Enemy.h"

class Boss 
	: public Enemy
{
public:
	Boss();
	~Boss();

	void Update(const float& someDelta) override;

	virtual void Ultimate();

protected:
	Player* myPlayer;

};

#endif