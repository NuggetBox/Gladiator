#ifndef APP_HEADER
#define APP_HEADER

#include "Player.h"

class App
{
public:
	App();
	~App();

	bool Update(const float& someDelta);
	void Draw(sf::RenderWindow& aWindow);
private:
	Player myPlayer;
	sf::Texture myTexture;
};

#endif