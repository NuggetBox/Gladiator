#include "GameObject.h"


GameObject::GameObject(Vector2 aPosition, sf::Texture aTexture, float aRotation, float aScale, int aLayer, float aHitBox)
{
	myPosition = aPosition;
	myLayer = aLayer;
	myHitRadius = aHitBox;
	myIsCharacter = false;
	imFuckingDead = false;

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

float GameObject::GetHitRadius()
{
	return myHitRadius;
}

bool GameObject::GetIsCharacter()
{
	return myIsCharacter;
}
