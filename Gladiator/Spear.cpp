#include "Spear.h"

Spear::Spear(bool anIsPlayer, Vector2 aDir, Vector2 aStartPos) 
{
	myHitRadius = 50;
	myIsPlayer = anIsPlayer;
	myIsDead = false;
	myDir = aDir;
	mySpeed = 1000;
	myDamage = 5;
	myTexture.loadFromFile("Textures/spear.png");
	myLayer = 11;
	myPosition = aStartPos;
	myVisual = Visual(myTexture, myDir.Angle() + 180, { 3.0f, 3.0f }, { 0.5f * myTexture.getSize().x, 0.5f * myTexture.getSize().y });

}

Spear::~Spear() 
{

}

void Spear::Update(const float& someDelta) 
{
	myDir.Normalize();
	myDir *= (mySpeed * someDelta);
	RequestMove(myDir);
	
}

void Spear::Draw(sf::RenderWindow& aWindow) 
{
	myVisual.Draw(aWindow,myPosition);
}

Vector2 Spear::GetDir() {
	return myDir;
}

void Spear::SetDir(Vector2 aDir) {
	myDir = aDir;
}

void Spear::RequestMove(Vector2 aMovement)
{
	myPosition += aMovement;

	RequestHit(myIsPlayer);

	std::vector<GameObject*>* tempGameObjects = gameInfo::getGameObjects();

	if (gameInfo::getOutOfBounds(myPosition, myHitRadius))
	{
		myIsDead = true;
	}

	//for (GameObject* g : *tempGameObjects)
	//{
	//	if (g->GetHitRadius() != 0 && g != this && !g->GetIsCharacter())
	//	{
	//		if (tempDestination.Distance(g->GetPosition()) < myHitRadius + g->GetHitRadius())
	//		{
	//			imFuckingDead = true;
	//		}
	//	}
	//}

}

void Spear::RequestHit(bool anIsPlayer)
{
	std::vector<GameObject*>* tempGameObjects = gameInfo::getGameObjects();

	for (GameObject* g : *tempGameObjects)
	{
		if (g->GetIsCharacter())
		{
			Character* tempCharacter = (Character*)g;

			if (!tempCharacter->GetIsInvincible())
			{
				if (anIsPlayer && !tempCharacter->GetIsPlayer() || !anIsPlayer && tempCharacter->GetIsPlayer())
				{
					Vector2 dir = tempCharacter->GetPosition() - myPosition;

					if (dir.Length() < myHitRadius)
					{
						tempCharacter->TakeDamage(myDamage);
						myIsDead = true;
						// It's a hit	
					}
				}
			}
		}
	}
}