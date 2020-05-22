#include "Animation.h"

Animation::Animation(sf::Texture someTextures, int aNumberOfFrames, float aLengthInSec)
{
	myTexture = someTextures;
	myNumberOfFrames = aNumberOfFrames;
	myLength = aLengthInSec;
	myTimer = 0;
	myIsPlaying = false;
	myPlayingOnlyOnce = false;
}

Animation::Animation()
{
	myTexture = sf::Texture();
	myNumberOfFrames = 1;
	myLength = 0.1f;
	myTimer = 0;
	myIsPlaying = false;
	myPlayingOnlyOnce = false;
}

Animation::~Animation()
{
	
}

void Animation::Update(const float& someDelta)
{
	if (myIsPlaying)
	{
		myTimer += someDelta;

		if (myTimer >= myLength)
		{
			myTimer = 0;

			if (myPlayingOnlyOnce)
			{
				Stop();
			}
		}
	}
}

void Animation::PlayOnLoop()
{
	myIsPlaying = true;
	myPlayingOnlyOnce = false;
	myTimer = 0;
}

void Animation::PlayOnce()
{
	myIsPlaying = true;
	myPlayingOnlyOnce = true;
	myTimer = 0;
}

void Animation::Stop()
{
	myIsPlaying = false;
	myTimer = 0;
}

bool Animation::GetIsPlaying()
{
	return myIsPlaying;
}

float Animation::GetAnimationCompletion()
{
	return myTimer / myLength;
}

sf::Texture Animation::GetTexture()
{
	return myTexture;
}

sf::IntRect Animation::GetCurrentTextureRect()
{
	return sf::IntRect(((int)(myTimer * myNumberOfFrames / myLength)) * (myTexture.getSize().x / myNumberOfFrames), 0, myTexture.getSize().x / myNumberOfFrames, myTexture.getSize().y);
}