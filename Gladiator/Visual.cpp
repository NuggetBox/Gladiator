#include "Visual.h"

Visual::Visual(sf::Texture aTexture, float aRotation, Vector2 aScale, Vector2 anOrigin)
{
	myTexture = aTexture;
	myRotation = aRotation;
	myScale = aScale;
	myOrigin = anOrigin;
	myColor = { 255,255,255,255 };
	myTextureRect = sf::IntRect( 0, 0, aTexture.getSize().x, aTexture.getSize().y );
	myAnimation = Animation();
}

Visual::Visual(sf::Texture aTexture, float aRotation, Vector2 aScale, Vector2 anOrigin, Animation anAnimation)
{
	myTexture = aTexture;
	myRotation = aRotation;
	myScale = aScale;
	myOrigin = anOrigin;
	myColor = { 255,255,255,255 };
	myTextureRect = sf::IntRect(0, 0, aTexture.getSize().x, aTexture.getSize().y);
	myAnimation = anAnimation;
}

Visual::Visual()
{
	myAnimation = Animation();
	myColor = { 255,255,255,255 };
}

Visual::~Visual()
{
	
}

void Visual::Update(const float& someDelta)
{
	myAnimation.Update(someDelta);
}

void Visual::Draw(sf::RenderWindow& aWindow, Vector2 aPosition)
{
	sf::Sprite tempSprite;
	sf::Texture tempTexture = GetTexture();
	tempSprite.setTexture(tempTexture);
	tempSprite.setRotation(myRotation);
	tempSprite.setOrigin(myOrigin.x, myOrigin.y);
	tempSprite.setScale(myScale.x, myScale.y);
	tempSprite.setPosition(aPosition.x, aPosition.y);
	tempSprite.setColor(myColor);
	tempSprite.setTextureRect(GetTextureRect());
	aWindow.draw(tempSprite);
}




void Visual::SetTexture(sf::Texture aTexture)
{
	myTexture = aTexture;
}

void Visual::SetRotation(float aRotation)
{
	myRotation = aRotation;
}

void Visual::SetScale(Vector2 aScale)
{
	myScale = aScale;
}

void Visual::SetOrigin(Vector2 anOrigin)
{
	myOrigin = anOrigin;
}

void Visual::SetColor(sf::Color aColor)
{
	myColor = aColor;
}

void Visual::SetTextureRect(sf::IntRect anIntRect)
{
	myTextureRect = anIntRect;
}




sf::Texture Visual::GetTexture()
{
	if (myAnimation.GetIsPlaying())
	{
		return myAnimation.GetTexture();
	}

	return myTexture;
}

float Visual::GetRotation()
{
	return myRotation;
}

Vector2 Visual::GetScale()
{
	return myScale;
}

Vector2 Visual::GetOrigin()
{
	return myOrigin;
}

sf::Color Visual::GetColor()
{
	return myColor;
}

sf::IntRect Visual::GetTextureRect()
{
	if (myAnimation.GetIsPlaying())
	{
		return myAnimation.GetCurrentTextureRect();
	}

	return myTextureRect;
}

void Visual::SetAnimation(Animation anAnimation)
{
	myAnimation = anAnimation;
}

void Visual::PlayAnimationOnce()
{
	myAnimation.PlayOnce();
}

void Visual::PlayAnimationOnLoop()
{
	myAnimation.PlayOnLoop();
}

void Visual::PlayAnimationOnce(Animation anAnimation)
{
	myAnimation = anAnimation;
	
	myAnimation.PlayOnce();
}

void Visual::PlayAnimationOnLoop(Animation anAnimation)
{
	myAnimation = anAnimation;

	myAnimation.PlayOnLoop();
}

void Visual::StopAnimation()
{
	myAnimation.Stop();
}

bool Visual::GetAnimationOn()
{
	return myAnimation.GetIsPlaying();
}