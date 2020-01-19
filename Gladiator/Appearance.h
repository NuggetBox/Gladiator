#ifndef APPEARANCE_HEADER
#define APPEARANCE_HEADER

#include "Animation.h"
#include "Vector2.h"

class Appearance
{
public:
	Appearance(sf::Texture aTexture, float aRotation, Vector2 aScale, Vector2 anOrigin, sf::Color aColor);
	Appearance(sf::Texture aTexture, float aRotation, Vector2 aScale, Vector2 anOrigin, sf::Color aColor, Animation anAnimation);
	~Appearance();

	void Update(const float& someDelta);

	void SetTexture(sf::Texture aTexture);
	void SetRotation(float aRotation);
	void SetScale(Vector2 aScale);
	void SetOrigin(Vector2 anOrigin);
	void SetColor(sf::Color aColor);

	void SetAnimation(Animation anAnimation);
	void PlayAnimationOnce();
	void PlayAnimationOnLoop();
	void PlayAnimationOnce(Animation anAnimation);
	void PlayAnimationOnLoop(Animation anAnimation);
	void StopAnimation();

	sf::Sprite GetSprite();

private:
	sf::Sprite mySprite;
	Animation myAnimation;
};

#endif