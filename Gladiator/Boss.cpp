#include "Boss.h"


Boss::Boss()
{
	myCharacterType = BossType;
	myPlayer = gameInfo::getPlayer();
}

void Boss::Update(const float& someDelta)
{

}


void Boss::Ultimate()
{

}

Boss::~Boss()
{
	delete(myPlayer);
}