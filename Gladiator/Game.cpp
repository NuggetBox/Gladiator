#include <SFML/Graphics.hpp>
#include "Game.h"

Game::Game()
{
	gameInfo::setGameObjects(&myGameObjects);

	Player* tempPlayer = new Player();
	gameInfo::setPlayer(tempPlayer);

	StartingBoss* tempBoss = new StartingBoss();
	myGameObjects.push_back(tempPlayer);
	myGameObjects.push_back(tempBoss);

	sf::Texture tempTexture;
	tempTexture.loadFromFile("Textures/Sand.png");
	myGameObjects.push_back(new GameObject({ 1000, 500 }, tempTexture, 0, 5, 0, 0));
}

Game::~Game()
{
	

}

bool Game::Update(const float& someDelta, sf::RenderWindow &aRenderWindow)
{
	for (int i = 0; i < myGameObjects.size(); ++i)
	{
		myGameObjects[i]->Update(someDelta);
	}

	in::update(aRenderWindow);

	return true;
}

void Game::Draw(sf::RenderWindow& aWindow)
{
	myGameObjects = SortByLayer(myGameObjects);

	for (int i = 0; i < myGameObjects.size(); ++i)
	{
		myGameObjects[i]->Draw(aWindow);
	}
}

void RequestHit(Player* aPlayer, float aHitAngle, float aHitRange)
{

}

std::vector<GameObject*> Game::SortByLayer(std::vector<GameObject*> someGameObjects)
{
	bool tempFinished = false;
	bool tempNoErrors;

	while (!tempFinished)
	{
		tempNoErrors = true;

		for (int i = 0; 1.0f + i < someGameObjects.size(); ++i)
		{
			if (someGameObjects[i]->GetLayer() > someGameObjects[1.0f + i]->GetLayer())
			{
				tempNoErrors = false;

				GameObject* tempGameObject = someGameObjects[1.0f + i];
				someGameObjects[1.0f + i] = someGameObjects[i];
				someGameObjects[i] = tempGameObject;
			}
		}

		if (tempNoErrors)
		{
			tempFinished = true;
		}
	}

	return someGameObjects;
}