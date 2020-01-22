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
	sf::Sprite tempSprite;
	sf::Texture tempTexture = myAppearance.GetTexture();
	tempSprite.setTexture(tempTexture);
	tempSprite.setRotation(myAppearance.GetRotation());
	tempSprite.setOrigin(myAppearance.GetOrigin().x, myAppearance.GetOrigin().y);
	tempSprite.setScale(myAppearance.GetScale().x, myAppearance.GetScale().y);
	tempSprite.setPosition(myPosition.x, myPosition.y);
	tempSprite.setColor(myAppearance.GetColor());
	tempSprite.setTextureRect(myAppearance.GetTextureRect());
	aWindow.draw(tempSprite);
}