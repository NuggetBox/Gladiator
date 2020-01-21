#include "Animation.h"

Animation::Animation(std::vector<sf::Texture> someTextures, float aLengthInSec)
{
	myTextures = someTextures;
	myLength = aLengthInSec;
	myTimer = 0;
	myIsPlaying = false;
	myPlayingOnlyOnce = false;
}

Animation::Animation()
{
	myTextures = { sf::Texture() };
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

sf::Texture Animation::GetCurrentTexture()
{
	return myTextures[(int)(myTimer * myTextures.size() / myLength)];
}