#include "GameObject.h"
#include "GameInfo.h"


GameObject::GameObject(Vector2 aPosition, sf::Texture aTexture, float aRotation, float aScale, int aLayer, float aHitBox)
{
	myPosition = aPosition;
	myLayer = aLayer;
	myHitRadius = aHitBox;

	myVisual = Visual(aTexture, aRotation, { aScale, aScale }, { 0.5f * aTexture.getSize().x, 0.5f * aTexture.getSize().y });
}

GameObject::GameObject()
{
	myPosition = { 0, 0 };
	myVisual = Visual();
}

GameObject::~GameObject()
{

}

void GameObject::Update(const float& someDelta)
{
	myVisual.Update(someDelta);
}

void GameObject::Draw(sf::RenderWindow& aWindow)
{
	myVisual.Draw(aWindow, myPosition);
}

int GameObject::GetLayer()
{
	return myLayer;
}

Vector2 GameObject::GetPosition()
{
	return myPosition;
}

void GameObject::RequestMove(Vector2 aMovement)
{
	Vector2 tempDestination = myPosition + aMovement;

	std::vector<GameObject*>* tempGameObjects = gameInfo::getGameObjects();

	if (gameInfo::getOutOfBounds(tempDestination, myHitRadius))
	{
		return;
	}

	for (GameObject* g : *tempGameObjects)
	{
		if (g->myHitRadius != 0 && g != this)
		{
			if (tempDestination.Distance(g->GetPosition()) < myHitRadius + g->myHitRadius)
			{
				return;
			}
		}
	}

	myPosition = tempDestination;
}
