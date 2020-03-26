#ifndef GAME_HEADER
#define GAME_HEADER

#include "GameInfo.h"
#include "Enemy.h"
#include "Player.h"
#include "StartingBoss.h"

class Game
{
public:
	Game();
	~Game();

	bool Update(const float& someDelta, sf::RenderWindow &aRenderWindow);
	void Draw(sf::RenderWindow& aWindow);

private:
	std::vector<GameObject*> myGameObjects;

	std::vector<GameObject*> SortByLayer(std::vector<GameObject*> someGameObjects);
};

#endif