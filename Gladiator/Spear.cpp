#include "Spear.h"

Spear::Spear(CharacterType aCharactertype, Vector2 aDir) {
	myHitRadius = 3;
	myCharactertype = aCharactertype;
	myDir = aDir;
}

Spear::~Spear() {

}

void Spear::Update(const float& someDelta) {

	myDir *= (mySpeed * someDelta);
	RequestMove(myDir);

	RequestHit(myCharactertype);
}

void Spear::Draw(sf::RenderWindow& aWindow) {

}

Vector2 Spear::GetDir() {
	return myDir;
}

void Spear::SetDir(Vector2 aDir) {
	myDir = aDir;
}

void Spear::RequestMove(Vector2 aMovement)
{
	Vector2 tempDestination = myPosition + aMovement;

	std::vector<GameObject*>* tempGameObjects = gameInfo::getGameObjects();

	if (gameInfo::getOutOfBounds(tempDestination, myHitRadius))
	{
		imFuckingDead = true;
	}

	for (GameObject* g : *tempGameObjects)
	{
		if (g->GetHitRadius() != 0 && g != this && !g->GetIsCharacter())
		{
			if (tempDestination.Distance(g->GetPosition()) < myHitRadius + g->GetHitRadius())
			{
				imFuckingDead;
			}
		}
	}

	myPosition = tempDestination;
}

void Spear::RequestHit(CharacterType anAllyCharacterType)
{
	std::vector<GameObject*>* tempGameObjects = gameInfo::getGameObjects();

	bool tempFriendly = anAllyCharacterType == PlayerType;

	for (GameObject* g : *tempGameObjects)
	{
		if (g->GetIsCharacter())
		{
			Character* tempCharacter = (Character*)g;

			if (!tempCharacter->GetIsInvincible())
			{
				if (tempFriendly && tempCharacter->GetCharacterType() != PlayerType || !tempFriendly && tempCharacter->GetCharacterType() == PlayerType)
				{
					Vector2 dir = tempCharacter->GetPosition() - myPosition;

					if (dir.Length() < myHitRadius)
					{
						tempCharacter->TakeDamage(myDamage);
					}
				}
			}
		}
	}
}