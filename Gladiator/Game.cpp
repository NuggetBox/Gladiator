#include <SFML/Graphics.hpp>
#include "Game.h"

Game::Game()
{
	gameInfo::setGameObjects(&myGameObjects);

	// Player
	/*Player* tempPlayer = new Player();
	gameInfo::setPlayer(tempPlayer);
	myGameObjects.push_back(tempPlayer);

	// Second boss
	SecondBoss* tempBoss = new SecondBoss();
	myGameObjects.push_back(tempBoss);

	// Third boss
	ThirdBoss* tempThird = new ThirdBoss();
	myGameObjects.push_back(tempThird);

	// Sand ground
	sf::Texture tempTexture;
	tempTexture.loadFromFile("Textures/Sand.png");
	myGameObjects.push_back(new GameObject({ 1000, 500 }, tempTexture, 0, 5, 0, 0));

	// Gay button
	tempTexture.loadFromFile("Textures/gmod.png");
	myGUI.push_back(new GUI(tempTexture, { 900, 320 }, { 10,5 }, "You have to win in the gladiator tournament\n				to get the gay vaccine.", 40, { 400, 200 }, true));*/

	BattleBossOne();
}

Game::~Game()
{
	
}

bool Game::Update(const float& someDelta, sf::RenderWindow &aRenderWindow)
{
	// Boss has been killed
	if (gameInfo::getBossIsDead())
	{
		gameInfo::setBossIsDead(false);

		sf::Texture tempTexture;
		tempTexture.loadFromFile("Textures/Ok.png");
		myGUI.push_back(new GUI(tempTexture, { 900, 320 }, { 10, 5 }, "Congratulations! You Win!", 40, { 400, 200 }, gameInfo::getWinButtonBool(), true));
	}

	// Win button pressed
	if (gameInfo::getWinButtonPressed())
	{
		gameInfo::setWinButton(false);

		myGameObjects.clear();
	}

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

void Game::BattleBossOne()
{
	// Sand ground
	sf::Texture tempTexture;
	tempTexture.loadFromFile("Textures/Sand.png");
	myGameObjects.push_back(new GameObject({ 1000, 500 }, tempTexture, 0, 5, 0, 0));

	// Player
	Player* tempPlayer = new Player();
	playerInfo::setPlayer(tempPlayer);
	myGameObjects.push_back(tempPlayer);

	// First boss
	StartingBoss* tempStartingBoss = new StartingBoss();
	myGameObjects.push_back(tempStartingBoss);
}

void Game::BattleBossTwo()
{
	// Sand ground
	sf::Texture tempTexture;
	tempTexture.loadFromFile("Textures/Sand.png");
	myGameObjects.push_back(new GameObject({ 1000, 500 }, tempTexture, 0, 5, 0, 0));

	// Player
	Player* tempPlayer = new Player();
	playerInfo::setPlayer(tempPlayer);
	myGameObjects.push_back(tempPlayer);

	// Second boss
	SecondBoss* tempBoss = new SecondBoss();
	myGameObjects.push_back(tempBoss);
}

void Game::BattleBossThree()
{
	// Sand ground
	sf::Texture tempTexture;
	tempTexture.loadFromFile("Textures/Sand.png");
	myGameObjects.push_back(new GameObject({ 1000, 500 }, tempTexture, 0, 5, 0, 0));

	// Player
	Player* tempPlayer = new Player();
	playerInfo::setPlayer(tempPlayer);
	myGameObjects.push_back(tempPlayer);

	// Third boss
	ThirdBoss* tempThird = new ThirdBoss();
	myGameObjects.push_back(tempThird);
}

void Game::OpenSkillAndEquipmentMenu()
{

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

		for (int i = 0; (size_t)i + (size_t)1 < someGameObjects.size(); ++i)
		{
			if (someGameObjects[i]->GetLayer() > someGameObjects[(size_t)i + (size_t)1]->GetLayer())
			{
				tempNoErrors = false;

				GameObject* tempGameObject = someGameObjects[(size_t)i + (size_t)1];
				someGameObjects[(size_t)i + (size_t)1] = someGameObjects[i];
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

		for (int i = 0; (size_t)i + (size_t)1 < someGUI.size(); ++i)
		{
			if (someGUI[i]->GetLayer() > someGUI[(size_t)i + (size_t)1]->GetLayer())
			{
				tempNoErrors = false;

				GUI* tempGUI = someGUI[(size_t)i + (size_t)1];
				someGUI[(size_t)i + (size_t)1] = someGUI[i];
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