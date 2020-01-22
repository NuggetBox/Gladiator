#ifndef GAME_HEADER
#define GAME_HEADER

#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	bool Update(const float& someDelta);
	void Draw(sf::RenderWindow& aWindow);

private:
	std::vector<GameObject*> myGameObjects;

};

#endif