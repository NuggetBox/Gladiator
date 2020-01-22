#include "GameObject.h"

GameObject::GameObject(Vector2 aPosition, sf::Texture aTexture, float aRotation, float aScale, int aLayer)
{
	myPosition = aPosition;

	myLayer = aLayer;

	myAppearance = Appearance(aTexture, aRotation, { aScale, aScale }, { 0.5f * aTexture.getSize().x, 0.5f * aTexture.getSize().y });
}

GameObject::GameObject()
{
	myPosition = { 0, 0 };
	myAppearance = Appearance();
}

GameObject::~GameObject()
{

}

void GameObject::Update(const float& someDelta)
{
	myAppearance.Update(someDelta);
}

void GameObject::Draw(sf::RenderWindow& aWindow)
{
	myAppearance.Draw(aWindow, myPosition);
}

int GameObject::GetLayer()
{
	return myLayer;
}