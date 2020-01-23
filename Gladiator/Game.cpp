#include "Game.h"

Game::Game()
{
	gameInfo::setGameObjects(&myGameObjects);

	Player* tempPlayer = new Player();
	gameInfo::SetPlayer(tempPlayer);
	myGameObjects.push_back(tempPlayer);

	sf::Texture tempTexture;
	tempTexture.loadFromFile("Textures/Sand.png");
	myGameObjects.push_back(new GameObject({ 1000, 500 }, tempTexture, 0, 5, 0, 0));
}


Game::~Game()
{

}

bool Game::Update(const float& someDelta)
{
	for (int i = 0; i < myGameObjects.size(); ++i)
	{
		myGameObjects[i]->Update(someDelta);
	}

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

std::vector<GameObject*> Game::SortByLayer(std::vector<GameObject*> someGameObjects)
{
	bool tempFinished = false;
	bool tempNoErrors;

	while (!tempFinished)
	{
		tempNoErrors = true;

		for (int i = 0; i + 1 < someGameObjects.size(); ++i)
		{
			if (someGameObjects[i]->GetLayer() > someGameObjects[i + 1]->GetLayer())
			{
				tempNoErrors = false;

				GameObject* tempGameObject = someGameObjects[i + 1];
				someGameObjects[i + 1] = someGameObjects[i];
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