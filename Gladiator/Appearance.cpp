#include "Appearance.h"

Appearance::Appearance(sf::Texture aTexture, float aRotation, Vector2 aScale, Vector2 anOrigin)
{
	myTexture = aTexture;
	myRotation = aRotation;
	myScale = aScale;
	myOrigin = anOrigin;
	myColor = { 255,255,255,255 };
	myIntRect = sf::IntRect( 0, 0, aTexture.getSize().x, aTexture.getSize().y );
	myAnimation = Animation();
}

Appearance::Appearance(sf::Texture aTexture, float aRotation, Vector2 aScale, Vector2 anOrigin, Animation anAnimation)
{
	myTexture = aTexture;
	myRotation = aRotation;
	myScale = aScale;
	myOrigin = anOrigin;
	myColor = { 255,255,255,255 };
	myIntRect = sf::IntRect(0, 0, aTexture.getSize().x, aTexture.getSize().y);
	myAnimation = anAnimation;
}

Appearance::Appearance()
{
	myAnimation = Animation();
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
	myTexture = aTexture;
}

void Appearance::SetRotation(float aRotation)
{
	myRotation = aRotation;
}

void Appearance::SetScale(Vector2 aScale)
{
	myScale = aScale;
}

void Appearance::SetOrigin(Vector2 anOrigin)
{
	myOrigin = anOrigin;
}

void Appearance::SetColor(sf::Color aColor)
{
	myColor = aColor;
}

void Appearance::SetTextureRect(sf::IntRect anIntRect)
{
	myIntRect = anIntRect;
}




sf::Texture Appearance::GetTexture()
{
	if (myAnimation.GetIsPlaying())
	{
		return myAnimation.GetTexture();
	}

	return myTexture;
}

float Appearance::GetRotation()
{
	return myRotation;
}

Vector2 Appearance::GetScale()
{
	return myScale;
}

Vector2 Appearance::GetOrigin()
{
	return myOrigin;
}

sf::Color Appearance::GetColor()
{
	return myColor;
}

sf::IntRect Appearance::GetTextureRect()
{
	if (myAnimation.GetIsPlaying())
	{
		return myAnimation.GetCurrentTextureRect();
	}

	return myIntRect;
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