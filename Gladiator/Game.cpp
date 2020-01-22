#include "Game.h"

Game::Game()
{
	myGameObjects.push_back(new Player());
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
	for (int i = 0; i < myGameObjects.size(); ++i)
	{
		myGameObjects[i]->Draw(aWindow);
	}
}