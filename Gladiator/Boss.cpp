#include "Boss.h"


Boss::Boss()
{
	myCharacterType = BossType;
	myPlayer = gameInfo::getPlayer();
}

void Boss::Update(const float& someDelta)
{

}

Boss::~Boss()
{
	delete(myPlayer);
}