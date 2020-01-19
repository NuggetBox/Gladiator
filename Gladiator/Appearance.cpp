#include "Appearance.h"

Appearance::Appearance(sf::Texture aTexture, float aRotation, Vector2 aScale, Vector2 anOrigin, sf::Color aColor)
{
	mySprite.setTexture(aTexture);
	mySprite.setRotation(aRotation);
	mySprite.setScale(aScale.x, aScale.y);
	mySprite.setOrigin(anOrigin.x, anOrigin.y);
	mySprite.setColor(aColor);
	mySprite.setPosition(0, 0);
	myAnimation = Animation({ aTexture }, 0.1f);
}

Appearance::Appearance(sf::Texture aTexture, float aRotation, Vector2 aScale, Vector2 anOrigin, sf::Color aColor, Animation anAnimation)
{
	mySprite.setTexture(aTexture);
	mySprite.setRotation(aRotation);
	mySprite.setScale(aScale.x, aScale.y);
	mySprite.setOrigin(anOrigin.x, anOrigin.y);
	mySprite.setColor(aColor);
	mySprite.setPosition(0, 0);
	myAnimation = anAnimation;
}

Appearance::~Appearance()
{

}

void Appearance::Update(const float& someDelta)
{
	myAnimation.Update(someDelta);
}

void Appearance::SetTexture(sf::Texture aTexture)
{
	mySprite.setTexture(aTexture);
}

void Appearance::SetRotation(float aRotation)
{
	mySprite.setRotation(aRotation);
}

void Appearance::SetScale(Vector2 aScale)
{
	mySprite.setScale(aScale.x, aScale.y);
}

void Appearance::SetOrigin(Vector2 aScale)
{
	mySprite.setOrigin(aScale.x, aScale.y);
}

void Appearance::SetColor(sf::Color aColor)
{
	mySprite.setColor(aColor);
}

void Appearance::SetAnimation(Animation anAnimation)
{
	myAnimation = anAnimation;
}

void Appearance::PlayAnimationOnce()
{
	myAnimation.PlayOnce();
}

void Appearance::PlayAnimationOnLoop()
{
	myAnimation.PlayOnLoop();
}

void Appearance::PlayAnimationOnce(Animation anAnimation)
{
	myAnimation = anAnimation;
	
	myAnimation.PlayOnce();
}

void Appearance::PlayAnimationOnLoop(Animation anAnimation)
{
	myAnimation = anAnimation;

	myAnimation.PlayOnLoop();
}

void Appearance::StopAnimation()
{
	myAnimation.Stop();
}

sf::Sprite Appearance::GetSprite()
{
	if (myAnimation.GetIsPlaying())
	{
		sf::Sprite tempSprite = mySprite;

		tempSprite.setTexture(myAnimation.GetCurrentTexture());

		return tempSprite;
	}

	return mySprite;
}