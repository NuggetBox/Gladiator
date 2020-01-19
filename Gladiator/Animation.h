#ifndef ANIMATION_HEADER
#define ANIMATION_HEADER

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
public:
	Animation(std::vector<sf::Texture> someTextures, float aLengthInSec);
	Animation();
	~Animation();

	void Update(const float& someDelta);

	void PlayOnLoop();
	void PlayOnce();
	void Stop();

	bool GetIsPlaying();

	sf::Texture GetCurrentTexture();

private:
	std::vector<sf::Texture> myTextures;
	float myLength;
	float myTimer;
	bool myIsPlaying;
	bool myPlayingOnlyOnce;
	
};

#endif