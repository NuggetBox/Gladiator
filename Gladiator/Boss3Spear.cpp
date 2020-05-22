#include "Boss3Spear.h"
#include "GameInfo.h"

Boss3Spear::Boss3Spear(Vector2 aPosition, Vector2 someMovement)
{
	imFuckingDead = false;
	myPosition = aPosition;
	myTexture.loadFromFile("Textures/spear.png");
	myVisual = Visual(myTexture, 0, Vector2(5, 5), Vector2(myTexture.getSize().x * 0.5f, myTexture.getSize().y * 0.5f));
	myLayer = 20;
	myHitRadius = 15;
	myIsCharacter = false;
	mySpeed = 1000;
	myMovement = someMovement * mySpeed;
	myDamage = 15;
	myIsStuck = false;
}

Boss3Spear::~Boss3Spear()
{

}

void Boss3Spear::Update(const float& someDelta)
{
	if (TryMove(myMovement * someDelta) || myIsStuck)
	{
		myIsStuck = true;
		myMovement = Vector2(0, 0);
	}
	else
	{
		myPosition += myMovement * someDelta;
		myVisual.SetRotation(myMovement.Angle() + 180);
	}
}

void Boss3Spear::Draw(sf::RenderWindow& aWindow)
{
	myVisual.Draw(aWindow, myPosition);
}

bool Boss3Spear::TryMove(Vector2 someMovement)
{
	std::vector<GameObject*>* tempGameObjects = gameInfo::getGameObjects();

	if (gameInfo::getOutOfBounds(myPosition + someMovement, myHitRadius))
	{
		return true;
	}

	for (GameObject* g : *tempGameObjects)
	{
		if (g != this && g->GetIsCharacter())
		{
			Character* tempCharacter = (Character*)g;

			if (tempCharacter->GetIsPlayer())
			{
				if (!myIsStuck)
				{
					if ((myPosition - tempCharacter->GetPosition()).Length() < myHitRadius + tempCharacter->GetHitRadius())
					{
						tempCharacter->TakeDamage(myDamage);
						return true;
					}
				}
			}
		}
	}

	return false;
}
