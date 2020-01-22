#ifndef APPEARANCE_HEADER
#define APPEARANCE_HEADER

#include "Animation.h"
#include "Vector2.h"

class Appearance
{
public:
	Appearance(sf::Texture aTexture, float aRotation, Vector2 aScale, Vector2 anOrigin);
	Appearance(sf::Texture aTexture, float aRotation, Vector2 aScale, Vector2 anOrigin, Animation anAnimation);
	Appearance();
	~Appearance();

	void Update(const float& someDelta);

	void SetTexture(sf::Texture aTexture);
	void SetRotation(float aRotation);
	void SetScale(Vector2 aScale);
	void SetOrigin(Vector2 anOrigin);

	sf::Texture GetTexture();
	float GetRotation();
	Vector2 GetScale();
	Vector2 GetOrigin();

	void SetAnimation(Animation anAnimation);
	void PlayAnimationOnce();
	void PlayAnimationOnLoop();
	void PlayAnimationOnce(Animation anAnimation);
	void PlayAnimationOnLoop(Animation anAnimation);
	void StopAnimation();

private:
	sf::Texture myTexture;
	float myRotation;
	Vector2 myScale;
	Vector2 myOrigin;
	Animation myAnimation;
};

#endif