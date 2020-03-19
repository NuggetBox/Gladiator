#ifndef ANIMATION_HEADER
#define ANIMATION_HEADER

#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation(sf::Texture someTextures, int aNumberOfFrames, float aLengthInSec);
	Animation();
	~Animation();

	void Update(const float& someDelta);

	void PlayOnLoop();
	void PlayOnce();
	void Stop();

	bool GetIsPlaying();

	sf::Texture GetTexture();

	sf::IntRect GetCurrentTextureRect();

private:
	sf::Texture myTexture;
	int myNumberOfFrames;
	float myLength;

	float myTimer;
	bool myIsPlaying;
	bool myPlayingOnlyOnce;
	
};

#endif