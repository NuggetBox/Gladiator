#include "Boss.h"

Boss::Boss()
{
	myIsPlayer = false;
	myPlayer = gameInfo::getPlayer();
}

void Boss::Update(const float& someDelta)
{

}

Boss::~Boss()
{
	delete(myPlayer);
}