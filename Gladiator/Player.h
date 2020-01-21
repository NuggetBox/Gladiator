#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	~Player();

	void Init(const sf::Texture& aTexture);

	void Update(const float& someDelta);
	void Draw(sf::RenderWindow& aWindow);
private:
	sf::Sprite mySprite;
	float mySpeed;
};

#endif