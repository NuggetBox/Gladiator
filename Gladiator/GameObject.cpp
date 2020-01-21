#include "GameObject.h"

GameObject::GameObject()
{
	myPosition = Vector2(0, 0);
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
	sf::Sprite tempSprite = myAppearance.GetSprite();
	tempSprite.setPosition(myPosition.x, myPosition.y);
	aWindow.draw(tempSprite);
}