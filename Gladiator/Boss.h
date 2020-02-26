#ifndef BOSS_HEADER
#define BOSS_HEADER

#include "Enemy.h"
#include "Player.h"
#include "GameInfo.h"

class Boss : public Enemy
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