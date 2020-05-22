#include <SFML/Graphics.hpp>
#include "Game.h"

Game::Game()
{
	gameInfo::setGameObjects(&myGameObjects);

	Player* tempPlayer = new Player();
	gameInfo::setPlayer(tempPlayer);

	SecondBoss* tempBoss = new SecondBoss();
	myGameObjects.push_back(tempPlayer);
	myGameObjects.push_back(tempBoss);
	ThirdBoss* tempThird = new ThirdBoss();
	myGameObjects.push_back(tempThird);

	sf::Texture tempTexture;
	tempTexture.loadFromFile("Textures/Sand.png");
	myGameObjects.push_back(new GameObject({ 1000, 500 }, tempTexture, 0, 5, 0, 0));

	tempTexture.loadFromFile("Textures/gmod.png");
	myGUI.push_back(new GUI(tempTexture, { 900, 320 }, { 10,5 }, "You have to win in the gladiator tournament\n				to get the gay vaccine.", 40, { 400, 200 }, true));
}

Game::~Game()
{
	
}

bool Game::Update(const float& someDelta, sf::RenderWindow &aRenderWindow)
{
	


	for (int i = 0; i < myGameObjects.size(); ++i)
	{
		if (myGameObjects[i]->imFuckingDead)
		{
			myGameObjects.erase(myGameObjects.begin() + i);
		}
		else
		{
			myGameObjects[i]->Update(someDelta);

			if (myGameObjects[i]->GetIsCharacter())
			{
				Character* tempCharacter = (Character*)myGameObjects[i];

				tempCharacter->CharacterUpdate(someDelta);
			}
		}
	}

	for (int i = 0; i < myGUI.size(); ++i)
	{
		if (myGUI[i]->GetDead())
		{
			myGUI.erase(myGUI.begin() + i);
		}
		else
		{
			myGUI[i]->Update(someDelta);
		}
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

std::vector<GameObject*> Game::SortByLayer(std::vector<GameObject*> someGameObjects)
{
	bool tempFinished = false;
	bool tempNoErrors;

	while (!tempFinished)
	{
		tempNoErrors = true;

		for (int i = 0; 1.0f + i < someGameObjects.size(); ++i)
		{
			if (someGameObjects[i]->GetLayer() > someGameObjects[(size_t)1 + (size_t)i]->GetLayer())
			{
				tempNoErrors = false;

				GameObject* tempGameObject = someGameObjects[(size_t)1 + (size_t)i];
				someGameObjects[(size_t)1 + (size_t)i] = someGameObjects[i];
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
			if (someGUI[i]->GetLayer() > someGUI[(size_t)1 + (size_t)i]->GetLayer())
			{
				tempNoErrors = false;

				GUI* tempGUI = someGUI[(size_t)1 + (size_t)i];
				someGUI[(size_t)1 + (size_t)i] = someGUI[i];
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