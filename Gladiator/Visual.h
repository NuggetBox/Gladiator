#ifndef VISUAL_HEADER
#define VISUAL_HEADER

#include "Vector2.h"
#include "Animation.h"

class Visual
{
public:
	Visual(sf::Texture aTexture, float aRotation, Vector2 aScale, Vector2 anOrigin);
	Visual(sf::Texture aTexture, float aRotation, Vector2 aScale, Vector2 anOrigin, Animation anAnimation);
	Visual();
	~Visual();

	void Update(const float& someDelta);

	void Draw(sf::RenderWindow& aWindow, Vector2 aPositon);

	void SetTexture(sf::Texture aTexture);
	void SetRotation(float aRotation);
	void SetScale(Vector2 aScale);
	void SetOrigin(Vector2 anOrigin);
	void SetColor(sf::Color aColor);
	void SetTextureRect(sf::IntRect aTextureRect);

	sf::Texture GetTexture();
	Animation GetAnimation();
	float GetRotation();
	Vector2 GetScale();
	Vector2 GetOrigin();
	sf::Color GetColor();
	sf::IntRect GetTextureRect();

	void SetAnimation(Animation anAnimation);
	void PlayAnimationOnce();
	void PlayAnimationOnLoop();
	void PlayAnimationOnce(Animation anAnimation);
	void PlayAnimationOnLoop(Animation anAnimation);
	void StopAnimation();

	bool GetAnimationOn();

private:
	sf::Texture myTexture;
	float myRotation;
	Vector2 myScale;
	Vector2 myOrigin;
	sf::Color myColor;
	sf::IntRect myTextureRect;
	Animation myAnimation;
};

#endif