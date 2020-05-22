#include "Boss.h"

Boss::Boss()
{
	myIsPlayer = false;
	myPlayer = playerInfo::getPlayer();
}

void Boss::Update(const float& someDelta)
{

}

Boss::~Boss()
{
	delete(myPlayer);
}