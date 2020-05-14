#include <SFML/Graphics.hpp>
#include "Game.h"

Game::Game()
{
	gameInfo::setGameObjects(&myGameObjects);

	Player* tempPlayer = new Player();
	gameInfo::setPlayer(tempPlayer);

	Boss* tempBoss = new StartingBoss();
	myGameObjects.push_back(tempPlayer);
	myGameObjects.push_back(tempBoss);
	ThirdBoss* tempThird = new ThirdBoss();
	myGameObjects.push_back(tempThird);

	for (int i = 0; i < 50; ++i)
	{
		Enemy* tempEnemy = new Enemy();
		myGameObjects.push_back(tempEnemy);
	}

	sf::Texture tempTexture;
	tempTexture.loadFromFile("Textures/Sand.png");
	myGameObjects.push_back(new GameObject({ 1000, 500 }, tempTexture, 0, 5, 0, 0));

	tempTexture.loadFromFile("Textures/gmod.png");
	myGUI.push_back(new GUI(tempTexture, { 100,100 }, { 10,10 }, "Hej Benjamin och Alvin", 24, { 100, 200 }));
}

Game::~Game()
{
	

}

bool Game::Update(const float& someDelta, sf::RenderWindow &aRenderWindow)
{
	for (int i = 0; i < myGameObjects.size(); ++i)
	{
		GameObject* tempObject = myGameObjects[i];
		
		if (tempObject->imFuckingDead)
		{
			myGameObjects.erase(myGameObjects.begin() + i);
		}
		else
		{
			tempObject->Update(someDelta);
		}
	}

	for (int i = 0; i < myGUI.size(); ++i)
	{
		myGUI[i]->Update(someDelta);
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

	myGUI = SortByLayer(myGUI);

	for (int i = 0; i < myGUI.size(); ++i)
	{
		myGUI[i]->Draw(aWindow);
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

std::vector<GUI*> Game::SortByLayer(std::vector<GUI*> someGUI)
{
	bool tempFinished = false;
	bool tempNoErrors;

	while (!tempFinished)
	{
		tempNoErrors = true;

		for (int i = 0; 1.0f + i < someGUI.size(); ++i)
		{
			if (someGUI[i]->GetLayer() > someGUI[1.0f + i]->GetLayer())
			{
				tempNoErrors = false;

				GUI* tempGUI = someGUI[1.0f + i];
				someGUI[1.0f + i] = someGUI[i];
				someGUI[i] = tempGUI;
			}
		}

		if (tempNoErrors)
		{
			tempFinished = true;
		}
	}

	return someGUI;
}