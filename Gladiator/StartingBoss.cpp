#include "StartingBoss.h"

StartingBoss::StartingBoss()
{
	myPlayer = gameInfo::getPlayer();
}

void StartingBoss::Update(const float& someDelta)
{
	if (myPlayer->GetPosition().Distance(myPosition) < 100)
	{
		Attack(true);
	}
	if (myPlayer->GetPosition().Distance(myPosition) > 100)
	{
		Attack(false);
	}
}

void StartingBoss::Attack(bool aNear)
{
	switch (aNear)
	{
	case 0:
		
		break;
	case 1:
		break;
	}
}

void StartingBoss::Ultimate()
{

}

void StartingBoss::Idle()
{

}

StartingBoss::~StartingBoss()
{

}